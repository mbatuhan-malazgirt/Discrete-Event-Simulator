#include "Simulation.h"
using namespace std;

Simulation::Simulation() // simulation default constructor.
{
	this->entered_hoodie=0;
	this->last_time=0;
	this->time = 0;
	this->total_turnaround_time = 0;
	this->eventQueue;
	this->all_hackers;
	this->hoodie_queue;
	this->sticker_queue;
	this->last_time=0;
	 this->code_commited = 0;
}

void Simulation::scheduleEvent(Eventss newEvent) // schedule event.
{
	eventQueue.push(newEvent);
}

void Simulation::pushHacker(Hacker& hacker) // hacker queue push.
{
	all_hackers.push_back(hacker);
}

void Simulation::pushSticker(StickerDesk& sticker_desk) // sticker desk push.
{
	sticker_queue.append_desks(sticker_desk);
}

void Simulation::pushHoodie(HoodieDesk& hoodie_desk) // hoodie queue push.
{
	hoodie_queue.append_desks(hoodie_desk);
}

void Simulation::run()
{
	while (!eventQueue.empty())
	{
		if (eventQueue.top().commitCode == true)// code commit event.
		{
			this->code_commited++;
			all_hackers[eventQueue.top().hackerID-1].commitcode(eventQueue.top().length_of_commit);
		}
		else if (eventQueue.top().queueEntrance == true) // sticker queue enter attempt
		{
			
			int available_id = sticker_queue.available_desk();
			int is_qualified = sticker_queue.is_qualified(all_hackers[eventQueue.top().hackerID - 1]);
			
			if (available_id != -1 &&  is_qualified ==1) // empty desk and qualified hacker.
			{
				
				all_hackers[eventQueue.top().hackerID - 1].turnaround_time_begin = eventQueue.top().time;
				
				all_hackers[eventQueue.top().hackerID-1].sticker_desk_id = available_id;
				
				float service_time = sticker_queue.sticker_desks[available_id].service_time;
				
				sticker_queue.sticker_desks[available_id].full = true;
				
				float timee = service_time + eventQueue.top().time;
				
				Eventss events(timee, eventQueue.top().hackerID, 0, false, false, true, false);
				this->scheduleEvent(events);
				
			}
			else if (available_id == -1 && is_qualified == 1) // qualified hacker and not empty desk.
			{
			
				sticker_queue.append_hacker(all_hackers[eventQueue.top().hackerID - 1]);
				
				all_hackers[eventQueue.top().hackerID - 1].enter_time_sticker = eventQueue.top().time;
				
				all_hackers[eventQueue.top().hackerID - 1].turnaround_time_begin = eventQueue.top().time;
				
			} 
			
		}
		else if (eventQueue.top().stickerExit == true) // sticker queue exit.
		{
			
			sticker_queue.sticker_desks[all_hackers[eventQueue.top().hackerID-1].sticker_desk_id].full = false;
			
			
			all_hackers[eventQueue.top().hackerID-1].stickers_taken++;
			
			

			int available_id = sticker_queue.available_desk();
			
			if (available_id != -1 && !sticker_queue.queue_empty()) // non empty desk and sticker queue not empty.
			{
				
				this->all_hackers[sticker_queue.hacker_queue.front().ID - 1].exit_time_sticker = eventQueue.top().time;
				
				this->all_hackers[sticker_queue.hacker_queue.front().ID - 1].waiting_time_sticker += all_hackers[sticker_queue.hacker_queue.front().ID - 1].exit_time_sticker - all_hackers[sticker_queue.hacker_queue.front().ID - 1].enter_time_sticker;
				
				this->all_hackers[sticker_queue.hacker_queue.front().ID - 1].sticker_desk_id = available_id;
				
				float service_time = sticker_queue.sticker_desks[available_id].service_time;
				
				sticker_queue.sticker_desks[available_id].full = true;
				
				float timee = service_time + eventQueue.top().time;
				
				Eventss events(timee, sticker_queue.hacker_queue.front().ID, 0, false, false, true, false);
				
				this->scheduleEvent(events);
				sticker_queue.hacker_queue.pop();
			
			}

		
			available_id = hoodie_queue.available_desk();
			
			all_hackers[eventQueue.top().hackerID - 1].enter_time_hoodie = eventQueue.top().time;

			if (available_id != -1 && !hoodie_queue.queue_empty()) // empty desk and hoodie queue not empty.
			{
				hoodie_queue.append_hacker(all_hackers[eventQueue.top().hackerID - 1]); 
				
				all_hackers[hoodie_queue.hacker_heap.top().ID - 1].exit_time_hoodie = eventQueue.top().time;
				all_hackers[hoodie_queue.hacker_heap.top().ID - 1].waiting_time_hoodie += all_hackers[hoodie_queue.hacker_heap.top().ID - 1].exit_time_hoodie - all_hackers[hoodie_queue.hacker_heap.top().ID - 1].enter_time_hoodie;
				this->all_hackers[hoodie_queue.hacker_heap.top().ID - 1].hoodie_desk_id = available_id;
				hoodie_queue.hoodie_desks[available_id].full = true;
				float service_time = hoodie_queue.hoodie_desks[available_id].service_time;
				float timee = service_time + eventQueue.top().time;
				Eventss events(timee, hoodie_queue.hacker_heap.top().ID, 0, false, false, false, true);
				this->scheduleEvent(events);
				hoodie_queue.hacker_heap.pop();
			}
			else if (available_id != -1 && hoodie_queue.queue_empty()) // non empty desk and hoodie queue empty.
			{
				
				this->all_hackers[eventQueue.top().hackerID-1].hoodie_desk_id = available_id;
				hoodie_queue.hoodie_desks[available_id].full = true;
				float service_time = hoodie_queue.hoodie_desks[available_id].service_time;
				float timee = service_time + eventQueue.top().time;
				Eventss events(timee, eventQueue.top().hackerID, 0, false, false, false, true);
				this->scheduleEvent(events);
			}

			else if (available_id == -1) // non empty desk.
			{
				
				hoodie_queue.append_hacker(all_hackers[eventQueue.top().hackerID - 1]);
				
			}

			
			
		}
		else if (eventQueue.top().hoodieExit == true) // hoodie queue exit.
		{

			hoodie_queue.hoodie_desks[all_hackers[eventQueue.top().hackerID-1].hoodie_desk_id].full = false;
			all_hackers[eventQueue.top().hackerID - 1].turnaround_time_end = eventQueue.top().time;
			all_hackers[eventQueue.top().hackerID-1].hoodies_taken++;
			all_hackers[eventQueue.top().hackerID - 1].total_gifts++;
			this->total_turnaround_time += all_hackers[eventQueue.top().hackerID - 1].turnaround_time_end - all_hackers[eventQueue.top().hackerID - 1].turnaround_time_begin;
			all_hackers[eventQueue.top().hackerID-1].total_waited_queue = all_hackers[eventQueue.top().hackerID - 1].waiting_time_sticker + all_hackers[eventQueue.top().hackerID - 1].waiting_time_hoodie;
			int available_id = hoodie_queue.available_desk();
			if (available_id != -1 && !hoodie_queue.queue_empty())
			{
				
				all_hackers[hoodie_queue.hacker_heap.top().ID - 1].exit_time_hoodie = eventQueue.top().time;
				all_hackers[hoodie_queue.hacker_heap.top().ID - 1].waiting_time_hoodie += all_hackers[hoodie_queue.hacker_heap.top().ID - 1].exit_time_hoodie - all_hackers[hoodie_queue.hacker_heap.top().ID - 1].enter_time_hoodie;
			
				this->all_hackers[hoodie_queue.hacker_heap.top().ID - 1].hoodie_desk_id = available_id;
				hoodie_queue.hoodie_desks[available_id].full = true;
				float service_time = hoodie_queue.hoodie_desks[available_id].service_time;
				float timee = service_time + eventQueue.top().time;
				Eventss events(timee, hoodie_queue.hacker_heap.top().ID, 0, false, false, false, true);
				this->scheduleEvent(events);
				hoodie_queue.hacker_heap.pop();
			}
		
		}
		last_time = eventQueue.top().time;
		eventQueue.pop();
	}
}
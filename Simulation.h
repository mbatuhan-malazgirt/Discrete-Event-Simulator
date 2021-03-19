#include "HoodieQueue.h"
#include "StickerQueue.h"
#include "Eventss.h" 
#include "Hacker.h"
#include "StickerDesk.h"
#include "HoodieDesk.h"
using namespace std;

#ifndef SIMULATION_H
#define SIMULATION_H

struct eventComparator {
	bool operator() (Eventss const left, Eventss const right) const // event comperator
	{
		
		if (left.time - right.time > (float) 0.00001)
		{
			return true;
		}
		else if (left.time - right.time < (float) 0.00001)
		{
			if (abs(left.time - right.time) < (float) 0.00001)
			{
				return left.hackerID > right.hackerID;
			}
			return false;
		}		
	}
};

class Simulation
{
public:
	Simulation();
	float last_time;
	float time;
	int code_commited;
	int entered_hoodie;
	float total_turnaround_time;
	void run();
	Eventss first_event;
	void scheduleEvent(Eventss newEvent);
	void pushHacker(Hacker &  hacker);
	void pushSticker(StickerDesk&  sticker_desk);
	void pushHoodie(HoodieDesk&  hoodie_desk);
	priority_queue<Eventss, vector<Eventss>, eventComparator> eventQueue;

	vector<Hacker> all_hackers;
	HoodieQueue hoodie_queue;
	StickerQueue sticker_queue;
};

#endif // SIMULATION_H
#include "HoodieQueue.h"
using namespace std;


HoodieQueue::HoodieQueue() // Hoodie Queue default constructor.
{
	priority_queue<Hacker, vector<Hacker>, CompareHacker> hacker_heap();
	vector<HoodieDesk> all_desks();
	this->max_length = 0;
}

void HoodieQueue::append_desks(HoodieDesk s) // appending desks to the queue.
{
	hoodie_desks.push_back(s);
}

void HoodieQueue::append_hacker(Hacker h) // appending hacker to the vector.
{
	hacker_heap.push(h);

	if (this->max_length < this->hacker_heap.size())
	{
		this->max_length = this->hacker_heap.size();
	}
	
}

int HoodieQueue::available_desk()
{
	for (int i = 0; i < hoodie_desks.size(); i++)
	{
		if (hoodie_desks[i].full == false)
		{
			return i;
		}
	}
	return -1;
}

bool HoodieQueue::queue_empty()
{
	return hacker_heap.empty();
}


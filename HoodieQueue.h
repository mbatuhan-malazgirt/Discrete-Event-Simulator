#include "Hacker.h"
#include "HoodieDesk.h"
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

#ifndef HOODIEQUEUE_H
#define HOODIEQUEUE_H
struct CompareHacker
{
	bool operator() (Hacker const& h1, Hacker const& h2) // compare hacker comperator
	{
		if (h1.valid_commits == h2.valid_commits)
		{
			if (h1.enter_time_hoodie - h2.enter_time_hoodie > (float)  0.00001)
			{
				return true; 
			}
			else if ( h1.enter_time_hoodie - h2.enter_time_hoodie < (float)  0.00001)
			{
				if (abs(h1.enter_time_hoodie - h2.enter_time_hoodie) < (float)  0.00001)
				{
					return h1.ID > h2.ID;
				}
				return false; 
			}
		}
		return h2.valid_commits > h1.valid_commits;
	}
};

class HoodieQueue // Hoodie Queue class
{
public:
	priority_queue<Hacker, vector<Hacker>, CompareHacker> hacker_heap;
	vector<HoodieDesk> hoodie_desks;

	int max_length;

	HoodieQueue();
	void append_desks(HoodieDesk s);
	void append_hacker(Hacker h);
	int available_desk();
	bool queue_empty();
};
#endif // HOODIEQUEUE_H

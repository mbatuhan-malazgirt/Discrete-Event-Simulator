#include "Hacker.h"
#include "StickerDesk.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

#ifndef STICKERQUEUE_H
#define STICKERQUEUE_H

class StickerQueue
{
public:
	int gift_exceed;
	int invalid_attemps;
	int max_length;
	queue<Hacker> hacker_queue;
	vector<StickerDesk> sticker_desks;

	StickerQueue();
	bool is_qualified(Hacker h);
	void append_desks(StickerDesk s);
	void append_hacker(Hacker h);
	int available_desk();
	bool queue_empty();
};

#endif // STICKERQUEUE_H
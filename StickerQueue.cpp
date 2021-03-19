#include "StickerQueue.h"
using namespace std;


StickerQueue::StickerQueue()
{
	this->invalid_attemps = 0;
	this->gift_exceed = 0;
	this->max_length = 0;
	queue<Hacker> hacker_queue();
	vector<StickerDesk> sticker_desks();
}

void StickerQueue::append_desks(StickerDesk s)
{
	sticker_desks.push_back(s);
}

void StickerQueue::append_hacker(Hacker h)
{
	
	if (this->is_qualified(h))
	{
		hacker_queue.push(h);
	}
	if (max_length < hacker_queue.size())
	{
		max_length = hacker_queue.size();
	}
	
}

int StickerQueue::available_desk()
{
	
	for (int i = 0; i < sticker_desks.size(); i++)
	{
		if (sticker_desks[i].full == false)
		{
			return i;
		}
	}
	return -1;
}

bool StickerQueue::queue_empty()
{
	return hacker_queue.empty();
}

bool StickerQueue::is_qualified(Hacker h)
{
	if (h.valid_commits >= 3 && h.stickers_taken < 3)
	{
		return true;
	}
	else if (h.stickers_taken >= 3)
	{
		this->gift_exceed++;
		return false;
	}
	else
	{
		this->invalid_attemps++;
		return false;
	}
}




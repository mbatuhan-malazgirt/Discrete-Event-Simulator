#include "StickerDesk.h"

StickerDesk::StickerDesk() 
{
	this->ID = 0;
	this->service_time = 0;
	this->full = true;
}
StickerDesk::StickerDesk(int ID, float service_time)
{
	this->ID = ID;
	this->service_time = service_time;
	full = false;
}


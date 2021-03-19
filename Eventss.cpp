#include "Eventss.h"

Eventss::Eventss()
{
	this->time = 0;
	this->hackerID = 0;
	this->length_of_commit = 0;
	this->queueEntrance = 0;
	this->commitCode = 0;
	this->stickerExit = 0;
	this->hoodieExit = 0;
}

Eventss::Eventss(float time, int hackerID, int length_of_commit, bool queueEntrance, bool commitCode, bool stickerExit, bool hoodieExit)
{
	this->time = time;
	this->hackerID = hackerID;
	this->length_of_commit = length_of_commit;
	this->queueEntrance = queueEntrance;
	this->commitCode = commitCode;
	this->stickerExit = stickerExit;
	this->hoodieExit = hoodieExit;
}
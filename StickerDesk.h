using namespace std;

#ifndef STICKERDESK_H
#define STICKERDESK_H

class StickerDesk
{
public:
	int ID;
	float service_time;
	bool full;
	StickerDesk();
	StickerDesk(int ID, float service_time);

};
#endif
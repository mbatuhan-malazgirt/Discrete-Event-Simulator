using namespace std;

#ifndef HOODIEDESK_H
#define HOODIEDESK_H


class HoodieDesk
{
public:
	int ID;
	float service_time;
	bool full;
	HoodieDesk();
	HoodieDesk(int ID, float service_time);
};
#endif // HOODIEDESK_H
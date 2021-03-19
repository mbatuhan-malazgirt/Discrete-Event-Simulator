#include "HoodieDesk.h"


HoodieDesk::HoodieDesk()
{
	this->ID = 0;
	this->service_time = 0;
	this->full = true;
}
HoodieDesk::HoodieDesk(int ID, float service_time)
{
	this->ID = ID;
	this->service_time = service_time;
	full = false;
}

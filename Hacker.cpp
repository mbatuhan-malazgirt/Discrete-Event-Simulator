#include "Hacker.h"
using namespace std;

Hacker::Hacker()
{
    this->ID=0;
    this->valid_commits=0;
    this->stickers_taken=0;
    this->hoodies_taken=0;
    this->total_gifts=0;
    this-> arrival_time=0;
    this->number_of_commits=0;
    this->sticker_desk_id=0;
    this->hoodie_desk_id=0;
    this->length_of_commits=0;
    this-> enter_time_sticker=0;
    this-> enter_time_hoodie=0;
    this->exit_time_sticker=0;
    this-> exit_time_hoodie=0;
    this->waiting_time_sticker=0;
    this-> waiting_time_hoodie=0;
    this-> total_waited_queue=0;
    this-> turnaround_time_begin=0;
    this->turnaround_time_end=0;
    this-> turnaround_time=0;
}

Hacker::Hacker(int ID,float arrival_time)
{
	this->ID = ID;

	this->number_of_commits = 0;
	this->valid_commits = 0;

	this->hoodies_taken = 0;
	this->stickers_taken = 0;
	this->total_gifts = 0; 

	this->sticker_desk_id = -1;
	this->hoodie_desk_id = -1;
	this->length_of_commits = 0;

	this->arrival_time = arrival_time;
	this->enter_time_sticker = 0;
	this->enter_time_hoodie = 0;
	this->exit_time_sticker = 0;
	this->exit_time_hoodie = 0;
	this->waiting_time_sticker = 0;
	this->waiting_time_hoodie = 0;
	this->total_waited_queue = 0;
	this->turnaround_time_begin = 0;
	this->turnaround_time_end = 0;
	this->turnaround_time = 0;
}

void Hacker::commitcode(int length_of_code)
{
	this->length_of_commits += length_of_code;

	this->number_of_commits++;
	if (length_of_code >= 20)
	{
		this->valid_commits++;
	}
}


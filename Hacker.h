using namespace std;

#ifndef HACKER_H
#define HACKER_H

class Hacker
{
public:
	int ID; 
	int valid_commits;
	int stickers_taken;
	int hoodies_taken;
	int total_gifts;
	float arrival_time;
	int number_of_commits;
	int sticker_desk_id;
	int hoodie_desk_id;
	int length_of_commits;
	float enter_time_sticker;
	float enter_time_hoodie;
	float exit_time_sticker;
	float exit_time_hoodie;
	float waiting_time_sticker;
	float waiting_time_hoodie;
	float total_waited_queue;
	float turnaround_time_begin;
	float turnaround_time_end;
	float turnaround_time;

	void commitcode(int length_of_code);
	Hacker();
	Hacker(int ID,float arrival_time);
};


#endif // HACKER_H
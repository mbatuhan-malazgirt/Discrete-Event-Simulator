#include "Simulation.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

static int ID = 1;

int main(int argc, char* argv[])
{


    string infile_name = argv[1]; // I/O process.
    string outfile_name = argv[2];
    ifstream iss;
    iss.open(infile_name);
    ofstream outputFile;
    outputFile.open(outfile_name);

    Simulation simulation;

    string line;
    int count = 0;

    int number_of_hackers;

    int number_of_attempts;
    int sticker_desks;
    int hoodie_desks;

    float arrival_time;
    float commit_time;
    float attempt_time;
    float service_time;

    int number_of_commits;
    float number_of_commits2;
    int ID_of_hacker;
    int commit_length;

    iss >> number_of_hackers;
    
    for (int i = 0; i < number_of_hackers; i++)
    {
        iss >> arrival_time;

        Hacker hacker(ID, arrival_time);
        simulation.pushHacker(hacker);
        ID++;
    }
    ID = 1;

    iss >> number_of_commits;
    number_of_commits2 = number_of_commits;

    for (int i = 0; i < number_of_commits; i++)
    {
        iss >> ID_of_hacker;
        iss >> commit_length;
        iss >> commit_time;

        Eventss events(commit_time, ID_of_hacker, commit_length, false, true, false, false);
        simulation.scheduleEvent(events);
    }

    iss >> number_of_attempts;

    for (int i = 0; i < number_of_attempts; i++)
    {
        iss >> ID_of_hacker;
        iss >> attempt_time;
        Eventss events(attempt_time, ID_of_hacker, 0, true, false, false, false);
        simulation.scheduleEvent(events);
    }

    iss >> sticker_desks;
    for (int i = 0; i < sticker_desks; i++)
    {
        iss >> service_time;
        StickerDesk sticker_desk(ID, service_time);
        simulation.pushSticker(sticker_desk);
        ID++;
    }
    ID = 1;
    iss >> hoodie_desks;
    for (int i = 0; i < hoodie_desks; i++)
    {
        iss >> service_time;
        HoodieDesk hoodie_desk(ID, service_time);
        simulation.pushHoodie(hoodie_desk);
        ID++;
    }
     // I/O process.
     // simulation run.
    simulation.run();

    // output process.
    outputFile << setprecision(3) << fixed;
    outputFile << simulation.sticker_queue.max_length << "\n";
    outputFile << simulation.hoodie_queue.max_length << "\n";

    float all_gifts = 0;
    float all_waiting_sticker = 0;
    float all_waiting_hoodie = 0;
    float all_valid_commits = 0;
    float all_length_commit = 0;
    float all_turnaround = 0;
    int total_invalid_sticker = 0;
    int exceed_gift_total = 0;
    int lazy_hacker_ID = -2;
    int hardworking_hacker_ID = -1;
    float max_waited = -2;
    float min_waited = 2147483647.000;

    for (int i = 0; i < simulation.all_hackers.size(); i++)
    {
        all_gifts += simulation.all_hackers[i].total_gifts;
        all_waiting_sticker += simulation.all_hackers[i].waiting_time_sticker;
        all_waiting_hoodie += simulation.all_hackers[i].waiting_time_hoodie;
        all_length_commit += simulation.all_hackers[i].length_of_commits;
       

        if (simulation.all_hackers[i].total_waited_queue - max_waited > (float) 0.00001)
        {
            lazy_hacker_ID = i+1;
            max_waited = simulation.all_hackers[i].total_waited_queue;
        }

        if (simulation.all_hackers[i].total_gifts >= 3 && min_waited - simulation.all_hackers[i].total_waited_queue > (float) 0.00001 )
        {
            hardworking_hacker_ID = i + 1;
            min_waited = simulation.all_hackers[i].total_waited_queue;
        }


    }
    if (min_waited == 2147483648.000)
    {
        min_waited = -1;
    }

    outputFile <<  all_gifts / (float)simulation.all_hackers.size() << "\n";
    outputFile <<  all_waiting_sticker / all_gifts << "\n";
    outputFile <<  all_waiting_hoodie / all_gifts << "\n";
    outputFile <<  number_of_commits2 / simulation.all_hackers.size() << "\n";
    outputFile <<  all_length_commit / simulation.code_commited << "\n";
    outputFile <<  simulation.total_turnaround_time / all_gifts << "\n";
    outputFile <<  simulation.sticker_queue.invalid_attemps << "\n";
    outputFile <<  simulation.sticker_queue.gift_exceed << "\n";
    outputFile <<  lazy_hacker_ID << " " << max_waited << "\n";
    outputFile <<  hardworking_hacker_ID << " " << min_waited << "\n";
    outputFile <<  simulation.last_time << "\n";

    iss.close();
    outputFile.close();


}

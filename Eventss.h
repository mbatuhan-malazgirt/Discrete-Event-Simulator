using namespace std;

#ifndef EVENTSS_H
#define EVENTSS_H

class Eventss
{
public:
	float time;
	int hackerID;
	int length_of_commit;
	bool queueEntrance;
	bool commitCode;
	bool stickerExit;
	bool hoodieExit;

	Eventss();
	Eventss(float time, int hackerID, int length_of_commit, bool queueEntrance, bool commitCode, bool stickerExit, bool hoodieExit);

};
#endif // EVENTSS_H
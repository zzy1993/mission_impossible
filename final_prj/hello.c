#include "types.h"
#include "user.h"
#include "date.h"

//this is a function that uses date to improvise to count 10-second-interval
//it is used to count how long the process takes time
//unable to add into the system call for some reason because it has to call another system 
//call. 
void stopwatch() {
	struct rtcdate rtc;
	int timer1;
	int timer2;
	date(&rtc);
	timer1=rtc.second;
	printf(1, "stopwatch initiated, it is now %d second\n", timer1);
	while(1)
	{
		date(&rtc);
		timer2=rtc.second;

		//begin section of 10-second-count
		if(timer2<timer1)    	//abnormal 10 second count, cross-minutes
		{
			timer2+=60;	//add additional 60 seconds on the vale
			if(timer2-timer1==10)
				break;
		}
		else    		//normal 10 second count
		{
			if(timer2-timer1==10)   //inaccurate timer calculation
				break;
		}
		//end section of 10-second-count

	}
	printf(1, "stopwatch finishes, it is now %d second\n", timer2);
}
//end of the stopwatch function

int main(int argc, char **argv)
{
	stopwatch();
	exit();
}

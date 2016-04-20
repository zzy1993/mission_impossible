#include "types.h"
#include "user.h"
#include "date.h"
struct rtcdate rtc;

int main(int argc, char **argv)
{
	date(&rtc);
	//printf(1, "%d/%d/%d %d:%d:%d\n", rtc.month, rtc.day, rtc.year, rtc.hour, rtc.minute, rtc.second);
	exit();
}

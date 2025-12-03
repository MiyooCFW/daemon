#include <ctime>
#include <sys/time.h>

#include <stdio.h>
#include <unistd.h>
#include <string>

const char* nowtime = "2025-12-03 18:34";

const std::string get_date_time() {
	char buf[80];
	time_t now = time(0);
	struct tm tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%F %R", &tstruct);
	return buf;
}

void sync_date_time(time_t t) {
	struct timeval tv = { t, 0 };
	settimeofday(&tv, NULL);
}

void set_date_time(const char* timestamp) {
	int imonth, iday, iyear, ihour, iminute;

	sscanf(timestamp, "%d-%d-%d %d:%d", &iyear, &imonth, &iday, &ihour, &iminute);

	struct tm datetime = { 0 };

	datetime.tm_year = iyear - 1900;
	datetime.tm_mon  = imonth - 1;
	datetime.tm_mday = iday;
	datetime.tm_hour = ihour;
	datetime.tm_min  = iminute;
	datetime.tm_sec  = 0;

	if (datetime.tm_year < 0) datetime.tm_year = 0;

	time_t t = mktime(&datetime);

	sync_date_time(t);
}

main() {
    set_date_time(nowtime);
	usleep(10000);
	printf("current time set=%s\n", get_date_time().c_str());
	return 0;
}
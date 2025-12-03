#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char* nowtime = "2025-12-03 18:34";
char datebuf[80];

void get_date_time(char *out, size_t size) {
    time_t now = time(NULL);
    struct tm t;
    localtime_r(&now, &t);
    strftime(out, size, "%F %R", &t);
}

void sync_date_time(time_t t) {
    struct tm tmv;
    localtime_r(&t, &tmv);

    char cmd[128];
    snprintf(cmd, sizeof(cmd),
             "date -s \"%04d-%02d-%02d %02d:%02d:00\"",
             tmv.tm_year + 1900,
             tmv.tm_mon + 1,
             tmv.tm_mday,
             tmv.tm_hour,
             tmv.tm_min);

    system(cmd);
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

int main() {
    set_date_time(nowtime);
	usleep(10000);
	get_date_time(datebuf, sizeof(datebuf));
	printf("current time set=%s\n", datebuf);
	return 0;
}
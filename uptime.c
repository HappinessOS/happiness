#include <stdio.h>
#include <time.h>

int main(void) {
  FILE *stream = fopen("/proc/uptime", "r");
  if (stream != nullptr) {
    double uptime_secs;
    fscanf(stream, "%lf", &uptime_secs);

    time_t timer;
    time(&timer);
    const struct tm *tm = localtime(&timer);

    char uptime_str[100];
    unsigned len = 0;
    len += snprintf(uptime_str + len, 100 - len, " %02d:%02d:%02d up ",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);

    const int updays = (int)uptime_secs / 86400;
    const int uphours = (int)uptime_secs % 86400 / 3600;
    const int upmins = (int)uptime_secs % 86400 % 3600 / 60;

    if (updays > 0) {
      len += snprintf(uptime_str + len, 100 - len, "%d day%s, ", updays,
                      updays > 1 ? "s" : "");
    }

    if (uphours > 0) {
      len += snprintf(uptime_str + len, 100 - len, "%2d:%02d", uphours, upmins);
    } else {
      len += snprintf(uptime_str + len, 100 - len, "%d min", upmins);
    }

    printf("%s\n", uptime_str);
  }

  fclose(stream);
}

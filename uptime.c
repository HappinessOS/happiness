#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv) {
  FILE *stream = fopen("/proc/uptime", "r");
  if (stream == nullptr) {
    perror("fopen(/proc/uptime)");
    return 1;
  }

  double uptime_secs;
  fscanf(stream, "%lf", &uptime_secs);

  time_t timer;
  time(&timer);
  struct tm *tm = localtime(&timer);

  // FIXME: Allow setting via command-line argument.
  int pretty = 0;
  if (argc == 2 && (!(strcmp(argv[1], "-p") && strcmp(argv[1], "--pretty")))) {
    pretty = 1;
  }

  if (pretty) {
    printf("up ");
  } else {
    printf(" %02d:%02d:%02d up ", tm->tm_hour, tm->tm_min, tm->tm_sec);
  }

  int updays = (int)uptime_secs / 86400;
  int uphours = (int)uptime_secs % 86400 / 3600;
  int upmins = (int)uptime_secs % 86400 % 3600 / 60;

  if (updays) {
    printf("%d day%s, ", updays, updays > 1 ? "s" : "");
  }

  if (pretty) {
    if (uphours) {
      printf("%d hour%s, ", uphours, uphours > 1 ? "s" : "");
    }

    printf("%d minute%s\n", upmins, upmins > 1 ? "s" : "");
  } else {
    if (uphours) {
      printf("%2d:%02d\n", uphours, upmins);
    } else {
      printf("%d min\n", upmins);
    }
  }

  fclose(stream);
  return 0;
}

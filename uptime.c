#include <stdint.h>
#include <stdio.h>
#include <time.h>

int main(void) {
  FILE *stream = fopen("/proc/uptime", "r");
  if (stream != nullptr) {
    char str[BUFSIZ];
    fgets(str, BUFSIZ, stream);

    double upsecs;
    sscanf(str, "%lf", &upsecs);

    const time_t seconds = (time_t)upsecs;

    const intmax_t updays = seconds / 86400;
    const int uphours = seconds % 86400 / 3600;
    const int upmins = seconds % 86400 % 3600 / 60;

    if (updays > 0) {
      printf("Up %jd day%s %2d:%02d\n", updays, updays > 1 ? "s" : "", uphours,
             upmins);
    } else if (uphours > 0) {
      printf("Up %2d:%02d\n", uphours, upmins);
    } else {
      printf("Up %d min\n", upmins);
    }
  }

  fclose(stream);
}

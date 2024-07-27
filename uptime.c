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
    printf("up %ld day%s, ", seconds / 86400, seconds / 86400 > 0 ? "s" : "");
    printf("%ld hour%s, ", seconds % 86400 / 3600,
           seconds % 86400 / 3600 > 0 ? "s" : "");
    printf("%ld minute%s, ", seconds % 86400 % 3600 / 60,
           seconds % 86400 % 3600 / 60 > 0 ? "s" : "");
    printf("%ld second%s\n", seconds % 86400 % 3600 % 60,
           seconds % 86400 % 3600 % 60 > 0 ? "s" : "");
  }

  fclose(stream);
}

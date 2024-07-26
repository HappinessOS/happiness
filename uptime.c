#include <stdio.h>

int main(void) {
  FILE *stream = fopen("/proc/uptime", "r");
  if (stream != nullptr) {
    char str[BUFSIZ];
    fgets(str, BUFSIZ, stream);

    double seconds;
    sscanf(str, "%lf", &seconds);

    printf("up %.2f seconds\n", seconds);
  }

  fclose(stream);
}

#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    int val = 0;
    char error_buf[128];

    while (!feof(fp)) {
	if (fscanf(fp, "%d", &val) == 1) {
	    sum += val;
	} else {
	    if (fscanf(fp, "%s", error_buf) == 1) {
		fprintf(stderr, "invalid input %s\n", error_buf);
	    }
	}
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}

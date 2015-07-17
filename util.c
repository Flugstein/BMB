#include <stdio.h>

size_t get_cache_line_size() {
    FILE* fp;
    unsigned int ret= 0;

    fp = fopen("/sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size", "r");
    if(fp) {
        fscanf(fp, "%d", &ret);
        fclose(fp);
    }
    return ret;
}

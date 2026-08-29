#include <cstdlib>
#include <cstring>
#include <ctime>
#include <locale.h>
#include <sys/socket.h>

extern "C" {

char *strptime_l(const char *buf, const char *fmt, struct tm *tm) {
    return strptime(buf, fmt, tm);
}

unsigned long strtoul_l(const char *nptr, char **endptr, int base, locale_t loc) {
    (void)loc;
    return strtoul(nptr, endptr, base);
}

long strtoll_l(const char *nptr, char **endptr, int base, locale_t loc) {
    (void)loc;
    return strtoll(nptr, endptr, base);
}

unsigned long long strtoull_l(const char *nptr, char **endptr, int base, locale_t loc) {
    (void)loc;
    return strtoull(nptr, endptr, base);
}

float strtof_l(const char *nptr, char **endptr, locale_t loc) {
    (void)loc;
    return strtof(nptr, endptr);
}

long double strtold_l(const char *nptr, char **endptr, locale_t loc) {
    (void)loc;
    return strtold(nptr, endptr);
}

struct cmsghdr *__cmsg_nxthdr(struct msghdr *m, struct cmsghdr *c) {
    return CMSG_NXTHDR(m, c);
}

}

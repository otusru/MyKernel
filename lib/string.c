void *memcpy(void *dest, const void *src, unsigned long n) {
    char *d = dest;
    const char *s = src;
    for (unsigned long i = 0; i < n; i++) d[i] = s[i];
    return dest;
}


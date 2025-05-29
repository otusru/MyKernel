void *memset(void *s, int c, unsigned long n) {
    unsigned char *p = s;
    for (unsigned long i = 0; i < n; ++i) p[i] = (unsigned char)c;
    return s;
}


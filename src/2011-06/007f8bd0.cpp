// from server: 100% by atomic.potato
extern "C" int (__cdecl *_snprintf)(char *, unsigned int, const char *, ...);

struct S
{
    char *buffer;
    int count;
    char data[1];

    char *f(char *);
};

char *S::f(char *value)
{
    if (value == 0)
        value = buffer;
    _snprintf(data, 100, value, count);
    ++count;
    return data;
}

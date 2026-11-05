// from server: 96% by atomic.potato
extern "C" char *__cdecl strncpy(char *, const char *, unsigned int);

struct Exposer
{
    void f(const char *);
};

void Exposer::f(const char *value)
{
    strncpy((char *)this + 0x10a, value, 0xff);
    *((char *)this + 0x209) = 0;
}

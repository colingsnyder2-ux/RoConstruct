// from server: 95% by atomic.potato
extern "C" char *__cdecl strncpy(char *, const char *, unsigned int);

struct Exposer
{
    void f(const char *);
};

void Exposer::f(const char *source)
{
    strncpy((char *)((char *)this + 10), source, 255);
    *((unsigned char *)this + 265) = 0;
}

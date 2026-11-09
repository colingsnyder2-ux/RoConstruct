// from server: 45% by atomic.potato
typedef unsigned int DWORD;

extern "C" void ConstructString(void *, const void *);
extern "C" void Call539770(void *, const void *);

struct S
{
    int f(const char *);
};

int S::f(const char *value)
{
    char local[28];
    ConstructString(local, value);
    Call539770((char *)this + 0x9c, local);
    return 0;
}

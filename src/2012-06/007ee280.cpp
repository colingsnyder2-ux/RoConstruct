// from server: 44% by atomic.potato
typedef unsigned int DWORD;

struct S
{
    void *callable(DWORD, DWORD, DWORD, DWORD);
};

extern "C" void target(void *, DWORD *);

void *S::callable(DWORD a, DWORD b, DWORD c, DWORD d)
{
    DWORD args[4];
    args[0] = a;
    args[1] = b;
    args[2] = c;
    args[3] = d;
    target((char *)this + 0x10, args);
    return 0;
}

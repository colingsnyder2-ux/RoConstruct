// from server: 76% by atomic.potato
typedef unsigned int DWORD;

extern "C" void sub_00534150(void *, void *);
extern "C" void sub_00518150(void *, void *, DWORD);

struct S
{
    void f(void *, void *, DWORD);
};

void S::f(void *a, void *b, DWORD c)
{
    sub_00534150(a, b);
    sub_00518150((char *)this + 0x1cb8, b, c);
}

// from server: 73% by atomic.potato
typedef unsigned int DWORD;

struct C402090
{
    void f(void *);
};

struct C598d90
{
    void f(DWORD);
};

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    DWORD value = *(DWORD *)p;
    ((C402090 *)((char *)this + 0xa8))->f((char *)p + 4);
    value = *(DWORD *)p;
    ((C598d90 *)this)->f(value);
}

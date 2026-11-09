// from server: 47% by atomic.potato
extern "C" void __cdecl call_7f4878(void *, const void *);

struct S
{
    void f();
};

void S::f()
{
    call_7f4878((char *)this + 8, (const void *)0xA904F0);
}

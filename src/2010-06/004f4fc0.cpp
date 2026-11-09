// from server: 50% by atomic.potato
extern "C" unsigned char __cdecl sub_004f4f70(void *);
extern "C" void __cdecl sub_00649bf0(void *, unsigned char *);

struct S
{
    void f();
};

void S::f()
{
    unsigned char value = sub_004f4f70((char *)this + 0xc0);
    sub_00649bf0(this, &value);
}

// from server: 50% by atomic.potato
struct S
{
    void f();
};

extern "C" int __cdecl sub_004f4f70(void *);
extern "C" void __cdecl sub_00649b30(void *, int *);

void S::f()
{
    int value = sub_004f4f70((char *)this + 0xc0);
    sub_00649b30(this, &value);
}

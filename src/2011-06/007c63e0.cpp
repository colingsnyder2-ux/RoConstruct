// from server: 85% by atomic.potato
extern "C" void __cdecl sub_004f4330(int);

struct S
{
    int pad0;
    int pad1;
    int value();
};

int S::value()
{
    sub_004f4330(*(int *)(*(int *)((char *)this + 8) + 0x104));
    return 0;
}

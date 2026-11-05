// from server: 77% by atomic.potato
extern "C" void __cdecl sub_004f4330(int);

struct EdgeEdgePair
{
    int value;

    void f();
};

void EdgeEdgePair::f()
{
    sub_004f4330(*(int *)(*(int *)((char *)this + 4) + 0x104));
}

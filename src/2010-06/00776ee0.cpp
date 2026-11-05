// from server: 85% by atomic.potato
extern "C" void __cdecl sub_004e5f50(int);

struct S
{
    int pad0;
    int pad4;
    int field8;
    int f();
};

int S::f()
{
    sub_004e5f50(*(int *)(field8 + 0xf0));
    return 0;
}

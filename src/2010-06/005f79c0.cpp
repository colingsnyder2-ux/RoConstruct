// from server: 81% by atomic.potato
struct S
{
    int f();
};

extern "C" int __stdcall sub_4B12A0(S*);

int S::f()
{
    return sub_4B12A0((S*)((char*)this + 0x160));
}

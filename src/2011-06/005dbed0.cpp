// from server: 100% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_5980D0();

int S::f()
{
    *(int*)this = 0xA8FE94;
    *((int*)this + 1) = 0xA8FE88;
    *((int*)this + 6) = 0xA8FE7C;
    *((int*)this + 7) = 0xA8FE70;
    return sub_5980D0();
}

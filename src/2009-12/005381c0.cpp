// from server: 65% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_531160(int, int);

int S::f()
{
    int value = *(int*)((char*)this + 0x29b0);
    if (value != 0)
        return sub_531160(*(int*)((char*)this + 0x29b8),
                          *(int*)((char*)this + 0x29bc));
    return 0;
}

// from server: 65% by atomic.potato
extern "C" int __cdecl func_004df550(int, int);

struct S
{
    int f();
};

int S::f()
{
    if (*(int*)((char*)this + 0x29b0))
        return func_004df550(*(int*)((char*)this + 0x29b8),
                             *(int*)((char*)this + 0x29bc));
    return 0;
}

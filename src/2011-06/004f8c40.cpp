// from server: 69% by atomic.potato
typedef void *PVOID;

extern "C" void __cdecl Call4F07A0(PVOID, PVOID);
extern "C" void __cdecl Call4F72D0(PVOID);

struct S
{
    void __cdecl f(PVOID, PVOID);
    int field;
};

void __cdecl S::f(PVOID a, PVOID b)
{
    PVOID local;
    Call4F07A0(&local, a);
    if (field != 0)
        Call4F72D0(&local);
}

// from server: 41% by atomic.potato
typedef unsigned long DWORD;

struct S
{
    int f();
};

extern "C" void __cdecl sub_44BB70(S*, void*);

int S::f()
{
    DWORD value = 0;
    S* object = (S*)value;
    object = *(S**)((char*)0 + 8);
    *(DWORD*)object = value;
    sub_44BB70(object, *(void**)0xB99080);
    return (int)object;
}

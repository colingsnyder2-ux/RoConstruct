// from server: 68% by Intel
struct TToolVerb
{
    int f();
};

typedef int (__thiscall *TypeInfoEqualProc)(void*, int);

extern "C" int __cdecl sub_495f40(int);
extern "C" int __cdecl sub_983b6a(int);
extern "C" TypeInfoEqualProc g_typeInfoEqual;

int TToolVerb::f()
{
    int* ptr = *(int**)((char*)this + 0x0c);
    int ecx_val = ptr[0xac4 / 4];
    int eax_val = sub_495f40(ecx_val);
    if (!eax_val)
        return 0;
    eax_val = sub_983b6a(eax_val);
    return g_typeInfoEqual((void*)0xdebb54, eax_val);
}

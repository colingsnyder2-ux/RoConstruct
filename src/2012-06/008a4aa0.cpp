// from server: 77% by atomic.potato
typedef int __cdecl TypeInfoCompare(int, int);
typedef int __cdecl ResolveType(int);
typedef int GlobalCall(int, int);

extern "C" int __cdecl sub_495f40(int);
extern "C" int __cdecl sub_983b6a(int);
extern "C" int __stdcall imported_call(int, int);

struct TToolVerb
{
    int pad0[3];
    int value;
    int f();
};

int TToolVerb::f()
{
    int value = sub_495f40(*(int *)(*(int *)((char *)this + 12) + 0xac4));
    if (value)
    {
        value = sub_983b6a(value);
        imported_call(0xdeba84, value);
    }
    return 0;
}

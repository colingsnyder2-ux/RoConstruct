// from server: 54% by atomic.potato
typedef int BOOL;

extern "C" int __cdecl sub_495f40(int);
extern "C" int __cdecl sub_983b6a(int);
extern "C" BOOL (__thiscall *type_info_equal)(int, int);

struct TToolVerb
{
    int pad0[3];
    int value;
    int f();
};

int TToolVerb::f()
{
    int result = sub_495f40(value);
    if (!result)
        return 0;

    result = sub_983b6a(result);
    type_info_equal(0x00DEC82C, result);
    return result;
}

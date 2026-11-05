// from server: 50% by atomic.potato
extern "C" int __cdecl sub_005d0670();

struct S_func_006c8a90
{
    int pad[9];
};

S_func_006c8a90* __stdcall sub_006c8a90(
    int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    S_func_006c8a90* result;
    int value;

    value = sub_005d0670();
    result = (S_func_006c8a90*)a2;
    result->pad[9] = value;
    return result;
}

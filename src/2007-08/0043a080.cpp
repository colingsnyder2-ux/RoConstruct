// from server: 84% by Yeetserama
struct S_func_0043a080 {
};

void __cdecl f(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6)
{
    int* begin = (int*)a3;
    int* end = (int*)a4;
    void* ctx = a2;
    void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))a5;
    while (begin != end) {
        fn(ctx, *begin);
        ++begin;
    }
    int* out = (int*)a1;
    out[0] = (int)a5;
    out[1] = (int)a2;
    out[2] = (int)a6;
}

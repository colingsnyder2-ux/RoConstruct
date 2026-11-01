// from server: 100% by why2
struct S_func_0077ff60 {
    int f(int, int);
};

extern "C" void* __cdecl G1_func_0077f940();

int S_func_0077ff60::f(int, int)
{
    void* p = G1_func_0077f940();
    if (p == 0)
        return 0;
    return *(int*)((char*)p + 0x68);
}

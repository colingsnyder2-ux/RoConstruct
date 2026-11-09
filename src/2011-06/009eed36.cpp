// from server: 73% by atomic.potato
struct S
{
    int value;
};

extern "C" void __cdecl G1_func_0080b1d8(S*, int, int, const char*);

void func_009eed36(S* p)
{
    G1_func_0080b1d8((S*)((char*)p + 0xd4), 20, 2, "QVRP");
}

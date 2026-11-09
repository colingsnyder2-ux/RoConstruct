// from server: 100% by colin
struct T_func_005a6210 {
    int m();
};

extern "C" void* __cdecl sub_005a5d60();

int T_func_005a6210::m()
{
    char* p = (char*)sub_005a5d60();
    if (p)
        return *(int*)(p + 0x1d8);
    return 0;
}

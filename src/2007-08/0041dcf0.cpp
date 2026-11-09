// from server: 100% by Yeetserama
extern "C" __declspec(dllimport) void __stdcall _invalid_parameter_noinfo();

struct CInstanceExplorer
{
    void func_005330f0();
    void func_00532f50(int);
    void func_0041dcf0(int* first, int* last, int* other_first, int* other_last);
};

void CInstanceExplorer::func_0041dcf0(int* first, int* last, int* other_first, int* other_last)
{
    void (__stdcall *handler)() = _invalid_parameter_noinfo;

    func_005330f0();

    for (;;)
    {
        if (first == 0 || first != other_first)
            handler();

        if (last == other_last)
            break;

        if (first == 0)
            handler();

        if (last >= *(int**)((char*)first + 8))
            handler();

        func_00532f50(*(int*)last);

        if (last >= *(int**)((char*)first + 8))
            handler();

        last += 1;
    }
}

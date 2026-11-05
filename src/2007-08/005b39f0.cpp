// from server: 52% by colin
struct Assembly
{
    char pad0[0xc];
    int field_c;
    int field_10;
    void func();
};

extern "C" void __stdcall _invalid_parameter_noinfo();

void Assembly::func()
{
    int* p = *(int**)&field_10;
    int* end = (int*)&field_c;
    int* it = p;
    int* local1 = end;
    int* local2 = it;
    while (true)
    {
        int* cur = local1;
        int* next = *(int**)((char*)&field_c + 4);
        if (cur != 0 && cur == &field_c)
        {
        }
        else
        {
            _invalid_parameter_noinfo();
        }
        if (local2 == next)
            break;
        if (local2 == 0)
            _invalid_parameter_noinfo();
        if (local2 == *(int**)((char*)local2 + 4))
            _invalid_parameter_noinfo();
        ((void (__thiscall*)(void*, int))0x60ba10)((void*)local2[3], 0);
        ((void (__thiscall*)(void*))0x627240)(&local1);
        local2 = *(int**)((char*)&local1 + 4);
        local1 = *(int**)&local1;
    }
}

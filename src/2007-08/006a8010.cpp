// from server: 77% by colin
struct CXTPRibbonBar
{
    void sub_6febf0(int, int, int);
    void sub_646e20(int, int, int);
    void func_006a8010(int, int, int);
};

void CXTPRibbonBar::func_006a8010(int a1, int a2, int a3)
{
    int* p = *(int**)((char*)this + 0x264);
    p = (int*)((char*)p + 0x178);
    ((void (__thiscall*)(int*, int, int, int))0x6febf0)(p, *(int*)((char*)this + 0x20), -1, -1);

    if (*(int*)((char*)this + 0x274) != 0)
    {
        void (__thiscall* fn)(CXTPRibbonBar*, int, int) = *(void (__thiscall**)(CXTPRibbonBar*, int, int))(*(int*)this + 0x19c);
        *(int*)((char*)this + 0x274) = 0;
        fn(this, 0, 1);
    }

    ((void (__thiscall*)(CXTPRibbonBar*, int, int, int))0x646e20)(this, a1, a2, a3);
}

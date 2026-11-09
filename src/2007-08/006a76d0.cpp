// from server: 100% by colin
struct CXTPRibbonBar
{
    void setSomething(int value);
};

void CXTPRibbonBar::setSomething(int value)
{
    *(int*)((char*)this + 0x16c) = value;
    int one = 1;
    if (*(int*)((char*)this + 0xa0) != one)
    {
        *(int*)((char*)this + 0xa0) = one;
        extern void __stdcall sub_0063a690(int);
        sub_0063a690(one);
    }
}

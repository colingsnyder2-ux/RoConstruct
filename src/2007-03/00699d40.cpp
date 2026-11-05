// from server: 100% by tester
struct CXTPRibbonBar
{
    int getValue();
};

int CXTPRibbonBar::getValue()
{
    int* p = *(int**)((char*)this + 0x264);
    if (p == 0)
        return 0;
    return *(int*)((char*)p + 0x17c);
}

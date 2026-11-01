// from server: 100% by colin
struct CXTPRibbonTabContextHeader
{
    int GetFlag(int index);
    int IsSomething();
};

int CXTPRibbonTabContextHeader::IsSomething()
{
    if ((GetFlag(0) & 0x1000000) != 0)
    {
        if ((GetFlag(1) & 0x40) != 0)
            return 1;
    }
    return 0;
}

// from server: 100% by colin
struct CXTPRibbonTabContextHeader
{
    int field_0;
    int field_4;
    int field_8;
    int field_c;

    int sub_716780();
    int sub_716730(int);
    int sub_7167b0();
};

int CXTPRibbonTabContextHeader::sub_7167b0()
{
    if (sub_716780() != 0)
        return 0;

    int p = field_c;
    if (p != 0)
    {
        if (*(int*)(p + 0xd8) != 0)
        {
            if (*(int*)(p + 0x238) != 0)
            {
                if (*(int*)(p + 0xfc) == 0)
                {
                    int r = sub_716730(0);
                    r &= 0x60000000;
                    return r == 0x60000000;
                }
            }
        }
    }
    return 1;
}

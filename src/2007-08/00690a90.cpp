// from server: 100% by colin
// roc 2007-08 00690a90  unit: seg_00690000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00690a90

extern "C" int (__stdcall *SystemParametersInfoA)(unsigned int, unsigned int, void*, unsigned int);

struct CXTSplitterWnd
{
    char pad[0xfc];
    int field_fc;
    int field_100;
    unsigned char field_104;
    unsigned char field_105;
    unsigned char field_106;
    unsigned char field_107;
    unsigned char field_108;
    void method_738ade(int, int);
    void method_690a90(int, int);
};

void CXTSplitterWnd::method_690a90(int a, int b)
{
    method_738ade(a, b);
    if (field_100 == 0)
    {
        SystemParametersInfoA(0x26, 0, &field_fc, 0);
        if (field_108 & 2)
        {
            field_fc = 0;
        }
    }
}

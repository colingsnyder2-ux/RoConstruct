// from server: 87% by colin
struct CRobloxTreeCtrlNode {
    char pad[0x2c];
    unsigned char flags2c;
    unsigned char flags2d;
    char pad2[0x30 - 0x2e];
    void* ptr30;
    char pad3[0x44 - 0x34];
    int val44;
    void SetState(int);
};

void CRobloxTreeCtrlNode::SetState(int state)
{
    if (flags2d != 0)
    {
        flags2c &= 0xfd;
        return;
    }

    void** vtbl = *(void***)ptr30;
    int (__stdcall *fn1)(int, int) = (int (__stdcall *)(int, int))vtbl[0x13c / 4];
    int r1 = fn1(val44, 8);
    if ((r1 | 0x20) != 0)
    {
        flags2c |= 2;
        void** vtbl2 = *(void***)ptr30;
        int (__stdcall *fn2)(int, int) = (int (__stdcall *)(int, int))vtbl2[0x13c / 4];
        int r2 = fn2(val44, 8);
        if ((r2 | 0x80) != 0)
        {
            void** vtbl3 = *(void***)ptr30;
            int (__stdcall *fn3)(int, int, int) = (int (__stdcall *)(int, int, int))vtbl3[0x144 / 4];
            fn3(val44, 0x20, 8);
        }
    }
}

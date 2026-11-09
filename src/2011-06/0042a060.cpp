// from server: 87% by atomic.potato
struct CRobloxTreeCtrlNode
{
    unsigned char pad[0x2c];
    unsigned char flags;
    unsigned char flag2d;
    unsigned char pad2[0x30 - 0x2e];
    void* ptr30;
    unsigned char pad3[0x48 - 0x34];
    void* ptr48;
    void f(void* arg);
};

void CRobloxTreeCtrlNode::f(void* arg)
{
    if (flag2d != 0)
    {
        flags &= 0xfd;
        return;
    }

    void* p = ptr30;
    int (__stdcall *fn)(void*, int) = *(int (__stdcall **)(void*, int))(*(unsigned int*)p + 0x144);
    int r = fn(ptr48, 8);
    if ((r | 0x20) != 0)
    {
        flags |= 2;
        void* p2 = ptr30;
        int (__stdcall *fn2)(void*, int) = *(int (__stdcall **)(void*, int))(*(unsigned int*)p2 + 0x144);
        int r2 = fn2(ptr48, 8);
        if ((r2 | 0x80) != 0)
        {
            void* p3 = ptr30;
            int (__stdcall *fn3)(void*, int, int) = *(int (__stdcall **)(void*, int, int))(*(unsigned int*)p3 + 0x14c);
            fn3(ptr48, 0x20, 8);
        }
    }
}

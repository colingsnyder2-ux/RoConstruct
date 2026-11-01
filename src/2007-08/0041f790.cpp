// from server: 72% by colin
struct CSelectionTreeCtrl
{
    char pad0[0x2c];
    unsigned char flags;
    char pad1[0x17];
    unsigned int item;
    char pad2[0x10];
    void* tree;
    void Invalidate();
};

extern "C" int __stdcall sub_63047e(unsigned int, void*, int);
extern "C" void* __stdcall InvalidateRect(void*, const void*, int);

void CSelectionTreeCtrl::Invalidate()
{
    if (flags & 1)
    {
        unsigned int it = item;
        if (it != 0 && it != 0xffff0000)
        {
            int local = 0;
            if (sub_63047e(it, &local, 0))
            {
                void* t = tree;
                void* h = *(void**)((char*)t + 0x20);
                InvalidateRect(h, &local, 1);
            }
        }
        flags &= 0xfe;
    }
}

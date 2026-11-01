// from server: 100% by colin
struct CXTPControlColorSelector {
    char pad_0x000[0x16c];
    int field_0x16c;
    int field_0x170;
    void func_006725c0();
};

extern int g_array_008c8d58[];
extern void func_0063c510();

void CXTPControlColorSelector::func_006725c0()
{
    int idx = field_0x16c;
    if (idx != -1)
    {
        field_0x170 = g_array_008c8d58[idx * 3];
    }
    func_0063c510();
}

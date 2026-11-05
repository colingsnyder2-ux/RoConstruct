// from server: 100% by colin
struct CXTColorSelectorCtrl {
    char pad[0x20];
    void* hwnd;
    char pad2[0x54];
    int field_78;
    int field_7c;
    bool sub_710fd0();
    void sub_63023e();
    void sub_711280(int, int, int);
};

extern "C" int (__stdcall *g_InvalidateRect)(void*, const void*, int);

void CXTColorSelectorCtrl::sub_711280(int a, int b, int c)
{
    if (sub_710fd0())
        return;
    sub_63023e();
    int v = field_78;
    if (field_7c == v && v != -1)
    {
        void** vt = *(void***)this;
        void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))vt[0x13c / 4];
        fn(this, v);
    }
    void* h = hwnd;
    field_7c = -1;
    field_78 = -1;
    g_InvalidateRect(h, 0, 0);
}

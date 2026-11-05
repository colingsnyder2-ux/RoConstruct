// from server: 64% by atomic.potato
extern "C" int __stdcall InvalidateRect(void*, const void*, int);

struct CIDEBrowserView {
    char pad0[0x120];
    void* field_120;
    char pad1[0x2ac - 0x124];
    unsigned char field_2ac;
    unsigned char field_2ad;
    void sub_00412460(int, int);
};

void CIDEBrowserView::sub_00412460(int a, int b)
{
    extern void sub_0080a424(void*, int, int);
    sub_0080a424(this, a, b);
    if (a == -1) {
        InvalidateRect(field_120, 0, 1);
    } else if (a == 1) {
        field_2ad = (b != 0);
    } else if (a == 2) {
        field_2ac = (b != 0);
    }
}

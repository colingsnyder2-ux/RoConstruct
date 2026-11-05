// from server: 100% by colin
struct CXTPControlCustom {
    char pad[0x170];
    void* field_170;
    void m(int, int, int);
    int sub_639f70();
    void sub_6ca5f0(int, int, int);
};

extern "C" int (__stdcall *IsWindowVisible)(void*);

void CXTPControlCustom::m(int a, int b, int c)
{
    if (field_170 != 0) {
        if (IsWindowVisible(field_170) != 0) {
            if (sub_639f70() == 0) {
                return;
            }
        }
    }
    sub_6ca5f0(a, b, c);
}

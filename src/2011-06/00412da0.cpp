// from server: 33% by atomic.potato
struct CIDEBrowserView {
    char pad[0x2b0];
    int field_2b0;
    int method_a();
    int method_b();
    void method_c();
};

extern "C" int __stdcall sub_a5beca();
extern "C" int __stdcall sub_a42dcc();
extern "C" int __stdcall sub_a42dc8();

void sub_80a352(int);

void CIDEBrowserView::method_c()
{
    if (sub_a42dcc() != 0)
    {
        sub_80a352(sub_a42dc8());
    }
}

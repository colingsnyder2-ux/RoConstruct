// from server: 48% by tester
struct CIDEBrowserView
{
    char pad[0x2b0];
    int field_2b0;
    void* construct();
};

extern "C" void __stdcall sub_416090();
extern "C" void* __stdcall sub_4152D0();
extern "C" void* __stdcall sub_4159A0(void*, void*, void*);
extern "C" void __stdcall sub_B24520(int, void*);
extern "C" void __stdcall sub_B247D0(void*);

extern char g_b45b74;
extern char g_b45b8c;

void* CIDEBrowserView::construct()
{
    sub_416090();
    this->field_2b0 = 0;
    *(void**)this = &g_b45b8c;
    void* p = sub_4152D0();
    void* q = sub_4159A0(&p, &g_b45b74, 0);
    sub_B24520(this->field_2b0, q);
    sub_B247D0(&p);
    sub_B247D0(&q);

    return this;
}

// from server: 100% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

extern "C" char s_785954[];

struct CBrowserView {
    char pad[0x54];
    CBrowserView* field54;
    char pad2[0x2b8 - 0x58];
    char field2b8[1];
    void func();
    void sub_62ff56(void* q);
};

struct __declspec(dllimport) Inner {
    void* method1(const char*);
    void* method2(int, int, int, int, int);
};

extern "C" void __stdcall sub_6300b8();

void CBrowserView::func()
{
    sub_6300b8();
    if (field54 != 0)
        field54->field54 = this;
    Inner* p = (Inner*)field2b8;
    if (p->method1((const char*)(int)s_785954) != 0)
    {
        void* q = p->method2(0, 0, 0, 0, 0);
        this->sub_62ff56(q);
    }
}

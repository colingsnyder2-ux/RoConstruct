// from server: 49% by tester
struct CBrowserView
{
    char pad[0x2b8];
    void* field_2b8;
    CBrowserView* func_0040c710();
};

extern "C" void __stdcall sub_40c410();
extern "C" void* __stdcall sub_40a730();
extern "C" void* __stdcall sub_40aa00(void*, void*, void*);
extern "C" void __stdcall sub_77d434(void*, void*);
extern "C" void __stdcall sub_77ddbc(void*);

extern char g_7861b4;
extern char g_7861a4;
extern char g_739c1a;

CBrowserView* CBrowserView::func_0040c710()
{
    void* v1;
    void* v2;
    void* v3;
    void* v4;

    sub_40c410();
    *(void**)this = &g_7861b4;
    v1 = sub_40a730();
    v2 = sub_40aa00(&v3, &g_7861a4, v1);
    sub_77d434(&this->field_2b8, v2);
    sub_77ddbc(&v4);
    sub_77ddbc(&v3);
    return this;
}

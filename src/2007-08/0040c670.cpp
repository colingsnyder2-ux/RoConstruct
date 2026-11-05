// from server: 42% by colin
struct CBrowserView {
    char pad[0x2b8];
    void* field_2b8;
    void construct();
};

extern "C" void __stdcall sub_40c410();
extern "C" void* __stdcall sub_40a730();
extern "C" void* __stdcall sub_40aa00(void*, void*, void*);
extern "C" void __stdcall sub_77d434(void*, void*);
extern "C" void __stdcall sub_77ddbc(void*);

void CBrowserView::construct()
{
    void* v1;
    void* v2;
    void* v3;

    sub_40c410();
    this->field_2b8 = 0;
    *(void**)this = (void*)0x785f7c;
    v1 = sub_40a730();
    v2 = sub_40aa00(&v3, v1, (void*)0x785f64);
    sub_77d434((char*)this + 0x2b8, v2);
    sub_77ddbc(&v3);
    sub_77ddbc(&v2);
}

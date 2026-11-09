// from server: 45% by colin
struct CWebToolbox {
    char pad[0xf8];
    void* field_f8;
    CWebToolbox();
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);
extern "C" void __fastcall sub_461C60(CWebToolbox* self);

CWebToolbox* __cdecl create_web_toolbox()
{
    CWebToolbox* p = (CWebToolbox*)sub_62FEF6(0xfc);
    if (p != 0) {
        sub_461C60(p);
        *(void**)p = (void*)0x795cbc;
        p->field_f8 = 0;
    }
    return p;
}

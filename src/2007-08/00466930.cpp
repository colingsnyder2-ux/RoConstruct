// from server: 34% by colin
extern "C" void __stdcall sub_62fc62(void*);

struct CWebToolbox {
    void* field_0;
    char pad[0xf4];
    void* field_f8;
    void sub_461c80();
    void sub_466930(int);
};

void CWebToolbox::sub_466930(int arg)
{
    field_0 = (void*)0x795cbc;
    if (field_f8 != 0) {
        void* p = field_f8;
        (*(void (__stdcall**)(void*))(*(int*)p + 8))(p);
    }
    sub_461c80();
    if (arg & 1) {
        sub_62fc62(this);
    }
}

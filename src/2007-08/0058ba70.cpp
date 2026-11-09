// from server: 100% by colin
struct SoundService {
    char pad[0xf4];
    void* field_f4;
    char pad2[0x120 - 0xf8];
    int field_120;
    void sub_58b7e0();
    void sub_444710(const void*);
    void cleanup();
};

extern "C" void __stdcall func_62fc0e(void*, int);
extern "C" void __stdcall func_62fc4a(void*);

void SoundService::cleanup()
{
    if (field_f4) {
        func_62fc0e(field_f4, 0);
        func_62fc4a(field_f4);
        field_f4 = 0;
    }
    sub_58b7e0();
    int v = -1;
    if (field_120 != v) {
        field_120 = v;
        sub_444710((const void*)0x8c33e8);
    }
}

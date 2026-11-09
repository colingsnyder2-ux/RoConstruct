// from server: 38% by atomic.potato
struct RBX_MovingAssemblyStage {
    char pad0[0xcc];
    int field_cc;
    void construct(void* a, void* b);
};

extern "C" void __stdcall sub_894190(void* a, void* b);
extern "C" void __stdcall sub_972290(unsigned char a, const char* b);

extern unsigned char byte_E580B3;
extern void* ptr_E5809C;
extern const char str_BFD780[];
extern const char str_BFD878[];
extern const char str_BFD908[];
extern const char str_BFD938[];
extern const char str_BFD9C8[];
extern const char str_BFD9F8[];

void RBX_MovingAssemblyStage::construct(void* a, void* b)
{
    sub_894190(a, b);
    field_cc = 0;
    *(const char**)this = str_BFD9F8;
    if (byte_E580B3 != 0) {
        if (*(int*)((char*)b + 0x104) == 0) {
            if (ptr_E5809C != 0) {
                if (((int(__stdcall*)(int, const char*, const char*))ptr_E5809C)(0x11, str_BFD780, str_BFD9C8) != 0) {
                    goto skip1;
                }
            }
            sub_972290(byte_E580B3, str_BFD938);
        }
    skip1:
        if (byte_E580B3 != 0) {
            if (*(int*)((char*)a + 0x104) == 0) {
                if (ptr_E5809C != 0) {
                    if (((int(__stdcall*)(int, const char*, const char*))ptr_E5809C)(0x12, str_BFD780, str_BFD908) != 0) {
                        return;
                    }
                }
                sub_972290(byte_E580B3, str_BFD878);
            }
        }
    }
}

// from server: 30% by atomic.potato
struct OgreMaterialPtr {
    void* p;
    OgreMaterialPtr();
};

extern "C" void __stdcall sub_98c668();
extern "C" void* __stdcall sub_7f4aaa(int, const char*, const char*, int, void*);
extern "C" void __stdcall sub_4b2f60();
extern "C" void __stdcall sub_4b5a80();
extern "C" void __stdcall sub_5c9690();
extern "C" void __stdcall sub_5ca070();
extern "C" void __stdcall sub_5ca280();

struct RbxMaterialAdapter {
    void* field0;
    char pad[0x100];
    void func(int, int, int, int, int, int);
};

void RbxMaterialAdapter::func(int a1, int a2, int a3, int a4, int a5, int a6)
{
    OgreMaterialPtr mat;
    char buf[0xe0];
    int flag = 0;
    void* p;
    int v;

    sub_98c668();
    sub_4b2f60();
    *(char*)a6 = 0;
    p = sub_7f4aaa(0, (const char*)0xaffe40, (const char*)0xb03a58, 0, 0);
    if (p) {
        sub_5c9690();
    } else {
        p = sub_7f4aaa(0, (const char*)0xaffe40, (const char*)0xb10178, 0, 0);
        if (p) {
            sub_5ca280();
        } else {
            p = sub_7f4aaa(0, (const char*)0xaffe40, (const char*)0xb100fc, 0, 0);
            if (p) {
                sub_5ca070();
            }
        }
    }
    sub_4b5a80();
}

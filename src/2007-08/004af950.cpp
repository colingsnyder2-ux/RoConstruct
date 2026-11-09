// from server: 36% by colin
// roc 2007-08 004af950  unit: RBX::VMotor::?$FactoryProduct::Creator  size: 251 bytes

struct Name;
struct ICreator {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
};

struct CreatorBase {
    void* field0;
    void* field4;
};

struct Creator : ICreator {
    Creator();
    ~Creator();
};

struct CreatorList {
    void* head;
    void* field4;
};

extern "C" {
    int __cdecl sub_4890a0(void* a, void* b);
    void __cdecl sub_5f1a40(void* a);
    void* __cdecl sub_728f60(void* a);
    void __cdecl sub_413c00(void* a);
    void __cdecl sub_414170(void* a);
}

extern void* g_77e708;
extern void* g_8827c8;
extern void* g_891458;
extern void* g_8b5188;

typedef int (__stdcall *FnPtr)(void*, void*);

Creator::Creator() {
    char local1[0x40];
    char local2[0x40];
    char flag;

    flag = 0;
    if (sub_4890a0(local2, &flag) == 0) {
        do {
            void* p = sub_728f60(local1);
            void* esi = (char*)p + 0x10;
            void* eax = 0;
            if (esi != 0) {
                void* ecx = *(void**)esi;
                if (ecx != 0) {
                    void** vt = *(void***)ecx;
                    FnPtr fn = (FnPtr)vt[1];
                    eax = (void*)fn(ecx, 0);
                } else {
                    eax = &g_8827c8;
                }
                if (((int (__stdcall*)(void*, void*))g_77e708)(eax, &g_891458)) {
                    eax = (char*)(*(void**)esi) + 4;
                } else {
                    eax = 0;
                }
            } else {
                eax = 0;
            }
            if (*(void**)eax != 0) {
                void* ecx2 = *(void**)((char*)eax + 4);
                void* edx2 = *(void**)((char*)eax + 8);
                ((void (__stdcall*)(void*))edx2)(ecx2);
                if (flag == 0) {
                    flag = 1;
                }
            }
            sub_5f1a40(local1);
        } while (sub_4890a0(local2, &flag) == 0);
    }
}

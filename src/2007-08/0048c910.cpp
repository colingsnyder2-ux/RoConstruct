// from server: 39% by colin
// roc 2007-08 0048c910  unit: RBX::VHumanoid::?$FactoryProduct::Creator  size: 272 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048c910

struct Name;

struct CreatorBase {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
};

struct Creator : CreatorBase {
    char pad[0x84];
    void construct();
};

struct MapNode {
    int key;
    int value;
};

struct Map {
    void* head;
};

extern "C" {
    int __stdcall sub_4890a0(void* a, void* b);
    void __stdcall sub_5f1a40(void* a);
    void* __stdcall sub_728f60(void* a);
    void __stdcall sub_413c00(void* a);
    void __stdcall sub_414170(void* a);
}

typedef bool (__stdcall *TypeInfoEq)(const void*, const void*);

extern void* g_77e708;
extern void* g_8827c8;
extern void* g_88c5a8;

void Creator::construct() {
    char local_4c[0x40];
    char local_8c[4];
    char local_88[4];
    char local_84[4];
    char local_48[4];
    char local_38[4];
    char local_10[0x28];
    char local_0c[4];

    if (sub_4890a0(local_8c, local_4c)) {
        return;
    }

    do {
        char* namePtr = *(char**)local_88;
        if (*namePtr == 0) {
            sub_728f60(local_4c);
            void* esi = (char*)local_4c + 0x10;
            void* eax;
            if (esi) {
                void* ecx = *(void**)esi;
                if (ecx) {
                    void** vtable = *(void***)ecx;
                    TypeInfoEq fn = (TypeInfoEq)vtable[1];
                    eax = (void*)fn(ecx, 0);
                } else {
                    eax = &g_8827c8;
                }
            } else {
                eax = 0;
            }
            TypeInfoEq eq = (TypeInfoEq)g_77e708;
            if (eq(eax, &g_88c5a8)) {
                eax = (char*)(*(void**)esi) + 4;
            } else {
                eax = 0;
            }
            if (*(int*)eax != 0) {
                float f = **(float**)local_84;
                *(float*)local_0c = f;
                void* edx = *(void**)((char*)eax + 4);
                void* fn2 = *(void**)((char*)eax + 8);
                float f2 = *(float*)local_0c;
                void* args[2];
                args[0] = edx;
                args[1] = *(void**)&f2;
                ((void (__stdcall*)(void*, float))fn2)(edx, f2);
                char* flag = *(char**)local_8c;
                if (*flag == 0) {
                    *flag = 1;
                }
            } else {
                sub_413c00(local_10);
                sub_414170(local_10);
            }
        }
        sub_5f1a40(local_4c);
        if (!sub_4890a0(local_8c, local_4c)) {
            break;
        }
    } while (true);
}

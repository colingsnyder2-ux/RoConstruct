// from server: 44% by tester
// roc 2007-08 005f2db0  unit: RBX::Reflection::Z::$$A6AXMM::?$TSignalDesc::TSignalInstance  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005f2db0

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" int __stdcall sub_4890a0(void*, void*);
extern "C" void __stdcall sub_5f1700(void*, Vec3);
extern "C" void __stdcall sub_5f1a40(void*);
extern "C" void* __stdcall sub_728f60(void*);

typedef int (__stdcall *FnPtr)(void*, void*);

struct SignalInstance {
    void invoke(Vec3* v, char* flag);
};

void SignalInstance::invoke(Vec3* v, char* flag)
{
    char local[0x40];
    void* slot;
    void* impl;
    void* obj;
    void* conn;
    FnPtr fn;
    Vec3 tmp;

    if (sub_4890a0(local, flag)) {
        return;
    }

    fn = *(FnPtr*)0x77e708;

    while (*flag == 0) {
        sub_728f60(&slot);
        impl = (char*)slot + 0x10;

        if (impl != 0) {
            void* p = *(void**)impl;
            if (p != 0) {
                obj = (*(void***)p)[1];
            } else {
                obj = (void*)0x8827c8;
            }

            if (fn(obj, (void*)0x8b0ee0)) {
                conn = (char*)(*(void**)impl) + 4;
            } else {
                conn = 0;
            }
        } else {
            conn = 0;
        }

        tmp = *v;
        sub_5f1700(conn, tmp);

        if (*flag == 0) {
            *flag = 1;
        }

        sub_5f1a40(&slot);

        if (sub_4890a0(local, flag)) {
            break;
        }
    }
}

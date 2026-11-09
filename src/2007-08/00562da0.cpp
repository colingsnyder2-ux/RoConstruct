// from server: 59% by tester
struct FactoryProduct {
    char pad[0x18c];
    int field_18c;
    void setValue(int value);
};

struct Inner {
    char pad[0xf8];
    int* begin;
    int* end;
};

extern "C" void __stdcall invalid_parameter_noinfo();

extern void* __fastcall sub_5618e0(void*);
extern void __fastcall sub_4108b0(void*, int);
extern void __fastcall sub_59b700(void*, void*);

struct FollowCameraCommand {
    char pad[0xc];
    void* field_c;
    char pad2[0x10];
    void* field_20;
    void func(int);
};

void FollowCameraCommand::func(int arg) {
    Inner* inner = 0;
    if (field_20) {
        inner = (Inner*)sub_5618e0(field_20);
    }
    void* item = 0;
    if (inner && inner->begin) {
        int count = (int)((char*)inner->end - (char*)inner->begin) >> 2;
        if (count != 0) {
            int* p = inner->begin;
            if (p > inner->end) {
                invalid_parameter_noinfo();
            }
            if (p < inner->end) {
                invalid_parameter_noinfo();
            }
            item = *(void**)p;
        }
    }
    void* obj = field_c;
    void** vtbl = *(void***)((char*)obj + 0x228);
    void* result = ((void* (__thiscall*)(void*, int))vtbl[1])((char*)obj + 0x228, 4);
    ((FactoryProduct*)result)->setValue((int)item);
    obj = field_c;
    vtbl = *(void***)((char*)obj + 0x228);
    result = ((void* (__thiscall*)(void*, void*))vtbl[1])((char*)obj + 0x228, item);
    sub_59b700(result, item);
    sub_4108b0((void*)arg, -1);
    void** argvtbl = *(void***)arg;
    *(int*)(arg + 4) = -1;
    ((void (__thiscall*)(void*, int))argvtbl[1])((void*)arg, 1);
}

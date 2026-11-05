// from server: 33% by colin
struct FunctionDescriptor {
    void* vtable;
    char pad[0x24];
    int field28;
    int field2c;
    int field30;
    int field34;
};

struct BoundFuncDesc : FunctionDescriptor {
    BoundFuncDesc(int function, const char* name, int security, int attributes);
};

extern "C" void* __stdcall sub_4991B0(int a, int b);
extern "C" void __stdcall sub_570DB0(int a);
extern "C" void* __stdcall sub_56D7D0(int a);
extern "C" void* __stdcall sub_62FEF6(int size);
extern "C" void* __stdcall sub_56D350();
extern "C" void* __stdcall sub_52C940(int a, int b, int c);
extern "C" void __stdcall sub_56D400(int a);

extern int g_787198;
extern int g_79C4D8;

BoundFuncDesc::BoundFuncDesc(int function, const char* name, int security, int attributes)
{
    int* p = (int*)this;
    p[0] = (int)&g_79C4D8;

    void* r = sub_4991B0(security, attributes);
    sub_570DB0((int)r);

    this->field28 = security;
    this->field2c = attributes;

    int* edi = &this->field30;
    *edi = (int)sub_56D7D0(0);

    void* mem = sub_62FEF6(8);
    if (mem) {
        *(int*)mem = (int)&g_787198;
        *(int*)((char*)mem + 4) = (int)name;
    } else {
        mem = 0;
    }
    *(int*)(edi + 1) = (int)mem;

    int* ebx = &this->field28;
    *ebx = (int)sub_56D350();

    void* v = sub_56D7D0((int)edi);
    void* r2 = sub_52C940((int)name, -1, (int)v);
    sub_56D400((int)r2);
}

// from server: 12% by colin
extern "C" int __cdecl sub_56cbc0();
extern "C" void* __cdecl sub_6a0920(unsigned int);
extern "C" void __stdcall VariantClear(void*);
extern "C" void __cdecl sub_509b10(void*, const char*, int, int);
extern "C" void __cdecl sub_6a158c(void*, const char*);
extern "C" void __cdecl sub_594ac0_helper();

struct Variant {
    short vt;
    short r1;
    short r2;
    short r3;
    int data;
};

struct Holder {
    int field0;
    void* field4;
    Holder* init(void* arg);
};

struct VCLuaFunction {
    char pad[0xc];
    void* fieldC;
    void addArg(Variant* v);
    void execute(int a, int b, int c, int d);
};

void VCLuaFunction::execute(int a, int b, int c, int d)
{
    Variant v;
    v.vt = 7;
    v.data = a;
    addArg(&v);
    if (v.data != 0) {
        int* p = (int*)v.data;
        int* vt = (int*)*p;
        ((void (__stdcall*)(int))vt[0])(1);
    }
    VariantClear(&v);
}

// from server: 46% by colin
struct FunctionDescriptor {
    FunctionDescriptor();
    FunctionDescriptor(const void*, const char*, int, int);
};

struct Descriptor {
    struct Attributes {
        int value;
        Attributes() : value(0) {}
    };
};

struct Security {
    enum Permissions { None = 0 };
};

struct FunctionDescriptorBase {
    void* vtable;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
};

struct BoundFuncDesc : FunctionDescriptorBase {
    BoundFuncDesc(const void* function, const char* name, int security, Descriptor::Attributes attributes);
};

extern "C" void* __cdecl sub_499230(const char*, int);
extern "C" void* __cdecl sub_56D7D0();
extern "C" void* __cdecl sub_62FEF6(int);
extern "C" void* __cdecl sub_56D350();
extern "C" void* __cdecl sub_52C940(const char*, int);

struct Helper570DB0 {
    void method(void*);
};
struct Helper56D400 {
    void method(void*);
};

BoundFuncDesc::BoundFuncDesc(const void* function, const char* name, int security, Descriptor::Attributes attributes)
{
    void* p = sub_499230(name, security);
    ((Helper570DB0*)this)->method(p);
    this->vtable = (void*)0x79CBE4;
    this->field28 = attributes.value;
    this->field2C = 0;
    this->field30 = (int)sub_56D7D0();
    void* q = sub_62FEF6(8);
    if (q) {
        *(int*)q = 0x787198;
        *(int*)((char*)q + 4) = (int)function;
    } else {
        q = 0;
    }
    this->field34 = (int)q;
    this->field14 = (int)sub_56D350();
    void* r = sub_56D7D0();
    void* s = sub_52C940(name, -1);
    ((Helper56D400*)&this->field14)->method(s);
}

// from server: 35% by tester
struct FunctionDescriptor {
    FunctionDescriptor(const void* classDesc, const char* name, int security, int attributes);
};

struct FuncDesc : FunctionDescriptor {
    FuncDesc(const char* name, int security, int attributes)
        : FunctionDescriptor(0, name, security, attributes) {}
};

struct BoundFuncDesc : FuncDesc {
    void* function;
    int field_1c;
    int field_30;
    int field_34;

    BoundFuncDesc(void* function, const char* name, int security, int attributes);
};

extern "C" int __cdecl sub_7090E0();

BoundFuncDesc::BoundFuncDesc(void* function_, const char* name, int security, int attributes)
    : FuncDesc(name, security, attributes)
{
    this->function = function_;
    this->field_1c = sub_7090E0();
    this->field_30 = 0;
    this->field_34 = 0;
}

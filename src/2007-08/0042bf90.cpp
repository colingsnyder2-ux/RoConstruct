// from server: 67% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct FunctionDescriptor;
struct DescribedBase;

struct Function {
    const FunctionDescriptor* descriptor;
    DescribedBase* instance;
    Function(const FunctionDescriptor& d, DescribedBase* i);
    ~Function();
};

struct RefCounted {
    long refCount;
};

struct VCLuaFunction {
    char pad[0xfc];
    FunctionDescriptor* desc;
    RefCounted* ref;
    char pad2[8];
    Function func;
    void destroy();
};

extern "C" void __cdecl sub_40D550(void*);
extern "C" void __cdecl sub_5595A0(void*);

void VCLuaFunction::destroy()
{
    Function f(*desc, 0);
    if (ref) {
        _InterlockedExchangeAdd(&ref->refCount, 1);
    }
    sub_40D550(&f);
    func.~Function();
    sub_5595A0(this);
}

// from server: 100% by king_originala
struct Object
{
    void func_00598c70();
    void func_00598c90();
};

struct Argument
{
    Object* object;
    void func_005f1690();
    void func_005f13e0(int value);
};

namespace RBX
{
    struct Instance;
    struct ServiceProvider
    {
        void func_005bd820(int value);
    };
}

extern RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance* object);

struct S
{
    char padding[0x18];
    RBX::Instance* object;
    void func_00619ff0(Argument* argument);
};

void S::func_00619ff0(Argument* argument)
{
    argument->object->func_00598c70();
    argument->func_005f1690();
    argument->func_005f13e0(3);
    argument->object->func_00598c90();
    func_005807b0(object)->func_005bd820(8);
}

// from server: 100% by king_originala
namespace RBX {
struct Instance;
struct ServiceProvider {
    void func_005bd820(int value);
};
}

extern RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance* object);

struct S {
    void func_00598c70();
    void func_00598c90();
};

struct Argument {
    S* object;
    void func_005f1690();
    void func_005f13e0(int value);
};

struct GlueTool {
    char padding[0x18];
    RBX::Instance* instance;
    void func_00619f70(Argument* argument);
};

void GlueTool::func_00619f70(Argument* argument)
{
    argument->object->func_00598c70();
    argument->func_005f1690();
    argument->func_005f13e0(1);
    argument->object->func_00598c90();
    func_005807b0(instance)->func_005bd820(8);
}

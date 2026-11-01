// from server: 100% by king_originala
namespace RBX
{
    class Instance;
    class ServiceProvider
    {
    public:
        void func_005bd820(int);
    };
}

extern RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance*);

struct S
{
    void func_00598c70();
    void func_00598c90();
};

struct Argument
{
    S* object;
    void func_005f1690();
    void func_005f13e0(int);
};

struct InletTool
{
    char padding[0x18];
    RBX::Instance* instance;
    void func_0061a030(Argument*);
};

void InletTool::func_0061a030(Argument* argument)
{
    argument->object->func_00598c70();
    argument->func_005f1690();
    argument->func_005f13e0(4);
    argument->object->func_00598c90();
    func_005807b0(instance)->func_005bd820(8);
}

// from server: 100% by king_originala
namespace RBX {
    class Instance;
    class ServiceProvider {
    public:
        void action(int);
    };
}

RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance*);

struct Callback {
    virtual void invoke(int);
};

struct CameraVerb {
    char padding[12];
    RBX::Instance* instance;
    void execute(Callback*);
};

void CameraVerb::execute(Callback* callback)
{
    func_005807b0(instance)->action(11);
    callback->invoke(1);
}

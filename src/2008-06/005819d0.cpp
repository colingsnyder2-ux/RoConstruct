// from server: 100% by king_originala
struct Camera {
    void panLeft();
};

struct CameraSource {
    virtual void unused();
    virtual Camera* getCamera(int index);
};

struct Completion {
    virtual void complete(int value);
};

namespace RBX {
    struct Instance {
        char padding[0x288];
        CameraSource source;
    };

    struct ServiceProvider {
        void activate(int command);
    };
}

RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance* instance);

struct CameraPanLeftCommand {
    char padding[12];
    RBX::Instance* instance;

    void execute(Completion* completion);
};

void CameraPanLeftCommand::execute(Completion* completion)
{
    instance->source.getCamera(-1)->panLeft();
    func_005807b0(instance)->activate(11);
    completion->complete(1);
}

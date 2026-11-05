// from server: 100% by king_originala
namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
        char pad[0x100];
        Instance* next;
    };

    class ServiceProvider : public Instance {
    public:
        void notify(int);
    };
}

RBX::ServiceProvider* func_005807b0(RBX::Instance* p);

struct Camera {
    bool zoom(float amount);
};

struct CameraProvider {
    virtual void unused();
    virtual Camera* getCamera();
};

struct Owner : RBX::Instance {
    char padding[0x180];
    CameraProvider provider;
};

struct Callback {
    virtual void invoke(int value);
};

struct CameraZoomInCommand {
    char padding[12];
    Owner* owner;
    void execute(Callback* callback);
};

void CameraZoomInCommand::execute(Callback* callback) {
    Camera* camera = owner->provider.getCamera();
    if (camera->zoom(1.0f)) {
        func_005807b0(owner)->notify(11);
        callback->invoke(1);
    }
}

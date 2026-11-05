// from server: 100% by king_originala
struct Camera {
    bool tilt(int direction);
};

struct CameraAccess {
    virtual void reserved();
    virtual Camera* get();
};

struct Callback {
    virtual void notify(int value);
};

namespace RBX {
    class Instance {
    public:
        char padding[0x288];
        CameraAccess access;
    };

    class ServiceProvider {
    public:
        void command(int value);
    };
}

RBX::ServiceProvider* func_005807b0(RBX::Instance* instance);

struct S {
    char padding[12];
    RBX::Instance* instance;
    void f(Callback* callback);
};

void S::f(Callback* callback)
{
    Camera* camera = instance->access.get();
    if (camera->tilt(-1)) {
        func_005807b0(instance)->command(11);
        callback->notify(1);
    }
}

// from server: 100% by king_originala
extern float zoomAmount;

struct Camera {
    bool zoom(float amount);
};

struct CameraProvider {
    virtual void reserved();
    virtual Camera* getCamera();
};

struct Owner {
    char padding[0x288];
    CameraProvider provider;
};

struct ServiceProvider {
    void notify(int event);
};

extern ServiceProvider* __cdecl func_005807b0(Owner* owner);

struct Completion {
    virtual void complete(int result);
};

struct CameraZoomOutCommand {
    char padding[0x0C];
    Owner* owner;
    void execute(Completion* completion);
};

void CameraZoomOutCommand::execute(Completion* completion) {
    Camera* camera = owner->provider.getCamera();
    if (camera->zoom(zoomAmount)) {
        func_005807b0(owner)->notify(11);
        completion->complete(1);
    }
}

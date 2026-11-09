// from server: 100% by king_originala
struct Camera {
    void zoom(int direction);
};

struct CameraProvider {
    virtual void reserved();
    virtual Camera* getCamera();
};

struct Owner {
    char padding[0x288];
    CameraProvider provider;
};

struct CameraZoomOutCommand {
    char padding[0x0C];
    Owner* owner;
    void execute();
};

void CameraZoomOutCommand::execute() {
    Camera* camera = owner->provider.getCamera();
    camera->zoom(-1);
}

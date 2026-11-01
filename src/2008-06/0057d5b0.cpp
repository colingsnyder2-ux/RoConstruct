// from server: 100% by king_originala
struct Camera {
    void zoom(int direction);
};

struct CameraProvider {
    virtual void unused();
    virtual Camera* getCamera();
};

struct Owner {
    char padding[648];
    CameraProvider provider;
};

struct CameraZoomInCommand {
    char padding[12];
    Owner* owner;
    void execute();
};

void CameraZoomInCommand::execute() {
    Camera* camera = owner->provider.getCamera();
    camera->zoom(1);
}

// from server: 100% by king_originala
struct Camera {
    char padding[0x1D4];
    int mode;
};

struct CameraSource {
    virtual void unused();
    virtual Camera* getCamera();
};

struct Context {
    char padding[0x288];
    CameraSource source;
};

struct FollowCameraCommand {
    char padding[0x0C];
    Context* context;
    bool isChecked();
};

bool FollowCameraCommand::isChecked() {
    return context->source.getCamera()->mode == 4;
}

// from server: 100% by king_originala
struct Camera {
    char padding[0x1d4];
    int state;
};

struct CameraSource {
    virtual void unused();
    virtual Camera* getCamera();
};

struct Context {
    char padding[0x288];
    CameraSource source;
};

struct FixedCameraCommand {
    char padding[0x0c];
    Context* context;
    bool isChecked();
};

bool FixedCameraCommand::isChecked() {
    return context->source.getCamera()->state == 0;
}

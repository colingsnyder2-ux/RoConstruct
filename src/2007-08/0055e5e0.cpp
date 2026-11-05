// from server: 100% by Intel
struct Camera {
    char padding[0x18C];
    int state;
};

struct CameraSource {
    virtual void unused();
    virtual Camera* getCamera();
};

struct Context {
    char padding[0x228];
    CameraSource source;
};

struct FixedCameraCommand {
    char padding[0x0C];
    Context* context;
    bool isChecked();
};

bool FixedCameraCommand::isChecked() {
    return context->source.getCamera()->state == 0;
}

// from server: 100% by king_originala
struct Camera {
    char padding[0x1D4];
    int mode;
};

struct CameraProvider {
    virtual void unused();
    virtual Camera* getCamera();
};

struct Owner {
    char padding[0x288];
    CameraProvider provider;
};

struct TrackCameraCommand {
    char padding[0xC];
    Owner* owner;
    bool isTracking();
};

bool TrackCameraCommand::isTracking()
{
    return owner->provider.getCamera()->mode == 3;
}

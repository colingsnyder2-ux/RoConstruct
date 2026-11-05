// from server: 100% by king_originala
struct Camera {
    void tiltDown(int);
};

struct CameraSource {
    virtual void reserved();
    virtual Camera* getCamera();
};

struct Owner {
    char padding[0x288];
    CameraSource source;
};

struct Command {
    char padding[0x0c];
    Owner* owner;
    void execute();
};

void Command::execute()
{
    Camera* camera = owner->source.getCamera();
    camera->tiltDown(1);
}

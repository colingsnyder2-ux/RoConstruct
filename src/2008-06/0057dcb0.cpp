// from server: 100% by king_originala
struct Result {
    char padding[0x1D4];
    int state;
};

struct Interface {
    virtual void unused();
    virtual Result* getResult();
};

struct Owner {
    char padding[0x288];
    Interface camera;
};

struct AttachCameraCommand {
    char padding[0xC];
    Owner* owner;
    bool execute();
};

bool AttachCameraCommand::execute() {
    return owner->camera.getResult()->state == 1;
}

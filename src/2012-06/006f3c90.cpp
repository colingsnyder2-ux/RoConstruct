// from server: 60% by atomic.potato
struct WatchCameraCommand
{
    void* camera;
    bool f();
};

bool WatchCameraCommand::f()
{
    struct Camera
    {
        void* pad0[84];
        int value;
        void* pad1[18];
        int state;
    };

    Camera* camera = *(Camera**)((char*)this + 12);
    return camera->state == 2;
}

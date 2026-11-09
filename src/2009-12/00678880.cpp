// from server: 72% by atomic.potato
struct FollowCameraCommand
{
    int IsActive();
};

int FollowCameraCommand::IsActive()
{
    struct VTable
    {
        int (**functions)(int);
    };

    struct Camera
    {
        char padding[0x120];
        VTable* vtable;
    };

    struct State
    {
        char padding[0x144];
        int value;
    };

    Camera* camera = *(Camera**)((char*)this + 0x0c);
    int result = camera->vtable->functions[1]((int)((char*)camera + 0x120));
    return (*(int*)((char*)result + 0x144) == 4);
}

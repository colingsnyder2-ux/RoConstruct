// from server: 73% by colin
struct Camera {
    char pad[0x228];
    void* vtable;
};

struct FixedCameraCommand {
    char pad[0xc];
    Camera* camera;
    bool isEnabled();
};

bool FixedCameraCommand::isEnabled()
{
    Camera* cam = camera;
    void* vtbl = cam->vtable;
    void* fn = *(void**)((char*)vtbl + 4);
    ((void (__fastcall*)(void*))fn)((char*)cam + 0x228);
    return *(int*)((char*)cam + 0x18c) == 0;
}

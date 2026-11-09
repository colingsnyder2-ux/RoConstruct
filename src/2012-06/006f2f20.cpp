// from server: 44% by atomic.potato
struct Camera;

extern "C" int __cdecl sub_6865a0(Camera *, int);

struct Camera {
    struct VTable {
        void (__thiscall *fn)(Camera *);
    };
    int pad[84];
    VTable *vtable;
};

struct CameraZoomInCommand {
    Camera *camera;
    int f();
};

int CameraZoomInCommand::f()
{
    Camera *c = camera;
    c->vtable->fn(c);
    return sub_6865a0(c, 1);
}

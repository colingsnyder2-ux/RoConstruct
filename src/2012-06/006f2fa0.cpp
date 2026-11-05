// from server: 73% by atomic.potato
typedef int (__thiscall *CameraZoomOutVirtual)(void *);

extern "C" void __cdecl sub_6865a0(int);

struct CameraZoomOutCommand
{
    void *camera;
    void f();
};

void CameraZoomOutCommand::f()
{
    void *p = *(void **)((char *)camera + 0x150);
    CameraZoomOutVirtual fn = *(CameraZoomOutVirtual *)((char *)p + 8);
    int result = fn((char *)camera + 0x150);
    sub_6865a0(result);
}

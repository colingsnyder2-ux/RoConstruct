// from server: 73% by atomic.potato
struct CameraZoomInCommand
{
    int f();
};

extern "C" int __stdcall CameraZoomIn(int);

int CameraZoomInCommand::f()
{
    int *p = *(int **)((char *)this + 12);
    int *q = (int *)((char *)p + 0x120);
    int result = ((int (__thiscall *)(int *))(*(int **)((char *)p + 0x120) + 8))(q);
    return CameraZoomIn(result);
}

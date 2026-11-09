// from server: 80% by atomic.potato
struct CameraTiltDownCommand
{
    int f();
};

typedef int (__thiscall *CameraMethod)(void *);

extern "C" int __cdecl call_00664000(void *, int);

int CameraTiltDownCommand::f()
{
    void *object = *(void **)((char *)this + 0x0c);
    void *table = *(void **)((char *)object + 0x118);
    CameraMethod method = *(CameraMethod *)((char *)table + 8);
    int result = method((char *)object + 0x118);
    return call_00664000((void *)result, 1);
}

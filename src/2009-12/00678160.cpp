// from server: 75% by atomic.potato
struct CameraTiltUpCommand
{
    int *context;
    int f();
};

struct Camera
{
    void *vtable;
};

extern "C" int __cdecl sub_006dbe70(int, int);

int CameraTiltUpCommand::f()
{
    Camera *camera = (Camera *)this->context;
    Camera *target = *(Camera **)((char *)camera + 0x120);
    int value = ((int (__thiscall *)(Camera *))(*(int *)((char *)target + 8)))(
        (Camera *)((char *)camera + 0x120));
    return sub_006dbe70(value, -1);
}

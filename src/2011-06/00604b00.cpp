// from server: 78% by atomic.potato
struct WatchCameraCommand
{
    char unk0[12];
    void* object;
    int f();
};

int WatchCameraCommand::f()
{
    typedef void* (__thiscall *Getter)(void*);
    void* value = ((Getter)(*(void**)((char*)object + 0x118)))(object);
    return *(int*)((char*)value + 0x13c) == 2;
}

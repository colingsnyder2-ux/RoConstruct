// from server: 86% by atomic.potato
struct AttachCameraCommand
{
    void* field0C;
    int f();
};

int AttachCameraCommand::f()
{
    typedef void* (__thiscall *GetObject)(void*);
    void* object = *reinterpret_cast<void**>(
        reinterpret_cast<char*>(field0C) + 0x118);
    GetObject getObject = *reinterpret_cast<GetObject*>(
        reinterpret_cast<char*>(object) + 4);
    object = getObject(reinterpret_cast<char*>(field0C) + 0x118);
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(object) + 0x13c) == 1;
}

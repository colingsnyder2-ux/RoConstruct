// from server: 86% by atomic.potato
struct TrackCameraCommand
{
    void* m_0c;
    int f();
};

int TrackCameraCommand::f()
{
    void* p = *(void**)((char*)m_0c + 0x120);
    int result = ((int (__thiscall *)(void*))(*(void**)((char*)p + 4)))(
        (char*)m_0c + 0x120);
    return *(int*)((char*)result + 0x144) == 3;
}

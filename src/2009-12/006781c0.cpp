// from server: 80% by atomic.potato
struct CameraZoomOutCommand
{
    int Execute();
};

typedef int (__thiscall *VirtualCall)(void*);

extern "C" int __cdecl Function006dbe10(void*, int);

int CameraZoomOutCommand::Execute()
{
    void* object = *(void**)((char*)this + 0x0c);
    void* target = (char*)object + 0x120;
    VirtualCall function = *(VirtualCall*)((char*)*(void**)((char*)object + 0x120) + 8);
    int result = function(target);
    return Function006dbe10((void*)result, -1);
}

// from server: 52% by atomic.potato
struct CameraZoomOutCommand
{
    void* parent;
    void f();
};

extern "C" void __stdcall Function00663f70(void*, int);

void CameraZoomOutCommand::f()
{
    void* object = parent;
    void* camera = *(void**)((char*)object + 0x118);
    Function00663f70(*(void**)((char*)camera + 8), -1);
}

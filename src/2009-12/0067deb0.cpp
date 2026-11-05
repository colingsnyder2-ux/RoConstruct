// from server: 65% by atomic.potato
extern "C" void AboutRobloxDialogFunction(void*, void*);

struct CameraZoomExtentsCommand
{
    void f();
};

void CameraZoomExtentsCommand::f()
{
    void* value = *(void**)((char*)this + 8);
    if (value)
    {
        void* argument = *(void**)((char*)this + 4);
        AboutRobloxDialogFunction((char*)value + 4, &argument);
    }
}

// from server: 25% by atomic.potato
struct TweenService_0073ee20 {
    void* vtable0;
    void* vtable4;
    char pad[0x10];
    void* field18;
    void* field1c;
    void* field20;
    TweenService_0073ee20();
};

struct Base_00598990 {
    void ctor();
};

extern void* __cdecl cb_005ce840();
extern int g_counter_00cca98c;

TweenService_0073ee20::TweenService_0073ee20()
{
    ((Base_00598990*)this)->ctor();
    *(void**)this = (void*)0xab44b4;
    *(void**)((char*)this + 4) = (void*)0xab44a8;
    *(void**)((char*)this + 0x18) = (void*)0xab449c;
    *(void**)((char*)this + 0x1c) = (void*)0xab4490;
    *(void**)((char*)this + 0x20) = cb_005ce840();
    g_counter_00cca98c++;
}

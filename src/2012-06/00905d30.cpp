// from server: 100% by atomic.potato
extern "C" void G1_func_00961540();

struct ContentProviderJob
{
    ContentProviderJob* f();
};

ContentProviderJob* ContentProviderJob::f()
{
    G1_func_00961540();
    *(int*)((char*)this + 0x1c) = 0;
    *(int*)((char*)this + 0x20) = 0;
    *(int*)((char*)this + 0x24) = 0;
    *(int*)this = 0x00bf2bac;
    return this;
}

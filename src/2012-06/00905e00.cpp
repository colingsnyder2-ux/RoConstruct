// from server: 100% by atomic.potato
extern "C" void G1_func_00905e00();

struct ContentProviderJob
{
    void f();
};

void ContentProviderJob::f()
{
    (*(void (__thiscall **)(ContentProviderJob*))(*(int*)this + 0x20))(this);

    ContentProviderJob* child = *(ContentProviderJob**)((char*)this + 4);
    if (child)
        child->f();

    ContentProviderJob* next = *(ContentProviderJob**)((char*)this + 0x1c);
    if (next)
        next->f();
}

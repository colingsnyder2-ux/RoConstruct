// from server: 100% by atomic.potato
extern "C" void __cdecl sub_0080A058(void *);

struct DirectPhysicsReceiver
{
    void *vtable;
    int field_4;
    void *field_8;
    void f();
};

void DirectPhysicsReceiver::f()
{
    if (field_4 != 0)
        sub_0080A058(field_8);
}

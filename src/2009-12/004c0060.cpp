// from server: 51% by atomic.potato
struct S_func_004c0060 {
    char pad[568];
    struct VTableObject {
        int (**vtable)();
    };
    VTableObject *m_object;
    int f();
};

int S_func_004c0060::f()
{
    return m_object->vtable[0]();
}

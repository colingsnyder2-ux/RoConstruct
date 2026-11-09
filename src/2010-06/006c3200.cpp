// from server: 71% by atomic.potato
struct VVelocityMotorRefPropDescriptor {
    char pad[0x20];
    void* field20;
    void __thiscall set(void* a, void* b);
};

extern "C" void* __cdecl sub_6c31b0(void* p);

void VVelocityMotorRefPropDescriptor::set(void* a, void* b)
{
    void* v;
    if (a != 0) {
        v = sub_6c31b0(a);
    } else {
        v = 0;
    }
    void* p = field20;
    void** slot = (void**)p;
    void (__stdcall *fn)(void*, void*) = (void (__stdcall *)(void*, void*))slot[4];
    fn(v, b);
}

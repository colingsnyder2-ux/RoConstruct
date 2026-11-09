// from server: 45% by atomic.potato
struct VVelocityMotor_RefPropDescriptor {
    char pad0[0x20];
    void* field20;
    void* sub_6fa730(void* a, void* b);
};

extern "C" void* __cdecl sub_6fa6c0(void* p);

void* VVelocityMotor_RefPropDescriptor::sub_6fa730(void* a, void* b) {
    void* v;
    if (a) {
        v = sub_6fa6c0(a);
    } else {
        v = 0;
    }
    void* p = field20;
    void* tmp = v;
    void* (__thiscall *fn)(void*, void*, void*) = *(void* (__thiscall **)(void*, void*, void*))((*(char**)p) + 0xc);
    return fn(p, b, tmp);
}

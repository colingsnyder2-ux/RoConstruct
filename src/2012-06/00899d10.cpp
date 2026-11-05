// from server: 51% by atomic.potato
struct VVelocityMotorRefPropDescriptor {
    char pad0[0x2c];
    void* field2c;
    void* sub_899CC0(void*);
    void invoke(void*, void*);
};

void VVelocityMotorRefPropDescriptor::invoke(void* a, void* b)
{
    void* v;
    if (b) {
        v = sub_899CC0(b);
    } else {
        v = 0;
    }
    void* p = field2c;
    void* q = v;
    (*(void (__thiscall**)(void*, void*))((*(void***)p)[3]))(p, q);
}

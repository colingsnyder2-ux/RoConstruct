// from server: 100% by colin
struct Humanoid {
    char pad[0xb4];
    void* field_b4;
    void setWalkSpeed(float value, int extra);
};

void Humanoid::setWalkSpeed(float value, int extra)
{
    void* p = field_b4;
    if (p) {
        void** vtbl = *(void***)p;
        typedef void (__thiscall *Fn)(void*, float);
        Fn fn = (Fn)vtbl[2];
        fn(p, value);
    }
}

// from server: 100% by why2
struct Humanoid {
    char pad[0xec];
    void* field_ec;
    float getValue();
};

float Humanoid::getValue()
{
    void* p = field_ec;
    if (p != 0)
        return ((float (__thiscall*)(void*))((*(void***)p)[8]))(p);
    return 0.0f;
}

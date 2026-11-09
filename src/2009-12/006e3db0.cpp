// from server: 59% by atomic.potato
struct Humanoid_006e3db0
{
    virtual ~Humanoid_006e3db0();
    char field_000[276];
    int field_114;
    void* field_118;
    void f();
};

void Humanoid_006e3db0::f()
{
    if (field_114 == 0 && field_118 != 0)
        ((void (__thiscall *)(void*))(*(void***)field_118)[1])(field_118);
}

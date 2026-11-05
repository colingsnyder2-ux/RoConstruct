// from server: 100% by colin
struct Humanoid {
    char pad[0x98];
    void* field98;
    bool getSomething();
};

bool Humanoid::getSomething()
{
    void* p = field98;
    if (p) {
        return (*(bool (__thiscall **)(void*))((*(char**)p) + 0x14))(p);
    }
    return false;
}

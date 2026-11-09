// from server: 46% by atomic.potato
struct Pose_007a6b30 {
    char pad0[0x1c];
    struct Inner {
        char pad0[0xc];
        void* m_p;
    } m_inner;
};

struct C_006c8100 {
    char __thiscall f(void* arg);
};

extern "C" void* __stdcall sub_007824b0();

char __stdcall check_007a6b30(Pose_007a6b30* p)
{
    if (p == 0)
        return 0;
    Pose_007a6b30::Inner* inner = &p->m_inner;
    if (inner == 0)
        return 0;
    void* v = inner->m_p;
    void* r = sub_007824b0();
    char ok = ((C_006c8100*)v)->f(r);
    if (!ok)
        return 0;
    return (p != 0) ? 1 : 0;
}

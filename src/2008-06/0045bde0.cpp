// from server: 100% by colin
struct CRobloxWnd {
    char pad0[0xa4];
    void* m_a4;
    char pad1[4];
    void* m_ac;
    void f();
};

struct Helper_47c3e0 {
    void run();
};

struct Helper_47bec0 {
    void run();
};

extern void* g_96eff4;
extern void __cdecl sub_006a067a(void*);

void CRobloxWnd::f()
{
    void* p = m_a4;
    if (p != 0 && g_96eff4 != p) {
        (*(void (__thiscall **)(void*))(*(int*)p + 0x98))(p);
        g_96eff4 = p;
    }

    Helper_47c3e0* q = (Helper_47c3e0*)m_ac;
    if (q != 0) {
        q->run();
        Helper_47bec0* r = (Helper_47bec0*)m_ac;
        if (r != 0) {
            r->run();
            sub_006a067a(r);
        }
        m_ac = 0;
    }

    void* s = m_a4;
    if (s != 0) {
        (*(void (__thiscall **)(void*, int))(*(int*)s + 0x9c))(s, 1);
        m_a4 = 0;
    }
}

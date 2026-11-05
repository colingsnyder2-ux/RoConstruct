// from server: 47% by colin
struct CSelectionPropGrid {
    char pad0[0x114];
    void* m_p114;
    void* m_p118;
    void f();
};

struct Sub188 {
    char pad0[0x160];
    void* m_p160;
};

struct Sub114 {
    char pad0[0x188];
    Sub188* m_p188;
};

struct Str {
    char pad0[8];
    void dtor();
};

extern "C" void __stdcall sub_5592d0(void*, void*);
extern "C" void __stdcall sub_5595a0(void*);
extern "C" void __stdcall sub_40f800(void*);
extern "C" void __stdcall sub_62fc62(void*);
extern "C" void __stdcall sub_410bb0(void*);
extern "C" void* __stdcall sub_77e69c(void*, const void*, unsigned int);

void CSelectionPropGrid::f()
{
    Sub114* p114 = (Sub114*)m_p114;
    if (p114->m_p188 != 0) {
        void* p188 = p114->m_p188;
        char buf[0x1c];
        sub_5592d0(buf, p188);
        void* p118 = m_p118;
        void* p4 = *(void**)((char*)p118 + 4);
        void* src = (char*)p4 + 4;
        sub_77e69c(buf, src, 0x1c);
        Sub188* s = ((Sub114*)m_p114)->m_p188;
        sub_410bb0((char*)s + 0x160);
        Sub188* s2 = ((Sub114*)m_p114)->m_p188;
        void* vt = *(void**)((char*)s2 + 0x160);
        void (*fn)(void*, int) = *(void (**)(void*, int))((char*)vt + 4);
        fn((char*)s2 + 0x160, 1);
        sub_5595a0(buf);
    }
    void* p18 = *(void**)((char*)this + 0x18);
    if (p18 != 0) {
        sub_40f800((char*)p18 + 8);
        sub_62fc62(p18);
    }
    void* p1c = *(void**)((char*)this + 0x1c);
    if (p1c != 0) {
        sub_40f800((char*)p1c + 8);
        sub_62fc62(p1c);
    }
}

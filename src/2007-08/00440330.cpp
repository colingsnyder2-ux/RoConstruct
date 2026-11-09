// from server: 46% by colin
struct CSelectionPropGrid {
    char pad0[0x120];
    void* m_p120;
    void* m_p124;
    void f();
};

struct Sub120 {
    char pad0[0x188];
    void* m_p188;
};

struct Sub188 {
    char pad0[0x160];
    void* m_p160;
};

struct Str {
    char pad0[8];
    void dtor();
};

extern "C" void __stdcall sub_40f800(void*);
extern "C" void __stdcall sub_410bb0(void*);
extern "C" void __stdcall sub_5592d0(void*, void*);
extern "C" void __stdcall sub_5595a0(void*);
extern "C" void __stdcall sub_62fc62(void*);
extern "C" void __stdcall sub_77e69c(void*, void*);

void CSelectionPropGrid::f()
{
    Sub120* p120 = (Sub120*)m_p120;
    if (p120->m_p188 != 0) {
        void* p188 = p120->m_p188;
        char buf[0x1c];
        sub_5592d0(buf, p188);
        void* p124 = m_p124;
        void* p124_4 = *(void**)((char*)p124 + 4);
        void* src = (char*)p124_4 + 4;
        sub_77e69c(buf, src);
        Sub188* p188b = (Sub188*)((Sub120*)m_p120)->m_p188;
        sub_410bb0((char*)p188b + 0x160);
        Sub188* p188c = (Sub188*)((Sub120*)m_p120)->m_p188;
        void** vtbl = *(void***)((char*)p188c + 0x160);
        void (*fn)(void*, int) = (void (*)(void*, int))vtbl[1];
        fn((char*)p188c + 0x160, 1);
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

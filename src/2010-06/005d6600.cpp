// from server: 26% by atomic.potato
extern "C" void* __stdcall make_desc_005b3ee0(const char*, int);
extern "C" int __cdecl func_00618710();
extern "C" int __cdecl func_005a5740();
extern "C" void* __stdcall func_007a79a0(int);

struct Descriptor_005b3ee0 { void attach(void*); };
extern Descriptor_005b3ee0 global_desc_005b3ee0;
extern void register_desc_005b3ee0(void(*)());
extern int name_005b3ee0;
extern int callback_impl;

struct Init_005b3ee0 {
    Init_005b3ee0() {
        void* p = make_desc_005b3ee0((const char*)&name_005b3ee0, 0);
        global_desc_005b3ee0.attach(p);
        register_desc_005b3ee0((void(*)())&callback_impl);
    }
};
Init_005b3ee0* func_005b3ee0();

extern int g_00C184A8;

struct S_005d6600 {
    char pad0[0x38];
    int m_38;
    int m_3c;
    char pad40[8];
    int m_48;
    int m_4c;
    void ctor_005b3ee0(const char*, int, int, int, int, int, int, char);
};

void S_005d6600::ctor_005b3ee0(const char* a, int b, int c, int d, int e, int f, int g, char h) {
    func_005b3ee0();
    void* p = make_desc_005b3ee0(a, b);
    ((void (__thiscall*)(void*, void*))0x67a200)(this, p);
    m_38 = d;
    m_3c = e;
    ((void (__thiscall*)(void*))0x618780)((char*)this + 0x40);
    ++g_00C184A8;
    m_48 = func_005a5740();
    void* q = func_007a79a0(8);
    if (q) {
        *(int*)q = 0xa00aa4;
        *(char*)((char*)q + 4) = h;
    } else {
        q = 0;
    }
    m_4c = (int)q;
    ((void (__thiscall*)(void*, int, int))0x5cdba0)(this, f, g);
}

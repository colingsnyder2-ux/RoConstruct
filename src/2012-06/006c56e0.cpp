// from server: 55% by atomic.potato
extern "C" void __cdecl sub_982114(void*);

struct S {
    char pad0[0x20];
    void* p20;
    void* p24;
    char pad28[0x0c];
    void* p34;
    void* p38;
    char pad3c[0x04];
    void* p40;
    void* p44;
    char pad48[0x08];
    void* p50;
    void* p54;
    void* p58;
    char pad5c[0x14];
    void* p70;
    void* p74;
    void* p78;
    char pad7c[0x04];
    void* p80;
    void* p84;
    void* p88;
    char pad8c[0x04];
    void* p90;
    void* p94;
    void* p98;
    char pad9c[0x04];
    void* pa0;
    void* pa4;
    void* pa8;
    void destroy();
};

struct T { void f(void*); };
struct U { void f(void*, void*, void*); };
struct V { void f(); };

void S::destroy() {
    *(void**)this = (void*)0xb96a4c;
    ++*(int*)0xe488b8;
    void** it = (void**)p20;
    void** end = (void**)p24;
    while (it != end) {
        void* v = *it;
        if (v) {
            (*(void(__thiscall**)(void*, int))*(void**)v)(v, 1);
        }
        ++it;
    }
    if (pa0) { sub_982114(pa0); }
    pa0 = 0; pa4 = 0; pa8 = 0;
    if (p90) { sub_982114(p90); }
    p90 = 0; p94 = 0; p98 = 0;
    if (p80) { sub_982114(p80); }
    p80 = 0; p84 = 0; p88 = 0;
    if (p70) { sub_982114(p70); }
    p70 = 0; p74 = 0; p78 = 0;
    ((T*)((char*)this + 0x5c))->f(0);
    if (p50) { sub_982114(p50); }
    p50 = 0; p54 = 0; p58 = 0;
    {
        void* a = p44;
        void* b = *(void**)a;
        void* tmp;
        ((U*)((char*)this + 0x40))->f(&tmp, b, a);
    }
    sub_982114(*(void**)((char*)this + 0x44));
    *(void**)((char*)this + 0x44) = 0;
    *(void**)((char*)this + 0x48) = 0;
    {
        void* a = p38;
        void* b = *(void**)a;
        void* tmp;
        ((U*)((char*)this + 0x34))->f(&tmp, b, a);
    }
    sub_982114(*(void**)((char*)this + 0x38));
    *(void**)((char*)this + 0x38) = 0;
    *(void**)((char*)this + 0x3c) = 0;
    ((V*)this)->f();
}

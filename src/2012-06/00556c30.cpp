// from server: 56% by atomic.potato
extern "C" void __cdecl sub_982114(void*);
extern "C" void __fastcall sub_423e20(void*);
extern "C" void __fastcall sub_425320(void*, void*, void*, void*);
extern "C" void __fastcall sub_6cb3c0(void*);

int g_counter = 0;

struct VReplicator {
    char pad0[0x20];
    void** begin20;
    void** end24;
    char pad28[0x0C];
    void* p34;
    void* p38;
    void* p3C;
    void* p40;
    void* p44;
    void* p48;
    void* p4C;
    void* p50;
    void* p54;
    void* p58;
    char pad5C[0x14];
    void* p70;
    void* p74;
    void* p78;
    char pad7C[0x04];
    void* p80;
    void* p84;
    void* p88;
    char pad8C[0x04];
    void* p90;
    void* p94;
    void* p98;
    char pad9C[0x04];
    void* pA0;
    void* pA4;
    void* pA8;
    void destroy();
};

void VReplicator::destroy()
{
    *(void**)this = (void*)0xB72D98;
    ++g_counter;

    void** it = begin20;
    void** last = end24;
    while (it != last) {
        void* obj = *it;
        if (obj != 0) {
            void** vt = *(void***)obj;
            void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
            fn(obj, 1);
        }
        ++it;
    }

    if (pA0 != 0) {
        sub_982114(pA0);
    }
    pA0 = 0;
    pA4 = 0;
    pA8 = 0;

    if (p90 != 0) {
        sub_982114(p90);
    }
    p90 = 0;
    p94 = 0;
    p98 = 0;

    if (p80 != 0) {
        sub_982114(p80);
    }
    p80 = 0;
    p84 = 0;
    p88 = 0;

    if (p70 != 0) {
        sub_982114(p70);
    }
    p70 = 0;
    p74 = 0;
    p78 = 0;

    sub_423e20((char*)this + 0x5C);

    if (p50 != 0) {
        sub_982114(p50);
    }
    p50 = 0;
    p54 = 0;
    p58 = 0;

    {
        void* a = p44;
        void* b = *(void**)a;
        void* tmp;
        sub_425320((char*)this + 0x40, &tmp, b, a);
        sub_982114(*(void**)((char*)this + 0x44));
        *(void**)((char*)this + 0x44) = 0;
        *(void**)((char*)this + 0x48) = 0;
    }

    {
        void* a = p38;
        void* b = *(void**)a;
        void* tmp;
        sub_425320((char*)this + 0x34, &tmp, b, a);
        sub_982114(*(void**)((char*)this + 0x38));
        *(void**)((char*)this + 0x38) = 0;
        *(void**)((char*)this + 0x3C) = 0;
    }

    sub_6cb3c0(this);
}

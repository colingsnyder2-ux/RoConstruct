// from server: 34% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct Inner {
    void* p;
    void* q;
};

struct Elem {
    char pad[0x1c];
    Inner inner;
};

struct Player {
    char pad0[0x34];
    int count;
    int method2(Elem* e, void* p, int c);
    int method(Elem* e, int a, int b, int c);
};

int Player::method(Elem* e, int a, int b, int c)
{
    int local = 0;
    if (e == 0) {
        InterlockedIncrement((long volatile*)0xb7a220);
        *(int*)a = 0;
        *(int*)(a + 4) = 0;
        return local;
    }
    Elem* esi = (Elem*)((char*)e - 0x1c);
    Inner tmp;
    tmp.p = 0;
    Inner* src = &e->inner;
    if (src->p != 0) {
        tmp.p = src->p;
        void** vt = (void**)src->p;
        void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vt[0];
        fn(src->p, &tmp.q, 0);
    }
    int r = this->method2(esi, tmp.p, c);
    return r;
}

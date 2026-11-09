// from server: 77% by atomic.potato
struct BallBallContact {
    char pad[0x34];
    void* field34;
    void release();
};

extern "C" void* __cdecl sub_7b2f50(void*);
extern "C" void __cdecl sub_775d60(void*);

void BallBallContact::release()
{
    void* p = field34;
    if (p) {
        void* q = sub_7b2f50(p);
        sub_775d60(q);
        if (p) {
            void** vt = *(void***)p;
            void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
            fn(p, 1);
        }
        field34 = 0;
    }
}

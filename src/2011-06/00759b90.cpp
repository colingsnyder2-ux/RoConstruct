// from server: 73% by atomic.potato
extern "C" void __stdcall sub_6d5c00(int);

struct BallBallContact {
    char pad[0x2c];
    void* field_2c;
    void release();
};

void BallBallContact::release()
{
    void* p = field_2c;
    if (p) {
        sub_6d5c00((int)p);
        void* q = (void*)0x74b9e0;
        (void)q;
        if (p) {
            void** vt = *(void***)p;
            void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
            fn(p, 1);
        }
        field_2c = 0;
    }
}

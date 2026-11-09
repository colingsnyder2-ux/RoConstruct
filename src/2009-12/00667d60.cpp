// from server: 27% by atomic.potato
struct RBX_SimpleThrottlingArbiter;

extern "C" void* __cdecl sub_7F3860(unsigned int size);

struct AllocObj {
    void init();
};

extern "C" void __cdecl sub_675010_wrap(void* self);
extern "C" void __cdecl sub_667450(void* self, void* a, void* b);

struct RBX_SimpleThrottlingArbiter {
    void __cdecl construct(void* arg);
};

void RBX_SimpleThrottlingArbiter::construct(void* arg) {
    void* mem = sub_7F3860(0xa8);
    void* obj = 0;
    if (mem) {
        ((AllocObj*)mem)->init();
        obj = mem;
    } else {
        obj = 0;
    }
    sub_667450(this, obj, arg);
}

// from server: 26% by atomic.potato
extern "C" void* __cdecl sub_80a05e(unsigned int size);

struct T {
    void sub_5e2600();
    void sub_5dc6b0(void* a, void* b);
};

struct S {
    void f(void* arg);
};

void S::f(void* arg) {
    void* p = sub_80a05e(0xa0);
    void* q = 0;
    if (p) {
        ((T*)p)->sub_5e2600();
        q = p;
    } else {
        q = 0;
    }
    ((T*)this)->sub_5dc6b0(q, arg);
}

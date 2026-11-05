// from server: 42% by atomic.potato
struct Job {
    void* vtbl;
    float x;
    float y;
};

struct Holder {
    Job* p;
};

extern "C" void __cdecl sub_4f0db0(float* out, float* in);
extern "C" void* __cdecl sub_80a05e(unsigned int size);

void __cdecl sub_4f8990(Holder* h, float* src)
{
    float tmp[2];
    tmp[0] = 0.0f;
    tmp[1] = 0.0f;
    sub_4f0db0(tmp, src);

    Job* j = (Job*)sub_80a05e(0xc);
    if (j) {
        j->vtbl = (void*)0xa7b324;
        j->x = tmp[0];
        j->y = tmp[1];
    } else {
        j = 0;
    }

    Job* old = h->p;
    if (&h->p != (Job**)&h->p) {
        old = h->p;
        h->p = j;
    } else {
        old = j;
    }

    if (old) {
        void** vt = (void**)old->vtbl;
        void (*fn)(void*) = (void (*)(void*))vt[0];
        fn(old);
    }
}

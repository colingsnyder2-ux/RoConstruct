// from server: 63% by atomic.potato
extern "C" long __stdcall InterlockedDecrement(long volatile*);

struct Inner {
    void* vtbl;
    void release();
};

struct Holder {
    char pad[8];
    Inner* ptr;
};

struct Adapter {
    char pad[8];
    Holder* holder;
    void clear();
};

void Adapter::clear() {
    Holder* h = holder;
    Inner* p = h->ptr;
    if (p) {
        if (InterlockedDecrement((long*)p + 1) == 0) {
            p->release();
            if (p) {
                void** vt = *(void***)p;
                void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
                fn(p, 1);
            }
        }
        h->ptr = 0;
    }
}

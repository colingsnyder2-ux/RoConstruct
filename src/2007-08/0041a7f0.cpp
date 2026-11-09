// from server: 10% by colin
struct BoundFuncDesc {
    char pad[0x30];
    void* field30;
    void* field34;
    void* field38;
    void* field3c;
    void* field40;
    void* field44;

    void declareSignature();
};

void BoundFuncDesc::declareSignature()
{
    void* a = field30;
    void* b = field34;
    if (b) {
        void** vt = *(void***)b;
        void (*fn)(void*) = (void (*)(void*))vt[2];
        fn(b);
    }
    void* c = field38;
    void* d = field3c;
    if (d) {
        void** vt = *(void***)d;
        void (*fn)(void*) = (void (*)(void*))vt[2];
        fn(d);
    }
    void* e = field40;
    void* f = field44;
    if (f) {
        void** vt = *(void***)f;
        void (*fn)(void*) = (void (*)(void*))vt[2];
        fn(f);
    }
}

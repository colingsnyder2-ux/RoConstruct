// from server: 58% by colin
struct S {
    void* f(void* a, void* b, void* c);
};

extern "C" void* __stdcall sub_4CA490(void* a, void* b, void* c);

void* S::f(void* a, void* b, void* c)
{
    void* p = sub_4CA490(a, b, c);
    if (p) {
        void** vt = *(void***)p;
        void* (*fn)(void*) = (void* (*)(void*))vt[6];
        if (fn(p)) {
            void** vt2 = *(void***)p;
            void* (*fn2)(void*) = (void* (*)(void*))vt2[6];
            return fn2(p);
        }
        return p;
    }
    return 0;
}

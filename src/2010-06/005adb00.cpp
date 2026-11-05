// from server: 28% by atomic.potato
extern "C" {
    int __stdcall sub_40A530(void*);
    void* __stdcall sub_9EA89C(void*);
    int __stdcall sub_9EA8D8(void*, const char*);
}

struct type_info;

struct bad_cast {
    bad_cast(const char*);
};

struct S {
    void* f(void*);
};

void* S::f(void* arg) {
    if (arg != 0) {
        void* p = *(void**)arg;
        if (p != 0) {
            void** vt = *(void***)p;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(p);
        } else {
            p = (void*)0xb7930c;
        }
        if (sub_9EA8D8(p, (const char*)0xba0a1c)) {
            void* q = *(void**)arg;
            q = (char*)q + 4;
            if (q != 0) {
                return q;
            }
        }
    }
    char buf[8];
    sub_9EA89C(buf);
    *(void**)(buf + 4) = (void*)0xa00a4c;
    sub_40A530(buf + 4);
    return 0;
}

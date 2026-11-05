// from server: 26% by atomic.potato
extern "C" {
    int __stdcall sub_40F520(void*);
}

struct type_info;

struct bad_cast {
    bad_cast(const char*);
};

extern "C" {
    void* __stdcall sub_B22A20();
    bool __stdcall sub_B22A2C(void*, void*);
}

struct S {
    void f(void*);
};

void S::f(void* arg) {
    void* p = arg;
    void* v = *(void**)p;
    void* t;
    if (v) {
        t = *(void**)v;
    } else {
        t = (void*)0xd60ac8;
    }
    if (t != (void*)0xd8add0) {
        void* u;
        if (v) {
            u = *(void**)v;
        } else {
            u = (void*)0xd60ac8;
        }
        if (sub_B22A2C(u, (void*)0xd8add0)) {
            void* buf[1];
            sub_B22A20();
            buf[0] = (void*)0xb44120;
            sub_40F520(buf);
        }
    }
}

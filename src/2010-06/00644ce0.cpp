// from server: 33% by atomic.potato
struct type_info;

extern "C" {
    void __stdcall func_9ea89c(void*);
    int __stdcall func_9ea8d8(void*, const char*);
    void __cdecl func_40a530(void*);
}

struct bad_cast {
    bad_cast(const char*);
};

struct X_00644ce0 {
    void* f_0;
    void* get();
    void run(void*);
};

void* X_00644ce0::get() {
    void* p = f_0;
    if (p) {
        void** vt = *(void***)p;
        void* (*fn)(void*) = (void* (*)(void*))vt[1];
        return fn(p);
    }
    return (void*)0xb7930c;
}

void X_00644ce0::run(void* arg) {
    X_00644ce0* self = (X_00644ce0*)arg;
    if (self) {
        void* p = self->f_0;
        void* r;
        if (p) {
            void** vt = *(void***)p;
            void* (*fn)(void*) = (void* (*)(void*))vt[1];
            r = fn(p);
        } else {
            r = (void*)0xb7930c;
        }
        if (func_9ea8d8(r, (const char*)0xbb6168)) {
            if ((char*)self->f_0 + 4) {
                return;
            }
        }
    }
    func_9ea89c((void*)0xa00a54);
    *(void**)0xa00a4c = (void*)0xa00a4c;
    func_40a530((void*)0xa00a4c);
}

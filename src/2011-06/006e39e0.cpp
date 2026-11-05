// from server: 58% by atomic.potato
struct S {
    char pad0[8];
    void* field8;
    void* fieldC;
    void* f();
};

extern "C" void* __stdcall sub_A4064C(void*, void*);

void* S::f() {
    void* p = fieldC;
    if (*(void**)((char*)p + 8) == 0) {
        void* q = field8;
        void* r = *(void**)((char*)q + 4);
        return sub_A4064C((char*)this + 8 + (int)r, 0);
    } else {
        void* q = *(void**)((char*)p + 4);
        void* r = *(void**)q;
        void* s = *(void**)((char*)r + 8);
        void* t = field8;
        void* u = *(void**)((char*)t + 4);
        return sub_A4064C((char*)this + 8 + (int)u, s);
    }
}

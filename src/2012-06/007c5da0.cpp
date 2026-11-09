// from server: 94% by atomic.potato
extern "C" void __cdecl free(void*);

struct S {
    void f(int* p);
};

void S::f(int* p) {
    *p = 0;
    if (p[2]) {
        free((void*)p[2]);
    }
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
}

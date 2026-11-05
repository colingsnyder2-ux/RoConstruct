// from server: 42% by atomic.potato
struct S {
    char pad0[4];
    void __cdecl f(char*);
};

extern "C" void __cdecl sub_6e0c50(void*, void*, int, int);

void S::f(char* p) {
    char* q = p;
    char* r = p + 4;
    char local = 0;
    sub_6e0c50(r, &q, 0, *(int*)p);
}

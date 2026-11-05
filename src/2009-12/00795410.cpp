// from server: 84% by atomic.potato
struct S {
    char pad0[8];
    void* field8;
    char padC[4];
    void* field10;
};

extern "C" char __cdecl sub_78AC70(void* a, void* b, void** out);

char __cdecl sub_795410(void* a, void* b, void* c) {
    void* local;
    if (sub_78AC70(a, b, &local)) {
        S* p = (S*)local;
        void** vtbl = *(void***)p->field8;
        void (__stdcall *fn)(void*, void*) = (void (__stdcall *)(void*, void*))vtbl[5];
        fn(p->field10, c);
        return 1;
    }
    return 0;
}

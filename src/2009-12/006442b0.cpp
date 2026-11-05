// from server: 77% by atomic.potato
struct S {
    char pad[0x1c];
    void* field_1c;
    bool method(void* arg1, void* arg2);
};

extern "C" bool __cdecl helper(void* a, void* b);

bool S::method(void* arg1, void* arg2) {
    if (helper(arg1, &arg2)) {
        void* p = field_1c;
        void** vt = *(void***)p;
        void (*fn)(void*, void*) = (void (*)(void*, void*))vt[4];
        fn(p, arg2);
        return true;
    }
    return false;
}

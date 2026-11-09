// from server: 50% by atomic.potato
struct TypedPropertyDescriptor {
    char pad[0x1c];
    void* field1c;
    bool f(void* a, void* b);
};

extern "C" int __cdecl sub_6BC1F0(void* a, void* b);

bool TypedPropertyDescriptor::f(void* a, void* b) {
    if (!sub_6BC1F0(a, b)) {
        return false;
    }
    void* p = field1c;
    void* vt = *(void**)p;
    void (*fn)(void*, void*) = *(void (**)(void*, void*))((char*)vt + 0x10);
    fn(p, a);
    return true;
}

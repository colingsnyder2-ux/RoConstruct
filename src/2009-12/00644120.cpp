// from server: 62% by atomic.potato
struct TypedPropertyDescriptor {
    char pad[0x1c];
    void* field_1c;
    bool compare(void*, void*);
};

extern "C" int __cdecl sub_6bbec0(void*, void*);

bool TypedPropertyDescriptor::compare(void* a, void* b) {
    void* local = a;
    if (sub_6bbec0(local, b)) {
        void* p = field_1c;
        void* vt = *(void**)p;
        void (*fn)(void*, void*) = *(void (**)(void*, void*))((char*)vt + 0x10);
        fn(p, local);
        return true;
    }
    return false;
}

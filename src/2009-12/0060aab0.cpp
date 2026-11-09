// from server: 100% by atomic.potato
extern "C" unsigned int (__cdecl *fread)(void*, unsigned int, unsigned int, void*);
extern "C" void __cdecl sub_00610190(void*, const char*);

struct S {
    char pad[0x54];
    void* field_54;
};

void __cdecl sub_0060aab0(S* p, void* buf, unsigned int size) {
    if (p) {
        unsigned int n = fread(buf, 1, size, p->field_54);
        if (n != size) {
            sub_00610190(p, "Read Error");
        }
    }
}

// from server: 100% by atomic.potato
extern "C" unsigned int (__cdecl *fwrite)(const void*, unsigned int, unsigned int, void*);
extern "C" void __cdecl sub_610190(void*, const char*);

struct S {
    char pad[0x54];
    void* field_54;
};

void __cdecl sub_6033b0(S* s, const void* buf, unsigned int size) {
    if (s != 0) {
        unsigned int written = fwrite(buf, 1, size, s->field_54);
        if (written != size) {
            sub_610190(s, "Write Error");
        }
    }
}

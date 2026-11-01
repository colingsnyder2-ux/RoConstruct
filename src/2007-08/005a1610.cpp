// from server: 100% by colin
struct CharacterAppearance {
    void apply(void*);
};

extern "C" char __cdecl sub_4915F0(void*, void*);
extern "C" void* __cdecl sub_5A56B0(void*);

void CharacterAppearance::apply(void* a) {
    if (*(void**)a == this) {
        if (sub_4915F0(this, 0)) {
            void* arg = *(void**)((char*)this + 0xbc);
            void* p = sub_5A56B0(arg);
            if (p) {
                void** vt = *(void***)this;
                void (__thiscall *fn)(void*, void*) = (void (__thiscall *)(void*, void*))vt[0x44 / 4];
                fn(this, p);
            }
        }
    }
}

// from server: 90% by atomic.potato
struct RBX_BaseScript {
    char pad[0xa0];
    void* field_a0;
    void sub_0071a2b0(int, int);
};

extern "C" void __stdcall sub_00721d30(void*);

void RBX_BaseScript::sub_0071a2b0(int a, int b)
{
    if (a != 0) {
        void* p = field_a0;
        if (p != 0) {
            field_a0 = 0;
            sub_00721d30(this);
        }
    }
    if (b != 0) {
        void** vt = *(void***)this;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vt[0x54 / 4];
        fn(this);
    }
}

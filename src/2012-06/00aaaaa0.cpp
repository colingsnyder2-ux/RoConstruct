// from server: 52% by Intel
extern "C" void __cdecl dec_byte_at(void*);

struct seg_00aa0000 {
    void func();
};

void seg_00aa0000::func() {
    dec_byte_at((void*)0x4d04ff25);
}

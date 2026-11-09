// from server: 34% by atomic.potato
struct RBX_BlockBlockContact {
    char pad[0x100];
};

extern "C" void __cdecl sub_6909C0(void*, void*, void*);

void* __cdecl sub_71AEE0(void* a, void* b) {
    float f0 = 0.0f;
    float f1 = 0.0f;
    *(float*)0x00C1B4C0 = f0;
    *(float*)0x00C1B4C4 = f1;
    *(float*)0x00C1B4C8 = f0;
    sub_6909C0((void*)0x00C1B4C0, b, a);
    return a;
}

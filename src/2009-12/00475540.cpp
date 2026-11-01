// from server: 100% by atomic.potato
extern "C" void __cdecl free(void*);

struct DxUserInput {
    unsigned short a0;
    unsigned short a2;
    void* p4;
    int pad8;
    int padC;
    int p10;
    void reset();
};

void DxUserInput::reset() {
    p10 = 0;
    if (p4 != 0) {
        free(p4);
        p4 = 0;
    }
    pad8 = 0;
    padC = 0;
    a0 = 0;
    a2 = 0x4e4;
}

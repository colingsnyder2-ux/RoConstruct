// from server: 1% by atomic.potato
struct GfxClustererPart {
    char pad0[0x10];
    void* field10;
    char pad14[0x4];
    void* field14;
    int insert(void* a, void* b, int c);
    int find(void* a, void* b);
    int helper(void* a, void* b);
};

extern "C" int __stdcall string_less(void* a, void* b);
extern "C" void* __stdcall sub_773880(void* a);
extern "C" void* __stdcall sub_92c290(void* a);

int GfxClustererPart::insert(void* a, void* b, int c) {
    return 0;
}

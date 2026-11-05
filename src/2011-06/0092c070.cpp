// from server: 95% by atomic.potato
extern "C" void* __stdcall allocBytes(unsigned int size, const char* file, int line, const char* func);

struct GfxClustererPart {
    char pad[0x48];
    void construct();
};

void GfxClustererPart::construct() {
    GfxClustererPart* p = (GfxClustererPart*)allocBytes(0x48, 0, 0, 0);
    if (p) {
        *(int*)p = 0;
    }
    int* q = (int*)((char*)p + 4);
    if (q) {
        *q = 0;
    }
    int* r = (int*)((char*)p + 8);
    if (r) {
        *r = 0;
    }
    *((char*)p + 0x45) = 0;
    *((char*)p + 0x44) = 1;
}

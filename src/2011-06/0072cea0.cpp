// from server: 47% by atomic.potato
extern "C" void __stdcall helper_0091e320(void*, void*);
extern "C" void __stdcall helper_00773bd0(void*);
extern "C" char __stdcall helper_006b6b00(void*);

struct RBX_FileMeshDataV2 {
    int field0;
    char pad[0x24];
    int init(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j);
};

int RBX_FileMeshDataV2::init(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j) {
    char buf[0x28];
    *(void**)buf = a;
    *(int*)(buf + 0x24) = 0;
    helper_0091e320(buf + 4, &b);
    char r = helper_006b6b00((void*)0xc878cc);
    int v = -(int)(unsigned char)r;
    v = v & 0xc878cc;
    field0 = v;
    *(int*)(buf + 0x18) = -1;
    helper_00773bd0(buf + 0x18);
    return 0;
}

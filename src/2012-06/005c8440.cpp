// from server: 100% by Intel
struct RBX_AdornRbxGfx {
    void func(void* a1, void* a2, void* a3, void* a4, void* a5);
};

void RBX_AdornRbxGfx::func(void* a1, void* a2, void* a3, void* a4, void* a5) {
    unsigned char* ptr = static_cast<unsigned char*>(a3);
    *ptr = 0;
}

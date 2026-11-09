// from server: 100% by atomic.potato
extern "C" int __cdecl sub_7F90E0(int, const char*, const char*, int, int, int, int);

extern unsigned char byte_CCC3A0;

struct AdornRbxGfx {
    char pad[0xc];
    int field_c;
    void f();
};

void AdornRbxGfx::f() {
    if (byte_CCC3A0) {
        int* p = *(int**)(field_c + 0x4c);
        sub_7F90E0(3, "Post-Submit. Size of buffers, 3D: %u, 3DTexture: %u",
                   ".\\AdornRbxGfx.cpp", 0x51d, p[0x2c / 4], p[0x80 / 4], 0);
    }
}

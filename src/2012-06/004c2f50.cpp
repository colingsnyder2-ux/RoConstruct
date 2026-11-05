// from server: 84% by atomic.potato
extern "C" void __cdecl sub_005ca000(const char*, unsigned char, unsigned int,
                                      unsigned int, unsigned int, int);

extern unsigned char byte_00e31aae;

struct S {
    void f();
    void* member_10;
};

void S::f()
{
    if (byte_00e31aae)
    {
        unsigned int* p = *(unsigned int**)((char*)member_10 + 0x4c);
        sub_005ca000("Post-Submit. Size of buffers, 3D: %u, 3DTexture: %u",
                     byte_00e31aae, p[0x2c / 4], p[0x80 / 4], 0, 0);
    }
}

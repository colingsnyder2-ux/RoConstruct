// from server: 81% by atomic.potato
struct RbxMeshPartAdapter {
};

extern "C" void* __cdecl sub_7f3860(unsigned int size);
extern "C" void* __cdecl sub_49c6f0(void* p, int b, int c, int d, float a);

void* __cdecl create(float a, int b, int c, int d)
{
    void* p = sub_7f3860(0x20);
    if (p) {
        return sub_49c6f0(p, b, c, d, a);
    }
    return 0;
}

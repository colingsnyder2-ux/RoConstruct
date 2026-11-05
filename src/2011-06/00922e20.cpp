// from server: 100% by atomic.potato
extern "C" int __cdecl sub_7F90E0(int, const char*, const char*, int, int, int, int);

struct AdornRbxGfx {
    char pad[0xc];
    int field_c;
    void f();
};

void AdornRbxGfx::f() {
    if (*(char*)0xccc3a0 == 0) return;
    int* p = *(int**)(field_c + 0x4c);
    sub_7F90E0(3, (const char*)0xaf4ca8, (const char*)0xaf4cdc, 0x517,
               p[0x2c/4], p[0x80/4], 0);
}

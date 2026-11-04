// from server: 74% by Intel
struct Sphere {
};

void __cdecl func(int* a) {
    int v = -1;
    a[0] = 0;
    a[1] = v;
    a[2] = 0;
    a[3] = 0;
    a[4] = v;
    a[5] = v;
    a[6] = v;
    a[7] = v;
    *(short*)&a[8] = 0;
    *(short*)((char*)a + 0x22) = 0;
}

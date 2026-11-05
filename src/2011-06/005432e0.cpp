// from server: 75% by atomic.potato
struct G3D_Sphere {
    int field0;
    int field4;
    void func(int arg);
};

void G3D_Sphere::func(int arg) {
    if (arg == 0) return;
    if (arg < 0) {
        int edx = field4;
        int esi = -arg;
        if ((unsigned)edx >= (unsigned)esi) {
            goto normal;
        }
        arg += edx;
        edx = -1;
        edx -= arg;
        edx = (unsigned)edx >> 5;
        edx += edx;
        edx += edx;
        esi = -4;
        esi -= edx;
        field0 += esi;
        arg &= 0x1f;
        field4 = arg;
        return;
    }
normal:
    {
        int edx = field4;
        arg += edx;
        edx = arg;
        edx = (unsigned)edx >> 5;
        edx += edx;
        edx += edx;
        field0 += edx;
        arg &= 0x1f;
        field4 = arg;
    }
}

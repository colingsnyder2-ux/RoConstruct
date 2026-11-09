// from server: 45% by atomic.potato
struct ProfilingItem {
    char pad0[0x98];
    double field98;
    char padA0[0x20];
    void* fieldC0;
    void update();
};

extern "C" {
    double __stdcall sub_6cab40(void* a, void* b);
    void __stdcall sub_6ca9d0(void* a);
    void __stdcall sub_6ca9b0(void* a, double b);
    void __stdcall sub_7e4e90(void* a, void* b);
    int __stdcall sub_98b7dc(const char* fmt, ...);
    void __stdcall sub_98b6e4(void* a);
    void __stdcall sub_98b700(void* a);
}

extern double dbl_b3d608;
extern double dbl_9a49e0;
extern char str_9bd9d0[];
extern char str_9d9454[];
extern char str_9d945c[];

void ProfilingItem::update()
{
    double local8;
    char buf[0x160];
    void* localC0;

    sub_6cab40(fieldC0, &local8);

    if (local8 > 0.0) {
        field98 = local8 / *(double*)&buf[0];
        if (*(int*)&buf[8] > 0) {
            sub_6ca9d0(&local8);
            sub_7e4e90(&buf[0x18], &local8);
            char* p = buf;
            if (*(int*)&buf[0x2c] >= 0x10)
                p = *(char**)&buf[0x18];
            sub_6ca9b0(&local8, field98 * dbl_9a49e0);
            sub_98b7dc(str_9d945c, p, local8);
            sub_98b6e4(&buf[0x14]);
        } else {
            sub_98b7dc(str_9d9454, field98 * dbl_9a49e0);
        }
    } else {
        field98 = 0.0;
        sub_98b7dc(str_9bd9d0);
    }
    sub_98b700(&field98 + 1);
}

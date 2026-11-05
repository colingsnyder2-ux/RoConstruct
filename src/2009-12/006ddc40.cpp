// from server: 45% by atomic.potato
struct VCRenderSettingsItem_EnumPropDescriptor {
    char pad0[0xa0];
    char field_a0[4];
    void sub_6dc020(float);
    void sub_6dca20(double);
    void sub_6ddae0();
    void sub_6ddc40(float, float, float, int, int, int);
};

extern "C" {
    void __stdcall sub_5f3450(void*, void*);
    int __stdcall sub_71e900(void*, void*);
    int __stdcall sub_67f790(void*, void*);
    void __stdcall sub_486000(void*);
}

extern float g_9af2dc;
extern double g_9a44c0;

void VCRenderSettingsItem_EnumPropDescriptor::sub_6ddc40(float a, float b, float c, int d, int e, int f)
{
    if ((double)(c - a) > g_9a44c0) {
        return;
    }
    sub_6dc020(b);
    sub_6dca20(1.0);
    sub_6ddae0();

    char local[4];
    sub_5f3450(field_a0, local);

    int r1 = sub_71e900((void*)d, local);
    int r2 = 0;
    if (!r1) {
        if (e) {
            r2 = sub_67f790((void*)e, local);
        }
    }
    float x;
    float y;
    if (r1 || r2) {
        x = b + c;
        y = a;
    } else {
        x = c + a;
        y = b;
    }
    x = x * g_9af2dc;
    sub_6ddc40(y, x, c, d, e, f);
    sub_486000(local);
}

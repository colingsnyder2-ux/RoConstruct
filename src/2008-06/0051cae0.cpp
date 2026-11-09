// from server: 100% by king_originala
struct DialogTemplate {
    int field0;
    int field4;
    int flags;
    char pad[0x80 - 0x0c];
    float f80;
    float f84;
    float f88;
    float f8c;
    float f90;
    float f94;
    float f98;
    float f9c;
    char pad2[0x100 - 0xa0];
    int i100;
    int i104;
    int i108;
    int i10c;
    int i110;
    int i114;
    int i118;
    int i11c;
};

extern "C" int __cdecl sub_529a50(int, const char*);
extern const double g_828f80;
extern const double g_828f88;
extern const char g_828ef8[];
extern const char g_828f2c[];

void __cdecl sub_51cae0(
    int context, DialogTemplate* self,
    int a3, int a4, int a5, int a6,
    int a7, int a8, int a9, int a10)
{
    if (context == 0)
        return;
    if (self == 0)
        return;

    if (a3 < 0 || a4 < 0 || a5 < 0 || a6 < 0 ||
        a7 < 0 || a8 < 0 || a9 < 0 || a10 < 0) {
        sub_529a50(context, g_828ef8);
        return;
    }

    if ((double)a3 > g_828f88 ||
        (double)a4 > g_828f88 ||
        (double)a5 > g_828f88 ||
        (double)a6 > g_828f88 ||
        (double)a7 > g_828f88 ||
        (double)a8 > g_828f88 ||
        (double)a9 > g_828f88 ||
        (double)a10 > g_828f88) {
        sub_529a50(context, g_828f2c);
        return;
    }

    const double scale = g_828f80;
    self->flags |= 4;

    self->i100 = a3;
    self->f80 = (float)((double)a3 * scale);
    self->i104 = a4;
    self->f84 = (float)((double)a4 * scale);
    self->i108 = a5;
    self->f88 = (float)((double)a5 * scale);
    self->i10c = a6;
    self->f8c = (float)((double)a6 * scale);
    self->i110 = a7;
    self->f90 = (float)((double)a7 * scale);
    self->i114 = a8;
    self->f94 = (float)((double)a8 * scale);
    self->i118 = a9;
    self->f98 = (float)((double)a9 * scale);
    self->i11c = a10;
    self->f9c = (float)((double)a10 * scale);
}

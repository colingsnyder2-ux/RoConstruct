// from server: 39% by Intel
struct AdornRbxGfx {
    double field_10;
    double field_18;
    int field_28;
    int field_2C;
    char field_30;
    char field_31;
    char field_38;

    void __thiscall sub_5C8670(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, char a14);
};

extern "C" const double _flt_7fffffff;
extern "C" const double _flt_4294967296;

void __thiscall AdornRbxGfx::sub_5C8670(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, char a14)
{
    __int64 v1 = ((__int64)a3 << 32) | (a2 & 0x7FFFFFFF);
    __int64 v2 = (__int64)a3 & 0x80000000;
    double d1 = *(double*)&v1;
    double d2 = *(double*)&v2;
    field_38 = a14;
    double val = d1 - d2;
    *(double*)((char*)this + 8) = val;

    if (!a14)
        return;

    int v3 = field_2C;
    if (v3 == a7)
        return;

    int diff = v3 - a7;
    diff &= 0xFFFFFF;
    if (diff <= 0x7FFFFF)
        return;

    field_2C = field_28;
    char flag = 1;
    field_30 = 0;
    field_31 = 0;

    double f10 = field_10;
    double f18 = field_18;
    if (f10 < f18) {
        double temp = f18;
        if (temp < f10) {
            if (!flag)
                return;
            int v4 = *(int*)this;
            int v5 = v4 * v4;
            double d3 = (double)v5;
            if (v5 < 0)
                d3 += _flt_4294967296;
            d3 = d3 / f18 + f18;
            field_10 = d3;
            return;
        }
    }

    if (f10 <= _flt_7fffffff)
        return;

    field_10 = f10 + f10;
    double f18_2 = field_18;
    if (f18_2 >= f10)
        return;

    if (f18_2 < f10) {
        if (!flag)
            return;
        int v6 = *(int*)this;
        int v7 = v6 * v6;
        double d4 = (double)v7;
        if (v7 < 0)
            d4 += _flt_4294967296;
        d4 = d4 / f10 + f10;
        field_10 = d4;
    }
}

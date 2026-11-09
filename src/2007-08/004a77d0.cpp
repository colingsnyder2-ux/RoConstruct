// from server: 57% by colin
struct ChangePropertyItem {
    char pad0[4];
    float x;
    float y;
    float z;
};

extern "C" int __stdcall sub_4A0250(int, char*);
extern "C" void __stdcall sub_49F9A0(int, int, int, int);
extern "C" void __stdcall sub_4A6C90(int, int, int, int);

extern double dbl_79D5F8;
extern double dbl_79D600;
extern double dbl_79D608;
extern double dbl_79D610;
extern double dbl_798B30;

void sub_4A77D0(ChangePropertyItem* item, int a2)
{
    char flag;
    int v1;
    int v2;
    int v3;

    sub_4A0250(a2, &flag);
    if (flag != 0) {
        v1 = 0;
        sub_49F9A0(a2, 0xf, (int)&v1, 1);
        sub_49F9A0(a2, 0xe, (int)&v2, 1);
        sub_49F9A0(a2, 0xf, (int)&v3, 1);

        unsigned short s1 = *(unsigned short*)&v1;
        unsigned short s2 = *(unsigned short*)&v2;
        unsigned short s3 = *(unsigned short*)&v3;

        int i1 = s1;
        int i2 = s2;
        int i3 = s3;

        float f1 = (float)i1;
        float f2 = (float)i2;
        float f3 = (float)i3;

        item->x = (float)(f1 * dbl_798B30 - dbl_79D608);
        item->y = (float)(f2 * dbl_79D600 * dbl_798B30 - dbl_79D5F8);
        item->z = (float)(f3 * dbl_79D610 * dbl_798B30 - dbl_79D608);
    } else {
        sub_4A6C90(a2, (int)&item->x, (int)&item->y, (int)&item->z);
    }
}

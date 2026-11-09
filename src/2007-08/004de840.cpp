// from server: 37% by colin
struct Level {
    void construct(float, float, float, int, int);
    char pad0[0x20];
    unsigned short a;
    unsigned short b;
    unsigned short c;
};

extern "C" void __stdcall sub_4eed00(int, float, float, float);
extern "C" int __cdecl sub_630d60(float);

extern float g_79f338;
extern int g_79f31c;

void Level::construct(float x, float y, float z, int p1, int p2)
{
    float v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    sub_4eed00(p1, x, y, z);
    *(int*)this = (int)&g_79f31c;
    a = 0;
    b = 0;
    c = 0;
    float t = x / g_79f338;
    int r1 = sub_630d60(t);
    int m1 = 1;
    unsigned short s1;
    if (r1 > 1)
        s1 = *(unsigned short*)&r1;
    else
        s1 = *(unsigned short*)&m1;
    a = s1;
    float t2 = y / t;
    int r2 = sub_630d60(t2);
    int m2 = 1;
    unsigned short s2;
    if (r2 > 1)
        s2 = *(unsigned short*)&r2;
    else
        s2 = *(unsigned short*)&m2;
    b = s2;
    float t3 = z / t2;
    int r3 = sub_630d60(t3);
    int m3 = 1;
    unsigned short s3;
    if (r3 > 1)
        s3 = *(unsigned short*)&r3;
    else
        s3 = *(unsigned short*)&m3;
    c = s3;
    int iv1 = (short)a;
    int lim = 4;
    int cmp1 = iv1;
    unsigned short q1;
    if (cmp1 < lim)
        q1 = *(unsigned short*)&cmp1;
    else
        q1 = *(unsigned short*)&lim;
    a = q1;
    int iv2 = (short)b;
    int cmp2 = iv2;
    unsigned short q2;
    if (cmp2 < lim)
        q2 = *(unsigned short*)&cmp2;
    else
        q2 = *(unsigned short*)&lim;
    b = q2;
    int iv3 = (short)c;
    int cmp3 = iv3;
    unsigned short q3;
    if (cmp3 < lim)
        q3 = *(unsigned short*)&cmp3;
    else
        q3 = *(unsigned short*)&lim;
    c = q3;
}

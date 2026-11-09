// from server: 58% by colin
struct S {
    char pad0[0x14];
    int* p14;
    char pad18[0x0c];
    int* p24;
    char pad28[0x0c];
    int* p34;
    char pad38[0x08];
    int field40;
    char pad44[0x08];
    int field4c;
    int field50;
    int field54;
    void m();
};

extern "C" int __stdcall sub_54dd50(int, int, int);

void S::m()
{
    int* a = p14;
    int* b = p24;
    int diff = *b - *a;
    if (diff > 0) {
        int r = sub_54dd50(field4c, *a, diff);
        if (r == diff) {
            int c = field50;
            *p14 = c;
            *p24 = c;
            *p34 = field54;
        } else {
            int old = *p24;
            int c = field50;
            int e = c + *a;
            *p14 = e;
            *p24 = e;
            *p34 = field54 + c - e;
            int f = old - *p24;
            *p34 -= f;
            *p24 += f;
        }
    }
}

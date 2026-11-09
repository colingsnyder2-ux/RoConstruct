// from server: 47% by atomic.potato
struct NodeVisiter {
    char pad0[4];
    int field4;
    int field8;
    int fieldC;
    char pad10[4];
    unsigned char field14;
    char pad15[3];
    int field18;
    char pad1C[0xC];
    float field28;
    int method(int, int, int);
};

extern "C" int __cdecl sub_4B96F0(int, int, int, int, int, int, int);
extern "C" int __cdecl sub_4E9A80(int);
extern "C" int __cdecl sub_7F4CF0();

int NodeVisiter::method(int a, int b, int c)
{
    int *p = (int *)a;
    if (p[0x284/4] < field18) {
        p[0x284/4] = field18;
        sub_4B96F0(field8, fieldC, 0, 1, 0, field14, b);
        int v = sub_4E9A80(field4 + 0x1C0);
        int w = sub_7F4CF0();
        float f = *(float *)(v + 8);
        if ((float)w > f) {
            float x = *(float *)&c;
            if (x > field28) {
                field28 = x;
            }
        } else {
            if (field28 >= *(float *)&c) {
                return 1;
            }
            return 0;
        }
    }
    return 1;
}

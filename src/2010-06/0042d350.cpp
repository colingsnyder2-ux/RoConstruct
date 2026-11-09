// from server: 42% by atomic.potato
struct S {
    char pad0[0xfc];
    char f_fc;
    char pad_fd;
    char f_fe;
    char pad_ff[0x108 - 0xff];
    char f_108;
    int f(int* arg);
};

extern "C" int __stdcall sub_7a7f70();
extern "C" int __cdecl sub_412fc0();
extern "C" int __stdcall SystemParametersInfoA(unsigned int, unsigned int, void*, unsigned int);

int S::f(int* arg)
{
    char buf[0x24];
    sub_7a7f70();
    int zero = 0;
    if (this->f_fc != 0) {
        arg[4] = 0;
        arg[5] = 0;
    }
    if (this->f_fe != 0) return 0;
    if (this->f_fc != 0) return 0;
    if (this->f_108 == 0) return 0;

    int v = sub_412fc0();
    v += 0x98;
    int val = *(int*)(v + 0x52);
    int lo = (short)val;
    int hi = (short)(val >> 16);

    int local1 = lo;
    int local2 = hi;
    int local3 = 0;
    int local4 = 0;

    int (*fn)(void*, int*, int) = *(int(**)(void*, int*, int))(*(int*)this + 0x70);
    fn(this, &local1, 0);

    int a = local3 - local1;
    int b = local4 - local2;

    int out1 = 0;
    int out2 = 0;
    if (SystemParametersInfoA(0x30, 0, &out1, 0)) {
        int w = out2 - out1;
        short sw = (short)a;
        int cmp = w;
        int c2 = sw;
        int *sel;
        if (cmp < c2) sel = &cmp; else sel = &c2;
        short r1 = *(short*)sel;

        int w2 = out2 - out1;
        short sw2 = (short)b;
        int cmp2 = w2;
        int c3 = sw2;
        int *sel2;
        if (cmp2 < c3) sel2 = &cmp2; else sel2 = &c3;
        short r2 = *(short*)sel2;

        arg[8] = (int)r1;
        arg[2] = (int)r1;
        arg[9] = (int)r2;
        arg[3] = (int)r2;
    }
    return 0;
}

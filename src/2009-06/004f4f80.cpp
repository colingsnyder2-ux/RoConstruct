// from server: 33% by atomic.potato
extern "C" int __stdcall sub_00719ec0(double);
extern "C" int __stdcall sub_00719d00(int, int, int, int);

extern double g_9f5e30;
extern int g_9f5e2c;
extern int g_9f5e38;
extern int g_9f5e3c;
extern int g_9f5e40;
extern int g_9f5e44;

struct ClientReplicator {
    char pad_0[0x38];
    int f_38;
    int f_3c;
    char pad_40[8];
    unsigned char f_48;
    char pad_49[0x830 - 0x49];
    int f_830;
    int f_834;
    void update(int a, int b, int c);
};

void ClientReplicator::update(int a, int b, int c) {
    int lo = f_830;
    int hi = f_834;
    int sign = hi & 0x80000000;
    int mag = hi & 0x7fffffff;
    double d = (double)lo + (double)((unsigned)mag | (unsigned)sign) * 0.0;
    (void)d;
    double val = (double)lo + (double)hi;
    int r = sub_00719ec0(val * g_9f5e30);
    int q = sub_00719d00(lo, hi, 0x3e8, 0);
    g_9f5e2c = q;
    int eax = r;
    int edx = (r < 0) ? -1 : 0;
    eax += a;
    edx += b;
    eax += 0x3a98;
    edx += 0;
    f_3c = edx;
    int ebx = f_3c;
    f_38 = eax;
    int g1 = g_9f5e40;
    int g2 = g_9f5e44;
    g1 += a;
    g2 += b;
    if (ebx > g2 || (ebx == g2 && f_38 > g1)) {
        f_38 = g1;
        f_3c = g2;
    }
    if (f_48 >= 3) {
        int h1 = g_9f5e38;
        int h2 = g_9f5e3c;
        h1 += a;
        h2 += b;
        int esi = f_3c;
        if (esi < h2 || (esi == h2 && f_38 < h1)) {
            f_38 = h1;
            f_3c = h2;
        }
    }
}

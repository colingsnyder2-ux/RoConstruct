// from server: 100% by atomic.potato
struct Geometry {
    int pad0;
    int pad4;
    int field8;
    int padC;
    int field10;
    int field14;
};

void sub_005b45f0(Geometry* self, int* a, int* b)
{
    int* p = (int*)self;
    int* q = (int*)b;
    int i = 0;
    do {
        int* r;
        if (i == 0) {
            r = (int*)a;
        } else {
            r = (int*)b;
        }
        int v = p[i + 2];
        int w = *r;
        if (v == p[2]) {
            p[4] = w;
        } else {
            p[5] = w;
        }
        r[1] = r[1] + 1;
        i = i + 1;
        *r = (int)p;
    } while (i < 2);
}

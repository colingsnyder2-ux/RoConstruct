// from server: 8% by atomic.potato
struct Mesh {
    char pad0[4];
    int field4;
    int field8;
    void sub_4e6d80(int);
    void sub_4e58e0(int a, char b);
};

struct Edge {
    int a;
    int b;
    int c;
    int d;
    Edge();
};

extern "C" int __cdecl sub_5fe630(Edge*);

extern int dword_B7DD28;
extern int dword_B7DD2C;
extern float flt_9B2690;
extern float flt_9B27B0;
extern float flt_9B1624;

void Mesh::sub_4e58e0(int a, char b) {
    int saved = field4;
    field4 = a;
    int i = field4;
    while (i < saved) {
        i++;
    }
    if (!(dword_B7DD2C & 1)) {
        dword_B7DD2C |= 1;
        int v = 10;
        if (v < 2) v = 2;
        dword_B7DD28 = v;
    }
    if (field4 > field8) {
        if (field8 == 0) {
            field8 = a;
            sub_4e6d80(saved);
        } else {
            if (field4 < dword_B7DD28) {
                field8 = dword_B7DD28;
            } else {
                float f = flt_9B2690;
                int sz = field8 << 4;
                if (sz > 0x61a80) {
                    f = flt_9B27B0;
                } else if (sz > 0xfa00) {
                    f = flt_9B1624;
                }
                int diff = field4 - field8;
                int add = (int)((float)field8 * f);
                field8 = diff + add;
                if (field8 < dword_B7DD28) {
                    field8 = dword_B7DD28;
                }
            }
            sub_4e6d80(saved);
        }
    } else {
        int q = field8 / 3;
        if (field4 <= q && b != 0 && field4 > dword_B7DD28) {
            int m = field4;
            int n = (m < saved) ? saved : m;
            sub_4e6d80(n);
        }
    }
    int j = saved;
    while (j < field4) {
        Edge* e = (Edge*)((char*)this + (j << 4));
        if (e) {
            sub_5fe630(e);
        }
        j++;
    }
}

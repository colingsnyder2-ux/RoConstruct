// from server: 47% by atomic.potato
extern "C" int __stdcall sub_9EA510(int, int);
extern "C" int __stdcall sub_7920B0(void*, void*, int, int);
extern "C" int __stdcall sub_7920E0(void*, void*, int, int);
extern "C" int __stdcall sub_792170(void*, int);
extern "C" int __stdcall sub_792000(int);

extern int G_a53f34;
extern int G_a53f54;

struct S {
    char pad0[0x14];
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    char pad28[0x14];
    char field3c;
    int f(int, int, int);
};

int S::f(int a, int b, int c)
{
    int* self = (int*)this;
    int* p = (int*)*self;
    if ((p[9] & 1) == 0) {
        p[9] |= 1;
        p = (int*)*self;
        int v = p[5];
        p[7] = v;
        p[8] = v;
    }
    p = (int*)*self;
    int state = (p[9] >> 2) & 1;
    state = ~state & 1;
    state |= 4;
    int start = a;
    int end = a + b;
    int* p20 = p + 8;
    int* p1c = p + 7;
    int* p14 = p + 5;
    int* p18 = p + 6;
    int result;
    for (;;) {
        int cur = *p1c;
        int lim = *p20;
        if (cur == lim && state == 4) {
            goto check6;
        }
        {
            int* base = (int*)*self;
            int tmp = cur;
            sub_7920B0(base, p14, cur, lim);
            int r = sub_792170(base, G_a53f54);
            sub_7920E0(base, p18, 0, 0);
            sub_792000(r);
            *p1c = tmp;
            if (r == G_a53f34) {
                result = start - a;
                if (result == 0) {
                    return -1;
                }
                return result;
            }
        }
        start = end;
        end = a + b;
    check6:
        if (state == 6) {
            if (*p1c == *p20) {
                result = start - a;
                return result;
            }
        }
        if (start == end) {
            result = start - a;
            return result;
        }
        if (state == 5) {
            p = (int*)*self;
            int v1 = p[5];
            int v2 = p[6];
            int r = sub_9EA510(v1, v2);
            int ec;
            if (r != 0) {
                ec = r;
            } else {
                ec = (this->field3c & 1) ? 0 : -1;
            }
            p = (int*)*self;
            if (ec == -1) {
                state = 4;
                p[9] |= 4;
                continue;
            }
            p[7] = v1;
            p[8] = v1 + ec;
            p = (int*)*self;
            state = (ec != p[6]) ? 6 : 5;
            continue;
        }
    }
}

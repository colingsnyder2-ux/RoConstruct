// from server: 0% by atomic.potato
struct E { int v[3]; };

struct Vec {
    E* begin;
    E* end;
    E* cap;
    char pad[8];
};

struct S {
    char pad0[8];
    Vec v;
    void insert(E* pos, unsigned int n, E* first, E* last);
};

extern "C" void __cdecl sub_423df0();
extern "C" void __cdecl sub_7a799a(void*);
extern "C" E* __cdecl sub_8ee8a0(unsigned int, int);
extern "C" void __cdecl sub_8f3640(E*, E*, E*, E*, int, int);
extern "C" void __cdecl sub_8f6750();

void S::insert(E* pos, unsigned int n, E* first, E* last)
{
    unsigned int cur = (unsigned int)((v.end - v.begin) / 3);
    if (n == 0) return;
    unsigned int cap = (unsigned int)((v.cap - v.begin) / 3);
    if (0x4924924u - cap < n) {
        sub_423df0();
    }
    if (cur >= n) {
        unsigned int half = cur >> 1;
        unsigned int newcap;
        if (0x4924924u - half < cur) {
            newcap = 0;
        } else {
            newcap = cur + half;
        }
        if (newcap < n) newcap = n;
        E* p = sub_8ee8a0(newcap, 0);
        unsigned int off = (unsigned int)((pos - v.begin) / 3);
        sub_8f6750();
        sub_8f3640(v.begin, p + off * 3, p + off * 3, p + (off + n) * 3, 0, 0);
        sub_8f3640(p + (off + n) * 3, v.end, p + (off + n) * 3, p + (off + n) * 3, 0, 0);
        unsigned int cnt = (unsigned int)((v.end - v.begin) / 3);
        if (v.begin) sub_7a799a(v.begin);
        v.cap = p + newcap * 3;
        v.end = p + (cnt + n) * 3;
        v.begin = p;
    } else {
        sub_8f6750();
        sub_8f3640(v.begin, pos, pos, v.end, 0, 0);
        sub_8f3640(pos, v.end, pos + n * 3, v.end, 0, 0);
        unsigned int cnt = (unsigned int)((v.end - v.begin) / 3);
        if (v.begin) sub_7a799a(v.begin);
        v.cap = v.begin + (cnt + n) * 3;
        v.end = v.begin + (cnt + n) * 3;
        v.begin = v.begin;
    }
}

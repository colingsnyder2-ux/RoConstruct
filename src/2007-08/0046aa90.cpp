// from server: 26% by TrollStein
struct E {
    int v[16];
};

struct Vec {
    E* begin;
    E* end;
    E* cap;
};

struct S {
    Vec v;
    void __cdecl f(int, int, int);
};

extern "C" void __cdecl sub_46A600(void*, int);
extern "C" void __cdecl sub_46A710(void*, int, int);
extern "C" void __cdecl sub_46A770(void*, void*, int, void*, void*, void*, int);
extern "C" void __cdecl sub_46A900(void*, void*, void*, void*);
extern "C" void __cdecl sub_46AA00(void*, int, void*, int);
extern "C" void __cdecl sub_417800();
extern "C" void __cdecl sub_62FC62(void*);

void S::f(int a, int b, int c)
{
    char tmp[0x54];
    sub_46A600(tmp, c);

    E* p = v.begin;
    int n = 0;
    if (p == 0)
        n = (int)((v.end - p) >> 6);

    if (b != 0) {
        int cap = 0;
        if (p != 0)
            cap = (int)((v.cap - p) >> 6);

        if ((0x3ffffff - cap) < b)
            sub_417800();

        int used = 0;
        if (p != 0)
            used = (int)((v.cap - p) >> 6);

        int need = used + b;
        if (n < need) {
            int newcap = n + (n >> 1);
            if ((0x3ffffff - (n >> 1)) < n)
                newcap = 0;
            else
                newcap = n + (n >> 1);

            int used2 = 0;
            if (p != 0)
                used2 = (int)((v.cap - p) >> 6);
            int need2 = used2 + b;
            if (newcap < need2) {
                int used3 = 0;
                if (p != 0)
                    used3 = (int)((v.cap - p) >> 6);
                newcap = used3 + b;
            }

            E* newelems = 0;
            sub_46A710(&newelems, newcap, 0);

            E* oldbegin = v.begin;
            char flag = 0;
            E* res = 0;
            sub_46A770(&res, oldbegin, a, &newelems, &flag, &flag, 0);
            sub_46AA00(&res, b, &tmp, 0);

            E* oldend = v.end;
            char flag2 = 0;
            E* res2 = 0;
            sub_46A770(&res2, oldend, a, &newelems, &flag2, &flag2, 0);

            E* oldbegin2 = v.begin;
            int cnt = 0;
            if (oldbegin2 != 0)
                cnt = (int)((v.end - oldbegin2) >> 6);
            b += cnt;

            if (oldbegin2 != 0) {
                char flag3 = 0;
                sub_46A900(oldbegin2, v.end, &newelems, &flag3);
                sub_62FC62(v.begin);
            }

            v.cap = newelems + newcap;
            v.end = newelems + b;
            v.begin = newelems;
        }
    }
}

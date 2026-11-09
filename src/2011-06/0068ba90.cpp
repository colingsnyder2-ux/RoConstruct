// from server: 35% by atomic.potato
struct Elem {
    char pad[0x18];
};

struct S {
};

extern "C" void __cdecl sub_68A7C0(Elem*, Elem*, int, int);
extern "C" void __cdecl sub_68A830(Elem*, Elem*, int);
extern "C" void __cdecl sub_68AEB0(Elem*, Elem*, Elem**);
extern "C" void __cdecl sub_68B050(Elem*, Elem*);

void __cdecl f(Elem* first, Elem* last, int n)
{
    int count = (int)((last - first)) / 0x18;
    if (count > 0x20) {
        if (n > 0) {
            Elem* mid;
            sub_68AEB0(first, last, &mid);
            int half = n / 2;
            int quarter = half / 2;
            int step = half + quarter;
            Elem* p = first + step;
            int c1 = (int)((p - first)) / 0x18;
            int c2 = (int)((last - p)) / 0x18;
            if (c2 < c1) {
                f(p, last, n - step);
                last = p;
            } else {
                f(first, p, step);
                first = p;
            }
            count = (int)((last - first)) / 0x18;
            if (count > 0x20)
                goto again;
        }
    }
    if (count > 1)
        sub_68A830(first, last, 0);
    return;
again:
    if (count > 1)
        sub_68A7C0(first, last, 0, 0);
    sub_68B050(first, last);
}

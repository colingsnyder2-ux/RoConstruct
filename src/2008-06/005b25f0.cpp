// from server: 100% by king_originala
extern "C" int __cdecl sub_4898d0(int);
extern "C" int __cdecl sub_495eb0(int, int);

struct Args {
    int unused;
    int first;
    int second;
};

struct S {
    char padding[0x154];
    int state;

    void f(Args*);
    void sub_5b2510(int, int);
    void sub_55acc0(Args*);
    void sub_5b10a0();
};

void S::f(Args* p)
{
    int first = sub_4898d0(p->first);
    int second = sub_4898d0(p->second);

    if (first) {
        if ((unsigned char)sub_495eb0(first, 1))
            sub_5b2510(0, first);
        else
            state = 0;
    }

    sub_55acc0(p);

    if (second && (unsigned char)sub_495eb0(second, 1))
        sub_5b10a0();
}

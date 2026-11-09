// from server: 100% by king_originala
extern int __cdecl sub_495eb0(int, int);
extern int __cdecl sub_495e80(int, int);
extern double __cdecl sub_508410();

struct S {
    char padding[0x1d0];
    double timestamp;

    void sub_4944b0(int);
    void sub_4924e0();
    void sub_494650();
    void sub_494740(int, int);
};

void S::sub_494740(int a, int b)
{
    if (a && (unsigned char)sub_495eb0(a, 1))
        sub_4944b0(0);

    if (b && (unsigned char)sub_495e80(b, 1))
        sub_4924e0();

    if (!a && (unsigned char)sub_495e80(b, 1)) {
        timestamp = sub_508410();
        sub_494650();
    }
}

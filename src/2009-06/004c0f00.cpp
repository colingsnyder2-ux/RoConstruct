// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern bool __cdecl sub_4c3f80(int, int);
extern bool __cdecl sub_4c3f50(int, int);
struct Time {
    double sec;
    Time() : sec(0) {}
    static Time now();
};
struct S {
    char padding[0xe0];
    Time timestamp;

    void sub_4c0be0(int);
    void sub_4bfe10();
    void sub_4c0df0();
    void sub_4c0f00(int, int);
};

void S::sub_4c0f00(int a, int b)
{
    if (a && sub_4c3f80(a, 1))
        sub_4c0be0(0);

    if (b && sub_4c3f50(b, 1))
        sub_4bfe10();

    if (!a && sub_4c3f50(b, 1)) {
        timestamp = Time::now();
        sub_4c0df0();
    }
}

// from server: 100% by colin
struct RakPeer {
    char pad0[0x80];
    char flag80;
    char pad1[0x3];
    char field84[0x40];
    char fieldC4[0x10];
    char fieldD4[0x10];
    char fieldE4[0x10];
    char fieldF4[0x10];
    char field104[0x10];
    char field114[0x10];
    char field124[0x10];
    void method(int, int);
};

extern "C" void __cdecl sub_4C09C0(
    int, int,
    void*, void*,
    void*, void*,
    void*, void*,
    void*, void*);

void RakPeer::method(int a, int b) {
    if (flag80 != 0) {
        sub_4C09C0(
            b, a,
            field84, fieldC4,
            fieldF4, field124,
            fieldD4, fieldE4,
            field104, field114);
    }
}

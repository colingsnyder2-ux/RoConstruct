// from server: 100% by colin
struct CXTPDefaultTheme {
    char pad[0xf4];
    int field0;
};

extern "C" int __stdcall sub_6420c0(int, int);

int __stdcall sub_6b9ef0(int *out, CXTPDefaultTheme *theme) {
    if (theme->field0 == 2) {
        out[0] = 3;
        out[1] = 3;
        out[2] = 3;
        out[3] = 3;
        return (int)out;
    }
    sub_6420c0((int)out, (int)theme);
    return (int)out;
}

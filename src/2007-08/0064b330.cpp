// from server: 100% by colin
struct CXTPImageManagerIcon {
    int sub_6496B0(int, int, int, int, int);
    int func(int, int, int, int);
};

extern "C" int __stdcall sub_630478(int, int);

int CXTPImageManagerIcon::func(int a, int b, int c, int d) {
    int result;
    if (d != 0) {
        result = sub_630478(a, 0xe);
        if (result != 0) {
            return sub_6496B0(result, a, b, c, 1);
        }
    }
    result = sub_630478(a, 3);
    if (result != 0) {
        return sub_6496B0(result, a, b, c, 0);
    }
    return 0;
}

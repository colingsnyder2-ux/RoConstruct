// from server: 100% by atomic.potato
struct CXTPImageManagerIconSet {
    int sub_80CDF0(int, int, int, int, int);

    int sub_80D7D0(int a, int b, int c, int d);
};

extern "C" int __stdcall sub_7F41DE(int, int);

int CXTPImageManagerIconSet::sub_80D7D0(int a, int b, int c, int d) {
    int v;
    if (d != 0) {
        v = sub_7F41DE(a, 0xe);
        if (v != 0) {
            return sub_80CDF0(v, a, b, c, 1);
        }
    }
    v = sub_7F41DE(a, 3);
    if (v != 0) {
        return sub_80CDF0(v, a, b, c, 0);
    }
    return 0;
}

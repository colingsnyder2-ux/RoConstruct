// from server: 100% by colin
struct CXTPImageManagerIconSet {
    void sub_64C960(int);
    void sub_648740();
    void sub_648760();
    void sub_648780();
    void sub_648730();
    void func(int);
};

void CXTPImageManagerIconSet::func(int n) {
    if (n == 1) {
        sub_64C960(n);
        return;
    }
    if (n == 2) {
        sub_648740();
        return;
    }
    if (n == 3) {
        sub_648760();
        return;
    }
    if (n == 4) {
        sub_648780();
        return;
    }
    sub_648730();
}

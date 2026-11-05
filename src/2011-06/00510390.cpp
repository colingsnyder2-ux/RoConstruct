// from server: 100% by atomic.potato
struct S {
    void helper();
    bool func();
};

bool S::func() {
    helper();
    return true;
}

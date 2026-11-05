// from server: 48% by atomic.potato
struct CXTPControls {
    int sub_838240(int, int);
    void sub_9267c0(void*);

    int sub_8383b0(int a, int b, int c);
};

int CXTPControls::sub_8383b0(int a, int b, int c) {
    int r = this->sub_838240(b, c);
    if (r) {
        this->sub_9267c0(this);
        return 1;
    }
    return 0;
}

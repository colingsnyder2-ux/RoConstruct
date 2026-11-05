// from server: 50% by atomic.potato
struct VFrame {
    void sub_76d3c0(float*, int, int);
    void func(int, int);
};

void VFrame::func(int a, int b) {
    float v[4] = {0.0f};
    sub_76d3c0(v, a, b);
}

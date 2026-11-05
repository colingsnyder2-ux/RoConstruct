// from server: 27% by atomic.potato
struct X_006a77a0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_006a77a0* base();
};

struct X_005f2580 {
    void f();
};

struct ImageButton {
    char pad_0[0xa8];
    X_005f2580 field_a8;
    void destroy();
};

void ImageButton::destroy() {
    field_a8.f();
    ((X_006a77a0*)this)->base();
}

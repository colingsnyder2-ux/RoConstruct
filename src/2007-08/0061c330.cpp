// from server: 100% by colin
struct S {
    static float* f();
};

float* S::f() {
    static int init = 0;
    static float values[3];
    if (!(init & 1)) {
        init |= 1;
        values[0] = *(float*)0x7c428c;
        values[1] = *(float*)0x7c4288;
        values[2] = *(float*)0x7c4284;
    }
    return values;
}

// from server: 31% by atomic.potato
struct RBX_006d8ad0 {
    char pad_0[0xb0];
    float f_b0;
    float get();
};

float RBX_006d8ad0::get() {
    float v = f_b0;
    float hi = *(float*)0xa46280;
    if (hi < v) {
        float lo = *(float*)0xa46278;
        if (v < lo) {
            return v;
        }
    }
    return hi;
}

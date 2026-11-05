// from server: 35% by atomic.potato
struct RBX_006d8a50 {
    char pad_0[0xa8];
    float f_a8;
    float get();
};

float RBX_006d8a50::get() {
    float v = f_a8;
    if (v > *(float*)0xa0c640) {
        if (v < *(float*)0xa4627c) {
            return v;
        }
    }
    return *(float*)0xa0c640;
}

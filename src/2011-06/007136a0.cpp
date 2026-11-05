// from server: 23% by atomic.potato
struct EventDesc {
    char pad_0[0xa4];
    float f_a4;
    float get() const;
};

float EventDesc::get() const {
    float lo = *(float*)0xa6ec60;
    float hi = *(float*)0xaaf0ac;
    if (lo < f_a4) {
        if (f_a4 < hi)
            return f_a4;
        return hi;
    }
    return lo;
}

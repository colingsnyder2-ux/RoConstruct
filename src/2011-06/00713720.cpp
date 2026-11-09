// from server: 35% by atomic.potato
struct EventDesc_00713720 {
    char pad_0[0xac];
    float f_ac;
    float get();
};

float EventDesc_00713720::get() {
    float v = f_ac;
    if (v < *(float*)0xaab060) {
        if (v < *(float*)0xaaf0a8) {
            return v;
        }
        return *(float*)0xaab060;
    }
    return *(float*)0xaab060;
}

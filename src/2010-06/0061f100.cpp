// from server: 63% by atomic.potato
struct seg_00610000 {
    void get_61f090(float *out);
    void get_61f100(float *out);
};

void seg_00610000::get_61f100(float *out) {
    float tmp[4];
    get_61f090(tmp);
    out[0] = tmp[0];
    out[1] = tmp[1];
    out[2] = tmp[2];
}

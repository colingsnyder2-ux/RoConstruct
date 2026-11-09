// from server: 40% by atomic.potato
struct Mat {
    float m[16];
};

void __stdcall func_008ab202(Mat* dst, const Mat* a, const Mat* b) {
    Mat tmp;
    Mat* out = dst;
    if (dst == a || dst == b) {
        out = &tmp;
    }
    out->m[0] = a->m[3]*b->m[12] + a->m[0]*b->m[0] + a->m[2]*b->m[8] + b->m[4]*a->m[1];
    out->m[1] = a->m[1]*b->m[5] + a->m[3]*b->m[13] + a->m[2]*b->m[9] + b->m[1]*a->m[0];
    out->m[2] = a->m[3]*b->m[14] + b->m[2]*a->m[0] + a->m[2]*b->m[10] + b->m[6]*a->m[1];
    out->m[3] = a->m[3]*b->m[15] + b->m[11]*a->m[2] + b->m[3]*a->m[0] + b->m[7]*a->m[1];
    out->m[4] = a->m[7]*b->m[12] + a->m[4]*b->m[0] + b->m[4]*a->m[5] + a->m[6]*b->m[8];
    out->m[5] = a->m[6]*b->m[9] + a->m[7]*b->m[13] + b->m[5]*a->m[5] + b->m[1]*a->m[4];
    out->m[6] = b->m[6]*a->m[5] + a->m[7]*b->m[14] + b->m[2]*a->m[4] + a->m[6]*b->m[10];
    out->m[7] = b->m[7]*a->m[5] + a->m[7]*b->m[15] + b->m[3]*a->m[4] + a->m[6]*b->m[11];
    out->m[8] = a->m[11]*b->m[12] + a->m[8]*b->m[0] + b->m[4]*a->m[9] + a->m[10]*b->m[8];
    out->m[9] = a->m[11]*b->m[13] + a->m[10]*b->m[9] + b->m[5]*a->m[9] + b->m[1]*a->m[8];
    out->m[10] = b->m[6]*a->m[9] + b->m[2]*a->m[8] + a->m[11]*b->m[14] + a->m[10]*b->m[10];
    out->m[11] = b->m[7]*a->m[9] + a->m[11]*b->m[15] + b->m[3]*a->m[8] + a->m[10]*b->m[11];
    out->m[12] = a->m[15]*b->m[12] + a->m[14]*b->m[8] + a->m[12]*b->m[0] + b->m[4]*a->m[13];
    out->m[13] = a->m[15]*b->m[13] + b->m[5]*a->m[13] + a->m[14]*b->m[9] + b->m[1]*a->m[12];
    out->m[14] = b->m[6]*a->m[13] + a->m[14]*b->m[10] + b->m[2]*a->m[12] + a->m[15]*b->m[14];
    out->m[15] = a->m[15]*b->m[15] + b->m[7]*a->m[13] + b->m[3]*a->m[12] + a->m[14]*b->m[11];
    if (out != dst) {
        for (int i = 0; i < 16; ++i) {
            dst->m[i] = out->m[i];
        }
    }
}

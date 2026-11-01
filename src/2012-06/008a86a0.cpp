// from server: 81% by Intel
struct Block {
    void __stdcall func(float* out, const float* src, int index);
};

void __stdcall Block::func(float* out, const float* src, int index) {
    out[0] = 0.0f;
    out[1] = 0.0f;

    if (index > 5)
        return;

    switch (index) {
    case 0:
        out[0] = src[1];
        out[1] = src[2];
        break;
    case 1:
        out[0] = src[2];
        out[1] = src[0];
        break;
    case 2:
        out[0] = src[0];
        out[1] = src[1];
        break;
    case 3:
        out[0] = src[2];
        out[1] = src[1];
        break;
    case 4:
        out[0] = src[0];
        out[1] = src[2];
        break;
    case 5:
        out[0] = src[1];
        out[1] = src[0];
        break;
    }
}

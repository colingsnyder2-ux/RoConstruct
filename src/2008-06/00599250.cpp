// from server: 100% by colin
struct VPartInstance {
    int type;
    void getPos0(float* out);
    void getPos1(float* out);
    void getPos2(float* out);
    void getPos3(float* out);
    void getPos4(float* out);
    void getPos5(float* out);
    void getPos6(float* out);
    void compute(float* out);
};

void VPartInstance::compute(float* out)
{
    float v[8];
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    v[4] = 0.0f;
    v[5] = 0.0f;
    v[6] = 0.0f;

    switch (type) {
    case 0: getPos0(v); break;
    case 1: getPos1(v); break;
    case 2: getPos2(v); break;
    case 3: getPos3(v); break;
    case 4: getPos4(v); break;
    case 5: getPos5(v); break;
    case 6: getPos6(v); break;
    }

    out[0] = v[4];
    out[1] = v[5];
    out[2] = v[6];
}

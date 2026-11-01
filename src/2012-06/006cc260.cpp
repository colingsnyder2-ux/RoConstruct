// from server: 20% by Intel
struct RelativePanel {
    void func_006cc260(float a2, float a3, float* a4);
};

void RelativePanel::func_006cc260(float a2, float a3, float* a4) {
    float v10[2];
    v10[0] = a2;
    v10[1] = a3;

    float v14[2];
    ((void(__thiscall*)(RelativePanel*, float*))(*(int**)this)[0x5c / 4])(this, v10);

    float v18[2];
    v18[0] = v14[0];
    v18[1] = v14[1];

    float v1C[2];
    ((void(__thiscall*)(RelativePanel*, float*))(*(int**)this)[0x70 / 4])(this, v18);

    float v20 = v1C[0];
    float v24 = v1C[1];

    float v28 = v20 + v14[0];
    float v2C = v24 + v18[1];

    float zero = 0.0f;
    a4[0] = zero;
    a4[1] = zero;
    a4[2] = zero;
    a4[3] = zero;

    float* v30;
    if (v28 > v14[0]) v30 = &v28; else v30 = &v20;
    a4[0] = *v30;

    float* v34;
    if (v2C > v18[1]) v34 = &v2C; else v34 = &v24;
    a4[2] = *v34;

    float* v38;
    if (v14[0] > v28) v38 = &v14[0]; else v38 = &v20;
    a4[1] = *v38;

    float* v3C;
    if (v18[1] > v2C) v3C = &v18[1]; else v3C = &v24;
    a4[3] = *v3C;
}

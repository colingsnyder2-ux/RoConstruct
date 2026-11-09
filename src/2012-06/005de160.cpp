// from server: 35% by Intel
struct BeveledBlockBuilder {
    float m_data[0x10];
    int build(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

int BeveledBlockBuilder::build(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
    int v1 = a1 << 4;
    int v2 = v1 - a1;
    int v3 = a2 << 4;
    int v4 = v3 - a2;
    float* v5 = (float*)a3;
    float* v6 = v5 + v2;
    float* v7 = v5 + v4;
    *v7 = v6[0];
    v7[1] = v6[1];
    v7[2] = v6[2];
    v7[3] = v6[3];
    v7[4] = v6[4];
    int v8 = a4 << 4;
    int v9 = v8 - a4;
    float* v10 = v5 + v9;
    v7[5] = v10[0];
    v7[6] = v10[1];
    v7[7] = v10[2];
    v7[8] = v10[3];
    v7[9] = v10[4];
    int v11 = a2 + 2;
    int v12 = v11 << 4;
    int v13 = v12 - v11;
    float* v14 = v5 + v13;
    v7[15] = v14[0];
    v7[16] = v14[1];
    v7[17] = v14[2];
    v7[18] = v14[3];
    v7[19] = v14[4];
    float* v15 = (float*)a5;
    v7[0] = v15[0] + v6[0];
    v7[1] = v15[1] + v6[1];
    v7[2] = v15[2] + v6[2];
    float* v16 = (float*)a6;
    v7[33] = v16[0] + v6[3];
    v7[34] = v16[1] + v6[4];
    int v17 = a7 + 3;
    int v18 = v17 << 4;
    int v19 = v18 - v17;
    float* v20 = v5 + v19;
    v20[0] = v15[0] + v10[0];
    v20[1] = v15[1] + v10[1];
    v20[2] = v15[2] + v10[2];
    v20[3] = v10[3] + v16[0];
    v20[4] = v10[4] + v16[1];
    float* v21 = (float*)a8;
    v7[48] = v21[0] + v10[3];
    v7[49] = v21[1] + v10[4];
    float* v22 = v7 + 8;
    float v23 = 0.0f;
    for (int i = 0; i < 4; ++i) {
        v22[-3] = v23;
        v22[-2] = v23;
        v22[-1] = ((float*)a7)[0];
        v22[0] = ((float*)a7)[1];
        v22[1] = ((float*)a7)[2];
        v22[2] = ((float*)a8)[0];
        v22[3] = ((float*)a8)[1];
        v22[4] = ((float*)a8)[2];
        v22[5] = 0;
        v22 += 15;
    }
    return 4;
}

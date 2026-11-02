// from server: 95% by Intel
struct BeveledBlockBuilder {
    int v0;
    int v4;
    int v8;
    int vC;
    int v10;
    int v14;
    int v18;
    float v1C;
    float v20;
    float v24;
    char v28;
    char v29;
    char v2A;
    char v2B;
    char v2C;
    BeveledBlockBuilder* __stdcall copyFrom(BeveledBlockBuilder* src);
};

BeveledBlockBuilder* __stdcall BeveledBlockBuilder::copyFrom(BeveledBlockBuilder* src) {
    v0 = src->v0;
    v4 = src->v4;
    v8 = src->v8;
    vC = src->vC;
    v10 = src->v10;
    v14 = src->v14;
    v18 = src->v18;
    v1C = src->v1C;
    v20 = src->v20;
    v24 = src->v24;
    v28 = src->v28;
    v29 = src->v29;
    v2A = src->v2A;
    v2B = src->v2B;
    v2C = src->v2C;
    return this;
}

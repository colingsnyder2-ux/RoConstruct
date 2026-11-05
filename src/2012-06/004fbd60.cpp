// from server: 33% by Intel
struct UTMeshGen {
    void __cdecl copyVertices(float* dest, const float* src, const float* end);
};

void UTMeshGen::copyVertices(float* dest, const float* src, const float* end) {
    if (src == end)
        return;

    float* d = dest + 5;
    const float* s = src + 5;

    do {
        s -= 8;
        d -= 8;

        float v0 = s[0];
        float v1 = s[1];
        float v2 = s[2];
        float v3 = s[3];
        float v4 = s[4];
        float v5 = s[5];
        float v6 = s[6];
        float v7 = s[7];

        d[0] = v0;
        d[1] = v1;
        d[2] = v2;
        d[3] = v3;
        d[4] = v4;
        d[5] = v5;
        d[6] = v6;
        d[7] = v7;
    } while (s != end);
}

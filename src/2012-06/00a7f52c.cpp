// from server: 38% by atomic.potato
struct S {
    char pad0[0xc];
    float x;
    float y;
    float z;
    float w;
};

extern "C" void __stdcall helper();

void func_00a7f52c(S* dst, int stride, S* src, float* mat, unsigned int count) {
    if (count == 0) return;
    do {
        float a = src->x * src->y + mat[0] * mat[4] + src->z * mat[8] + src->w * mat[12];
        float b = src->x * mat[1] + src->y * mat[5] + src->z * mat[9] + src->w * mat[13];
        float c = src->x * mat[2] + src->y * mat[6] + src->z * mat[10] + src->w * mat[14];
        float d = src->x * mat[3] + src->y * mat[7] + src->z * mat[11] + src->w * mat[15];
        dst->x = a;
        dst->y = b;
        dst->z = c;
        dst->w = d;
        dst = (S*)((char*)dst + stride);
        src = (S*)((char*)src + 0xc);
        count--;
    } while (count != 0);
}

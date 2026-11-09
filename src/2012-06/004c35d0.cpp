// from server: 16% by atomic.potato
struct Vec4 { float x, y, z, w; };

struct AdornRbxGfx {
    char pad0[8];
    char flag8;
    char pad9[7];
    void* ptr10;
    char pad14[0x38];
    void* ptr4c;

    void func(Vec4* a1, Vec4* a2, Vec4* a3, Vec4* a4, Vec4* a5);
};

extern "C" int __stdcall getActualHeight(void* vp);

extern "C" void __cdecl sub_4c32b0(Vec4* out, Vec4* in);
extern "C" void __cdecl sub_4dc950(void* a, void* b, ...);

void AdornRbxGfx::func(Vec4* a1, Vec4* a2, Vec4* a3, Vec4* a4, Vec4* a5) {
    Vec4 v10, v14;
    Vec4 v1c, v20, v24, v28;
    Vec4 v2c, v30, v34, v38;

    v20.x = a1->x;
    v20.y = a1->y;
    v20.z = a1->z;
    v20.w = a1->w;

    v10.x = a2->x;
    v10.y = a2->y;

    v1c.x = a3->x;
    v1c.y = a3->y;

    if (a4->x != a1->x || a4->y != a1->y || a4->z != a1->z || a4->w != a1->w) {
        sub_4c32b0(&v1c, a1);
        v1c = v1c;
        v20 = v20;
        if (v10.y != 0.0f || v10.x != 0.0f || v10.x != 1.0f || v10.y != 1.0f) {
            float dx = a1->z - a1->x;
            if (dx != 0.0f) {
                v10.x = (v1c.x - a1->x) / dx + v10.y;
                v10.y = (v1c.z - a1->z) / dx + v10.x;
            }
            float dy = a1->w - a1->y;
            if (dy != 0.0f) {
                v10.y = (v20.y - a1->y) / dy + v10.y;
                v10.x = (v20.w - a1->w) / dy + v10.x;
            }
        }
    } else {
        if (v10.y != 0.0f || v10.x != 0.0f || v10.x != 1.0f || v10.y != 1.0f) {
            float dx = a1->z - a1->x;
            if (dx != 0.0f) {
                v10.x = (v1c.x - a1->x) / dx + v10.y;
                v10.y = (v1c.z - a1->z) / dx + v10.x;
            }
            float dy = a1->w - a1->y;
            if (dy != 0.0f) {
                v10.y = (v20.y - a1->y) / dy + v10.y;
                v10.x = (v20.w - a1->w) / dy + v10.x;
            }
        }
    }

    v2c = *a5;
    v30 = *a5;
    v34 = *a5;
    v38 = *a5;

    char cl = flag8;
    void* p = ptr10;
    int h1 = getActualHeight(*(void**)((char*)p + 0x44));
    int h2 = getActualHeight(*(void**)((char*)ptr10 + 0x44));

    float f1 = v10.x;
    float f2 = v10.y;
    float f3 = v1c.x;
    float f4 = v1c.y;

    sub_4dc950((char*)this + 0x14, &v2c, f1, f2, f3, f4, (float)(h1 - 1) - v2c.x, (float)(h2 - 1) - v2c.y, cl);
}

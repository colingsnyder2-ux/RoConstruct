// from server: 57% by tajop
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
};

extern "C" __m128 _mm_load_ss(float const* a);
extern "C" __m128 _mm_set_ss(float a);
extern "C" __m128 _mm_mul_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ss(__m128 a, __m128 b);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct Vector3 {
    float x, y, z;
    Vector3() {}
};

struct S {
    char pad[0x24];
    Vector3 center;
    Vector3 size;
    Vector3 getMin() const;
};

Vector3 S::getMin() const {
    Vector3 r;
    __m128 half = _mm_set_ss(0.5f);
    __m128 hx = _mm_load_ss(&size.x);
    __m128 hy = _mm_load_ss(&size.y);
    __m128 hz = _mm_load_ss(&size.z);
    hx = _mm_mul_ss(hx, half);
    hy = _mm_mul_ss(hy, half);
    hz = _mm_mul_ss(hz, half);
    __m128 mx = _mm_sub_ss(_mm_load_ss(&center.x), hx);
    __m128 my = _mm_sub_ss(_mm_load_ss(&center.y), hy);
    _mm_store_ss(&r.y, my);
    __m128 mz = _mm_sub_ss(_mm_load_ss(&center.z), hz);
    _mm_store_ss(&r.x, mx);
    _mm_store_ss(&r.z, mz);
    return r;
}

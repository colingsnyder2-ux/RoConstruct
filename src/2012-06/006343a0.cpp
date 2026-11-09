// from server: 67% by tajop
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
};

extern "C" __m128 _mm_load_ss(float const* p);
extern "C" __m128 _mm_sub_ss(__m128 a, __m128 b);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3 operator-(const Vector3& v) const {
        Vector3 r;
        _mm_store_ss(&r.x, _mm_sub_ss(_mm_load_ss(&x), _mm_load_ss(&v.x)));
        _mm_store_ss(&r.y, _mm_sub_ss(_mm_load_ss(&y), _mm_load_ss(&v.y)));
        _mm_store_ss(&r.z, _mm_sub_ss(_mm_load_ss(&z), _mm_load_ss(&v.z)));
        return r;
    }
};

struct LineSegment {
    Vector3 point;
    Vector3 direction;
    LineSegment(const Vector3& _point, const Vector3& _direction) : point(_point), direction(_direction) {}
    virtual ~LineSegment() {}
    static LineSegment fromTwoPoints(const Vector3& point1, const Vector3& point2);
};

LineSegment LineSegment::fromTwoPoints(const Vector3& point1, const Vector3& point2) {
    return LineSegment(point1, point2 - point1);
}

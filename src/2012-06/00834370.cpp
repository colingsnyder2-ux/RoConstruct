// from server: 62% by tajop
struct lua_State;

extern "C" void* lua_newuserdata(lua_State* L, unsigned int size);
extern "C" void lua_getfield(lua_State* L, int idx, const char* k);
extern "C" int lua_setmetatable(lua_State* L, int objindex);

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

extern "C" __m128 _mm_load_ss(float const* p);
extern "C" void _mm_store_ss(float* p, __m128 v);

inline void* operator new(unsigned int, void* p) throw() { return p; }

struct Vector2 {
    float x;
    float y;
    Vector2(const Vector2& o) {
        _mm_store_ss(&x, _mm_load_ss(&o.x));
        _mm_store_ss(&y, _mm_load_ss(&o.y));
    }
};

extern const char* className;

void pushVector2(lua_State* L, const Vector2& value) {
    Vector2 copy(value);
    new (lua_newuserdata(L, sizeof(Vector2))) Vector2(copy);
    lua_getfield(L, -10000, className);
    lua_setmetatable(L, -2);
}

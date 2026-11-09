// from server: 87% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

union __declspec(intrin_type) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    signed char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
};

extern "C" __m128 _mm_setzero_ps(void);
extern "C" void _mm_store_ss(float*, __m128);

struct sp_counted_base {
    void* vtable_;
    long use_count_;
    void add_ref_copy() {
        volatile long* p = &use_count_;
        _InterlockedExchangeAdd(p, 1);
    }
};

struct shared_ptr_any {
    void* px;
    sp_counted_base* pi_;
    void init(const shared_ptr_any& r) {
        px = r.px;
        pi_ = r.pi_;
        if (pi_ != 0) pi_->add_ref_copy();
    }
};

namespace Ogre {

struct RbxMeshPartAdapter {
    int count;
    int zero;
    float value;
    shared_ptr_any first;
    shared_ptr_any second;
    RbxMeshPartAdapter(const shared_ptr_any& a, const shared_ptr_any& b, int c);
    virtual void slot0();
};

RbxMeshPartAdapter::RbxMeshPartAdapter(const shared_ptr_any& a, const shared_ptr_any& b, int c) {
    __m128 z = _mm_setzero_ps();
    count = c;
    zero = 0;
    _mm_store_ss(&value, z);
    first.init(a);
    second.init(b);
}

}

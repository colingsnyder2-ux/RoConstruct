// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is std::vector<float>::_Construct_n(size_type, const float&)
// (VC9 layout: _Myfirst/_Mylast/_Myend at +0xc/+0x10/+0x14).
struct FloatVecHolder {
    int pad[3];
    float* first;
    float* last;
    float* end;
};

extern "C" void fn_004c6d40(void);                        // vector::_Xlen
extern "C" void* fn_00420b50(unsigned count, void* hint); // std::_Allocate<...>

// INFERRED: mirrors std::_Fill_n (scalar path of _Uninit_fill_n)
static inline void Fill_n(float* _First, unsigned _Count, const float& _Val)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}

// INFERRED: mirrors vector::_Ufill
static inline float* Ufill(float* _Ptr, unsigned _Count, const float& _Val)
{
    Fill_n(_Ptr, _Count, _Val);
    return _Ptr + _Count;
}

// INFERRED: mirrors vector::_Buy
static inline bool Buy(FloatVecHolder* self, unsigned _Capacity)
{
    self->first = 0;
    self->last = 0;
    self->end = 0;
    if (_Capacity == 0)
        return false;
    if (0x3fffffff < _Capacity)
        fn_004c6d40();
    self->first = (float*)fn_00420b50(_Capacity, 0);
    self->last = self->first;
    self->end = self->first + _Capacity;
    return true;
}

extern "C" void __fastcall fn_006790b0(FloatVecHolder* self, int unusedEdx, unsigned _Count, const float& _Val)
{
    if (Buy(self, _Count))
        self->last = Ufill(self->first, _Count, _Val);
}

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: object is a class holding a std::vector<float>-like triple
// (first,last,end) at +0x0c, built via vector(size_type n, const float& val).
struct FloatVecHolder {
    char pad[0x0c];
    float* first;
    float* last;
    float* end;
};

extern "C" void fn_004c6d40();                         // vector::_Xlen (throws)
extern "C" float* fn_00420b50(unsigned count, void* hint); // std::_Allocate

extern "C" void __fastcall fn_006790b0(FloatVecHolder* self, int unusedEdx, unsigned n, const float* val)
{
    self->first = 0;
    self->last = 0;
    self->end = 0;
    if (n != 0) {
        if (n > 0x3fffffff)
            fn_004c6d40();
        float* p = fn_00420b50(n, 0);
        self->end = p + n;
        self->first = p;
        self->last = p;
        unsigned c = n;
        float* d = p;
        if (c != 0) {
            do {
                *d = *val;
                --c;
                ++d;
            } while (c != 0);
        }
        self->last = p + n;
    }
}

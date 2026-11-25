// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// Minimal local stand-in for G3D::Vector4 (g3d-6.09); layout x,y,z,w floats.
struct Vector4 {
    float x, y, z, w;
};

// INFERRED: MSVCP90 exports _Inf as a data object (imported via pointer at 0x8024ac);
// the first member of the _Dconst union is the double infinity value.
extern "C" __declspec(dllimport) const double _Inf;

// INFERRED: the vendor object was built with /fp:fast; approximate it with float_control.
#pragma float_control(precise, off, push)

// Shared function-static guard/value (guard at 0x96f020, value at 0x96f018), inlined four times.
static inline double g3dInf() {
    static double i = _Inf;
    return i;
}

// INFERRED: G3D Vector4::operator/=(float) - multiplies by 1/k, or sets all components to inf when k == 0.
extern "C" Vector4* __fastcall fn_007baf50(Vector4* self, int unusedEdx, float k)
{
    if (k != 0.0f) {
        float r = 1.0f / k;
        self->x *= r;
        self->y *= r;
        self->z *= r;
        self->w *= r;
    } else {
        self->x = (float)g3dInf();
        self->y = (float)g3dInf();
        self->z = (float)g3dInf();
        self->w = (float)g3dInf();
    }
    return self;
}

#pragma float_control(pop)

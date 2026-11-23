// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace G3D { const double& inf(); }

// INFERRED: 8-byte iterator pair (ConvexHull-like container iterator)
struct Fn5529b0Iter { int a; int b; };

extern "C" Fn5529b0Iter* __fastcall fn_00540660(void* self, int unusedEdx, Fn5529b0Iter* out);
extern "C" Fn5529b0Iter* __fastcall fn_00540630(void* self, int unusedEdx, Fn5529b0Iter* out);
extern "C" void* __fastcall fn_00541180(Fn5529b0Iter* it);
extern "C" void __fastcall fn_00541160(Fn5529b0Iter* it);
extern "C" bool __fastcall fn_00540f20(Fn5529b0Iter* it, int unusedEdx, Fn5529b0Iter* other);
extern "C" float __fastcall fn_00552e00(void* self, int unusedEdx, int a1);

extern "C" void* __fastcall fn_005529b0(char* self, int unusedEdx, int arg)
{
    void* result = 0;
    float best = (float)G3D::inf();
    Fn5529b0Iter tmp;
    Fn5529b0Iter end = *fn_00540660(self + 8, 0, &tmp);
    Fn5529b0Iter it;
    fn_00540630(self + 8, 0, &it);
    for (;; fn_00541160(&it)) {
        if (!fn_00540f20(&it, 0, &end))
            break;
        float d = fn_00552e00(fn_00541180(&it), 0, arg);
        if (best > d) {
            result = fn_00541180(&it);
            best = d;
        }
    }
    return result;
}

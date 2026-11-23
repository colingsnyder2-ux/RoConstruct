// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: constants at 0x82d038 and 0x84e800 unknown; placeholders.
extern const double kScale;
extern const double kFixedScale;

// INFERRED: layout from offsets only; self+0 is a 128-entry int width table,
// 0x134 fixed width, 0x200 baseW, 0x204 baseH.
extern "C" void __fastcall fn_00684640(char* self, int unusedEdx, float* out,
                                       std::string* str, double scale, int fixedWidth)
{
    int baseW = *(int*)(self + 0x200);
    int baseH = *(int*)(self + 0x204);
    double s = scale * kScale;
    double ratio = (double)baseW / ((double)baseW * s / baseH);
    double total = 0.0;
    int n = (int)str->size();

    if (!fixedWidth) {
        for (int i = 0; i < n; ++i)
            total += (double)((int*)self)[(*str)[i] & 0x7f] * ratio;
        out[0] = (float)total;
        out[1] = (float)s;
    } else {
        int w = *(int*)(self + 0x134) * n;
        out[0] = (float)(ratio * (double)w * kFixedScale);
        out[1] = (float)s;
    }
}

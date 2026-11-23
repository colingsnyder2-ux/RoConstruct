// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: font layout from offsets only: char widths at +0, cell size at +0x200/+0x204
struct FontObj {
    int widths[128];
    int cellW;
    int cellH;
};

// INFERRED: arg meanings guessed from the disassembly
extern "C" void __fastcall fn_006843f0(FontObj* self, int unusedEdx,
    float* out, const std::string* text, double x, double y,
    double scaleW, double scaleH, int mono, float* quads)
{
    double sx = scaleW / self->cellW;
    double sy = scaleH / self->cellH;
    float v = (float)(self->widths[0x4D] * 0.5f * sy);
    unsigned n = (unsigned)text->size();
    for (unsigned i = 0; i < n; i++) {
        unsigned char c = (*text)[i] & 0x7f;
        if (c != 0x20) {
            int row = c >> 4;
            int col = c & 0xf;
            double xx = x;
            if (!mono)
                xx = x * (self->cellW - self->widths[c]) * sx;
            quads[0] = (float)(self->cellW * col);
            quads[1] = (float)(self->cellH * row + 1);
            quads[2] = (float)xx;
            quads[3] = (float)(xx + sx);
            quads[4] = (float)(self->cellW * (col + 1) - 1);
            quads[5] = (float)(self->cellH * (row + 1) - 2);
            quads[6] = v;
            quads += 16;
        }
        if (!mono)
            x += self->widths[c] * sx;
        else
            x += sx;
    }
    out[0] = (float)x;
    out[1] = (float)y;
}

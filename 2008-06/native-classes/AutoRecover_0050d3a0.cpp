// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout from the disassembly; [+4] is a 32-bit element buffer and [+8] is the row stride.
struct Grid2D {
    int pad0;
    int* data;
    int stride;
};

extern "C" void fn_0050d3a0(Grid2D* g, int x, int y, int value)
{
    g->data[g->stride * y + x] = value;
}

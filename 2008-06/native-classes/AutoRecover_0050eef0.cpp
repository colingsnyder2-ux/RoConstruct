// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: approximate recovery. Layout and arg roles come from the disassembly, not a compile. It was not diffed against the original.
namespace G3D {
struct System {
    static void free(void* p);
    static void* calloc(unsigned m, unsigned n);
};
struct GImage {
    void* vtbl;
    unsigned char* data;
    int width;
    int height;
    int channels;
    static bool pasteSubImage(GImage& dst, const GImage& src, int dx, int dy, int sx, int sy, int w, int h);
};
}
using namespace G3D;

extern "C" int __fastcall fn_0050e280(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
extern "C" void fn_0050d3c0(unsigned char* out, unsigned int a, unsigned int b, float t);

// INFERRED: vtable of the scratch image class (address 0x0081975c in the original exe)
extern "C" char g_0081975c[];

// INFERRED: scratch square image (vtable, w, h, 4 channels, calloc'd data)
struct ScratchSquare {
    void* vtbl;
    int w, h, ch;
    int* data;
};

extern "C" void fn_0050eef0(GImage* src, int x, int y, int w, int h, int angle, int p6, int p7, int p8)
{
    int n = (h > w ? h : w) + 1;
    ScratchSquare sq;
    sq.vtbl = (void*)g_0081975c;
    System::free(0);
    sq.w = n;
    sq.h = n;
    sq.ch = 4;
    sq.data = (int*)System::calloc(n * n * 4, 1);

    if (angle == 0) {
        GImage::pasteSubImage(*(GImage*)&sq, *src, 0, n - h, x, y, w, h);
    } else if (angle == 90 || angle == -90) {
        fn_0050e280(&sq, 0, 0, n - w, x, y, w, h, angle, 0, 0);
        int t = h; h = w; w = t;
    } else if (angle == 180 && src->channels == 4) {
        for (int j = 0; j < w; ++j)
            for (int i = 0; i < h; ++i)
                sq.data[(n - h + i) * n + j] =
                    ((int*)src->data)[(y + i) * src->width + x + j];
    }

    int rows = n - h;
    int tl = sq.data[rows * n];
    int last = n - 1;
    int br = sq.data[last * n + w - 1];
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < n; ++c)
            sq.data[r * n + c] = tl;
    for (int r = last; r >= w; --r)
        sq.data[last * n + r] = br;

    fn_0050d3c0(&sq, 0, tl, br, 0, 0);

    for (int r = 1; r < n; ++r)
        for (int c = 0; c < last; ++c)
            sq.data[r * n + c] = br;

    for (int r = n - 1; r > 0; --r)
        for (int c = 1; c < w; ++c) {
            float f = 1.0f - (float)c / (float)w;
            sq.data[r * n + c] = fn_0050d3c0(&sq, 0, tl, br, *(int*)&f, 0);
        }

    if (angle == 0) {
        GImage::pasteSubImage(*src, *(GImage*)&sq, x, y, 0, rows, w, h);
    } else if (angle == 90 || angle == -90) {
        fn_0050e280(src, 0, x, y, 0, rows, w, h, -angle, 0, 0);
    } else if (angle == 180 && src->channels == 4) {
        for (int j = 0; j < w; ++j)
            for (int i = 0; i < h; ++i)
                ((int*)src->data)[(y + i) * src->width + x + j] =
                    sq.data[(rows + i) * n + j];
    }
    System::free(sq.data);
}

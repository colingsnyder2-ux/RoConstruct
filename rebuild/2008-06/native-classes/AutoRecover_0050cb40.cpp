// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <exception>

// INFERRED: minimal libjpeg 6b decompress struct layout; only fields this function touches.
struct jpeg_decompress_struct_min {
    struct Err { void* pad[2]; } *err;   // +0x00
    struct Mem { void* a; void* b; unsigned char** (__cdecl *alloc_sarray)(void*, int, unsigned, unsigned); } *mem; // +0x04
    char pad0[0x58 - 8];
    unsigned output_height_dummy;         // +0x58 (image_height region)
    char pad1[0x68 - 0x5C];
    unsigned output_width;                // +0x68
    unsigned output_height;               // +0x6c
    unsigned output_components;           // +0x70 (placeholder)
    char pad2[0x1b0 - 0x74];
};

struct GImageMin { int vtbl_pad; unsigned char* _byte; int width; int height; int channels; };
struct BinaryInputMin;

extern "C" void* __cdecl fn_0051eb40(void* err);
extern "C" void  __cdecl fn_0051e280(void* cinfo, int version, int size);
extern "C" void  __cdecl fn_0050ad20(void* cinfo, unsigned char* data, int len);
extern "C" int   __cdecl fn_0051e700(void* cinfo, int require_image);
extern "C" int   __cdecl fn_0051e8f0(void* cinfo);
extern "C" void* __cdecl fn_00508530(unsigned size);
extern "C" unsigned __cdecl fn_0051e850(void* cinfo, unsigned char** rows, unsigned n);
extern "C" int   __cdecl fn_0051e630(void* cinfo);
extern "C" int   __cdecl fn_0051e380(int a1);
extern "C" std::string* __fastcall fn_0050aa30(BinaryInputMin* self, int unusedEdx, std::string* out);
extern "C" void  __fastcall fn_004728b0(void* self, int unusedEdx, const std::string* a, const std::string* b);

extern "C" void __fastcall fn_0050cb40(GImageMin* self, int unusedEdx, BinaryInputMin* input)
{
    // INFERRED: this is GImage::decodeJPEG; BinaryInput layout (length +0x34/+0x38, data +0x40) from disassembly.
    char* in = (char*)input;
    jpeg_decompress_struct_min cinfo;
    char errmgr[0x80];
    int row = 0;

    self->channels = 3;
    cinfo.err = (jpeg_decompress_struct_min::Err*)fn_0051eb40(errmgr);
    fn_0051e280(&cinfo, 62, 0x1b0);

    unsigned hi = *(unsigned*)(in + 0x34);
    int len = *(int*)(in + 0x38);
    if (hi != 0) {
        throw std::exception("Cannot getCArray for a huge file");
    }
    fn_0050ad20(&cinfo, *(unsigned char**)(in + 0x40), len);
    fn_0051e700(&cinfo, 1);
    fn_0051e8f0(&cinfo);

    self->width = cinfo.output_width;
    self->height = cinfo.output_height;
    self->_byte = (unsigned char*)fn_00508530(cinfo.output_height * cinfo.output_width * 3);

    int rowStride = cinfo.output_components * cinfo.output_height;
    unsigned char** buffer = cinfo.mem->alloc_sarray(&cinfo, 1, rowStride, 1);

    while (cinfo.output_width < cinfo.output_height) {
        switch (cinfo.output_components) {
        case 1: {
            fn_0051e850(&cinfo, buffer, 1);
            unsigned char* d = self->_byte + row * 3;
            unsigned char* e = d + self->width * 3;
            unsigned char* s = buffer[0];
            for (; d < e; d += 3, ++s) { d[0] = *s; d[1] = *s; d[2] = *s; }
            break;
        }
        case 3: {
            unsigned char* rows[1] = { self->_byte + row };
            fn_0051e850(&cinfo, rows, 1);
            break;
        }
        case 4: {
            fn_0051e850(&cinfo, buffer, 1);
            unsigned char* d = self->_byte + row * 3;
            unsigned char* e = d + self->width * 3;
            unsigned char* s = buffer[0];
            for (; d < e; d += 3, s += 4) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
            break;
        }
        default: {
            std::string msg("Unexpected number6 of channels.");
            std::string fname;
            fn_0050aa30(input, 0, &fname);
            char err[0x40];
            fn_004728b0(err, 0, &msg, &fname);
            throw err;
        }
        }
        row += rowStride;
    }

    fn_0051e630(&cinfo);
    fn_0051e380((int)&cinfo);
}

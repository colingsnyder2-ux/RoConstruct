// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the disassembly is truncated at 0x5f0445, so this draft covers only the
// prologue, the cache check, the format detection and the first image setup.
// The signature, the argument layout and the GImage handling are guesses.
#include <string>

bool isCachedFileCurrent(const std::string& cachedFile, const std::string& sourceFile);

extern "C" int __fastcall fn_0050e260(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0050e280(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
extern "C" int fn_0050ad90(int a1, int a2, int a3, int a4);

// INFERRED: opaque stand-in for G3D::GImage; layout is not known from the visible code
struct GImageOpaque {
    void* vtbl;
    int pad[8];
    int width;
    int height;
};

extern "C" int fn_005ef840(std::string* outPath, const std::string& cachedFile, const std::string& sourceFile)
{
    // INFERRED: arg order and meaning from the stack offsets
    std::string key = sourceFile + "0xdecafbad";
    if (isCachedFileCurrent(key, cachedFile)) {
        new (outPath) std::string(key);
        return 1;
    }
    // The remaining body is not visible. It detects the format from the mime type
    // (png/jpeg/tga/bmp), loads a GImage, and if it is 585x559 builds a 408x408 RGBA
    // image from many pasteSubImage and rotated-copy calls (fn_0050e280).
    return 0;
}

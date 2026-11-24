// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

struct Texture;

// INFERRED: resolveMapPath(const char*) returns std::string by value (hidden return pointer, cdecl)
extern "C" std::string fn_0055d0b0(const char* path);
// INFERRED: texture loaders take a context, the resolved path, and a flag
extern "C" Texture* fn_00551920(void* ctx, const std::string& path, int flag);
extern "C" Texture* fn_00551a30(void* ctx, const std::string& path);
// ReferenceCountedPointer<Texture>::setPointer
extern "C" void __fastcall fn_00598fa0(Texture** self, int unusedEdx, Texture* p);

struct SurfaceTextures {
    Texture* surfacesStrip;
    Texture* surfaces;
    Texture* johnTex;
    Texture* unused; // INFERRED: zeroed 4th slot

    SurfaceTextures* init(void* ctx);
};

extern "C" SurfaceTextures* __fastcall fn_004f0920(SurfaceTextures* self, int unusedEdx, void* ctx)
{
    self->surfacesStrip = 0;
    self->surfaces = 0;
    self->johnTex = 0;
    self->unused = 0;

    fn_00598fa0(&self->surfaces, 0, fn_00551920(ctx, fn_0055d0b0("textures\\surfaces.png"), 1));
    fn_00598fa0(&self->johnTex, 0, fn_00551920(ctx, fn_0055d0b0("textures\\JohnTex.png"), 0));
    fn_00598fa0(&self->surfacesStrip, 0, fn_00551a30(ctx, fn_0055d0b0("textures\\SurfacesStrip.png")));
    return self;
}

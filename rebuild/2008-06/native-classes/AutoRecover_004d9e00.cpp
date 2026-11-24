// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: partial draft. The disassembly was truncated at 0x4da584, so the tail after the '.raw' append is guessed.
#include <string>

// INFERRED: ContentId = string followed by a Name pointer at +0x1c.
struct ContentIdLike : std::string {
    const void* name;
};

struct SkyFace {
    std::string path;
    const void* name;
};

struct ServiceProviderLike;
struct ContentProviderLike;
struct SkyOwner {
    char pad[0x14];
    ServiceProviderLike* serviceProvider; // +0x14
};

extern "C" int __fastcall fn_004b3870(void* self, int unusedEdx);
extern "C" const void* fn_00554270();                 // Name::getNullName
extern "C" ContentIdLike* fn_0055bd80(ContentIdLike* out, const char* s); // ContentId::fromAssets
extern "C" ContentProviderLike* __fastcall fn_0041eea0(ServiceProviderLike* sp, int unusedEdx); // create<ContentProvider>
extern "C" std::string* __fastcall fn_00561e30(ContentProviderLike* cp, int unusedEdx, std::string* out, const SkyFace* id); // getFile
extern "C" int fn_0050edb0(const std::string& path); // GImage::resolveFormat
extern "C" void fn_0055d0b0(std::string* out, const char* s); // LDraw2Lua::resolveMapPath

static const char* const kFormatExt[8] = { ".raw", ".raw", ".raw", ".raw", ".raw", ".raw", ".raw", ".raw" }; // INFERRED

static ContentProviderLike* getCP(SkyOwner* self)
{
    return self->serviceProvider ? fn_0041eea0(self->serviceProvider, 0) : 0;
}

extern "C" void __fastcall fn_004d9e00(SkyOwner* self, int unusedEdx, int arg1)
{
    std::string files[6];
    char* sky = 0;
    if (self->serviceProvider)
        sky = (char*)(size_t)fn_004b3870(self->serviceProvider, 0);

    SkyFace faces[6];
    for (int i = 0; i < 6; ++i)
        faces[i].name = fn_00554270();

    static const char* const names[6] = {
        "Sky\\null_plainsky512_up.jpg", "Sky\\null_plainsky512_lf.jpg",
        "Sky\\null_plainsky512_rt.jpg", "Sky\\null_plainsky512_bk.jpg",
        "Sky\\null_plainsky512_ft.jpg", "Sky\\null_plainsky512_dn.jpg"
    };
    static const int offs[6] = { 0x130, 0x150, 0x170, 0x190, 0x1b0, 0x1d0 };

    char* skyObj = sky ? *(char**)(sky + 0x2d4) : 0;
    if (!skyObj) {
        for (int i = 0; i < 6; ++i) {
            ContentIdLike tmp;
            ContentIdLike* c = fn_0055bd80(&tmp, names[i]);
            faces[i].path = *c;
            faces[i].name = c->name;
        }
    } else {
        for (int i = 0; i < 6; ++i) {
            ContentIdLike* c = (ContentIdLike*)(skyObj + offs[i]);
            faces[i].path = *c;
            faces[i].name = c->name;
        }
    }

    // INFERRED: order of getFile calls follows the disassembly (dn, bk... pairs by face).
    static const int order[6] = { 5, 3, 1, 2, 4, 0 };
    for (int i = 0; i < 6; ++i) {
        SkyFace id = faces[order[i]];
        std::string tmp;
        files[i] = *fn_00561e30(getCP(self), 0, &tmp, &id);
    }

    std::string dir, base;
    // Ogre::StringUtil::splitFilename(files[0], dir, base) is an rgmain import; omitted here.
    if (dir.find(".raw", 0, 1) == std::string::npos) {
        int fmt = fn_0050edb0(files[0]);
        std::string ext;
        if (fmt >= 0 && fmt < 8)
            ext = std::string(".raw") + kFormatExt[fmt];
        else
            ext = ".raw";
        // INFERRED: remaining tail (map path resolution) not visible in the truncated disassembly.
        static const int rorder[6] = { 4, 5, 3, 2, 0, 1 };
        for (int i = 0; i < 6; ++i) {
            std::string tmp;
            fn_0055d0b0(&tmp, names[rorder[i]]);
            files[i] = tmp;
        }
    }
}

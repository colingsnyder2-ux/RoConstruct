// from server: 27% by colin
// roc 2007-08 0046ffc0  unit: g3d-6.09/GLG3Dcpp/Texture.cpp  size: 402 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046ffc0

typedef unsigned int size_t_;

namespace std {
    template<class T> class allocator;
    template<class C, class Tr, class A> class basic_string;
    typedef basic_string<char, char, allocator<char> > string;
}

extern "C" {
    __declspec(dllimport) void __stdcall __std_string_ctor_PBD(void* self, const char* s);
    __declspec(dllimport) void __stdcall __std_string_dtor(void* self);
    __declspec(dllimport) void __stdcall __std_string_assign(void* self, const void* other);
    __declspec(dllimport) unsigned int __stdcall __std_string_rfind(void* self, const char* s, unsigned int pos, unsigned int n);
    __declspec(dllimport) void __stdcall __std_string_substr(void* ret, void* self, unsigned int pos, unsigned int n);
}

struct G3DString {
    char buf[16];
    unsigned int len;
    unsigned int cap;
};

struct G3DTexture {
    char pad[0x14];
    unsigned int width;
};

extern "C" void __stdcall G3D_throwError(const char* msg);
extern "C" void __stdcall G3D_throwError2(const char* msg, const char* file, int line);

struct G3DTextureSet {
    void loadCubeMap(G3DTexture* tex, G3DString* outName, G3DString* outName2);
};

void G3DTextureSet::loadCubeMap(G3DTexture* tex, G3DString* outName, G3DString* outName2)
{
    G3DString pattern;
    __std_string_ctor_PBD(&pattern, "Cube map filenames must contain \"*\" as a placeholder for up/lf/rt/bk/ft/dn");

    unsigned int pos = __std_string_rfind(&pattern, "*", 0, 1);
    if (pos == 0xffffffff) {
        G3DString msg;
        __std_string_ctor_PBD(&msg, "Cube map filenames must contain \"*\" as a placeholder for up/lf/rt/bk/ft/dn");
        G3D_throwError2((const char*)&msg, "glGetError() != GL_INVALID_OPERATION", 0);
        __std_string_dtor(&msg);
    }

    G3DString part1;
    __std_string_substr(&part1, &pattern, 0, pos);
    __std_string_assign(outName, &part1);
    __std_string_dtor(&part1);

    unsigned int rest = tex->width - pos - 1;
    G3DString part2;
    __std_string_substr(&part2, &pattern, pos + 1, rest);
    __std_string_assign(outName2, &part2);
    __std_string_dtor(&part2);

    __std_string_dtor(&pattern);
}

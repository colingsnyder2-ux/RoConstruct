// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

extern "C" __declspec(dllimport) void __stdcall glDeleteTextures(int, const unsigned int*);
extern "C" unsigned int g_0096ef44;

namespace G3D {

// INFERRED: Base layout and destructor behavior from vtable writes.
class ReferenceCountedObject {
public:
    virtual void referenceCountedMethod();
    ~ReferenceCountedObject() {}
    char data[8];
};

// INFERRED: Texture layout from member offsets.
class Texture : public ReferenceCountedObject {
public:
    unsigned int textureID;
    char data[0x2c];
    std::string name;

    unsigned int sizeInMemory() const;

    __forceinline virtual ~Texture() {
        g_0096ef44 -= sizeInMemory();
        glDeleteTextures(1, &textureID);
        textureID = 0;
    }
};

}

extern "C" void __fastcall fn_00473980(G3D::Texture* self, int unusedEdx) {
    self->G3D::Texture::~Texture();
}

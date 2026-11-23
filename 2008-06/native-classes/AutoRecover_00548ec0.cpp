// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: minimal local G3D declarations; no native header include path known for G3D
namespace G3D {
class VAR {
public:
    bool valid() const;
};
class RenderDevice {
public:
    void beginIndexedPrimitives();
    void setVertexArray(const VAR& v);
    void setTexCoordArray(unsigned int unit, const VAR& v);
};
}

extern "C" int fn_00548cb0();

// INFERRED: globals at 0x9738a1 / 0x9738d0 / 0x973940 / 0x973960 / 0x973908, named by address
extern unsigned char g_9738a1;
extern G3D::VAR g_9738d0;
extern G3D::VAR g_973940;
extern G3D::VAR g_973960;
extern G3D::VAR g_973908;

extern "C" void fn_00548ec0(G3D::RenderDevice* rd, bool useTex0, bool useTex2)
{
    fn_00548cb0();
    if (g_9738a1) {
        return;
    }
    rd->beginIndexedPrimitives();
    if (g_9738d0.valid()) {
        rd->setVertexArray(g_9738d0);
    }
    if (g_973940.valid()) {
        rd->setVertexArray(g_973940);
    }
    if (useTex0 && g_973960.valid()) {
        rd->setTexCoordArray(0, g_973960);
    }
    if (useTex2 && g_973908.valid()) {
        rd->setTexCoordArray(2, g_973908);
    }
}

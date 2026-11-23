// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace G3D {
class RenderDevice {
public:
    void endIndexedPrimitives();
};
}

// INFERRED: global byte flag at 0x009738a1, name invented
extern "C" unsigned char g_flag_009738a1;

extern "C" void fn_00549030(G3D::RenderDevice* device)
{
    if (g_flag_009738a1 == 0) {
        device->endIndexedPrimitives();
    }
}

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available, so the layouts below are minimal
// local reconstructions. The G3D types are declared locally to avoid
// guessing an include path.
namespace G3D {
class CoordinateFrame;
class RenderDevice {
public:
    void setObjectToWorldMatrix(const CoordinateFrame& cf);
    void setPolygonOffset(double offset);
};
}

// INFERRED: object at item+0x34 with a virtual call at vtable slot 11 (+0x2c)
struct RenderableObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void render(G3D::RenderDevice* rd);
};

// INFERRED: element layout; the CoordinateFrame sits at offset 0
struct RenderItem {
    char frame[0x34];
    RenderableObj* object;   // +0x34
    float polygonOffset;     // +0x38
    void* extra;             // +0x3c
};

// The disassembly shows the caller cleaning the stack (add esp, 8), so this
// is cdecl. That overrides the __thiscall guess in the task description.
extern "C" int fn_00548fe0(void* a, G3D::RenderDevice* rd);

// INFERRED: owner class with a pointer array at +0x274 and a count at +0x278
struct RenderListOwner {
    char pad[0x274];
    RenderItem** items;
    int count;
};

extern "C" void __fastcall fn_00502370(RenderListOwner* self, int unusedEdx, G3D::RenderDevice* rd)
{
    for (int i = self->count - 1; i >= 0; --i) {
        RenderItem* item = self->items[i];
        rd->setObjectToWorldMatrix(*reinterpret_cast<const G3D::CoordinateFrame*>(item));
        rd->setPolygonOffset((double)item->polygonOffset);
        item->object->render(rd);
        fn_00548fe0(item->extra, rd);
    }
}

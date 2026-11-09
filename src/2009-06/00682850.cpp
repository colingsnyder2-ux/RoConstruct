// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct SurfaceData {
    int input;
    float paramA;
    float paramB;
    SurfaceData() : input(0), paramA(-0.5f), paramB(0.5f) {}
    static const SurfaceData& empty() { static SurfaceData d; return d; }
};
class Value { public: int get(); };
class Primitive {
public:
    char pad[0xfc];
    int surfaceType[6];
    void setSurfaceType(int face, int type);
};
class PartInstance {
public:
    char pad[0x118];
    Primitive* primitive;
    Primitive* getPrimitive() const { return primitive; }
    void onSurfaceChanged(int face);
    Value* getSurface(int face);
    void raiseSurface(int v);
};
class Surface {
public:
    PartInstance* part;
    int face;
    void setSurfaceInput(int);
    void setParamA(float);
    void setParamB(float);
    void reset();
};
void Surface::reset()
{
    if (part->getPrimitive()->surfaceType[face] != 0) {
        part->getPrimitive()->setSurfaceType(face, 0);
        part->onSurfaceChanged(face);
        PartInstance* p = part;
        p->raiseSurface(p->getSurface(face)->get());
    }
    setSurfaceInput(SurfaceData::empty().input);
    setParamA(SurfaceData::empty().paramA);
    setParamB(SurfaceData::empty().paramB);
}
}

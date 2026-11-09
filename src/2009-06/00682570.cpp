// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
enum NormalId { NORM_X = 0 };
namespace Controller { enum InputType { NO_INPUT = 0 }; }
class SurfaceData {
public:
    SurfaceData() : inputType(Controller::NO_INPUT), paramA(-0.5f), paramB(0.5f) {}
    static const SurfaceData& empty() { static SurfaceData d; return d; }
    Controller::InputType inputType;
    float paramA;
    float paramB;
};
class Primitive {
public:
    const SurfaceData& getSurfaceData(NormalId normalId) const
    {
        return surfaceData[normalId] != 0 ? *surfaceData[normalId] : SurfaceData::empty();
    }
private:
    char pad[0x114];
    SurfaceData* surfaceData[6];
};
template<class T> class scoped_ptr { T* p; public: T* get() const { return p; } };
class PartInstance {
public:
    const Primitive* getPrimitive() const { return primitive.get(); }
private:
    char pad[0x118];
    scoped_ptr<Primitive> primitive;
};
class Surface {
    PartInstance* partInstance;
    NormalId surfId;
public:
    Controller::InputType getInput() const;
};
Controller::InputType Surface::getInput() const
{
    return partInstance->getPrimitive()->getSurfaceData(surfId).inputType;
}
}

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
enum NormalId { NORM_X, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };
class Controller { public: enum InputType { NO_INPUT = 0 }; };
class SurfaceData
{
public:
    Controller::InputType inputType;
    float paramA;
    float paramB;
    __forceinline SurfaceData() : paramA(-0.5f), paramB(0.5f), inputType(Controller::NO_INPUT) {}
    static const SurfaceData& empty()
    {
        static SurfaceData s;
        return s;
    }
};
class Primitive
{
    char pad[0x114];
    SurfaceData* surfaceData[6];
public:
    const SurfaceData& getSurfaceData(NormalId id) const
    {
        if (!surfaceData[id])
            return SurfaceData::empty();
        else
            return *surfaceData[id];
    }
};
class PartInstance
{
    char pad[0x118];
    Primitive* primitive;
public:
    const Primitive* getPrimitive() const { return primitive; }
};
class Surface
{
    PartInstance* partInstance;
    NormalId surfId;
public:
    Controller::InputType getInput() const;
    float getParamA() const;
    float getParamB() const;
};
float Surface::getParamA() const
{
    return partInstance->getPrimitive()->getSurfaceData(surfId).paramA;
}
}

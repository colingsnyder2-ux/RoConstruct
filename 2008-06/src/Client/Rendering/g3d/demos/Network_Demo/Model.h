#ifndef MODEL_H
#define MODEL_H

#include <G3DAll.h>

class Pose {
public:
    Pose();

    double              rotorAngle;
};


typedef ReferenceCountedPointer<class Model> ModelRef;
class Model : public ReferenceCountedObject {
};


typedef ReferenceCountedPointer<class PositionOverride> PositionOverrideRef;
/** Overrides the material and position settings. Used by Helicopter to
    override values set inside posed models so that they can be reused
    without being re-posed. */
class PositionOverride : public Shader {
public:
    GMaterial           material;
    CoordinateFrame     cframe;

    virtual void beforePrimitive (class RenderDevice *renderDevice);

    virtual void afterPrimitive (class RenderDevice *renderDevice);
};


typedef ReferenceCountedPointer<class Helicopter> HelicopterRef;
class Helicopter : public Model {
private:
    
    PosedModelRef             body;
    PosedModelRef             rotor;
    PositionOverrideRef       positionShader;

    Helicopter(const std::string& dataDir);

public:

    static HelicopterRef create(const std::string& dataDir);

    void render(
        RenderDevice*           rd,
        const CoordinateFrame&  cframe, 
        const Pose&             pose, 
        const GMaterial&        material) const;

};

#endif

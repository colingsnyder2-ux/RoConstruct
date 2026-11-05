#ifndef APP_H
#define APP_H

#include <G3DAll.h>
#include "../ArticulatedModel.h"

typedef ReferenceCountedPointer<class Entity> EntityRef;
class Entity : public ReferenceCountedObject {
private:

    Entity() {}

public:

    ArticulatedModelRef         model;

    ArticulatedModel::Pose      pose;

    /** Root frame */
    CoordinateFrame             cframe;

    static EntityRef create(
        ArticulatedModelRef model = NULL,
        const CoordinateFrame& c = CoordinateFrame()) {

        Entity* e = new Entity();

        e->model = model;
        e->cframe = c;
        return e;
    }
};


class App : public GApp {
protected:
    void main();
public:
    SkyRef                      sky;

    LightingParameters          skyParameters;
    LightingRef                 lighting;

    Array<EntityRef>            entityArray;
    TextureRef                  texture;

    App(const GAppSettings& settings);

    void loadScene();

    virtual ~App() {
        entityArray.clear();
    }
};

#endif

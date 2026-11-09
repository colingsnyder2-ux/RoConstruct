#ifndef HEADER_H
#define HEADER_H

#include <G3DAll.h>


class App : public GApp {
public:

    SkyRef              sky;
    TextureRef          textureMap;
    TextureRef          normalBumpMap;
    ShaderRef           bumpShader;

    virtual void main();

    App(const GAppSettings& settings = GAppSettings());
};


typedef ReferenceCountedPointer<class Mesh> MeshRef;

/** Basic geometry with texture parameterization
    and tangent space basis. */
class Mesh : public ReferenceCountedObject {
private:

    static VARAreaRef           varArea;

    VAR                         vertexArray;
    VAR                         tangentArray;
    VAR                         binormalArray;
    VAR                         normalArray;
    VAR                         texCoordArray;

    // For debug vertex lines
    Array<Vector3>              dbgVertexArray;
    Array<Vector3>              dbgBinormalArray;
    Array<Vector3>              dbgTangentArray;
    Array<Vector3>              dbgNormalArray;

    Array<int>                  indexArray;

    Mesh(
        const Array<int>&       index,
        const Array<Vector3>&   vertex,
        const Array<Vector3>&   normal,
        const Array<Vector2>&   tex);
public:

    static MeshRef quad();

    void render(RenderDevice* rd);
};


typedef ReferenceCountedPointer<class Entity> EntityRef;

class Entity : public ReferenceCountedObject {
private:
    Entity(const MeshRef& m, const CoordinateFrame& c);

public:
    MeshRef                 mesh;
    CoordinateFrame         cframe;

    static EntityRef Entity::create(const MeshRef& m, const CoordinateFrame& c = CoordinateFrame());

    void render(RenderDevice* rd);
};


typedef ReferenceCountedPointer<class BumpEffect> BumpEffectRef;



class Viewer : public GApplet {
public: 
    class App*              app;

    Array<EntityRef>        entityArray;
    float                   bumpScale;

    Viewer(App* app);    
    
    virtual ~Viewer() {}

    virtual void onInit();

    virtual void onUserInput(UserInput* ui);

    virtual void onSimulation(RealTime rdt, SimTime sdt, SimTime idt);

    virtual void onGraphics(RenderDevice* rd);
};


#endif

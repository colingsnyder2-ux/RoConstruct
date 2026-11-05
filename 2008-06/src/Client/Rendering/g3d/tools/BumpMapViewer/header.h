
#ifndef HEADER_H
#define HEADER_H

#include <G3DAll.h>

/**
 Set of filenames.  Each is the empty string if it does not exist.
 */
class FileSet {
public:
    std::string     color;
    std::string     alpha;
    std::string     bump;
    std::string     text;
};


class App : public GApp {
public:

    SkyRef              sky;

    Array<FileSet>      fileArray;

    virtual void main();

    /** Returns the set of all files, properly categorized.  Called from main. */
    static void getTextureFilenames(Array<FileSet>& fileArray);

    /** If base exists with any image extension in allFiles, returns the full name.
        Otherwise returns "".  Called from getTextureFilenames. */
    static std::string findFile(const std::string& base, const Set<std::string>& allFiles);

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

/** A material/BumpEffect */
class BumpEffect : public Shader {
private:

    /** Helper function for load */
    static TextureRef loadBumpAsNormalMap(const std::string& filename);

    BumpEffect();

public:

    static BumpEffectRef create();

    /** Current texture map.  Set by load. */
    TextureRef              textureMap;

    /** Bump is in the alpha channel.  Set by load */
    TextureRef              normalMap;

    /** Text description, one line per element. Set by load*/
    Array<std::string>      description;

    /** Set manually to the sky */
    TextureRef              environmentMap;

	Vector4					light;

	float					bumpScale;

    virtual void beforePrimitive(RenderDevice*);
    virtual void afterPrimitive(RenderDevice*);

    /** Load a new texture set */
    void load(const FileSet& f);
};


class Viewer : public GApplet {
public: 

    BumpEffectRef           bumpEffect;

    class App*              app;

    Array<EntityRef>        entityArray;

    Viewer(App* app);    

    virtual void init();

    virtual void doLogic();

    virtual void doSimulation(SimTime dt);

    virtual void doGraphics();

    virtual void cleanup();
};


#endif

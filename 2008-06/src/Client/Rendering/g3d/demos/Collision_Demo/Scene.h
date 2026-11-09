/**
 @file Collision_Demo/Scene.h

 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2003-02-07
 @edited  2003-11-18
 */

#ifndef SCENE_H
#define SCENE_H

#include <G3DAll.h>

/**
 */
class Scene {
//private:
public:    
    /** Static objects */
    Array<class Object*>        object;

    /** Dynamic objects */
    Array<class SimSphere*>     sim;

    SkyRef                      sky;

    TextureRef                  shadowMap;

    /** Draws all objects using current lighting and blending. */
    void renderingPass() const;

    /** Updates the shadow map texture. */
    void generateShadowMap(    
        const class CoordinateFrame& lightViewMatrix) const;

public:

    Scene();

    virtual ~Scene();

    /** Deletes all objects */
    void clear();

    void insertStatic(class Object*);

    /**
     Insert an object to be simulated.
     */
    void insertDynamic(class SimSphere*);

    void simulate(GameTime deltaTime);

    virtual void render(const LightingParameters& lighting) const;

    /** Returns the time until collision with a moving sphere,
        inf if no collision will ever occur.  Only <I>entering</I>
        collisions are detected, not ones where the sphere
        is leaving an object it is trapped inside. */
    virtual GameTime timeUntilCollisionWithMovingSphere(
        const Sphere&       sphere,
        const Vector3&      velocity,
        GameTime            timeLimit,
        Vector3&            outLocation,
        Vector3&            outNormal) const;
};

#endif

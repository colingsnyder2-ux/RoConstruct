/**
 @file Collision_Demo/Object.h

 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2003-02-07
 @edited  2003-02-07
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <G3DAll.h>

/**
 Base class for all static objects in the world.
 */
class Object {
protected:
    Color3                  color;

public:

    Object(const Color3& color);
    virtual ~Object();

    virtual void render() const = 0;

    /** Returns the time until collision with a moving sphere,
        inf if no collision will ever occur.  Only *entering*
        collisions are detected, not ones where the sphere
        is leaving an object it is trapped inside. */
    virtual GameTime timeUntilCollisionWithMovingSphere(
        const Sphere&       sphere,
        const Vector3&      velocity,
        GameTime            timeLimit,
        Vector3&            outLocation,
        Vector3&            outNormal) const = 0;
};

/**
 An object that uses a 3D model.
 */
class GeneralObject : public Object {
private:

    class Model*            model;
    CoordinateFrame         cframe;

public:

    GeneralObject(class Model* _model, const CoordinateFrame& cframe, const Color3& _color);

    virtual void render() const;

    virtual GameTime timeUntilCollisionWithMovingSphere(
        const Sphere&       sphere,
        const Vector3&      velocity,
        GameTime            timeLimit,
        Vector3&            outLocation,
        Vector3&            outNormal) const;
};


class SphereObject : public Object {
protected:

    Sphere                  sphere;

public:

    SphereObject(const Sphere& s, const Color3& _color);

    virtual void render() const;

    virtual GameTime timeUntilCollisionWithMovingSphere(
        const Sphere&       sphere,
        const Vector3&      velocity,
        GameTime            timeLimit,
        Vector3&            outLocation,
        Vector3&            outNormal) const;
};


class CapsuleObject : public Object {
protected:

    Capsule                  capsule;

public:

    CapsuleObject(const Capsule& c, const Color3& _color);

    virtual void render() const;

    virtual GameTime timeUntilCollisionWithMovingSphere(
        const Sphere&       sphere,
        const Vector3&      velocity,
        GameTime            timeLimit,
        Vector3&            outLocation,
        Vector3&            outNormal) const;
};


class BoxObject : public Object  {
private:
    Box                     box;

public:

    BoxObject(const Box& b, const Color3& _color);

    virtual void render() const;

    virtual GameTime timeUntilCollisionWithMovingSphere(
        const Sphere&       sphere,
        const Vector3&      velocity,
        GameTime            timeLimit,
        Vector3&            outLocation,
        Vector3&            outNormal) const;
};


/**
 An object simulated by the system.
 */
class SimSphere : public SphereObject {
public:
// TODO: make private
    friend class Scene;

    Vector3                 velocity;

public:

    SimSphere(const Sphere& s, const Vector3& _velocity, const Color3& _color);
    virtual void render() const;
};

#endif

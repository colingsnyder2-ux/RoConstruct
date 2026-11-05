/**
 @file Collision_Demo/Object.h

 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2003-02-07
 @edited  2004-06-20
 */

#include "Object.h"
#include "Model.h"
extern GApp* app;

void glSpecular() {
    // Material properties
    static const float white[] = {1,1,1,1};
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 16.0f);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}


void glDiffuse() {
    // Material properties
    static const float black[] = {0,0,0,1};
    glMaterialfv(GL_FRONT, GL_SPECULAR, black);
    glMaterialf(GL_FRONT, GL_SHININESS, 0.0f);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}


Object::Object(const Color3& _color) : color(_color) {
}


Object::~Object() {
}


////////////////////////////////////////////////////////////////////////////


GeneralObject::GeneralObject(
    class Model*            _model,
    const CoordinateFrame&  _cframe,
    const Color3&           _color) : Object(_color), model(_model), cframe(_cframe) {
}


void GeneralObject::render() const {
    app->renderDevice->setColor(color);
    app->renderDevice->setObjectToWorldMatrix(cframe);
    glSpecular();
    model->render();
}


GameTime GeneralObject::timeUntilCollisionWithMovingSphere(
    const Sphere&       sphere,
    const Vector3&      velocity,
    GameTime            timeLimit,
    Vector3&            outLocation,
    Vector3&            outNormal) const {

    // Transform the sphere to object space
    Sphere  s(cframe.toObjectSpace(sphere));
    Vector3 v(cframe.vectorToObjectSpace(velocity));

    GameTime t = model->timeUntilCollisionWithMovingSphere(s, v, timeLimit, outLocation, outNormal);

    if (t < inf()) {
        outLocation = cframe.pointToWorldSpace(outLocation);

        // There is no scaling in the coordinate frame, so we can
        // transform the normal using the vector routine.
        outNormal   = cframe.vectorToWorldSpace(outNormal);
    }

    return t;
}


////////////////////////////////////////////////////////////////////////////


SphereObject::SphereObject(const Sphere& s, const Color3& _color) :
     Object(_color), sphere(s) {
}


GameTime SphereObject::timeUntilCollisionWithMovingSphere(
    const Sphere&       movingSphere,
    const Vector3&      velocity,
    GameTime            timeLimit,
    Vector3&            outLocation,
    Vector3&            outNormal) const {

    GameTime t = CollisionDetection::collisionTimeForMovingSphereFixedSphere(movingSphere, velocity, sphere, outLocation, outNormal);

    if (t > timeLimit) {
        return inf();
    } else {
        return t;
    }
}


void SphereObject::render() const {
    glSpecular();
    Draw::sphere(sphere, app->renderDevice, color, Color4::clear());
}


////////////////////////////////////////////////////////////////////////////


CapsuleObject::CapsuleObject(const Capsule& c, const Color3& _color) :
     Object(_color), capsule(c) {
}


GameTime CapsuleObject::timeUntilCollisionWithMovingSphere(
    const Sphere&       movingSphere,
    const Vector3&      velocity,
    GameTime            timeLimit,
    Vector3&            outLocation,
    Vector3&            outNormal) const {

    GameTime t = CollisionDetection::collisionTimeForMovingSphereFixedCapsule(movingSphere, velocity, capsule, outLocation, outNormal);

    if (t > timeLimit) {
        return inf();
    } else {
        return t;
    }
}


void CapsuleObject::render() const {
    glSpecular();
    Draw::capsule(capsule, app->renderDevice, color, Color4::clear());
}

////////////////////////////////////////////////////////////////////////////


BoxObject::BoxObject(const Box& b, const Color3& _color) : Object(_color), box(b) {
}


GameTime BoxObject::timeUntilCollisionWithMovingSphere(
    const Sphere&       sphere,
    const Vector3&      velocity,
    GameTime            timeLimit,
    Vector3&            outLocation,
    Vector3&            outNormal) const {

    GameTime t = CollisionDetection::collisionTimeForMovingSphereFixedBox(sphere, velocity, box, outLocation, outNormal);

    if (fuzzyLe(t, timeLimit)) {
        return t;
    } else {
        return inf();
    }
}


void BoxObject::render() const {

    // TODO: switch to using VAR to radically improve performance.

    // Draw the six faces
    Vector3 v0, v1, v2, v3;

    glDiffuse();
    app->renderDevice->setColor(color);
    app->renderDevice->setObjectToWorldMatrix(CoordinateFrame());
    app->renderDevice->beginPrimitive(RenderDevice::QUADS);
    for (int f = 0; f < 6; ++f) {
        box.getFaceCorners(f, v0, v1, v2, v3);
        app->renderDevice->setNormal((v1 - v0).cross(v3 - v0).direction());
        app->renderDevice->sendVertex(v0);
        app->renderDevice->sendVertex(v1);
        app->renderDevice->sendVertex(v2);
        app->renderDevice->sendVertex(v3);
    }
    app->renderDevice->endPrimitive();

    /* Messes up the shadow map for some reason.
    app->renderDevice->pushState();
        Draw::box(box, app->renderDevice, color, Color4::clear());
    app->renderDevice->popState();
    */
}


////////////////////////////////////////////////////////////////////////////


SimSphere::SimSphere(const Sphere& s, const Vector3& _velocity, const Color3& _color) :
    SphereObject(s, _color), velocity(_velocity) {
}


void SimSphere::render() const {

    SphereObject::render();

}

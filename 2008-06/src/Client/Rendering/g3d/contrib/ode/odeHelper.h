/**
 @file odeHelper.h

 Routines that apply ODE functions to G3D types. 
 See also http://ode.org/ode-latest-userguide.htm

 Copyright 2005-2006, Morgan McGuire
 All rights reserved.
 */
#ifndef G3D_ODEHELPER_H
#define G3D_ODEHELPER_H

#include <g3d/G3D/platform.h>

#ifdef G3D_WIN32
#pragma warning (push)
// pointer truncation
#pragma warning (disable:4311)
// sscanf declared deprecated
#pragma warning (disable:4996)
#endif

#include <g3d/G3D/g3dmath.h>
#include <ode/ode.h>

// Forward declarations
namespace G3D {
    class RenderDevice;
    class Shape;
    class Matrix3;
    class CoordinateFrame;
    class Vector3;
}

/** Used when creating objects that are not in a collision space. */
#define ODE_NO_SPACE 0

void dBodySetPosition(dBodyID b, const G3D::Vector3& v);

void dGeomSetPositionAndRotation(dGeomID id, const G3D::CoordinateFrame& cframe);
void dGeomGetPositionAndRotation(dGeomID id, G3D::CoordinateFrame& cframe);

void dGeomGetPosition(dGeomID id, G3D::Vector3& pos);
void dGeomSetPosition(dGeomID id, const G3D::Vector3& pos);
void dGeomTranslate(dGeomID id, const G3D::Vector3& wsDelta);

void dBodySetPositionAndRotation(dBodyID id, const G3D::CoordinateFrame& cframe);

void dBodyZeroLinearAndAngularVel(dBodyID id);
void dBodySetLinearVel(dBodyID id, const G3D::Vector3& v);
void dBodySetAngularVel(dBodyID id, const G3D::Vector3& v);
void dBodySetLinearAndAngularVel(dBodyID id, const G3D::Vector3& L, const G3D::Vector3& A);

void dBodyGetLinearVel(dBodyID id, G3D::Vector3& v);
void dBodyGetAngularVel(dBodyID id, G3D::Vector3& v);
void dBodyGetLinearAndAngularVel(dBodyID id, G3D::Vector3& L, G3D::Vector3& A);

/** Removes the specified amount from the current velocity */
void dBodyDampVelocity(dBodyID id, float amount);

void dBodyGetPositionAndRotation(dBodyID id, G3D::CoordinateFrame& c);

void dJointSetHingeAnchor(dJointID id, const G3D::Vector3& v);
void dJointSetHingeAxis(dJointID id, const G3D::Vector3& v);
void dJointGetHingeAnchor(dJointID ID, G3D::Vector3& anchor);
void dJointGetHingeAxis(dJointID ID, G3D::Vector3& axis);

void dJointSetUniversalAnchor(dJointID id, const G3D::Vector3& v);
void dJointSetUniversalAxes(dJointID id, const G3D::Vector3& v, const G3D::Vector3& v2);
void dJointGetUniversalAxes(dJointID ID, G3D::Vector3& axis, G3D::Vector3& axis2);

void dJointGetBallAnchor(dJointID ID, G3D::Vector3& anchor);

/** Returns true if these geoms are in the same body or bodies that are connected by a joint. 
    Useful in collision detection.*/
int dAreConnected(dGeomID g1, dGeomID g2);

int dAreConnectedExcluding(dGeomID g1, dGeomID g2, int joint_type);

/** Applies this coordinate frame's world to object transformation. */
void dMassToObjectSpace(dMass *, const G3D::CoordinateFrame& cframe);

/** Applies this coordinate frame's object to world transformation. */
void dMassToWorldSpace(dMass *, const G3D::CoordinateFrame& cframe);

void dMassTranslate (dMass *, const G3D::Vector3& t);
void dMassRotate (dMass *, const G3D::Matrix3& M);

/** Constructs the appropriate mass object from a G3D::Shape. Note that if you have a 
    G3D::ShapeRef or G3D::ShapeRef&, you can pass it in by dereferencing as <code>*s</code>.
    
    Note that the resulting mass will not be centered at the origin; some versions of ODE
    require that geoms have center of mass at the local origin.  If you are using one
    of those versions, you will have to translate the entire object by <code>-m.c</code>.
    */
void dMassSetShapeTotal(dMass* m, float totalMass, const G3D::Shape& s);

dGeomID dCreateBox(dSpaceID space, const G3D::Vector3& extent);

/** Renders all geoms in a space.  For debugging purposes only. 
    Does not support planes, rays, or trimeshes.*/
void debugRenderODEGeoms(G3D::RenderDevice* rd, dSpaceID space);

inline G3D::int32 hashCode(const dGeomID& g) {
    return reinterpret_cast<G3D::int32>(g);
}

inline G3D::int32 hashCode(const dBodyID& g) {
    return reinterpret_cast<G3D::int32>(g);
}

inline G3D::int32 hashCode(const dJointID& g) {
    return reinterpret_cast<G3D::int32>(g);
}
#ifdef G3D_WIN32
#pragma warning (pop)
#endif

#endif // G3D_ODEHELPER_H

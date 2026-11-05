/**
 @file odeHelper.cpp

 Copyright 2005-2006, Morgan McGuire
 All rights reserved.
 */

#include "odeHelper.h"
#include <g3d/G3D/Matrix3.h>
#include <g3d/G3D/Vector3.h>
#include <g3d/G3D/CoordinateFrame.h>
#include <g3d/G3D/Capsule.h>
#include <g3d/G3D/AABox.h>
#include <g3d/G3D/Cylinder.h>
#include <g3d/GLG3D/Shape.h>
#include <g3d/GLG3D/Draw.h>
#include <g3d/GLG3D/RenderDevice.h>

void dMassSetShapeTotal(dMass* m, float totalMass, const G3D::Shape& s) {
    debugAssert(m);

    // Old versions of G3D had type() as const.
    G3D::Shape& nonConstS = const_cast<G3D::Shape&>(s);

    switch (nonConstS.type()) {
    case G3D::Shape::BOX:
        {
            const G3D::Box& box = s.box();
            G3D::Vector3 extent = box.extent();
            dMassSetBoxTotal(m, totalMass, extent.x, extent.y, extent.z);
            dMassToWorldSpace(m, box.localFrame());
            break;
        }

    case G3D::Shape::SPHERE:
        {
            const G3D::Sphere& sphere = s.sphere();
            dMassSetSphereTotal(m, totalMass, sphere.radius);

            // Transform to the correct reference frame
            dMassTranslate(m, sphere.center);
            break;
        }

    case G3D::Shape::CYLINDER:
        {
            const G3D::Cylinder& cylinder = s.cylinder();
            dMassSetCylinderTotal(m, totalMass, 3, cylinder.radius(), cylinder.height());

            // Transform to the correct reference frame
            G3D::CoordinateFrame C;
            C.lookAt(cylinder.getPoint2() - cylinder.getPoint1());
            C.translation += cylinder.center();
            dMassToWorldSpace(m, C);
            break;
        }

    case G3D::Shape::CAPSULE: 
        {
            const G3D::Capsule& capsule = s.capsule();
            dMassSetCappedCylinderTotal(m, totalMass, 3, capsule.getRadius(), capsule.height());

            // Transform to the correct reference frame
            G3D::CoordinateFrame C;
            C.lookAt(capsule.getPoint2() - capsule.getPoint1());
            C.translation += capsule.center();
            dMassToWorldSpace(m, C);
            break;
        }

    case G3D::Shape::PLANE:
    case G3D::Shape::MESH:
    case G3D::Shape::RAY:
        // These have no inherent inertia tensor, so just assign
        // the mass as if it was a sphere.
        dMassSetSphereTotal(m, totalMass, 1);
        break;

    default:
        alwaysAssertM(false, "Unrecognized G3D::Shape in dMassSetShapeTotal.");
    }
}


void dBodyDampVelocity(dBodyID id, float amount) {
	G3D::Vector3 L, A;
	debugAssert(amount >= 0.0f);
	debugAssert(amount <= 1.0f);

	dBodyGetLinearAndAngularVel(id, L, A);
	float x = 1.0f - amount;
	dBodySetLinearAndAngularVel(id, L * x, A * x);
}


void dBodySetPosition(dBodyID b, const G3D::Vector3& v) {
	dBodySetPosition(b, v.x, v.y, v.z);
}


void dGeomGetPosition(dGeomID id, G3D::Vector3& pos) {
    const dReal* v = dGeomGetPosition(id);
    for (int i = 0; i < 3; ++i) {
        pos[i] = static_cast<float>(v[i]);
    }
}


void dGeomSetPosition(dGeomID id, const G3D::Vector3& pos) {
    dGeomSetPosition(id, pos.x, pos.y, pos.z);
}


void dGeomTranslate(dGeomID id, const G3D::Vector3& wsDelta) {
    G3D::Vector3 v;
    dGeomGetPosition(id, v);
    dGeomSetPosition(id, v + wsDelta);
}


static void toODE(const G3D::Matrix3& gM, dMatrix3& oM) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            oM[i * 4 + j] = static_cast<dReal>(gM[i][j]);
        }
        oM[i * 4 + 3] = 0.0;
    }
}


static void toG3D(const dMatrix3& oM, G3D::Matrix3& gM) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            gM[i][j] = static_cast<float>(oM[i * 4 + j]);
        }
    }
}


void dMassToObjectSpace(dMass* m, const G3D::CoordinateFrame& cframe) {
    dMassToWorldSpace(m, cframe.inverse());
}


void dMassToWorldSpace(dMass* m, const G3D::CoordinateFrame& cframe) {
    dMassRotate(m, cframe.rotation);
    dMassTranslate(m, cframe.translation);
}


void dMassTranslate(dMass* m, const G3D::Vector3& t) {
    dMassTranslate(m, t.x, t.y, t.z);
}


void dMassRotate(dMass* m, const G3D::Matrix3& R) {
    dMatrix3 odeR;
    toODE(R, odeR);
    dMassRotate(m, odeR);
}


int dAreConnected(dGeomID g1, dGeomID g2) {
    if ((dGeomGetClass(g1) == dPlaneClass) ||
        (dGeomGetClass(g2) == dPlaneClass)) {
        // Non-placeable; we can't get any information out. 
        // These are only connected if they are the same geom.
        return g1 == g2;
    }

    dBodyID b1 = dGeomGetBody(g1);
    dBodyID b2 = dGeomGetBody(g2);

    if (b1 == b2) {
        return true;
    }

    if ((b1 == 0) || (b2 == 0)) {
        // If one is zero, then they can't be connected
        return false;
    }

    return dAreConnected(b1, b2);
}


int dAreConnectedExcluding(dGeomID g1, dGeomID g2, int joint_type) {
    // We want to ask if two geoms are connected, but ODE only allows
    // connection tests between bodies.  So we have to figure out
    // which bodies contain the geoms.

    if ((dGeomGetClass(g1) == dPlaneClass) ||
        (dGeomGetClass(g2) == dPlaneClass)) {
        // Non-placeable; we can't get any information out. 
        // These are only connected if they are the same geom.
        return g1 == g2;
    }

    dBodyID b1 = dGeomGetBody(g1);
    dBodyID b2 = dGeomGetBody(g2);

    if (b1 == b2) {
        return true;
    }

    if ((b1 == 0) || (b2 == 0)) {
        // If one is zero, then they can't be connected
        return false;
    }

    // Call ODE's are connected function.  
    return dAreConnectedExcluding(b1, b2, joint_type);
}


void dJointGetBallAnchor(dJointID ID, G3D::Vector3& anchor) {
    dReal v[3];
    dJointGetBallAnchor(ID, v);
    anchor.x = v[0];
    anchor.y = v[1];
    anchor.z = v[2];
}


void dJointGetHingeAnchor(dJointID ID, G3D::Vector3& anchor) {
    dReal v[3];
    dJointGetHingeAnchor(ID, v);
    anchor.x = v[0];
    anchor.y = v[1];
    anchor.z = v[2];
}


void dJointGetHingeAxis(dJointID ID, G3D::Vector3& axis) {
    dReal v[3];
    dJointGetHingeAxis(ID, v);
    axis.x = v[0];
    axis.y = v[1];
    axis.z = v[2];
}


void dJointSetHingeAnchor(dJointID id, const G3D::Vector3& v) {
    dJointSetHingeAnchor(id, v.x, v.y, v.z);
}


void dJointSetHingeAxis(dJointID id, const G3D::Vector3& v) {
    dJointSetHingeAxis(id, v.x, v.y, v.z);
}


void dJointSetUniversalAnchor(dJointID id, const G3D::Vector3& v) {
    dJointSetUniversalAnchor(id, v.x, v.y, v.z);
}


void dJointSetUniversalAxes(dJointID id, const G3D::Vector3& v, const G3D::Vector3& v2) {
    dJointSetUniversalAxis1(id, v.x, v.y, v.z);
    dJointSetUniversalAxis2(id, v2.x, v2.y, v2.z);
}


void dJointGetUniversalAxes(dJointID ID, G3D::Vector3& axis, G3D::Vector3& axis2) {
    dReal v[3];
    dJointGetUniversalAxis1(ID, v);
    axis.x = v[0];
    axis.y = v[1];
    axis.z = v[2];
    dJointGetUniversalAxis2(ID, v);
    axis2.x = v[0];
    axis2.y = v[1];
    axis2.z = v[2];
}


void dJointGetUniversalAnchor(dJointID ID, G3D::Vector3& anchor) {
    dReal v[3];
    dJointGetUniversalAnchor(ID, v);
    anchor.x = v[0];
    anchor.y = v[1];
    anchor.z = v[2];
}

void dGeomSetPositionAndRotation(dGeomID id, const G3D::CoordinateFrame& cframe) {
    const G3D::Matrix3& g3dR = cframe.rotation;
    dMatrix3 odeR;
    toODE(g3dR, odeR);

    const G3D::Vector3& c = cframe.translation;

    dGeomSetPosition(id, c.x, c.y, c.z);
    dGeomSetRotation(id, odeR);
}


void dBodySetPositionAndRotation(dBodyID id, const G3D::CoordinateFrame& cframe) {
    const G3D::Matrix3& g3dR = cframe.rotation;
    dMatrix3 odeR;
    toODE(g3dR, odeR);
    
    const G3D::Vector3& c = cframe.translation;

    dBodySetPosition(id, c.x, c.y, c.z);
    dBodySetRotation(id, odeR);
}


void dBodyGetPositionAndRotation(dBodyID id, G3D::CoordinateFrame& c) {

    // dReal may be either single or double
    const dReal* t = dBodyGetPosition(id);
    const dReal* r = dBodyGetRotation(id);    

    for (int i = 0; i < 3; ++i) {
        c.translation[i] = t[i];
        for (int j = 0; j < 3; ++j) {
            c.rotation[i][j] = static_cast<float>(r[i * 4 + j]);
        }
    }
}


void dGeomGetPositionAndRotation(dGeomID id, G3D::CoordinateFrame& c) {

    // dReal may be either single or double
    const dReal* t = dGeomGetPosition(id);
    const dReal* r = dGeomGetRotation(id);    

    for (int i = 0; i < 3; ++i) {
        c.translation[i] = t[i];
        for (int j = 0; j < 3; ++j) {
            c.rotation[i][j] = static_cast<float>(r[i * 4 + j]);
        }
    }
}

void dBodyZeroLinearAndAngularVel(dBodyID id) {
    dBodySetLinearVel(id, 0, 0, 0);
    dBodySetAngularVel(id, 0, 0, 0);
}


void dBodySetLinearVel(dBodyID id, const G3D::Vector3& v) {
    dBodySetLinearVel(id, v.x, v.y, v.z);
}


void dBodySetAngularVel(dBodyID id, const G3D::Vector3& v) {
    dBodySetAngularVel(id, v.x, v.y, v.z);
}


void dBodySetLinearAndAngularVel(dBodyID id, const G3D::Vector3& L, const G3D::Vector3& A) {
    dBodySetLinearVel(id, L.x, L.y, L.z);
    dBodySetAngularVel(id, A.x, A.y, A.z);
}


void dBodyGetLinearVel(dBodyID id, G3D::Vector3& L) {
    // dReal may be either single or double
    const dReal* t = dBodyGetLinearVel(id);

    for (int i = 0; i < 3; ++i) {
        L[i] = static_cast<float>(t[i]);
    }
}


void dBodyGetAngularVel(dBodyID id, G3D::Vector3& A) {
    // dReal may be either single or double
    const dReal* r = dBodyGetAngularVel(id);    

    for (int i = 0; i < 3; ++i) {
        A[i] = static_cast<float>(r[i]);
    }
}


void dBodyGetLinearAndAngularVel(dBodyID id, G3D::Vector3& L, G3D::Vector3& A) {
    // dReal may be either single or double
    const dReal* t = dBodyGetLinearVel(id);
    const dReal* r = dBodyGetAngularVel(id);    

    for (int i = 0; i < 3; ++i) {
        L[i] = static_cast<float>(t[i]);
        A[i] = static_cast<float>(r[i]);
    }
}


dGeomID dCreateBox(dSpaceID space, const G3D::Vector3& extent) {
    return dCreateBox(space, extent.x, extent.y, extent.z);
}


void debugRenderODEGeoms(G3D::RenderDevice* rd, dSpaceID space) {
    int n = dSpaceGetNumGeoms(space);
    static float Z_OFFSET = 0;

    for (int i = 0; i < n; ++i) {
        dGeomID g = dSpaceGetGeom(space, i);
        dVector3 pos;

        if (dGeomGetClass(g) == dPlaneClass) {
            // Not a placeable geom
            continue;
        }

        if (dGeomGetClass (g) != dPlaneClass) {
            memcpy(pos, dGeomGetPosition(g), sizeof(pos));
            pos[2] += Z_OFFSET;
        }

        G3D::CoordinateFrame cframe;
        dGeomGetPositionAndRotation(g, cframe);

        if (dGeomGetClass(g) == dGeomTransformClass) {
            g = dGeomTransformGetGeom(g);
            G3D::CoordinateFrame cframe2; 
            dGeomGetPositionAndRotation(g, cframe2);
            rd->setObjectToWorldMatrix(cframe * cframe2);
        } else {
            rd->setObjectToWorldMatrix(cframe);
        }

        switch (dGeomGetClass (g)) {
        case dSphereClass: 
            {
                G3D::Draw::sphere(G3D::Sphere(G3D::Vector3::zero(), dGeomSphereGetRadius(g)), rd);
                break;
            }

        case dBoxClass: 
            {
                dVector3 sides;
                dGeomBoxGetLengths(g, sides);
                G3D::Vector3 v(sides[0], sides[1], sides[2]);
                G3D::Draw::box(G3D::AABox(-v/2, v/2), rd);
                break;
            }

        case dCCylinderClass: 
            {
                dReal radius, length;
                dGeomCCylinderGetParams(g, &radius, &length);
                G3D::Draw::capsule(G3D::Capsule(G3D::Vector3(0,0,-length/2), G3D::Vector3(0,0,length/2), radius), rd);
                break;
            }

        case dCylinderClass: 
            {
                dReal radius, length;
                dGeomCylinderGetParams(g, &radius, &length);
                G3D::Draw::cylinder(G3D::Cylinder(G3D::Vector3(0,0,-length/2), G3D::Vector3(0,0,length/2), radius), rd);
                break;
            }

        case dPlaneClass: 
            {
                /*
                dVector4 n;
                dMatrix3 R,sides;
                dVector3 pos2;
                dGeomPlaneGetParams (g,n);
                dRFromZAxis (R,n[0],n[1],n[2]);
                for (j=0; j<3; j++) pos[j] = n[j]*n[3];
                pos[2] += Z_OFFSET;
                sides[0] = 2;
                sides[1] = 2;
                sides[2] = 0.001;
                dsSetColor (1,0,1);
                for (j=0; j<3; j++) pos2[j] = pos[j] + 0.1*n[j];
                dsDrawLine (pos,pos2);
                dsSetColorAlpha (1,0,1,0.8);
                dsDrawBox (pos,R,sides);
                */
                break;
            }
        } // switch
    } // for
}

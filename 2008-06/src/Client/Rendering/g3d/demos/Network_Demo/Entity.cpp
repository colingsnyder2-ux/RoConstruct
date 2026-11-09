/**
  @file Network_Demo/Entity.cpp

  @author Morgan McGuire, matrix@graphics3d.com
  @created 2004-03-28
  @edited  2004-10-24
 */

#include "Entity.h"
#include "messages.h"
#include "App.h"

extern App* app;

const RealTime Entity::networkLerpTime = 0.2;

Entity::Entity() : id(NO_ID), oldFrameTime(-inf()), velocity(Vector3::ZERO), oldDesiredVelocityTime(-100), tip(Matrix3::identity()) {
}


void Entity::serialize(BinaryOutput& b) const {
    b.writeInt32(id);
    color.serialize(b);
    b.writeUInt32(modelType);
    frame.serialize(b);
    b.writeString(name);
    velocity.serialize(b);
    controls.serialize(b);
}


void Entity::deserialize(BinaryInput& b) {
    id = b.readInt32();
    color.deserialize(b);
    modelType = (ModelType)b.readUInt32();
    frame.deserialize(b);
    name = b.readString();
    velocity.deserialize(b);
    controls.deserialize(b);
    oldFrameTime = -inf();
}


void Entity::makeStateMessage(class EntityStateMessage& msg) const {
    msg.id       = id;
    msg.frame    = frame;
    msg.velocity = velocity;
    msg.controls = controls;
}


void Entity::clientUpdateFromStateMessage(class EntityStateMessage& msg, Entity::ID localID) {
    debugAssert(id == msg.id);

    // oldDeltaFrame = correct - estimated
    oldDeltaFrame.translation = frame.translation - msg.frame.translation;
    oldDeltaFrame.rotation = frame.rotation * msg.frame.rotation.inverse();
    oldFrameTime = System::getTick();
    frame        = msg.frame;
    velocity     = msg.velocity;
    
    if (localID != id) {
        // Leave the local controls alone
        oldDesiredVelocityTime = oldFrameTime;
        oldDesiredVelocity = currentTiltVelocity;
        controls = msg.controls;
    }
    
}


CoordinateFrame Entity::coordinateFrame() const {
    CoordinateFrame c = frame.toCoordinateFrame();
    c.rotation = c.rotation * tip;
    return c;
}


CoordinateFrame Entity::smoothCoordinateFrame(RealTime now) const {

    // Amount of *old* time to blend in.
    RealTime alpha = clamp(1.0 - (now - oldFrameTime) / networkLerpTime, 0.0, 1.0);

    if (alpha == 0.0) {
        // No lerping necessary; the lerp-period has expired
        CoordinateFrame c = frame.toCoordinateFrame();
        c.rotation = c.rotation * tip;
        return c;
    } else {

        // Compose: position = current + delta*scale;
        PhysicsFrame scaledDelta = PhysicsFrame().lerp(oldDeltaFrame, alpha);
        PhysicsFrame current;
        current.translation = frame.translation + scaledDelta.translation;
        current.rotation = frame.rotation * scaledDelta.rotation;

        CoordinateFrame c = current.toCoordinateFrame();
        c.rotation = c.rotation * tip;
        return c;
    }
}


void Entity::doSimulation(SimTime dt) {
    // The simulation and control scheme for the demo is ridiculous-- it is
    // just for demonstration purposes and needs to be replaced for any
    // reasonable simulator.

    CoordinateFrame cframe = coordinateFrame();
    pose.rotorAngle = wrap(pose.rotorAngle - dt * 20, -G3D_PI * 100, G3D_PI * 100);

    Vector3 acceleration;
    
    for (int i = 0; i < 3; ++i) {
        const double maxAccel = 10;
        double a = controls.desiredVelocity[i] - velocity[i];
        // Obey maximum acceleration and don't overshoot the target velocity
        acceleration[i] = sign(a) * min(G3D::abs(a)/dt, maxAccel);
    }

    velocity = velocity + acceleration * dt;
    frame.translation += velocity;

    double dYaw = controls.desiredYawVelocity * dt;
    frame.rotation = Quat::fromAxisAngleRotation(Vector3::unitY(), dYaw) * frame.rotation;

    // Compute the orientation of the craft based on movement.
    {
        static const RealTime tiltLerpTime = 0.25;

        // World space velocity affecting tilt
        currentTiltVelocity = controls.desiredVelocity;

        double alpha = clamp((System::time() - oldDesiredVelocityTime) / tiltLerpTime, 0.0, 1.0);

        if (alpha < 1.0) {
            // Use cosine interpolation rate
            alpha = (1 - cos(alpha * G3D_PI)) * 0.5;
            currentTiltVelocity = oldDesiredVelocity.lerp(controls.desiredVelocity, alpha); 
        }

        // Object space velocity affecting tilt

        Matrix3 localAxes = frame.rotation.toRotationMatrix();
        double dx =  localAxes.getColumn(0).dot(currentTiltVelocity) * .1;
        double dz =  localAxes.getColumn(2).dot(currentTiltVelocity) * .1;

        Vector3 Y = Vector3(dx, 1.0, dz).direction();
        Vector3 X = (Vector3::unitX() - Y * dx).direction(); 
        Vector3 Z = X.cross(Y);
        tip.setColumn(0, X);
        tip.setColumn(1, Y);
        tip.setColumn(2, Z);
    }
}


////////////////////////////////////////////////////////////////////////

void simulateEntities(EntityTable& entityTable, SimTime dt) {
    EntityTable::Iterator end = entityTable.end();
    for (EntityTable::Iterator e = entityTable.begin(); e != end; ++e) {
        e->value.doSimulation(dt);
    }
}

////////////////////////////////////////////////////////////////////////

Controls::Controls() : desiredYawVelocity(0), desiredVelocity(Vector3::zero()) {
}


void Controls::serialize(BinaryOutput& b) const {
    b.writeFloat32(desiredYawVelocity);
    desiredVelocity.serialize(b);
}


void Controls::deserialize(BinaryInput& b) {
    desiredYawVelocity = b.readFloat32();
    desiredVelocity.deserialize(b);
}

// from server: 28% by colin
// roc 2007-08 0061a790  unit: RBX::ContactConnector  size: 588 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061a790

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Vector4 {
    float x, y, z, w;
    Vector4() {}
    Vector4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};

struct Matrix3 {
    float m[9];
};

struct Body;

struct ContactParams {
    float friction;
    float elasticity;
    float frictionWeight;
    float elasticityWeight;
    float bounceVel;
    float impulseFactor;
};

struct PairParams {
    Vector3 position;
    Vector3 normal;
    float length;
};

struct GeoPair {
    Body* body0;
    Body* body1;
};

struct ContactConnector {
    char pad0[4];
    bool impulseComputed;
    char pad1[3];
    Vector3 contactPoint;
    Vector3 contactNormal;
    float contactLength;
    Vector3 velocityAtPoint;
    Vector3 normal;
    float penetration;
    Vector3 position;
    Vector3 linearVelocity;
    Vector3 angularVelocity;
    float mass;
    Vector3 force;
    Vector3 torque;
    Vector3 impulse;
    float firstApproach;
    float threshold;
    float forceMagLast;
    Vector3 frictionOffset;
    Vector3 deltaVel;
    Vector3 impulsePerUnit;
    float inverseMass;
    float penetrationVelocity;
    float reboundVelocity;
    GeoPair geoPair;
    ContactParams contactParams;
    PairParams oldContactPoint;
    PairParams contactPoint2;

    void updateContactPoint();
    void computeImpulse(float dt);
    void reset();
    void applyContactPointForSymmetryDetection();
    void computeRelativeVelocity();
    void computeOverlap();
    void computeBallPoint();
    void computeBallPlane();
    void computeBallEdge();
    void clearImpulseComputed();
    void getContactParams();
    void getContactPoint();
    void getLengthNormalPosition();
};

extern float g_gravityX;
extern float g_gravityY;
extern float g_gravityZ;
extern float g_scale;
extern float g_dtScale;
extern int g_initialized;

void ContactConnector::updateContactPoint() {
    if (!g_initialized) {
        g_initialized = 1;
        g_gravityX = g_scale;
        g_gravityY = g_scale;
        g_gravityZ = g_scale;
    }
    if (impulseComputed) {
        computeImpulse(0.0f);
    }
    float dt = g_dtScale;
    contactPoint.x *= dt;
    contactPoint.y *= dt;
    contactPoint.z *= dt;
    float f = g_scale;
    Vector3 v;
    v.x = contactNormal.x * f;
    v.y = contactNormal.y * f;
    v.z = contactNormal.z * f;
    v.x += contactPoint.x;
    v.y += contactPoint.y;
    v.z += contactPoint.z;
    contactPoint = v;
    computeRelativeVelocity();
    velocityAtPoint = contactNormal;
    Vector4 q;
    q.x = velocityAtPoint.x;
    q.y = velocityAtPoint.y;
    q.z = velocityAtPoint.z;
    q.w = 0.0f;
    computeOverlap();
    float s = g_scale;
    Vector4 r;
    r.x = contactNormal.x * s;
    r.y = contactNormal.y * s;
    r.z = contactNormal.z * s;
    r.w = contactNormal.x * s;
    float t = g_dtScale;
    r.x *= t;
    r.y *= t;
    r.z *= t;
    r.w *= t;
    normal.x += r.x;
    normal.y += r.y;
    normal.z += r.z;
    normal.x += r.w;
    float len = normal.x * normal.y + normal.x * normal.y + normal.z * normal.z + normal.x * normal.x;
    len = 1.0f / len;
    normal.x *= len;
    normal.y *= len;
    normal.z *= len;
    normal.x *= len;
    computeBallPoint();
    float s2 = g_scale;
    Vector3 u;
    u.x = contactNormal.x * s2;
    u.y = contactNormal.y * s2;
    u.z = contactNormal.z * s2;
    u.x *= g_dtScale;
    u.y *= g_dtScale;
    u.z *= g_dtScale;
    position.x += u.x;
    position.y += u.y;
    position.z += u.z;
    linearVelocity.x += u.x;
    linearVelocity.y += u.y;
    linearVelocity.z += u.z;
    angularVelocity.x = 0.0f;
    angularVelocity.y = 0.0f;
    angularVelocity.z = 0.0f;
    force.x = 0.0f;
    force.y = 0.0f;
    force.z = 0.0f;
    contactPoint.x += g_gravityX;
    contactPoint.y += g_gravityY;
    contactPoint.z += g_gravityZ;
    position.x += g_gravityX;
    position.y += g_gravityY;
    position.z += g_gravityZ;
}

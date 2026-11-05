#include "v8kernel/SimBody.h"
#include <stddef.h>
namespace RBX {
SimBody::SimBody(Body* b) throw():body(b),dt(0.0f),dirty(1),constantForceY(0.0f),force(G3D::Vector3::zero()),torque(G3D::Vector3::zero()),unknownVector9c(G3D::Vector3::zero()),unknownVectorA8(G3D::Vector3::zero()) {}
SimBody::~SimBody() {}
typedef char C0[sizeof(SimBody)==0xb4?1:-1];
typedef char C1[offsetof(SimBody,dt)==4?1:-1];
typedef char C2[offsetof(SimBody,pv)==0xc?1:-1];
typedef char C3[offsetof(SimBody,force)==0x84?1:-1];
typedef char C4[offsetof(SimBody,unknownVector9c)==0x9c?1:-1];
typedef char C5[offsetof(SimBody,unknownVectorA8)==0xa8?1:-1];
}

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#pragma float_control(precise,off,push)
namespace G3D{struct Vector3{float x,y,z;Vector3(){} Vector3(float a,float b,float c):x(a),y(b),z(c){}};}
#include <algorithm>
struct Cofm{char p[0x14];float m;void update();float mass(){update();return m;}};struct SimBody{void accumulateForce(const G3D::Vector3&,const G3D::Vector3&);};struct Link{char prefix[0x34];SimBody*sim;};
struct Body{char prefix[0x2c];Link*link;Cofm*cofm;char gap2[0x60];float mass;float getMass(){return cofm?cofm->mass():mass;}};
struct Primitive{char prefix[0xe4];Body*body;};struct Human{Body* torso();};
G3D::Vector3 scaleBy20(const G3D::Vector3&);
struct GettingUp{char prefix[0x34];G3D::Vector3 position;Human*human();Primitive*floor();void update(float);};
void GettingUp::update(float dt){Body*torso=human()->torso();if(!torso)return;Primitive*part=floor();if(!part)return;float firstMass=torso->getMass();float secondMass=part->body->getMass();float mass=std::min(firstMass,secondMass);static G3D::Vector3 gravity(0,-9.81f,0);G3D::Vector3 force;force.x=0;float scaled=scaleBy20(gravity).y;SimBody*sim=part->body->link->sim;force.y=scaled*mass*dt*.5f;force.z=0;if(sim)sim->accumulateForce(force,position);}


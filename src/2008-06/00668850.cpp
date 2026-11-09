// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_jointremovalnative2c2983c873833050.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/JointStage.h"
#include "v8world/ClumpStage2.h"
#include "v8world/Joint.h"
#include "v8world/Primitive.h"
#include <vector>
namespace RBX {
inline ClumpStage* JointStage::getClumpStage() {return static_cast<ClumpStage*>(getDownstream());}
void JointStage::onPrimitiveRemoving(Primitive* p) {
 std::vector<Joint*> joints;
 for(Joint* j=p->getFirstJoint();j;j=p->getNextJoint(j)) {
  if(j->getJointType()!=Joint::ANCHOR_JOINT && j->getJointType()!=Joint::FREE_JOINT && j->downstreamOfStage(this)) joints.push_back(j);
 }
 for(unsigned i=0;i<joints.size();++i) {
  Joint* j=joints[i];
  getDownstreamWS()->onEdgeRemoving(j);
  JointStage::onEdgeAdded(j);
 }
 getClumpStage()->onPrimitiveRemoving(p);
 p->removeFromPipeline(this);
}
}

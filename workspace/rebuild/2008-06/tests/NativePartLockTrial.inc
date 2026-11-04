namespace RBX {
bool PartInstance::lockedInPlace() const {
 bool above=false, below=false;
 const Primitive* p = &primitive;
 Joint* joint = p->getFirstJoint();
 while (joint) {
  Edge* e = joint;
  int type;
  if ((e->getEdgeType() == Edge::JOINT && ((type=joint->getJointType())==Joint::WELD_JOINT || type==Joint::SNAP_JOINT)) ||
      (e->getEdgeType() == Edge::JOINT && joint->getJointType()==Joint::MOTOR_JOINT)) {
   NormalId n = p==e->getPrimitive(0) ? Matrix3ToNormalId(joint->getJointCoord(0).rotation) : normalIdOpposite(Matrix3ToNormalId(joint->getJointCoord(1).rotation));
   if(n==NORM_Y) above=true; else if(n==NORM_Y_NEG) below=true;
  }
  joint=p->getNextJoint(joint);
 }
 return above && below;
}
}

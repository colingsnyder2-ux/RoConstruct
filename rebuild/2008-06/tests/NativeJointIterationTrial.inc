namespace RBX {
Joint* Primitive::getFirstJoint() const {
    return joints.edges.size() > 0 ? static_cast<Joint*>(joints.edges[0]) : 0;
}
Joint* Primitive::getNextJoint(Joint* previous) const {
    int index = previous->getEdgeIndex(this) + 1;
    return index < joints.edges.size() ? static_cast<Joint*>(joints.edges[index]) : 0;
}
}

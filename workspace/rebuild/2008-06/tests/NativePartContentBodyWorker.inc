namespace RBX {
Body::Body()
    : index(-1), canThrottle(true), cofm(0), root(0), parent(0), link(0), simBody(0),
      stateIndex(getNextStateIndex()), moment(G3D::Matrix3::identity()), mass(0.0f) {
    root = this;
    simBody = new SimBody(this);
}
Body::~Body() {
    if (parent) setParent(0);
    delete simBody;
    simBody = 0;
}
typedef char NativeBodySizeCheck[sizeof(Body) == 0xdc ? 1 : -1];
typedef char NativeSimBodySizeCheck[sizeof(SimBody) == 0xb4 ? 1 : -1];
typedef char NativeContentIdSizeCheck[sizeof(ContentId) == 0x20 ? 1 : -1];
}

namespace RBX {
void Body::makeCofmDirty() {
    if (!(cofm && cofm->getIsDirty())) {
        if (getParent()) getParent()->makeCofmDirty();
        else if (simBody) simBody->makeDirty();
        if (cofm) cofm->makeDirty();
    }
}
void Body::onChildRemoved(Body* child) {
    children.fastRemove(child);
    if (numChildren() == 0) { delete cofm; cofm = 0; }
    makeCofmDirty();
}
void Body::onChildAdded(Body* child) {
    makeCofmDirty();
    children.fastAppend(child);
    if (!cofm) cofm = new Cofm(this);
}
}


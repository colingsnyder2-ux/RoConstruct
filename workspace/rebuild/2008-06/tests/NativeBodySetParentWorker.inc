namespace RBX {
void Body::resetRoot(Body* newRoot) {
    root = newRoot;
    for (int i = 0; i < children.size(); i++) children[i]->resetRoot(newRoot);
}
void Body::advanceStateIndex() { stateIndex = getNextStateIndex(); }
void Body::setParent(Body* newParent) {
    if (parent != newParent) {
        if (link) { link->setBody(0); link = 0; }
        if (getParent()) parent->onChildRemoved(this);
        else { delete simBody; simBody = 0; }
        parent = newParent;
        if (newParent) newParent->onChildAdded(this);
        else simBody = new SimBody(this);
        Body* myRoot = getParent() ? getParent()->calcRoot() : this;
        myRoot->advanceStateIndex();
        resetRoot(myRoot);
    }
}
}

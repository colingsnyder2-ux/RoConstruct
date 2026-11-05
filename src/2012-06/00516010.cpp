// from server: 74% by Intel
struct Ogre_RbxCullableSceneNode {
    bool func_00516010();
};

bool Ogre_RbxCullableSceneNode::func_00516010() {
    int eax = *(int*)((char*)this + 0x170);
    eax += 0x45e0;
    if (eax == 0) {
        return false;
    }
    int ecx = *(int*)((char*)this + 0x210);
    if (ecx > *(int*)(eax + 0x2c)) {
        return false;
    }
    return true;
}

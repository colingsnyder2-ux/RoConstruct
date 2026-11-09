// from server: 100% by Cezant64gamejr
struct RbxSceneManager {
    void setFindVisibleObjects(bool value);
};

void RbxSceneManager::setFindVisibleObjects(bool value) {
    *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x4290) = value;
}

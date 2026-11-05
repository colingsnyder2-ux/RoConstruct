// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
struct Ogre_RbxSceneManager {
    char pad0[488];
    bool m_flag : 1;

    bool getFlag();
};

bool Ogre_RbxSceneManager::getFlag() {
    return this->m_flag;
}

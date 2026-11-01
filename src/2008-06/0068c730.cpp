// from server: 100% by Cezant64gamejr
struct Ogre_RbxSceneManager {
    char pad0[16996];
    int m_counter;
    void incrementCounter();
};

void Ogre_RbxSceneManager::incrementCounter() {
    ++m_counter;
}

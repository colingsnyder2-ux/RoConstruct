// from server: 100% by tester
struct RbxSceneManager {
    char pad[0x1e8];
    unsigned char lo : 4;
    unsigned char flag : 1;
    unsigned char hi : 3;
    bool getFlag() const;
};

bool RbxSceneManager::getFlag() const {
    return flag;
}

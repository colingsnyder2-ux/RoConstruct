// from server: 100% by Intel
struct VPlayerRemoteEventDesc {
    int getFlag() const;
};

int VPlayerRemoteEventDesc::getFlag() const {
    return (reinterpret_cast<const int*>(this)[14] & 1);
}

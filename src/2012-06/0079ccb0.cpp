// from server: 100% by Intel
struct VHumanoid {
    int getRemoteEventDescFlag() const;
};

int VHumanoid::getRemoteEventDescFlag() const {
    return (reinterpret_cast<const int*>(this)[0x3c / 4] & 1);
}

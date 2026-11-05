// from server: 100% by Intel
struct RemoteEventDesc {
    int getFlag() const;
};

int RemoteEventDesc::getFlag() const {
    return *(const int*)((const char*)this + 0x34) & 1;
}

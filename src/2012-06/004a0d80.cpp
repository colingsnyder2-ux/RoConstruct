// from server: 100% by Intel
struct VInstance {
    bool hasSignal() const;
};

bool VInstance::hasSignal() const {
    return *(const int*)((const char*)this + 0x10) != 0;
}

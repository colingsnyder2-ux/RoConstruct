// from server: 100% by Intel
struct VModelInstance_BoundFuncDesc {
    unsigned char getFlag() const;
};

unsigned char VModelInstance_BoundFuncDesc::getFlag() const {
    unsigned char val = reinterpret_cast<const unsigned char*>(this)[0xB9];
    val >>= 1;
    val &= 1;
    return val;
}

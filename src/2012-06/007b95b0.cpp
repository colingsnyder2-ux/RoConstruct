// from server: 100% by Intel
struct Geometry {
    unsigned char getFlag() const;
};

unsigned char Geometry::getFlag() const {
    const void* ptr = *reinterpret_cast<const void* const*>(reinterpret_cast<const char*>(this) + 0x108);
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(ptr) + 0x40);
}

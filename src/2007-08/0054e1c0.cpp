// from server: 100% by colin
struct S {
    char pad[0xb0];
    unsigned int m_flags;
    unsigned int getFlag() const;
};

unsigned int S::getFlag() const {
    return (m_flags >> 4) & 1;
}

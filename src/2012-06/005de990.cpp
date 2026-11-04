// from server: 100% by Intel
namespace RBX {
    struct BeveledBlockBuilder {
        int m_ints[7];
        float m_floats[3];
        unsigned char m_bytes[5];
        BeveledBlockBuilder(const BeveledBlockBuilder& other);
    };
}

RBX::BeveledBlockBuilder::BeveledBlockBuilder(const BeveledBlockBuilder& other) {
    m_ints[0] = other.m_ints[0];
    m_ints[1] = other.m_ints[1];
    m_ints[2] = other.m_ints[2];
    m_ints[3] = other.m_ints[3];
    m_ints[4] = other.m_ints[4];
    m_ints[5] = other.m_ints[5];
    m_ints[6] = other.m_ints[6];
    m_floats[0] = other.m_floats[0];
    m_floats[1] = other.m_floats[1];
    m_floats[2] = other.m_floats[2];
    m_bytes[0] = other.m_bytes[0];
    m_bytes[1] = other.m_bytes[1];
    m_bytes[2] = other.m_bytes[2];
    m_bytes[3] = other.m_bytes[3];
    m_bytes[4] = other.m_bytes[4];
}

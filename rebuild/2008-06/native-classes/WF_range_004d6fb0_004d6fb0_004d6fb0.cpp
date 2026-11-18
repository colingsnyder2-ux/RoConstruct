// native-flags: /O2 /GS- /arch:IA32
struct Vector3 {
    float x, y, z;
};

// NEEDS-DECL: float x, y, z; (members at offsets 0x27c, 0x280, 0x284 of CSHA1)
// NEEDS-DECL: Vector3 sub_004d6fb0() const;
struct CSHA1 {
    char padding[0x27c];
    float x, y, z;
    Vector3 sub_004d6fb0() const;
};

Vector3 CSHA1::sub_004d6fb0() const {
    Vector3 result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

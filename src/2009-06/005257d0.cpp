// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Vector3 {
    float x, y, z;
};

struct CSHA1 {
    char padding[0x1d0];
    float x, y, z;
    Vector3 getVector() const;
};

Vector3 CSHA1::getVector() const {
    Vector3 result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}
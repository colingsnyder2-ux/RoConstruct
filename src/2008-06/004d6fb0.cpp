// from server: 100% by tester
struct Vector3 {
    float x, y, z;
};

struct CSHA1 {
    char padding[0x27c];
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

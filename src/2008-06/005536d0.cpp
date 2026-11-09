// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    Vector3& operator=(const Vector3&);
};

struct Data {
    char storage[24];
    Data& operator=(const Data&);
};

struct S : Vector3 {
    Data data;
    int value;
    S& operator=(const S&);
};

#pragma optimize("", off)
S& S::operator=(const S& other)
{
    Vector3::operator=(other);
    data = other.data;
    value = other.value;
    return *this;
}

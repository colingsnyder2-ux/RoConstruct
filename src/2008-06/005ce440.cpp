// from server: 100% by tester
struct Matrix3 { float m[9]; };
struct Vector3 {
    float x, y, z;
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
};
struct CF {
    Matrix3 rotation; Vector3 translation;
    CF& operator=(const CF& c) { rotation = c.rotation; translation = c.translation; return *this; }
};
struct Cam {
    char pad[0x174];
    CF cf;
    void changed();
    CF& frame() { return cf; }
    void setCameraCoordinateFrameNoLerp(const CF& c);
};
void Cam::setCameraCoordinateFrameNoLerp(const CF& c) {
    frame() = c;
    changed();
}

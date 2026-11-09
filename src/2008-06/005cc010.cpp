// from server: 100% by tester
struct V3 { float x, y, z; };
struct Sub {
    char pad[0x58];
    float ay, az;
    void update(const V3& v);
};
struct Cam {
    char pad[0x174];
    Sub sub;
    float tail;
    void lookAt(const V3& v);
};
void Cam::lookAt(const V3& v) {
    *(float*)((char*)this + 0x1c8) = v.x;
    sub.ay = v.y;
    sub.az = v.z;
    sub.update(v);
}

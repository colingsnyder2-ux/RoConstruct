// from server: 27% by colin




struct Vector3 {
    float x;
    float y;
    float z;
};

struct BodyMover {
    char pad[0x18];
    float m18;
    float m1c;
    void computeForce(Vector3 a, Vector3 b, Vector3& out);
};

extern "C" void __cdecl sub_6060B0();

void BodyMover::computeForce(Vector3 a, Vector3 b, Vector3& out)
{
    float t0 = m18 * a.x + b.x;
    float t1 = m18 * a.y + b.y;
    float t2 = m18 * a.z + b.z;
    out.x = t0 - a.x;
    out.y = t1 - a.y;
    out.z = t2 - a.z;
    sub_6060B0();
}

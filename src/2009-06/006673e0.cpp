// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    float squaredLength() const { return x * x + y * y + z * z; }
};
}
namespace RBX {
class Humanoid {
public:
    enum Status { RUNNING = 0, JUMPING = 3 };
    char pad[0x1e8];
    Status status;
    int jumpCounter;
    G3D::Vector3 computeVelocity();
    void updateJump();
};
void Humanoid::updateJump()
{
if (status == JUMPING) { jumpCounter--; if (jumpCounter <= 0) { status = RUNNING; jumpCounter = 0; } else if (computeVelocity().squaredLength() < 4.0f) { jumpCounter = 0; status = RUNNING; } }
}
}

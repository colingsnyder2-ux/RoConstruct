// from server: 27% by colin
struct Vector3 {
    float x, y, z;
    Vector3();
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct PartInstance {
    char pad[0x24];
    Vector3 position;
};

struct Humanoid {
    void* vtable;
    char pad[0x3c];
    void* somePtr;
    char pad2[0x1c];
    PartInstance* torso;
    char pad3[0x8];
    float health;
    char pad4[0x4];
    float maxHealth;
    char pad5[0x4];
    float walkSpeed;
    char pad6[0x4];
    float jumpPower;
    char pad7[0x4];
    float maxSlopeAngle;
    char pad8[0x4];
    float hipHeight;
    char pad9[0x4];
    bool torsoArrived;
    bool jump;
    bool autoJump;
    bool sit;
    bool touchedHard;
    bool strafe;
    bool localSimulating;

    bool computeForce(const Vector3& pos, const Vector3& dir, float* outDist);
};

extern "C" {
    void __cdecl sub_509640();
    void __cdecl sub_51D890();
    void __cdecl sub_5FFEB0();
    void __cdecl sub_601630();
    void __cdecl sub_62FC62();
    double __cdecl sqrt(double);
}

extern float g_793760;
extern float g_787050;
extern float g_7B1548;
extern void* g_8C7FC8;

bool Humanoid::computeForce(const Vector3& pos, const Vector3& dir, float* outDist) {
    Vector3 localPos;
    Vector3 localDir;
    float dist;
    float bestDist;
    int count;
    int i;
    bool result;

    count = 0;
    bestDist = 0.0f;

    for (i = -2; i <= 2; i += 2) {
        Vector3 offset;
        offset.x = (float)i * dir.x;
        offset.y = (float)i * dir.y;
        offset.z = (float)i * dir.z;

        Vector3 testPos;
        testPos.x = pos.x + offset.x;
        testPos.y = pos.y + offset.y;
        testPos.z = pos.z + offset.z;

        Vector3 delta;
        delta.x = testPos.x - this->torso->position.x;
        delta.y = testPos.y - this->torso->position.y;
        delta.z = testPos.z - this->torso->position.z;

        dist = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
        dist = (float)sqrt((double)dist);

        if (dist < bestDist || count == 0) {
            bestDist = dist;
            count++;
        }
    }

    if (count > 1) {
        bestDist = bestDist - g_793760;
        if (bestDist < g_787050) {
            bestDist = g_787050;
        }
        if (bestDist > g_7B1548) {
            bestDist = g_7B1548;
        }
        *outDist = bestDist;
        result = true;
    } else {
        *outDist = bestDist;
        result = false;
    }

    return result;
}

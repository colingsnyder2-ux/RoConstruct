// from server: 56% by colin
struct Vector3 {
    float x, y, z;
};

struct CFrame {
    float r00, r01, r02;
    float r10, r11, r12;
    float r20, r21, r22;
    float x, y, z;
};

struct HumanoidState {
    void* vtable;
    char pad[0x80];
    CFrame cframe;
};

struct Balancing {
    void* vtable;
    void* humanoid;
    float kP;
    float kD;
    Vector3 lastBalanceTorque;
    int tick;

    void onComputeForceImpl(float dt);
};

extern float g_balanceP;
extern float g_balanceD;
extern float g_balanceI;
extern unsigned char g_balanceInit;

void* sub_5A6270(void* p);
void sub_530100(void* p);
CFrame* sub_5099A0(void* p, CFrame* out);
void sub_625F40(Balancing* self, float dt, Vector3* torque);

void Balancing::onComputeForceImpl(float dt)
{
    void* h = sub_5A6270(humanoid);
    if (!h)
        return;

    if (!(g_balanceInit & 1)) {
        g_balanceInit |= 1;
        g_balanceP = 0.0f;
        g_balanceD = 1.0f;
        g_balanceI = 0.0f;
    }

    sub_530100(h);

    CFrame cf;
    sub_5099A0((char*)h + 0x84, &cf);

    Vector3 torque;
    torque.x = cf.r00 * cf.r10 + g_balanceP * g_balanceD + cf.r20 * g_balanceI;
    torque.y = cf.r01 * g_balanceP + cf.r11 * g_balanceD + cf.r21 * g_balanceI;
    torque.z = cf.r02 * g_balanceP + cf.r12 * g_balanceD + cf.r22 * g_balanceI;

    sub_625F40(this, dt, &torque);
}

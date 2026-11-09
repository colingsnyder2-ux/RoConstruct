// from server: 25% by colin
struct V3 { float x, y, z; };

struct Body {
    char pad0[0x1c];
    void* unk1c;
    char pad20[0x60];
    float unk7c;
    char pad80[0x34];
    float b4, b8, bc;
    char padc0[0x1c];
    float a8, ac, b0;
};

struct Part {
    char pad0[4];
    Body* body;
};

struct Target {
    char pad0[0x64];
    Part* part;
};

struct Rocket {
    char pad0[0x10];
    Target* target;
    char pad14[4];
    bool active;
    char pad19[7];
    V3 targetOffset;
    char pad2c[0xc];
    float kThrustP;
    float kThrustD;
    float maxSpeed;
    float kTurnP;
    float kTurnD;
    char pad4c[0xc];
    float maxThrust;
    char pad5c[0x8c];
    void computeForceImpl(bool, Body*, Body*, V3&, V3&);
};

extern "C" {
    void __stdcall sub_573f80(V3* out, V3* in);
    void __stdcall sub_4731a0(void* p);
    void __stdcall sub_530100(void* p);
    void __stdcall sub_624d80(void* p);
    void __stdcall sub_50f630(V3* out, V3* a, V3* b);
    void __stdcall sub_5aaac0(V3* v);
    void __stdcall sub_4a04a0(V3* out, V3* a, V3* b, V3* c);
    void __stdcall sub_5eb2e0(void* p, V3* v);
    void __stdcall sub_5eb6f0(void* p, V3* a, V3* b, V3* c);
}

extern float g_79fe50;
extern float g_8bd12c;
extern float g_8bd130;
extern float g_8bd134;
extern int g_8bd138;

void Rocket::computeForceImpl(bool throttling, Body* body, Body* root, V3& force, V3& torque)
{
    if (!active)
        return;

    Part* part = target->part;
    Body* body2 = part->body;

    V3 tgt;
    if (target) {
        V3 tmp;
        sub_573f80(&tmp, &targetOffset);
        sub_4731a0(&tmp);
        tgt = tmp;
    } else {
        tgt = targetOffset;
    }

    sub_530100(body2);

    float dx = tgt.x - body2->a8;
    float dy = tgt.y - body2->ac;
    float dz = tgt.z - body2->b0;

    float dist = dx*dx + dy*dy + dz*dz;
    float inv = 1.0f / (dist > 0.0f ? dist : 1.0f);
    float nx = dx * inv;
    float ny = dy * inv;
    float nz = dz * inv;

    float f = kThrustP;
    float fx = nx * f;
    float fy = ny * f;
    float fz = nz * f;

    float spd;
    if (body2->unk1c)
        sub_624d80(body2->unk1c);
    spd = body2->unk7c;

    V3 vel;
    vel.x = fx * spd;
    vel.y = fy * spd;
    vel.z = fz * spd;

    sub_530100(body2);

    float bx = body2->b4;
    float by = body2->b8;
    float bz = body2->bc;

    float kd = kThrustD;
    float dot = bx*vel.x + by*vel.y + bz*vel.z;
    float sq = dot * dot;

    if (sq > 0.0f) {
        sub_530100(body2);
        float bxx = body2->b4;
        float byy = body2->b8;
        float bzz = body2->bc;
        float blen = bxx*bxx + byy*byy + bzz*bzz;
        float binv = 1.0f / (blen > 0.0f ? blen : 1.0f);
        float ux = bxx * binv;
        float uy = byy * binv;
        float uz = bzz * binv;
        float d2 = vel.x*ux + vel.y*uy + vel.z*uz;
        if (d2 > 0.0f) {
            vel.x -= ux * d2;
            vel.y -= uy * d2;
            vel.z -= uz * d2;
        }
    }

    sub_530100(body2);

    float vx = body2->b4 - vel.x;
    float vy = body2->b8 - vel.y;
    float vz = body2->bc - vel.z;

    float spd2;
    if (body2->unk1c)
        sub_624d80(body2->unk1c);
    spd2 = body2->unk7c;

    V3 tv;
    tv.x = vx * spd2;
    tv.y = vy * spd2;
    tv.z = vz * spd2;

    V3 tmp2;
    sub_50f630(&tmp2, &tv, &vel);
    vel.x -= tmp2.x;
    vel.y -= tmp2.y;
    vel.z -= tmp2.z;

    sub_530100(body2);

    float spd3;
    if (body2->unk1c)
        sub_624d80(body2->unk1c);
    spd3 = body2->unk7c;

    float m = spd3 * kTurnD;
    float ax = body2->b4 * m;
    float ay = body2->b8 * m;
    float az = body2->bc * m;

    vel.x -= ax;
    vel.y -= ay;
    vel.z -= az;

    Body* rootBody = body2;
    V3* rootPos;
    if (rootBody->unk1c) {
        rootPos = (V3*)((char*)rootBody->unk1c + 0x80);
    } else {
        if (!(g_8bd138 & 1)) {
            g_8bd138 |= 1;
            g_8bd12c = 0.0f;
            g_8bd130 = 0.0f;
            g_8bd134 = 0.0f;
        }
        rootPos = (V3*)&g_8bd12c;
    }

    vel.x -= rootPos->x;
    vel.y -= rootPos->y;
    vel.z -= rootPos->z;

    sub_5aaac0(&vel);

    V3 t1, t2, t3;
    t1.x = kTurnP; t1.y = kTurnP; t1.z = kTurnP;
    t2.x = kTurnP; t2.y = kTurnP; t2.z = kTurnP;
    t3.x = -kTurnP; t3.y = -kTurnP; t3.z = -kTurnP;

    V3 r;
    sub_4a04a0(&r, &t1, &t2, &t3);

    V3 rv;
    rv.x = r.x;
    rv.y = r.y;
    rv.z = r.z;

    sub_5eb2e0(body2, &rv);

    float len2 = vel.x*vel.x + vel.y*vel.y + vel.z*vel.z;
    if (len2 > g_79fe50) {
        float inv2 = 1.0f / (len2 > 0.0f ? len2 : 1.0f);
        vel.x *= inv2;
        vel.y *= inv2;
        vel.z *= inv2;
    } else {
        if (!(g_8bd138 & 1)) {
            g_8bd138 |= 1;
            g_8bd12c = 0.0f;
            g_8bd130 = 0.0f;
            g_8bd134 = 0.0f;
        }
        vel.x = 0.0f;
        vel.y = 0.0f;
        vel.z = 0.0f;
    }

    float mt = maxThrust;
    V3 fv;
    fv.x = vel.x * mt;
    fv.y = vel.y * mt;
    fv.z = vel.z * mt;

    V3 tv2;
    tv2.x = vel.x * mt;
    tv2.y = vel.y * mt;
    tv2.z = vel.z * mt;

    sub_5eb6f0((char*)this - 0xe8, &tv2, &fv, &vel);
}

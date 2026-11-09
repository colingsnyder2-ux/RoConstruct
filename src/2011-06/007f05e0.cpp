// from server: 15% by atomic.potato
struct Vec3 { float x, y, z; };

struct Sub {
    char pad0[0xac];
    float m_ac;      // 0xac
    float m_b0;      // 0xb0
    float m_b4;      // 0xb4
    float m_b8;      // 0xb8
    float m_bc;      // 0xbc
};

struct Other {
    char pad0[0xd0];
    float m_d0;      // 0xd0
    float m_d4;      // 0xd4
    float m_d8;      // 0xd8
};

struct BallEdgeConnector {
    char pad0[0x24];
    Other* m_pOther;   // 0x24
    Sub* m_pSub;       // 0x28
    char pad2[0x68 - 0x2c];
    float m_68;        // 0x68
    float m_6c;        // 0x6c
    float m_70;        // 0x70
    float m_74;        // 0x74
    float m_78;        // 0x78
    float m_7c;        // 0x7c
    float m_80;        // 0x80

    void f(Vec3* out);
};

extern "C" float __stdcall sub_5429f0(Vec3* a, float b);

extern float g_a7b984;

void BallEdgeConnector::f(Vec3* out)
{
    Other* o = m_pOther;
    Sub* s = m_pSub;

    float x0 = m_6c;
    float x1 = m_70;
    float x2 = m_74;
    float x3 = m_78;
    float x4 = m_7c;
    float x5 = m_80;

    float a0 = s->m_ac;
    float a1 = s->m_b0;
    float a2 = s->m_b4;
    float a3 = s->m_b8;
    float a4 = s->m_bc;

    float r0 = a1 * x1 + a3 * x2 + a0 * x0 + s->m_b4 * 0 + 0;
    // recompute properly
    r0 = a1 * x1 + a3 * x2 + a0 * x0;
    r0 += *(float*)((char*)s + 0xd8);
    r0 -= o->m_d0;

    float r1 = a2 * x0 + a4 * x1 + a3 * x3;
    r1 += *(float*)((char*)s + 0xdc);
    r1 -= o->m_d4;

    float r2 = a0 * x2 + a1 * x3 + a2 * x4;
    r2 += *(float*)((char*)s + 0xe0);
    r2 -= o->m_d8;

    float d0 = r0;
    float d1 = r1;
    float d2 = r2;

    float q0 = a0 * x3 + a1 * x4 + a2 * x5;
    float q1 = a3 * x3 + a4 * x4 + a0 * x5;
    float q2 = a1 * x4 + a2 * x5 + a3 * x3;

    float dot = d2 * q2 + d1 * q1 + d0 * q0;

    float nx = d0 - q0 * dot;
    float ny = d1 - q1 * dot;
    float nz = d2 - q2 * dot;

    out->x = nx;
    out->y = ny;
    out->z = nz;

    float ox = o->m_d0 + nx;
    float oy = o->m_d4 + ny;
    float oz = o->m_d8 + nz;

    out[1].x = ox;
    out[1].y = oy;
    out[1].z = oz;

    out[1].z = sub_5429f0(out, g_a7b984) - m_68;
}

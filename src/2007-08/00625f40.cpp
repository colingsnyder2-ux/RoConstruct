// from server: 36% by colin
struct Humanoid;
struct Body;

struct Running {
    char pad0[4];
    Humanoid* humanoid;
    char pad8[4];
    float f0c;
    float f10;
    char pad14[0x0c];
    void onComputeForceImpl();
};

struct Humanoid {
    char pad0[4];
    Body* body;
    char pad8[0x14];
    void* unk1c;
    void* unk20;
};

struct Body {
    char pad0[4];
    void* unk4;
    char pad8[0x14];
    void* unk1c;
    void* unk20;
    char pad24[0x34];
    float f58;
    float f5c;
    float f60;
    char pad64[0x5c];
    float fc0;
    float fc4;
    float fc8;
};

extern "C" {
    void __stdcall sub_5095d0(void* out, const void* in);
    void __stdcall sub_509970(void* out, const void* a, const void* b, float c);
    void __stdcall sub_5099a0(void* out, const void* in);
    void __stdcall sub_530100(void* self);
    void __stdcall sub_5a6270(void* self);
    void __stdcall sub_5aad40(void* out, const void* a);
    void __stdcall sub_61a510(void* self);
    void __stdcall sub_625100(void* self);
}

extern float g_7bf83c;
extern float g_8bd12c;
extern float g_8bd130;
extern float g_8bd134;
extern int g_8bd138;

void Running::onComputeForceImpl()
{
    Body* body = this->humanoid->body;
    sub_5a6270(body);
    Body* b = (Body*)body;

    float* arg = (float*)((char*)this + 0x0c);
    float v24 = -arg[2];
    float v2c = arg[0];

    sub_530100(b);
    sub_530100(b);

    float m54[9];
    sub_5099a0(m54, (char*)b + 0x84);

    float v18 = m54[2] * b->fc8 + m54[1] * b->fc4 + b->fc0 * m54[0];
    float v1c = m54[3] * b->fc0 + m54[5] * b->fc8 + m54[4] * b->fc4;
    float v20 = m54[6] * b->fc0 + m54[8] * b->fc8 + m54[7] * b->fc4;

    void* p20 = this->humanoid->unk20;
    float zero = 0.0f;
    float* pv;
    if (p20) {
        pv = (float*)((char*)p20 + 0x8c);
    } else {
        if (!(g_8bd138 & 1)) {
            g_8bd138 |= 1;
            g_8bd12c = zero;
            g_8bd130 = zero;
            g_8bd134 = zero;
        }
        pv = &g_8bd12c;
    }

    float v30 = pv[0];
    float v34 = pv[1];
    float v38 = pv[2];

    sub_530100(b);

    float m54b[9];
    sub_5099a0(m54b, (char*)b + 0x84);

    float v3c = m54b[2] * v38 + m54b[1] * v34 + m54b[0] * v30;
    float v40 = m54b[5] * v38 + m54b[4] * v34 + m54b[3] * v30;
    float v44 = m54b[8] * v38 + m54b[7] * v34 + m54b[6] * v30;

    void* p1c = b->unk1c;
    float* pv2;
    if (p1c) {
        sub_625100(p1c);
        pv2 = (float*)p1c;
    } else {
        pv2 = &b->f58;
    }

    float m58[9];
    sub_5095d0(m58, pv2);

    float v0c;
    float v10;
    float v14;
    {
        float tmp = -this->f0c;
        float m80[9];
        sub_509970(m80, m58, &tmp, 0.0f);
        v0c = m80[2] * v38 + m80[1] * v34 + m80[0] * v30 + v3c;
        v10 = m80[5] * v38 + m80[4] * v34 + m80[3] * v30 + v40;
        v14 = m80[8] * v38 + m80[7] * v34 + m80[6] * v30 + v44;
    }

    void* p1c2 = b->unk1c;
    float* pv3;
    if (p1c2) {
        sub_625100(p1c2);
        pv3 = (float*)p1c2;
    } else {
        pv3 = &b->f58;
    }

    float m58b[9];
    sub_5095d0(m58b, pv3);

    float v48[3];
    sub_5aad40(v48, m58b);

    for (int i = 0; i < 3; i++) {
        float diff = v48[i] - v3c;
        if (diff < 0.0f) diff = -diff;
        if (diff > g_7bf83c * v48[i]) {
            v48[i] = v48[i];
        }
    }

    float v0c2 = v0c - this->f10 * v48[0];
    float v102 = v10 - this->f10 * v48[1];
    float v142 = v14 - this->f10 * v48[2];

    sub_530100(b);

    float m84[9];
    sub_5099a0(m84, (char*)b + 0x84);

    float dx = m84[2] * v142 + m84[1] * v102 + m84[0] * v0c2 - v30;
    float dy = m84[5] * v142 + m84[4] * v102 + m84[3] * v0c2 - v34;
    float dz = m84[8] * v142 + m84[7] * v102 + m84[6] * v0c2 - v38;

    void* p20b = b->unk20;
    if (p20b) {
        if (*((char*)p20b + 4)) {
            sub_61a510(p20b);
        }
        *(float*)((char*)p20b + 0x8c) += dx;
        *(float*)((char*)p20b + 0x90) += dy;
        *(float*)((char*)p20b + 0x94) += dz;
    }
}

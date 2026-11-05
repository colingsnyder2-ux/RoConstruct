// from server: 100% by atomic.potato
struct BodyForce {
    char pad[0xfc];
    float field_fc;
    float field_100;
    float field_104;
    float field_108;
    float field_10c;
    float field_110;
};

extern float g_8bfbe8;
extern float g_8bfbec;
extern float g_8bfbf0;
extern unsigned int g_8bfbf4;
extern float g_8bd12c;
extern float g_8bd130;
extern float g_8bd134;
extern unsigned int g_8bd138;

extern "C" void __stdcall sub_5ee870(const char* name);

BodyForce* __fastcall BodyForce_ctor(BodyForce* self)
{
    sub_5ee870((const char*)0x8af400);

    *(unsigned int*)((char*)self + 0x00) = 0x7bfafc;
    *(unsigned int*)((char*)self + 0x04) = 0x7bfaf4;
    *(unsigned int*)((char*)self + 0x10) = 0x7bfaec;
    *(unsigned int*)((char*)self + 0x14) = 0x7bfadc;
    *(unsigned int*)((char*)self + 0x2c) = 0x7bfacc;
    *(unsigned int*)((char*)self + 0x44) = 0x7bfabc;
    *(unsigned int*)((char*)self + 0x5c) = 0x7bfaac;
    *(unsigned int*)((char*)self + 0x74) = 0x7bfa9c;
    *(unsigned int*)((char*)self + 0x8c) = 0x7bfa8c;
    *(unsigned int*)((char*)self + 0xe8) = 0x7bfa74;
    *(unsigned int*)((char*)self + 0xf0) = 0x7bfa68;

    if (!(g_8bfbf4 & 1)) {
        g_8bfbf4 |= 1;
        g_8bfbe8 = 0.0f;
        g_8bfbec = 1.0f;
        g_8bfbf0 = 0.0f;
    }

    self->field_fc = g_8bfbe8;
    self->field_100 = g_8bfbec;
    self->field_104 = g_8bfbf0;

    if (!(g_8bd138 & 1)) {
        g_8bd138 |= 1;
        g_8bd12c = 0.0f;
        g_8bd130 = 0.0f;
        g_8bd134 = 0.0f;
    }

    self->field_108 = g_8bd12c;
    self->field_10c = g_8bd130;
    self->field_110 = g_8bd134;

    return self;
}

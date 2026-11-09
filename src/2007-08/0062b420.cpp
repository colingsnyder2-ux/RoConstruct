// from server: 33% by colin
struct Vector3 {
    float x, y, z;
};

struct CoordinateFrame {
    float r00, r01, r02, r03;
    float r10, r11, r12, r13;
    float r20, r21, r22, r23;
};

struct MouseCommand {
    void *vtable;
    int field4;
    float field8;
    float fieldC;
    float field10;
};

struct GroupDragTool {
    void *vtable;
    int field4;
    float field8;
    float fieldC;
    float field10;
    char pad[0x60 - 0x14];
    void *field60;
    void *field64;
};

extern "C" void __stdcall sub_530100(void *p);
extern "C" int __stdcall sub_5BC430(void *p);
extern float dword_797E9C;

void GroupDragTool_method(GroupDragTool *self);

void GroupDragTool_method(GroupDragTool *self)
{
    void *p = *(void **)self;
    void *esi = *(void **)((char *)p + 0x64);
    sub_530100(esi);

    float dx = self->field8 - *(float *)((char *)esi + 0xa8);
    float dy = self->fieldC - *(float *)((char *)esi + 0xac);
    float dz = self->field10 - *(float *)((char *)esi + 0xb0);

    float m00 = *(float *)((char *)esi + 0x88);
    float m01 = *(float *)((char *)esi + 0x8c);
    float m02 = *(float *)((char *)esi + 0x90);
    float m10 = *(float *)((char *)esi + 0x94);
    float m11 = *(float *)((char *)esi + 0x98);
    float m12 = *(float *)((char *)esi + 0x9c);
    float m20 = *(float *)((char *)esi + 0xa0);
    float m21 = *(float *)((char *)esi + 0xa4);

    float rx = m00 * dx + m10 * dy + m20 * dz;
    float ry = m01 * dx + m11 * dy + m21 * dz;
    float rz = m02 * dx + m12 * dy + m20 * dz;

    float out[3];
    out[0] = rx;
    out[1] = ry;
    out[2] = rz;

    void *ecx = *(void **)self;
    void *eax = *(void **)((char *)ecx + 0x60);
    float a = *(float *)((char *)eax + 4);
    float b = *(float *)((char *)eax + 8);
    float c = *(float *)((char *)eax + 0xc);

    float s = dword_797E9C;
    float q0 = a * s;
    float q1 = b * s;
    float q2 = c * s;

    float buf[6];
    buf[0] = -q0;
    buf[1] = -q1;
    buf[2] = -q2;
    buf[3] = q0;
    buf[4] = q1;
    buf[5] = q2;

    int result = sub_5BC430(buf);
    self->field4 = result;
}

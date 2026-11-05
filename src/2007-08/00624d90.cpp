// from server: 35% by colin
struct Instance {
    char pad[0x10];
    int count;
    Instance** children;
};

struct Button {
    Instance* instance;
    bool active;
    char pad0[3];
    float x;
    float y;
    float z;
    float accumulated;
    char pad2[0x84 - 0x18];
    float matrix[9];
    float posX;
    float posY;
    float posZ;

    void process();
};

struct Vector3 {
    float x, y, z;
};

extern "C" void __cdecl sub_530100();
extern "C" void __cdecl sub_50f630();
extern "C" void __cdecl sub_5096f0();
extern "C" void __cdecl sub_5e2120();
extern "C" void __cdecl sub_5e2190();
extern "C" void __cdecl sub_52fc40();
extern "C" void __cdecl sub_5aacc0();

void Button::process()
{
    if (!active)
        return;

    Instance* inst = instance;
    accumulated = *(float*)((char*)inst + 0x7c);
    float base = *(float*)((char*)inst + 0x7c);

    sub_530100();

    float ax = *(float*)((char*)inst + 0xa8);
    float ay = *(float*)((char*)inst + 0xac);
    float az = *(float*)((char*)inst + 0xb0);

    float sx = ax * base;
    float sy = ay * base;
    float sz = az * base;

    int i = 0;
    while (i < inst->count) {
        Instance* child = inst->children[i];
        Button* btn = (Button*)child;
        if (btn->instance) {
            btn->process();
            accumulated += btn->accumulated;
        } else {
            accumulated += *(float*)((char*)child + 0x7c);
        }

        float childAccum;
        if (btn->instance) {
            btn->process();
            childAccum = btn->accumulated;
        } else {
            childAccum = *(float*)((char*)child + 0x7c);
        }

        float cx, cy, cz;
        if (btn->instance) {
            btn->process();
            sub_530100();
            float* m = (float*)((char*)child + 0x84);
            float* bm = (float*)((char*)btn + 0x0c);
            cx = m[0]*bm[0] + m[1]*bm[1] + m[2]*bm[2] + ax;
            cy = m[3]*bm[0] + m[4]*bm[1] + m[5]*bm[2] + ay;
            cz = m[6]*bm[0] + m[7]*bm[1] + m[8]*bm[2] + az;
        } else {
            sub_530100();
            cx = *(float*)((char*)child + 0xa8);
            cy = *(float*)((char*)child + 0xac);
            cz = *(float*)((char*)child + 0xb0);
        }

        sx += cx * childAccum;
        sy += cy * childAccum;
        sz += cz * childAccum;

        i++;
    }

    Vector3 v;
    v.x = sx;
    v.y = sy;
    v.z = sz;
    sub_50f630();

    sub_530100();

    float dx = v.x - ax;
    float dy = v.y - ay;
    float dz = v.z - az;

    float* m = (float*)((char*)inst + 0x84);
    float rx = m[0]*dx + m[3]*dy + m[6]*dz;
    float ry = m[1]*dx + m[4]*dy + m[7]*dz;
    float rz = m[2]*dx + m[5]*dy + m[8]*dz;

    x = rx;
    y = ry;
    z = rz;

    sub_5e2120();

    i = 0;
    while (i < inst->count) {
        Instance* child = inst->children[i];
        sub_5e2190();
        sub_5096f0();
        i++;
    }

    Instance* self = instance;
    if (self->children) {
        Instance* parent = (Instance*)((char*)self + 4);
        sub_530100();
        if (*(int*)((char*)parent + 0x80) != *(int*)((char*)self + 0x80)) {
            Instance* p2 = (Instance*)((char*)self + 8);
            sub_530100();
            sub_52fc40();
            sub_530100();
            *(int*)((char*)self + 0x80) = *(int*)((char*)p2 + 0x80);
        }
    }

    sub_5aacc0();

    active = false;
}

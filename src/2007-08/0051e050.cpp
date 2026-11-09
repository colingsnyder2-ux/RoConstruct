// from server: 45% by colin
// roc 2007-08 0051e050  unit: seg_00510000  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0051e050

extern "C" float __cdecl sqrtf_helper(float);

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Mat3 {
    float m[3][3];
};

struct S {
    float field0;
    float field4;
    float field8;
    float fieldC;
    float field10;
    void func(const Vec3* a, const Vec3* b, const Vec3* c);
};

void S::func(const Vec3* a, const Vec3* b, const Vec3* c) {
    float v8 = a->x;
    float vC = a->y;
    float v10 = a->z;

    float t0 = vC * b->z - v10 * b->y;
    float t1 = v10 * b->x - v8 * b->z;
    float t2 = v8 * b->y - vC * b->x;

    float len = t0 * t0 + t1 * t1 + t2 * t2;
    len = sqrtf_helper(len);
    float inv = 1.0f / len;

    float n0 = t0 * inv;
    float n1 = t1 * inv;
    float n2 = t2 * inv;

    this->field4 = n0;
    this->field8 = n1;
    this->fieldC = n2;

    this->field10 = this->field8 * c->y + c->x * this->field4 + this->fieldC * c->z;
}

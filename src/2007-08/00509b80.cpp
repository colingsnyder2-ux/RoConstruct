// from server: 44% by colin
// roc 2007-08 00509b80  unit: G3D::GCamera  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00509b80

extern "C" float __cdecl sqrtf(float);

struct GCamera {
    float field_04;
    float field_08;
    float field_0c;
    float field_10;
    float field_14;
    float field_18;
    float field_1c;
    float field_20;
    void update();
};

void GCamera::update() {
    float a = field_10 * field_18 - field_14;
    field_14 = a;
    float b = field_18 * field_1c - field_20;
    field_20 = b;
    float c = field_1c * field_14 - field_20;
    float d = sqrtf(c);
    float e = 1.0f / d;
    field_08 = field_08 * e;
    field_14 = field_14 * e;
    field_20 = field_20 * e;
}

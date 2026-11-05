// from server: 45% by colin
struct Vec2 {
    float x;
    float y;
};

struct CylinderBuilder {
    float field0;
    float field4;
    void compute(Vec2* out, float a, float b, float c, float d);
};

extern "C" float __stdcall sqrtf_helper(float);
extern "C" Vec2* __stdcall vec2_helper(Vec2* self, Vec2* out);

void CylinderBuilder::compute(Vec2* out, float a, float b, float c, float d)
{
    float ax = field0 < 0.0f ? -field0 : field0;
    float ay = field4 < 0.0f ? -field4 : field4;

    float result;

    if (ax == ay) {
        if (field4 == 0.0f) {
            result = 0.0f;
        } else {
            Vec2 tmp;
            vec2_helper(&tmp, out);
            float len = sqrtf_helper(tmp.x * tmp.x + tmp.y * tmp.y);
            result = (1.0f - (a / field4) / len) * b;
        }
    } else {
        if (field0 == 0.0f) {
            result = 0.0f;
        } else {
            Vec2 tmp;
            vec2_helper(&tmp, out);
            float len = sqrtf_helper(tmp.x * tmp.x + tmp.y * tmp.y);
            result = (1.0f - (a / field0) / len) * b;
        }
    }

    field0 = field0 * result;
    field4 = field4 * result;
}

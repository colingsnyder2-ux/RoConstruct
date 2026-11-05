// from server: 59% by colin
struct SphereBuilder {
    float x;
    float y;
    void normalize();
};

extern "C" float __stdcall sqrtf_helper(float);

struct Helper {
    void getXY(float* out);
};

void SphereBuilder::normalize() {
    float ax = x < 0.0f ? -x : x;
    float ay = y < 0.0f ? -y : y;

    float scale;
    if (ax == ay) {
        if (y == 0.0f) {
            scale = 1.0f;
        } else {
            float out[2];
            ((Helper*)this)->getXY(out);
            float len = sqrtf_helper(out[0] * out[0] + out[1] * out[1]);
            scale = len / y;
        }
    } else {
        if (x == 0.0f) {
            scale = 1.0f;
        } else {
            float out[2];
            ((Helper*)this)->getXY(out);
            float len = sqrtf_helper(out[0] * out[0] + out[1] * out[1]);
            scale = len / x;
        }
    }

    x = x * scale;
    y = y * scale;
}

// from server: 25% by colin
struct GFont {
    int computeGlyphPositions(float* out, int count, const float* params);
};

extern "C" float __cdecl sqrtf_helper(float);

int GFont::computeGlyphPositions(float* out, int count, const float* params)
{
    float a = params[0];
    float b = params[1];
    float c = params[2];
    float d = params[3];
    float e = params[4];
    float f = params[5];
    float g = params[6];
    float h = params[7];

    float t = a * b - c;
    float u = t * t;
    float v = d * 2.0f - e;
    float w = v * f + g;
    float x = t - w;

    if (x > h) {
        float y = sqrtf_helper(x);
        float z = a - y;
        float p = z * c + d;
        float q = p * e + f;
        if (q < g) {
            float r = q * b;
            out[0] = (float)r;
            out[1] = (float)(r * a);
            return 2;
        }
        float s = q - g;
        float t2 = s * b;
        out[0] = (float)t2;
        out[1] = (float)(t2 * a);
        return 2;
    }

    if (x < -h) {
        float y = sqrtf_helper(-x);
        float z = a + y;
        float p = z * c + d;
        float q = p * e + f;
        if (q < g) {
            float r = q * b;
            out[0] = (float)r;
            out[1] = (float)(r * a);
            return 2;
        }
        float s = q - g;
        float t2 = s * b;
        out[0] = (float)t2;
        out[1] = (float)(t2 * a);
        return 2;
    }

    return 0;
}

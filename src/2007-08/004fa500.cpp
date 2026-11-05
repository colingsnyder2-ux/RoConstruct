// from server: 21% by colin
// roc 2007-08 004fa500  unit: G3D::Lighting  size: 318 bytes

extern "C" double __cdecl pow(double, double);

struct Lighting {
    void applyColorMap(unsigned char* dst, const unsigned char* src);
};

void Lighting::applyColorMap(unsigned char* dst, const unsigned char* src)
{
    int i;
    for (i = 0; i < 3; ++i) {
        unsigned char s = src[i];
        unsigned char d = dst[i];
        float fsrc = (float)s;
        float fdst = (float)d;
        float result;
        if (d > 0x82) {
            float t = (fdst - 130.0f) * (1.0f / 125.0f);
            if (t > 1.0f) t = 1.0f;
            result = fsrc + (255.0f - fsrc) * t;
        } else if (d < 0x7e) {
            float t = fdst * (1.0f / 126.0f);
            result = fsrc * t;
        } else {
            result = fsrc;
        }
        float scaled = result / 255.0f;
        double p = pow((double)scaled, 0.45454545454545453);
        int v = (int)(p * 255.0);
        if (v <= 0) v = 0;
        else if (v >= 0xff) v = 0xff;
        dst[i] = (unsigned char)v;
    }
}

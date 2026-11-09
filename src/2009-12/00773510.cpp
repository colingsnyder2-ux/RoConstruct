// from server: 42% by atomic.potato
extern "C" float __stdcall sqrtf_helper(double);
extern "C" int __stdcall sub_6EC300();
extern "C" long long __stdcall sub_7F4A70(int, int, int, int);

struct CXTCaptionButtonTheme {
    char pad[0xf0];
    float* field_f0;
    int method_6EC300();
};

int CXTCaptionButtonTheme::method_6EC300() {
    float* p = field_f0;
    float a = p[1];
    float b = p[2];
    float c = p[3];
    float m;
    if (b > a) {
        if (c > a) {
            m = c * b;
        } else {
            m = b * a;
        }
    } else {
        if (c > b) {
            m = c * a;
        } else {
            m = b * a;
        }
    }
    float s = sqrtf_helper((double)m);
    int n = (int)s;
    int r = this->method_6EC300();
    long long q = sub_7F4A70(r, 0, n, 0);
    return (int)((double)q - (double)(unsigned long long)q);
}

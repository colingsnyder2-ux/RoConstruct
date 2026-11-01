// from server: 26% by Intel
struct VRegistry {
    bool func_567E60();
    bool func_567780(void* out);

    bool func_568660(unsigned short* a2, float* a3, float* a4, float* a5);
};

extern "C" const float flt_B687A0;

bool VRegistry::func_568660(unsigned short* a2, float* a3, float* a4, float* a5) {
    if (func_567E60()) {
        unsigned short v6;
        if (!func_567780(&v6))
            return false;
        unsigned char high = (v6 >> 8) & 0xFF;
        unsigned char low = v6 & 0xFF;
        unsigned short swapped = (high << 8) | low;
        float t = static_cast<float>(swapped) * flt_B687A0;
        float result = *a3 + (*a4 - *a3) * t;
        if (*a3 > result) {
            *a5 = *a3;
            return true;
        }
        if (result > *a4) {
            *a5 = *a4;
            return true;
        }
        *a5 = result;
        return true;
    } else {
        float v7;
        if (!func_567780(&v7))
            return false;
        float t = v7 * flt_B687A0;
        float result = *a3 + (*a4 - *a3) * t;
        if (*a3 > result) {
            *a5 = *a3;
            return true;
        }
        if (result > *a4) {
            *a5 = *a4;
            return true;
        }
        *a5 = result;
        return true;
    }
}

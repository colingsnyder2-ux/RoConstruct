// from server: 100% by Espeon
// from server: 85% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast

extern const char renderSettingsChanged;

struct CRenderSettings {
    char pad[0x144];
    float field_148;
    float field_144;
    void sub_448FD0(float);
    void sub_40DB00(const void*);
    void setAASamples(float);
};

inline const float& minimum(const float& a, const float& b) { return a > b ? b : a; }
inline const float& maximum(const float& a, const float& b) { return a > b ? a : b; }

void CRenderSettings::setAASamples(float value) {
    if (value < field_148)
        sub_448FD0(value);
    value = maximum(value, field_148);
    extern float lowerLimit;
    float zero = lowerLimit;
    float result = minimum(zero, value);
    if (result != field_144) {
        field_144 = result;
        sub_40DB00(&renderSettingsChanged);
    }
}


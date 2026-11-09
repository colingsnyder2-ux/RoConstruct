// from server: 54% by colin
struct CRenderSettings {
    float getAASamplesSafe(float);
    char pad[0xf0];
    float field_f0;
    float field_f4;
};

float CRenderSettings::getAASamplesSafe(float arg) {
    float local = arg;
    float tmp = 0.0f;
    float v = field_f0;
    if (!(v > local)) {
        local = tmp;
    }
    if (!(local < 0.0)) {
        tmp = local;
    }
    float result = tmp;
    if (!(result == field_f4)) {
        field_f4 = result;
        return 0.0f;
    }
    return result;
}

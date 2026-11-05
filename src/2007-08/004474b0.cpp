// from server: 86% by colin
struct CRenderSettings {
    char pad[0xf0];
    float fullscreenSize;
    float aaSamples;
    float getAASamplesSafe(float);
};

float CRenderSettings::getAASamplesSafe(float value)
{
    float local = 0.0f;
    float* p = &value;
    if (!(value > *(double*)0x78fee0))
        p = &local;
    float v = *p;
    float* q = &aaSamples;
    if (!(v > *q))
        q = p;
    float result = *q;
    if (result != fullscreenSize) {
        fullscreenSize = result;
        return ((float (__stdcall *)(float))0x8bbc88)(result);
    }
    return result;
}

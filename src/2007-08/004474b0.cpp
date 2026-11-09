// from server: 100% by tajop
struct PropDesc { int dummy; };
extern PropDesc desc_8bbc88;
extern const double dbl_78fee0;

struct CRenderSettings {
    char pad[0xf0];
    float fullscreenSize;
    float aaSamples;
    void raisePropertyChanged(const PropDesc& d);
    void setAASamplesSafe(float);
};

void CRenderSettings::setAASamplesSafe(float value)
{
    float local = 0.0f;
    float* p = &value;
    if (!(value > dbl_78fee0))
        p = &local;
    float v = *p;
    float* q = &aaSamples;
    if (v < *q)
        q = p;
    float result = *q;
    if (result != fullscreenSize) {
        fullscreenSize = result;
        raisePropertyChanged(desc_8bbc88);
    }
}

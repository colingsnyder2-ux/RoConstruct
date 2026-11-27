// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /arch:SSE /fp:fast /GS- /EHsc /MD
extern const float kScale;
extern const float kOff;
float f(unsigned char b)
{
    float x = b;
    static float s = kScale;
    return s * x - kOff;
}

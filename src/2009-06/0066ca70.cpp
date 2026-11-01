// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern const float scaleValue;
extern const float offsetValue;

double convert(unsigned char value)
{
    double converted = value;
    static float scale = scaleValue;
    return converted * scale - offsetValue;
}
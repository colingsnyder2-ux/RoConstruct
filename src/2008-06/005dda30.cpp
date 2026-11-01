// from server: 100% by king_originala
extern const float scaleValue;
extern const float offsetValue;

double convert(unsigned char value)
{
    double converted = value;
    static float scale = scaleValue;
    return converted * scale - offsetValue;
}

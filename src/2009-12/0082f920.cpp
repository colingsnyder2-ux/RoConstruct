// from server: 91% by atomic.potato
struct CXTPPaintManagerColor
{
    void SetStandardValue(unsigned int);
    void SetStandardValue(unsigned int, unsigned int, float);
};

extern float g_value;

void CXTPPaintManagerColor::SetStandardValue(unsigned int value)
{
    SetStandardValue(value, value, g_value);
}

// from server: 100% by king_originala
extern void __cdecl formatValue(void *, double, const char *, ...);

struct LaserTool {
    void setValue(const float &value);
};

void LaserTool::setValue(const float &value)
{
    formatValue(this, value, "%.3g", value);
}

// from server: 100% by king_originala
extern void __cdecl formatValue(void *, double, const char *, ...);

struct LaserTool {
    void setValue(const double &value);
};

void LaserTool::setValue(const double &value)
{
    formatValue(this, value, "%.3g", value);
}

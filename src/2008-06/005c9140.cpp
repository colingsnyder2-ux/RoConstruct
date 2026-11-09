// from server: 100% by king_originala
struct LaserTool {
    void setValue(const unsigned int *value);
};

extern const char message[];
extern void __cdecl report(LaserTool *, double, const char *, unsigned int);

void LaserTool::setValue(const unsigned int *value)
{
    unsigned int n = *value;
    report(this, (double)n, message, n);
}

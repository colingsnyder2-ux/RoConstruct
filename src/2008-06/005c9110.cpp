// from server: 100% by king_originala
extern const char label[];
extern void __cdecl helper(void *, double, const char *, int);

struct LaserTool {
    void f(const int *value);
};

void LaserTool::f(const int *value)
{
    int n = *value;
    helper(this, (double)n, label, n);
}

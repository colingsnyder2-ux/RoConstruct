// from server: 31% by atomic.potato
struct S
{
    int pad[125];
    double value;
    void f(double *result);
};

double g_value;

void S::f(double *result)
{
    double value = this->value > 0 ? 0.0 : g_value;
    *result = value;
}

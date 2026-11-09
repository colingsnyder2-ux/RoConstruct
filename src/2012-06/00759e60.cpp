// from server: 66% by atomic.potato
extern "C" void sub_759de0(void *, double, const char *);

struct EventDesc
{
    void f(double *);
};

void EventDesc::f(double *value)
{
    sub_759de0(this, *value, "%.3g");
}

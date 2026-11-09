// from server: 43% by atomic.potato
struct XItem
{
    typedef void (XItem::*Callback)(double);
    int value;
    Callback callback;
    void f(float *);
};

extern "C" void helper(double *);

void XItem::f(float *value)
{
    double converted = *value;
    helper(&converted);
    (this->*callback)(converted);
}

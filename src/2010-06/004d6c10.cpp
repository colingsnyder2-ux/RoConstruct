// from server: 41% by atomic.potato
extern "C" double CallValue(void *, void *);

struct S
{
    void *value;
    int pad[6];
    void *descriptor;
    double f(void *);
};

double S::f(void *arg)
{
    double value = CallValue(*(void **)descriptor, arg);
    return value;
}

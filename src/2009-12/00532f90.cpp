// from server: 65% by atomic.potato
struct Ray
{
    Ray& __cdecl f(double);
    Ray& g(double);
};

Ray& Ray::f(double x)
{
    return g(x);
}

// from server: 65% by atomic.potato
struct Ray
{
    Ray& __cdecl f(double value);
    Ray& g(double value);
};

Ray& Ray::f(double value)
{
    return g(value);
}

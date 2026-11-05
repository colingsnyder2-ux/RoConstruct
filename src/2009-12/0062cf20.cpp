// from server: 74% by atomic.potato
struct Inner {
    char pad[0xe0];
    double value;
};

struct Outer {
    char pad[0xe0];
    Inner inner;
};

extern "C" Outer* __cdecl getObj();

struct Helper {
    double* getValue(double* out);
};

double compute()
{
    Outer* o = getObj();
    double tmp;
    Helper* h = (Helper*)&o->inner;
    double* p = h->getValue(&tmp);
    double v = *p;
    if (0.0 < v)
        return 1.0 / v;
    return 0.0;
}

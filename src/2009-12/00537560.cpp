// from server: 91% by atomic.potato
struct type_info;

extern "C" int __stdcall type_info_before(const type_info *, const type_info *);

struct S {
    int f(type_info *, type_info *);
};

int S::f(type_info *a, type_info *b)
{
    int r = type_info_before(a, b);
    return r != 0;
}

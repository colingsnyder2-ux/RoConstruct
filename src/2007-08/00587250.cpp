// from server: 100% by colin
struct Inner {
    char pad[4];
    unsigned int begin;
    unsigned int end;
};

struct Result {
    Inner* first;
    unsigned int second;
};

extern Inner* getInner();

extern "C" void (__stdcall *invalid_parameter_noinfo)();

Result* func_00587250(Result* out)
{
    Inner* p = getInner();
    unsigned int e = p->end;
    if (p->begin > e)
        invalid_parameter_noinfo();
    out->second = e;
    out->first = p;
    return out;
}

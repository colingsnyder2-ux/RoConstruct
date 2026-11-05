// from server: 100% by king_originala
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Range {
    void* data;
    unsigned int reserved[2];
    unsigned int first;
    unsigned int last;
};

struct Result {
    void* data;
    unsigned int position;
};

struct CopyVerb {
    char reserved[0x154];
    Range* range;
    Result* f(Result* result);
};

Result* CopyVerb::f(Result* result) {
    Range* p = range;
    unsigned int last = p->last;
    result->data = 0;
    if (p->first > last)
        _invalid_parameter_noinfo();
    result->data = p->data;
    result->position = last;
    return result;
}

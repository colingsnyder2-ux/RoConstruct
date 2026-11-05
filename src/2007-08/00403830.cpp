// from server: 100% by Intel
struct Result {
    unsigned int first;
    unsigned int second;
};

struct Source {
    void copy(Result* output);
};

struct S {
    unsigned char padding[0x78];
    Source* source;
    Result* f(Result* output);
};

Result* S::f(Result* output)
{
    volatile unsigned int state = 0;
    if (source) {
        source->copy(output);
        return output;
    }
    output->first = 0;
    output->second = 0;
    return output;
}

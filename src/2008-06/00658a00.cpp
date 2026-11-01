// from server: 100% by king_originala
struct Triple {
    float x, y, z;
};

struct Six {
    float a, b, c, d, e, f;
    void initialize();
};

struct Data {
    char reserved[0x24];
    Triple input;
    Six output;
    void initialize();
};

struct S {
    Data* f(Data* result, const Triple* input);
};

Six* __cdecl compute(S* object, const Triple* input, Data* result);

Data* S::f(Data* result, const Triple* input)
{
    result->initialize();
    result->output.initialize();
    compute(this, input, result);
    return result;
}

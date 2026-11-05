// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Result {
    float x, y, z;
    float depth;
    float u, v, w;
    float extra;
};

extern const float threshold;

struct S {
    int kind;
    void evaluate(Result* result);
    bool f();
};

bool S::f()
{
    if (kind == 4) {
        Result result;
        result.x = 0.0f;
        result.y = 0.0f;
        result.z = 0.0f;
        result.u = 0.0f;
        result.v = 0.0f;
        result.w = 0.0f;
        evaluate(&result);
        return result.depth < threshold;
    }
    return true;
}

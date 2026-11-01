// from server: 100% by king_originala
struct Matrix {
    float data[9];
    Matrix(const Matrix&);
    Matrix() {}
};

struct Result {
    float data[12];
};

extern void __cdecl combine(Matrix*, const Matrix*, const Matrix*);
extern void __cdecl evaluate(Result*, const Result&, const Result&, const Matrix&, float);

struct S {
    char reserved0[0x68];
    Matrix rotation;
    float angle;
    char reserved1[4];
    Matrix adjustment;
    Result frame;

    const void* get();
    Result* f(Result*, const Result&);
};

Result* S::f(Result* output, const Result& value)
{
    float savedAngle = angle;
    get();
    Matrix local(rotation);
    Matrix adjusted;
    combine(&adjusted, &local, &adjustment);
    get();
    evaluate(output, frame, value, adjusted, savedAngle);
    return output;
}

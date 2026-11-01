// from server: 100% by king_originala
struct Matrix {
    float data[9];
    Matrix& operator=(const Matrix&);
};

struct Value {
    Matrix rotation;
    float x, y, z;
};

struct S {
    char padding[8];
    int offset;
    Value* f(Value* result, char* object);
};

Value* S::f(Value* result, char* object)
{
    char* base = object ? object - 20 : 0;
    Value* source = reinterpret_cast<Value*>(base + offset);
    result->rotation = source->rotation;
    result->x = source->x;
    result->y = source->y;
    result->z = source->z;
    return result;
}

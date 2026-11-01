// from server: 100% by king_originala
struct Float6 {
    float a, b, c, d, e, f;
};

struct Value {
    void read(Float6* result);
};

struct ModelInstance {
    char padding[0x228];
    Value value;
    Float6* method(Float6* result);
};

Float6* ModelInstance::method(Float6* result) {
    Float6 temporary;
    value.read(&temporary);
    result->a = temporary.a;
    result->b = temporary.b;
    result->c = temporary.c;
    result->d = temporary.d;
    result->e = temporary.e;
    result->f = temporary.f;
    return result;
}

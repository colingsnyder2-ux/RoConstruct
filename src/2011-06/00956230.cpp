// from server: 100% by atomic.potato
struct S {
    int a, b, c, d, e, f;
    float g, h;
    S* copy(const S* other);
};

S* S::copy(const S* other) {
    S* result = this;
    result->a = other->a;
    result->b = other->b;
    result->c = other->c;
    result->d = other->d;
    result->e = other->e;
    result->f = other->f;
    result->g = other->g;
    result->h = other->h;
    return result;
}

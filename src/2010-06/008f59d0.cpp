// from server: 100% by atomic.potato
struct S {
    float data[8];
    S* copy(const S* other);
};

S* S::copy(const S* other) {
    data[0] = other->data[0];
    data[1] = other->data[1];
    data[2] = other->data[2];
    data[3] = other->data[3];
    data[4] = other->data[4];
    data[5] = other->data[5];
    data[6] = other->data[6];
    data[7] = other->data[7];
    return this;
}

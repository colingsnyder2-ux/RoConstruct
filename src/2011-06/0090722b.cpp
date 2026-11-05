// from server: 57% by atomic.potato
struct S {
    float field0;
    float field4;
    float field8;
    float fieldC;
};

void __stdcall func_0090722b(S* out, const S* a, const S* b) {
    out->field0 = b->field0;
    out->field4 = b->field4;
    out->field8 = b->field8;
    out->fieldC = -(a->field4 * b->field4 + a->field8 * b->field8 + a->field0 * b->field0);
}

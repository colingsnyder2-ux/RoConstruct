// from server: 56% by colin
// roc 2007-08 004a4760  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a4760

extern "C" void __cdecl sub_62fc62(void*);

struct S {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
};

S* __stdcall assign(S* self, S* other, int a, int b, int c) {
    S* result;
    if (self != 0) {
        self->field4 = (int)other;
        self->field10 = a;
        self->field14 = b;
        result = self;
    } else {
        result = 0;
    }
    int old = other->field18;
    if (result != (S*)old) {
        sub_62fc62((void*)old);
    }
    other->field18 = (int)result;
    return other;
}

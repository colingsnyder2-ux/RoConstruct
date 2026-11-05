// from server: 31% by atomic.potato
extern "C" unsigned int __stdcall sub_720ac0(void*);
extern "C" void* __stdcall sub_759fc0(void*, unsigned int);

struct Inner {
    char pad0[4];
    void* field4;
    unsigned int field8;
    unsigned int fieldC;
    unsigned int field10;
};

struct Outer {
    char pad0[0xC];
    unsigned int fieldC;
    Inner inner;
    char pad20[0xC];
    unsigned int field20;
};

struct Result {
    void* ptr;
    void* val;
    char flag;
};

struct S {
    Result* method(void* a, void* b);
    void* sub_5ac010(void*, void*);
    void* sub_5ac210(void*);
    void* sub_5ac560(void*, void*);
};

Result* S::method(void* a, void* b)
{
    Outer* self = (Outer*)this;
    unsigned int n = sub_720ac0(b);
    unsigned int idx = n % self->inner.field8;
    void* slot = (char*)self->inner.field4 + idx * 4;
    void* r = sub_5ac010(slot, b);
    if (r != 0) {
        Result* out = (Result*)a;
        out->ptr = slot;
        out->val = r;
        out->flag = 0;
        return out;
    }
    Inner* inner = &self->inner;
    void* tmp = 0;
    sub_5ac210(&tmp);
    unsigned int cnt = self->field20;
    unsigned int next = cnt + 1;
    if (next >= self->fieldC) {
        unsigned int half = cnt >> 1;
        unsigned int cap = cnt + half;
        if (cap <= next) cap = next;
        void* p = sub_759fc0(self, cap);
        sub_5ac560(self, p);
        unsigned int n2 = sub_720ac0(b);
        unsigned int idx2 = n2 % inner->field8;
        slot = (char*)inner->field4 + idx2 * 4;
    }
    void* node;
    if (tmp != 0) {
        node = (char*)tmp + 0x14;
    } else {
        node = 0;
    }
    *(void**)node = *(void**)slot;
    *(void**)slot = node;
    inner->field10 += 1;
    if (slot < (void*)inner->fieldC) {
        inner->fieldC = (unsigned int)slot;
    }
    Result* out = (Result*)a;
    out->ptr = slot;
    out->val = node;
    out->flag = 1;
    return out;
}

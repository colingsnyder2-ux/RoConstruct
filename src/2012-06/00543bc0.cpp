// from server: 39% by atomic.potato
struct Inner {
    char pad0[0xc];
    char data[1];
};

struct Outer {
    char pad0[4];
    Inner* field4;
};

struct S {
    char pad0[4];
    Inner* field4;
    Inner* find(Inner*);
    bool equals(Inner*);
};

extern "C" Inner* __fastcall sub_541990(S* self, int, Inner* arg);
extern "C" bool __fastcall sub_72b3e0(Inner* self, int, Inner* arg);

Inner* S::find(Inner* arg) {
    Inner* result = sub_541990(this, 0, arg);
    if (result != this->field4) {
        if (!sub_72b3e0(arg, 0, result + 0xc)) {
            return result;
        }
    }
    return this->field4;
}

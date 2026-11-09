// from server: 48% by atomic.potato
struct Inner {
    char pad0[0xc];
    int* begin;
    int* end;
    int empty();
};

struct Mid {
    char pad0[0x4c];
    Inner* inner;
};

struct Outer {
    char pad0[0xc];
    Mid* mid;
    int check();
};

extern "C" Mid* __cdecl sub_4bd3e0(Outer* self);

int Outer::check() {
    Mid* m = this->mid;
    if (m == 0) {
        return 0;
    }
    m = sub_4bd3e0(this);
    if (m == 0) {
        return 0;
    }
    Inner* in = m->inner;
    if (in == 0) {
        return 0;
    }
    int n = (int)((char*)in->end - (char*)in->begin) >> 3;
    return n != 0;
}

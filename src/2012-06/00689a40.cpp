// from server: 100% by atomic.potato
struct Elem {
    char pad[96];
};

struct Container {
    char pad0[4];
    Elem* begin;
    Elem* end;
    int* f(int* out, Elem* pos, int b);
};

struct Caller {
    void sub_6896c0(Elem* pos, int a, int b);
};

int* Container::f(int* out, Elem* pos, int b) {
    Elem* first = begin;
    int count = (int)((char*)end - (char*)first) / 96;
    int idx;
    if (count == 0) {
        idx = 0;
    } else {
        idx = (int)((char*)pos - (char*)first) / 96;
    }
    ((Caller*)this)->sub_6896c0(pos, 1, b);
    *out = (int)(begin + idx);
    return out;
}

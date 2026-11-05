// from server: 100% by tester
struct Skin {
    char pad[0x84];
    int field_134;
    void sub_5D3AA0(int arg);
};

struct Arg {
    int sub_5D8A10();
    int sub_5D8B10();
    int sub_5D8C10();
    int sub_5D8D10();
    int sub_5D8E10();
    int sub_5D8F10();
};

struct Res {
    void sub_59DF40(int);
};

void Skin::sub_5D3AA0(int arg) {
    Arg* a = (Arg*)arg;
    Res* r;
    r = (Res*)a->sub_5D8A10();
    if (r) {
        r->sub_59DF40(field_134);
    }
    r = (Res*)a->sub_5D8C10();
    if (r) {
        r->sub_59DF40(field_134);
    }
    r = (Res*)a->sub_5D8D10();
    if (r) {
        r->sub_59DF40(field_134);
    }
    r = (Res*)a->sub_5D8B10();
    if (r) {
        r->sub_59DF40(field_134);
    }
    r = (Res*)a->sub_5D8E10();
    if (r) {
        r->sub_59DF40(field_134);
    }
    r = (Res*)a->sub_5D8F10();
    if (r) {
        r->sub_59DF40(field_134);
    }
}

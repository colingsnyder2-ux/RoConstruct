// from server: 100% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct Explosion {
    char pad[0xe8];
    int field_e8;
    void sub_57AA50(int, int);
    void sub_5E9220(int, int);
};

struct Other {
    char pad[0x100];
    void sub_432530(int);
    void sub_5B2DE0(int);
};

extern "C" int __fastcall sub_450D00(int);

void Explosion::sub_5E9220(int a, int b) {
    int* p;
    if (this) {
        p = &this->field_e8;
    } else {
        p = 0;
    }
    if (a) {
        int r = sub_450D00(a);
        if (r) {
            ((Other*)(r + 0x100))->sub_432530((int)p);
        }
    }
    sub_57AA50(a, b);
    int* p2;
    if (this) {
        p2 = &this->field_e8;
    } else {
        p2 = 0;
    }
    if (b) {
        int r = sub_450D00(b);
        if (r) {
            ((Other*)(r + 0x100))->sub_5B2DE0((int)p2);
        }
    }
}

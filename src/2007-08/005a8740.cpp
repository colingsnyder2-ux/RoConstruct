// from server: 100% by colin
struct Humanoid {
    char pad[0x124];
    int field_124;
    void sub_57AA50(int, int);
    void sub_5A8740(int, int);
};

struct Other {
    char pad[0x100];
    void sub_432530(int);
    void sub_5B2DE0(int);
};

extern "C" int __fastcall sub_450EC0(int);

void Humanoid::sub_5A8740(int a, int b) {
    int* p124;
    if (this) {
        p124 = &this->field_124;
    } else {
        p124 = 0;
    }
    if (a) {
        int r = sub_450EC0(a);
        if (r) {
            ((Other*)(r + 0x100))->sub_432530((int)p124);
        }
    }
    sub_57AA50(a, b);
    int* p124b;
    if (this) {
        p124b = &this->field_124;
    } else {
        p124b = 0;
    }
    if (b) {
        int r = sub_450EC0(b);
        if (r) {
            ((Other*)(r + 0x100))->sub_5B2DE0((int)p124b);
        }
    }
}

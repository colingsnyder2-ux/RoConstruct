// from server: 100% by colin
// roc 2007-08 0048f3d0  unit: RBX::Network::Player  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048f3d0

extern "C" int __cdecl sub_486830(int);
extern "C" char __cdecl sub_49E5E0(int, int);
char __cdecl sub_4915C0(int a, int b);
char __cdecl sub_4915F0(int a, int b);
double __cdecl sub_4FFF30();

struct Player {
    void sub_48F120(int);
    void sub_48F2D0();
    void sub_48E590();
    void sub_57AA50(int, int);
    void setParent(int, int);
};

void Player::setParent(int a, int b)
{
    if (a != 0) {
        if (sub_4915F0(a, 1) != 0) {
            sub_48F120(0);
        }
    }
    sub_57AA50(a, b);
    if (b != 0) {
        if (sub_4915C0(b, 1) != 0) {
            sub_48E590();
        }
    }
    if (a == 0) {
        if (sub_4915C0(b, 1) != 0) {
            *(double*)((char*)this + 0x160) = sub_4FFF30();
            sub_48F2D0();
        }
    }
}

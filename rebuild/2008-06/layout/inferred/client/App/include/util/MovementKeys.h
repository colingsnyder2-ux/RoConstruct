#pragma once
namespace RBX {
struct MovementKeys {
    unsigned char up, down, left, right, w, s, a, d, space;
    MovementKeys() : up(false), down(false), left(false), right(false),
        w(false), s(false), a(false), d(false), space(false) {}
    bool any() const;
    bool sub_005a0160() const;   // INFERRED: 005a0160, placeholder name (identity tier), body byte-proved (Inferred_005a0160.cpp)
};
}

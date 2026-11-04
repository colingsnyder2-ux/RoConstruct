#pragma once
namespace RBX {
// Original field order established by 005ce960 SDL key queries.
// Descriptive type/member names; original symbols unproven.
struct MovementKeys {
    bool up, down, left, right, w, s, a, d, space;
    MovementKeys() : up(false), down(false), left(false), right(false),
        w(false), s(false), a(false), d(false), space(false) {}
    // Return type provisional: original body writes EAX; render caller tests AL.
    int any() const;
};
}

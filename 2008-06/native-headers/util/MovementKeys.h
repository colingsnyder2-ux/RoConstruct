#pragma once
// >>> native-status (generated) -- do not edit >>>
// MovementKeys | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src b5d50a4f | roc native-status --write
namespace RBX {
// Original byte field order established by 005ce960 SDL key queries.
// Byte fields + bool predicate jointly reproduce reader, predicate and render caller.
// Descriptive type/member names; original symbols unproven.
struct MovementKeys {
    unsigned char up, down, left, right, w, s, a, d, space;
    MovementKeys() : up(false), down(false), left(false), right(false),
        w(false), s(false), a(false), d(false), space(false) {}
    bool any() const;
};
}

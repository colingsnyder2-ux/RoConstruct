// =============================================================================
// MovementKeys.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/MovementKeys.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
namespace RBX
{
struct MovementKeys {
    unsigned char up, down, left, right, w, s, a, d, space;
    MovementKeys() : up(false), down(false), left(false), right(false),
        w(false), s(false), a(false), d(false), space(false) {}
    bool any() const;
    bool sub_005a0160() const;   // INFERRED: 005a0160, placeholder name (identity tier), body byte-proved (Inferred_005a0160.cpp)
};
}

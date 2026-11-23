// =============================================================================
// scopedassign.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/scopedassign.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#ifndef UTIL_SCOPEDASSIGN_H
#define UTIL_SCOPEDASSIGN_H

namespace RBX
{

// SIZE 0x8
template <class T>
class ScopedAssign
{
public:
	ScopedAssign(T& value, const T& newValue) : value(&value), oldValue(value) { value = newValue; }

	~ScopedAssign() { *value = oldValue; }

private:
	T* value;   // 0x00
	T oldValue; // 0x04
};

// clang-format off
// TEMPLATE: WEBSERVICE 0x1019bf50
// RBX::ScopedAssign<int>::~ScopedAssign<int>
// clang-format on

} // namespace RBX

#endif // UTIL_SCOPEDASSIGN_H

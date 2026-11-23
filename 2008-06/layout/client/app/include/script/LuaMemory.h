// =============================================================================
// LuaMemory.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/script/LuaMemory.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once

class LuaAllocator
{
private:
    size_t heapSize;
    size_t heapCount;
    size_t maxHeapSize;
    size_t maxHeapCount;

public:
    LuaAllocator();
    void clearHeapMax();
    void getHeapStats(size_t&, size_t&) const;
    void getHeapStats(size_t& heapSize, size_t& heapCount, size_t& maxHeapSize, size_t& maxHeapCount) const;
    void* alloc(void* ptr, size_t osize, size_t nsize);

public:
    static void* alloc(void* ud, void* ptr, size_t osize, size_t nsize);
};

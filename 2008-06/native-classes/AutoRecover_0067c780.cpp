// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: element is an 8-byte pair whose second dword is a float sort key.
struct HeapElem {
    int   first;
    float key;
};

// INFERRED: the disassembly shows a plain cdecl call with 5 stack args
// (base, hole, top, value by value as 2 dwords), caller pops 0x14.
// This is the push_heap step.
extern "C" void fn_0067c640(HeapElem* base, int hole, int top, HeapElem value);

// INFERRED: std::__adjust_heap on 8-byte elements, compared by the float key.
extern "C" void fn_0067c780(HeapElem* first, int holeIndex, int len, HeapElem value)
{
    int topIndex = holeIndex;
    int child = 2 * holeIndex + 2;
    while (child < len) {
        // INFERRED: comparator written as greater-than on [child-1] vs [child]
        if (first[child - 1].key > first[child].key)
            --child;
        first[holeIndex] = first[child];
        holeIndex = child;
        child = 2 * (child + 1);
    }
    if (child == len) {
        first[holeIndex] = first[len - 1];
        holeIndex = len - 1;
    }
    fn_0067c640(first, holeIndex, topIndex, value);
}

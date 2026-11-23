// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is std::__adjust_heap for 8-byte elements ordered by the float in the second dword.
struct HeapElem {
    int   a;
    float key;
};

// INFERRED: the disassembly pushes 5 stack args and the caller pops 0x14, so this is declared
// as plain cdecl with 5 args rather than the __fastcall form suggested in the task.
// It is the push_heap step.
extern "C" void fn_0067c640(HeapElem* first, int hole, int top, int v0, int v1);

extern "C" void fn_0067c780(HeapElem* first, int hole, int len, int v0, int v1)
{
    int top = hole;
    int child = 2 * hole + 2;
    while (child < len) {
        if (first[child - 1].key > first[child].key)
            --child;
        first[hole] = first[child];
        hole = child;
        child = 2 * child + 2;
    }
    if (child == len) {
        first[hole] = first[len - 1];
        hole = len - 1;
    }
    fn_0067c640(first, hole, top, v0, v1);
}

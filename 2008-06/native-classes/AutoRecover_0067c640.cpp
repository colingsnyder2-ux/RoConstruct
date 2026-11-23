// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is std::__push_heap on 8-byte {int, float} elements, ordered by the float member.
struct HeapPair {
    int   first;
    float second;
};

extern "C" void fn_0067c640(HeapPair* heap, int hole, int top, HeapPair value)
{
    int parent = (hole - 1) / 2;
    while (top < hole && heap[parent].second < value.second) {
        heap[hole] = heap[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    heap[hole] = value;
}

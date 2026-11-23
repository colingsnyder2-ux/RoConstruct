// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::make_heap body for float*; callee is the adjust-heap helper.
// Disassembly shows only 4 stack args (first, hole, len, value), not the 7 in the
// inferred prototype; ecx passes through from the caller unchanged.
extern "C" void fn_00678780(float* first, int hole, int len, float value);

extern "C" void fn_00678910(float* first, float* last)
{
    int len = (int)(last - first);
    int parent = len / 2;
    while (parent > 0) {
        --parent;
        fn_00678780(0, 0, first, parent, len, first[parent]);
    }
}

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::__adjust_heap shape (sift down to leaf, then push-heap via fn_00678660)
extern "C" void fn_00678660(float* first, int hole, int top, float value);

extern "C" void fn_00678780(float* first, int hole, int len, float value)
{
    int top = hole;
    int child = 2 * hole + 2;
    while (child < len) {
        if (first[child - 1] > first[child])
            --child;
        first[hole] = first[child];
        hole = child;
        child = 2 * child + 2;
    }
    if (child == len) {
        first[hole] = first[len - 1];
        hole = len - 1;
    }
    fn_00678660(first, hole, top, value);
}

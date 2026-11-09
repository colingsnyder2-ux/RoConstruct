// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#pragma float_control(precise, off)

int __stdcall equal(const float* a, const float* b)
{
    if (*a == *b)
        return 1;
    return 0;
}
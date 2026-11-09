// from server: 100% by king_originala
#pragma float_control(precise, off)

int __stdcall equal(const float* a, const float* b)
{
    if (*a == *b)
        return 1;
    return 0;
}

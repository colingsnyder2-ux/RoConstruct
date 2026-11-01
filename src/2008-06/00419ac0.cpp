// from server: 100% by king_originala
extern "C" int __cdecl zero_case(int value);
extern "C" int __cdecl nonzero_case(int value);

extern "C" int __cdecl dispatch(int value)
{
    if (value == 0)
        return zero_case(value);
    return nonzero_case(value);
}

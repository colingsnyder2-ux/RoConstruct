// from server: 100% by king_originala
extern int __cdecl zero_case(int);
extern int __cdecl nonzero_case(int);

int __cdecl dispatch(int value)
{
    if (value == 0)
        return zero_case(value);
    return nonzero_case(value);
}

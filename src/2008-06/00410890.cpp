// from server: 100% by king_originala
extern "C" int __cdecl target_zero(int value);
extern "C" int __cdecl target_nonzero(int value);

int __cdecl dispatch(int value)
{
    if (value == 0)
        return target_zero(value);
    return target_nonzero(value);
}

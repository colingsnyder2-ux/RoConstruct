// from server: 100% by king_originala
extern bool __cdecl helper(void* value);

long __cdecl function(void* value)
{
    return helper(value) ? 0L : (long)0x80004005UL;
}

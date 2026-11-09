// from server: 100% by king_originala
struct TraitsTag {};
struct CheckedTag {};

TraitsTag __cdecl classify(char *const &, char *const &);
char *__cdecl copy_range(char *, char *, char *, char *, TraitsTag, CheckedTag);

#pragma optimize("", off)
char *__cdecl copy_dispatch(char *first, char *last, char *dest, char *destLast)
{
    return copy_range(first, last, dest, destLast,
                      classify(first, first), CheckedTag());
}
#pragma optimize("", on)

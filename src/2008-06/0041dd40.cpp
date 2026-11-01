// from server: 100% by king_originala
extern "C" int __cdecl helper(void *);

extern "C" int __cdecl function(void *arg, int kind)
{
    if (kind == 4)
        return (int)0x80004005;
    return helper(arg);
}

// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

// Element size from the target's mul/push immediate; ctor and dtor are out of line.
struct ElemN { ElemN(); ~ElemN(); int words[2]; };

template <class Type>
Type* OP_NEW_ARRAY(const int count, const char *file, unsigned int line)
{
    if (count == 0)
        return 0;
    (void) file; (void) line;
    return new Type[count];
}

template ElemN* OP_NEW_ARRAY<ElemN>(const int, const char *, unsigned int);

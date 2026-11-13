// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string-iterators /O1
// App unit 0046c000 (2008-06), inactive: the std::string const_iterator operator* instance at 0046f940 (49 B; its
// callers are 005dfdbe / 005dfddb, the linker kept this COMDAT copy between the LDraw2Lua rows). Exact only with the
// opt-in xstring of std-noinline-string-iterators (out-of-line _Myptr / size, as stringCompareNoCase 0046f9f0 needs)
// and /O1: the original shares one epilogue (mov eax, [esi+4]; pop edi; pop esi; ret) that /O2 duplicates (54 B).
// >>> native-status (generated) -- do not edit >>>
// AppUnit46CStringIterators | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 31e4bd48 | roc native-status --write
#include <string>

template const char& std::_String_const_iterator<char, std::char_traits<char>, std::allocator<char> >::operator*() const;

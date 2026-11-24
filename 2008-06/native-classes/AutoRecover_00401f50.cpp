// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: body of ATL::CRegParser::ChToByte (atl-8.0 atl.cpp), emitted
// directly under the fixed fn_<address> C-linkage name.
extern "C" unsigned char fn_00401f50(const char ch)
{
    switch (ch) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        return (unsigned char)(ch - '0');
    case 'A': case 'B': case 'C':
    case 'D': case 'E': case 'F':
        return (unsigned char)(10 + (ch - 'A'));
    case 'a': case 'b': case 'c':
    case 'd': case 'e': case 'f':
        return (unsigned char)(10 + (ch - 'a'));
    default:
        // ATLASSERT(FALSE) compiled out in release
        return 0;
    }
}

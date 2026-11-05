// from server: 86% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
char* __cdecl allocChars(unsigned int n, char* hint);
char* __cdecl allocate(unsigned int n)
{
    return allocChars(n, 0);
}

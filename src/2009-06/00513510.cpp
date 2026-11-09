// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
unsigned int CountWords(const unsigned int* p, unsigned int n)
{
    while (n) {
        --n;
        if (p[n] != 0)
            return n + 1;
    }
    return 0;
}

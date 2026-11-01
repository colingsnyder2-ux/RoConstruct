// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern const char LogTable256[256];
int highestBit(unsigned int v)
{
    unsigned int t, tt;
    if ((tt = v >> 16) != 0)
        return (t = tt >> 8) ? 24 + LogTable256[t] : 16 + LogTable256[tt];
    else
        return (t = v >> 8) ? 8 + LogTable256[t] : LogTable256[v];
}

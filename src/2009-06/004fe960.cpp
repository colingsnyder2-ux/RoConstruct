// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __cdecl memset(void*, int, unsigned int);
#pragma function(memset)
struct Entry { int a, b, c, d; };
struct Table {
    int hdr;
    Entry entries[3];
    void init(Entry* e);
};
extern Table g_table;
Entry* __stdcall getEntry(unsigned int i)
{
    if (i >= 3)
        i = 9;
    memset(g_table.entries, 0, sizeof(g_table.entries));
    g_table.init(g_table.entries);
    return &g_table.entries[i];
}

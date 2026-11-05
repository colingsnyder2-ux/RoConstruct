// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Part { char pad[0x1c0]; int id; };
extern int g_index;
struct Table {
    int header;
    bool cells[4][8][8];
    bool get(const Part* a, const Part* b) const;
};
bool Table::get(const Part* a, const Part* b) const
{
    return cells[g_index][a->id][b->id];
}

// from server: 51% by atomic.potato
struct CSettingsExplorer
{
    int IsAncestor(CSettingsExplorer *);
    CSettingsExplorer *field_4c;
};

int CSettingsExplorer::IsAncestor(CSettingsExplorer *p)
{
    CSettingsExplorer *q = field_4c;
    if (p == q)
        return 1;
    while (q != 0)
    {
        q = q->field_4c;
        if (p == q)
            return 1;
    }
    return 0;
}

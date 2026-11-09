// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct S {
    int count;
    int reserved;
    struct Record {
        float value;
        float v[4];
    } records[100];
    S();
};
S::S()
{
    count = 0;
    Record* p = records;
    int n = 99;
    do {
        p->value = -1.0f;
        for (int j = 0; j < 4; j++)
            p->v[j] = -1.0f;
        ++p;
    } while (--n >= 0);
}

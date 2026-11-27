// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Entry { char pad[28]; };
extern Entry g_pool[8];
extern unsigned char g_counter;

struct Creator
{
    void build(void* a1, Entry* e, void* a2);
    Entry* create(void* a1, void* a2);
};

Entry* Creator::create(void* a1, void* a2)
{
    unsigned char index = g_counter++;
    Entry* e = &g_pool[index & 7];
    build(a1, e, a2);
    return e;
}

// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern unsigned char g_flag;
extern char (__cdecl *g_handler)(const char*, const char*, int);
void __cdecl failAssert(unsigned char, const char*);
struct V3 { int x, y, z; };
struct Sub { int level(); };
struct Hash { char pad[0x1e0]; Sub sub; };
struct Node { short level; int a; V3 v; Hash* owner; };
void __stdcall f(Node* node, Hash* p, const V3* v, int a)
{
    if (g_flag) {
        if (node->level != p->sub.level()) {
            if (!g_handler || !g_handler("node->level == p->getSpatialNodeLevel()", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\Include\\v8World/SpatialHashMultiRes.inl", 0xc5))
                failAssert(g_flag, "node->level == p->getSpatialNodeLevel() file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\Include\\v8World/SpatialHashMultiRes.inl line: 197");
        }
    }
    node->owner = p;
    node->v = *v;
    node->a = a;
}

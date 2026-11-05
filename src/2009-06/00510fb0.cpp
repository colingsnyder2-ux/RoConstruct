// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Block { int v[6]; };
void process(int b, int c, int d, int e, int v0, int v1, int v2, int v3, int v4, int v5, int a);
class Job {
public:
    Block blk;
    int d;
    void* ready;
    int pad[2];
    int c;
    bool run(int a, int b);
};
bool Job::run(int a, int b)
{
    if (!ready)
        return false;
    process(b, c, d, c, blk.v[0], blk.v[1], blk.v[2], blk.v[3], blk.v[4], blk.v[5], a);
    return true;
}

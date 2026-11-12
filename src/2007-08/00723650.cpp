// from server: 72% by EspClaude
// roc 2007-08 00723650  unit: CXTIconHandle  size: 226 bytes
// zlib 1.2.3 trees.c scan_tree (bl_tree at deflate_state+0xa7c, REP_3_6/REPZ_3_10/REPZ_11_138 at +0xabc/+0xac0/+0xac4).
typedef unsigned short ush;
struct ct_data { union { ush freq; ush code; } fc; union { ush dad; ush len; } dl; };
struct deflate_state { char pad[0xa7c]; ct_data bl_tree[2*19+1]; };
#define Freq fc.freq
#define Len dl.len
#define REP_3_6 16
#define REPZ_3_10 17
#define REPZ_11_138 18

void scan_tree(deflate_state* s, ct_data* tree, int max_code)
{
    int n;
    int prevlen = -1;
    int curlen;
    int nextlen = tree[0].Len;
    int count = 0;
    int max_count = 7;
    int min_count = 4;

    if (nextlen == 0) max_count = 138, min_count = 3;
    tree[max_code+1].Len = (ush)0xffff;

    for (n = 0; n <= max_code; n++) {
        curlen = nextlen; nextlen = tree[n+1].Len;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            s->bl_tree[curlen].Freq += count;
        } else if (curlen != 0) {
            if (curlen != prevlen) s->bl_tree[curlen].Freq++;
            s->bl_tree[REP_3_6].Freq++;
        } else if (count <= 10) {
            s->bl_tree[REPZ_3_10].Freq++;
        } else {
            s->bl_tree[REPZ_11_138].Freq++;
        }
        count = 0; prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138, min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6, min_count = 3;
        } else {
            max_count = 7, min_count = 4;
        }
    }
}

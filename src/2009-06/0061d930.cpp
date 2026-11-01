// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <streambuf>
extern bool table_0061d930[];
struct Reader_0061d930 {
    int pad;
    std::streambuf* buf;
    void skip();
};
void Reader_0061d930::skip()
{
    int c = buf->sgetc();
    while (c != -1 && table_0061d930[(char)c]) {
        buf->sbumpc();
        c = buf->sgetc();
    }
}

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct basic_streambuf_DU
{
    __declspec(dllimport) int pubsync();
};

struct stream_buffer
{
    char pad[0xc];
    basic_streambuf_DU buf;
};

int sub_006133b0(stream_buffer** p)
{
    return (*p)->buf.pubsync();
}

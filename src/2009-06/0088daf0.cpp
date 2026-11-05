// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
int g_count;
struct Content;
Content* getContent();
struct Init {
    Init() { ++g_count; getContent(); }
    ~Init() {}
};
Init g_init;

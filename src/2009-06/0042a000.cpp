// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Item { int* p; Item() : p(0) {} ~Item() {} };
static Item& instance() { static Item s; return s; }
void initInstance() { instance(); }

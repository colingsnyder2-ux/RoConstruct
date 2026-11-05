// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
extern "C" long __stdcall PdhCloseQuery(void* q);
struct PdhQuery { void* query; ~PdhQuery() { PdhCloseQuery(query); } };
void destroyQuery(PdhQuery* p) { delete p; }

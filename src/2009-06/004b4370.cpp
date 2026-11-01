// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
void __cdecl operator delete(void*);
struct SmallBuf {
    void* data;
    unsigned size;
    unsigned capacity;
    ~SmallBuf();
};
SmallBuf::~SmallBuf() { if (capacity > 8 && data) operator delete(data); }

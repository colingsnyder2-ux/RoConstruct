// from server: 100% by EspClaude
// roc 2009-06 00486fd0  unit: Ogre (dtor)
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
void __cdecl operator delete(void*);
struct LightClippingInfo {
    char pad[0x50];
    void* head;    // 0x50
    int size;
    void* alloc;
    void* first;   // 0x5c
    void* last;
    void* end;
    ~LightClippingInfo();
};
LightClippingInfo::~LightClippingInfo()
{
    if (first) operator delete(first);
    first = 0; last = 0; end = 0;
    operator delete(head);
}

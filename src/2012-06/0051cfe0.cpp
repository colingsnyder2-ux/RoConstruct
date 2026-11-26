// from server: 100% by Xemicl
// roc 2012-06 0051cfe0  unit: Ogre::istreamDataStream  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051cfe0
//
// 0051cfe0  83790808             cmp dword ptr [ecx + 8], 8
// 0051cfe4  760d                 jbe 0x51cff3
// 0051cfe6  8b01                 mov eax, dword ptr [ecx]
// 0051cfe8  85c0                 test eax, eax
// 0051cfea  7407                 je 0x51cff3
// 0051cfec  50                   push eax
// 0051cfed  e8c8534600           call 0x9823ba
// 0051cff2  59                   pop ecx
// 0051cff3  c3                   ret 
// copied from an identical function in another client (function ??1SmallBuf@@QAE@XZ)

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
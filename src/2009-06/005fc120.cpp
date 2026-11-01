// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) void* __stdcall HeapAlloc(void*, unsigned long, size_t);

struct HeapObject {
    static void* operator new(size_t n)
    {
        void* p = HeapAlloc(GetProcessHeap(), 0, n);
        if (!p)
            throw std::bad_alloc();
        return p;
    }
    virtual ~HeapObject() {}
};
HeapObject* createHeapObject()
{
    return new HeapObject;
}

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
#include <new>
struct Buffer {
    union { char data[8]; char* ptr; };
    unsigned int size;
    Buffer(const Buffer& o) : size(o.size) {
        ptr = 0;
        char* dst;
        const char* src;
        if (size <= 8) { dst = data; src = o.data; }
        else { dst = ptr = (char*)operator new(size); src = o.ptr; }
        memcpy(dst, src, size);
    }
    ~Buffer() { if (size > 8 && ptr) operator delete(ptr); }
};
struct Item {
    Buffer buf;
    int value;
};
struct Flag { bool b; Flag(bool v) : b(v) {} };
struct S {
    bool g(Item item, int a, Flag f);
    bool f(Item item, int a);
};
bool S::f(Item item, int a)
{
    return g(item, a, Flag(false));
}

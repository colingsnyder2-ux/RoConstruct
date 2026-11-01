// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
#include <new>
struct Buffer {
    union { char data[8]; char* ptr; };
    unsigned int size;
    char* get() { return size <= 8 ? data : ptr; }
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
    Item(Buffer b, int v);
};
Item::Item(Buffer b, int v) : buf(b), value(v) {}

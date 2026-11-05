// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern void __cdecl read_count(unsigned int, unsigned int *);
extern void __cdecl read_key(unsigned int, unsigned int *);
extern void __cdecl read_string(unsigned int, std::string *);

struct S {
    unsigned char padding[12];
    unsigned int *begin;
    unsigned int *end;
    unsigned int *capacity;
    unsigned int bits;

    void reserve(unsigned int, unsigned int);
    void insert(std::string, unsigned int);
    void func_004b17f0(unsigned int);
};

void S::func_004b17f0(unsigned int count)
{
    unsigned int source = count;
    read_count(source, &count);
    reserve(count, 0);

    for (unsigned int i = 0; i < count; ++i) {
        unsigned int key;
        read_key(source, &key);
        std::string text;
        read_string(source, &text);
        insert(text, key);
    }

    unsigned int size = end - begin;
    unsigned int result = ~0u;
    while (size > 0) {
        size >>= 1;
        ++result;
    }
    bits = result + 1;
}

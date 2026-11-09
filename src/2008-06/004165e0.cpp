// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_safearrayvectorf35682ede47b583a.cpp

// Candidate translation unit (score above; library headers required).
// from server: 89% by colin
typedef long HRESULT;

struct Element {
    char data[16];
};

struct SafeArray {
    char padding[12];
    Element* data;
};

struct SafeArrayBound {
    unsigned long count;
    long lower;
};

extern "C" SafeArray* (__stdcall *SafeArrayCreate)(
    unsigned short, unsigned int, SafeArrayBound*);
extern "C" HRESULT (__stdcall *SafeArrayLock)(SafeArray*);
extern "C" HRESULT (__stdcall *SafeArrayUnlock)(SafeArray*);

struct ArrayAccess {
    SafeArray* array;
    Element* f(unsigned int index);
    ~ArrayAccess();
};

ArrayAccess::~ArrayAccess()
{
    if (array)
        SafeArrayUnlock(array);
}

struct Value {
    unsigned long words[2];
};

#include <vector>
typedef std::vector<Value> Values;

extern void __cdecl G1_func_00416370(Value*, Element*);

SafeArray* __cdecl func_004165e0(Values* values)
{
    ArrayAccess access;
    SafeArrayBound bound;
    bound.count = static_cast<unsigned long>(
        values->size());
    bound.lower = 0;

    SafeArray* result = SafeArrayCreate(12, 1, &bound);
    access.array = result;

    if (result)
        SafeArrayLock(result);

    unsigned int i = 0;
    unsigned int count = static_cast<unsigned int>(
        values->size());
    while (i < count) {
        Value* value = &(*values)[i];
        G1_func_00416370(value, access.f(i));
        ++i;
        count = static_cast<unsigned int>(
            values->size());
    }

    SafeArrayUnlock(result);
    access.array = 0;
    return result;
}

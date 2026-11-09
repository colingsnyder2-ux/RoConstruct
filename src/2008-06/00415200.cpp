// from server: 100% by colin
// from server: 98% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_servicecachevectoropaque_fd14fdd79a481017.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
struct Control {
    void* value;
    Control() : value(0) {}
    ~Control();
    Control& operator=(const Control&);
};

struct Pointer {
    void* object;
    Control control;
    Pointer() : object(0) {}
    Pointer(const Pointer&);
    ~Pointer();
    void* get() const {return object;}
    Pointer& operator=(const Pointer& other){object=other.object;control=other.control;return *this;}
};

typedef std::vector<Pointer> Storage;
extern void __cdecl initialize(void (__cdecl*)(), void*);
extern void __cdecl initializeIndex();
extern void __cdecl initializeType();
extern unsigned int indexFlag;
extern unsigned int typeFlag;
extern void* __cdecl func_00413810();
extern void* __cdecl func_004068c0();
extern void (__cdecl* invalid_parameter_noinfo)();

struct S {
    unsigned char padding[0x190];
    Storage entries;
    Pointer create(void*);
    void* get();
};

void* S::get()
{
    initialize(initializeIndex, &indexFlag);
    unsigned int index = (unsigned int)func_00413810();

    Storage* storage = &entries;

    if (index + 1 > entries.size()) {
        storage->resize(index + 1, Pointer());
    } else {
        void* result = (*storage)[index].get();
        if (result)
            return result;
    }

    initialize(initializeType, &typeFlag);
    Pointer result = create(func_004068c0());
    if (!result.get())
        return 0;

    void* object = result.get();
    (*storage)[index] = result;
    return object;
}

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
#include <typeinfo>
namespace RBX { enum SurfaceType {}; }
typedef type_info TypeInfo;
extern int onceFlag;
extern int exeCounter;
extern char castFormat[];

struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char *pointer;
    } data;
    unsigned int length;
    unsigned int capacity;
    const char* c_str() const { return capacity >= 16 ? data.pointer : data.buffer; }
};

struct NamedString {
    String value;
};

struct Placeholder;
struct PlaceholderTable {
    void (__thiscall *destroy)(Placeholder *, unsigned int);
    const TypeInfo &(__thiscall *type)(const Placeholder *);
};

struct Placeholder {
    PlaceholderTable *vtable;
};

struct Descriptor {
    unsigned int fields[2];
    const TypeInfo *type;
    NamedString *name;
};

extern void __cdecl descriptorCallback();
extern void __cdecl callOnce(int *, void (__cdecl *)());
extern Descriptor *__cdecl getDescriptor();
extern void *__cdecl convert(Placeholder **);
extern std::runtime_error __cdecl format(const char *, ...);

struct SurfaceDescriptor {
    Descriptor *descriptor;
    Placeholder *storage;

    int *cast();
};

int *SurfaceDescriptor::cast()
{
    Placeholder **source = &storage;
    if (source) {
        const TypeInfo &type = *source
            ? (*source)->vtable->type(*source)
            : typeid(void);
        if (type == typeid(RBX::SurfaceType)) {
            int *result = reinterpret_cast<int *>(*source) + 1;
            if (result)
                return result;
        }
    }

    const TypeInfo *actualType = descriptor->type;
    if (typeid(std::string) == *actualType)
        convert(source);

    ++exeCounter;
    callOnce(&onceFlag, descriptorCallback);

    const Descriptor& d = *getDescriptor();
    throw format(castFormat, descriptor->name->value.c_str(), d.name->value.c_str());
}

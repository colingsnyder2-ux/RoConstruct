// from server: 46% by king_originala
typedef unsigned long DWORD;
typedef long HRESULT;

extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)

struct Object;

struct VTable {
    HRESULT (__stdcall *query)(Object*, const void*, void**);
    void* unused[6];
    void (__thiscall *destroy)(Object*, int);
};

struct Object {
    VTable* vtable;
    HRESULT initialize(DWORD*, DWORD*, void*, int);
};

struct Holder {
    Object* object;
    ~Holder();
};

struct InterfaceId {
    DWORD data[4];
};

extern DWORD* offsets;
extern InterfaceId interfaceId;

HRESULT __stdcall func(void* base, void** result)
{
    Object* object = new Object;
    if (!object)
        return (HRESULT)0x8007000E;

    Holder holder;
    holder.object = object;

    DWORD* table = static_cast<DWORD*>(_alloca(12));
    DWORD* source = offsets;

    if (offsets != 0) {
        DWORD* destination = table;
        do {
            DWORD value = *source;
            if (value == (DWORD)-2) {
                DWORD* (__cdecl *provider)(int) =
                    reinterpret_cast<DWORD* (__cdecl *)(int)>(source[1]);
                source = provider(0);
            } else {
                *destination++ = value + reinterpret_cast<DWORD>(base);
                ++source;
            }
        } while (*source != (DWORD)-1);
    }

    HRESULT initialization = object->initialize(table, table + 1, base, 3);
    if (initialization < 0) {
        object->vtable->destroy(object, 1);
        return initialization;
    }

    HRESULT status = object->vtable->query(object, &interfaceId, result);
    if (status < 0)
        object->vtable->destroy(object, 1);

    return status;
}

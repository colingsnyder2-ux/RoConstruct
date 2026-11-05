// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD /fp:fast
typedef unsigned long DWORD;
typedef long HRESULT;

struct GUID {
    DWORD a;
    unsigned short b, c;
    unsigned char d[8];
};

struct Interface;

struct InterfaceTable {
    void* reserved0[2];
    DWORD (__stdcall *Release)(Interface*);
    void* reserved1[15];
    HRESULT (__stdcall *SetFlags)(Interface*, DWORD);
    void* reserved2[4];
    HRESULT (__stdcall *QueryValue)(Interface*, DWORD*, DWORD*, DWORD*);
};

struct Interface {
    InterfaceTable* table;
};

extern "C" {
    extern HRESULT (__stdcall *CoInitialize)(void*);
    extern HRESULT (__stdcall *CoCreateInstance)(
        const GUID&, void*, DWORD, const GUID&, void**);
    extern void (__stdcall *CoUninitialize)();
}

extern const GUID classId;
extern const GUID interfaceId;
extern DWORD cachedValue;
extern unsigned char initialized;

DWORD getValue()
{
    if (!initialized) {
        Interface* object;
        struct {
            DWORD count;
            DWORD flags;
        } values;

        CoInitialize(0);
        object = 0;
        values.count = 0;

        if (CoCreateInstance(classId, 0, 1, interfaceId,
                             reinterpret_cast<void**>(&object)) >= 0) {
            object->table->SetFlags(object, 0);
            values.flags = 0x10004000;
            if (object->table->QueryValue(
                    object, &values.flags, &cachedValue, &values.count) < 0) {
                cachedValue = 0;
                values.count = 0;
            }
            object->table->Release(object);
        }
        CoUninitialize();
        initialized = 1;
    }
    return cachedValue;
}

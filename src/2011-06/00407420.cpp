// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_atl_typeinfo_noinline_febe0641d88ed97b.cpp

// Candidate translation unit (score above; library headers required).
#include <atlbase.h>
#include <atlcom.h>

struct RocStringDispid
{
    BSTR value;
    int length;
    DISPID id;

    RocStringDispid() : length(0), id(DISPID_UNKNOWN) {}
    __declspec(noinline) ~RocStringDispid() throw()
    {
        ::SysFreeString(value);
    }
};

struct RocTypeInfoHolder
{
    const GUID* interfaceId;
    const GUID* libraryId;
    WORD majorVersion;
    WORD minorVersion;
    ITypeInfo* typeInfo;
    long references;
    RocStringDispid* names;
    int nameCount;

    static void __stdcall Cleanup(DWORD_PTR value)
    {
        if (value == 0)
            return;

        RocTypeInfoHolder* holder = reinterpret_cast<RocTypeInfoHolder*>(value);
        if (holder->typeInfo != 0)
            holder->typeInfo->Release();
        holder->typeInfo = 0;
        delete [] holder->names;
        holder->names = 0;
    }
};

typedef void (__stdcall *CleanupFunction)(DWORD_PTR);
CleanupFunction volatile roc_force_type_info_cleanup = &RocTypeInfoHolder::Cleanup;

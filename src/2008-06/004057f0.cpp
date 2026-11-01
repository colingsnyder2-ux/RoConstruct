// from server: 100% by king_originala
// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_atl_static_registry_wide_dc589bf9570d98db.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND
#define _ATL_APARTMENT_THREADED
#define _ATL_STATIC_REGISTRY
#include <atlbase.h>

HRESULT __stdcall roc_update_registry_from_resource_s(
    ATL::CAtlModule* module,
    LPCOLESTR resource,
    BOOL registerResource,
    ATL::_ATL_REGMAP_ENTRY* entries) throw()
{
    ATL::CRegObject registrar;
    HRESULT result = registrar.FinalConstruct();
    if (FAILED(result))
        return result;

    if (entries != NULL)
    {
        while (entries->szKey != NULL)
        {
            registrar.AddReplacement(entries->szKey, entries->szData);
            entries++;
        }
    }

    result = module->AddCommonRGSReplacements(&registrar);
    if (FAILED(result))
        return result;

    USES_CONVERSION_EX;
    TCHAR modulePath[MAX_PATH];
    HINSTANCE instance = ATL::_AtlBaseModule.GetModuleInstance();
    DWORD length = GetModuleFileName(instance, modulePath, MAX_PATH);
    if (length == 0)
        return ATL::AtlHresultFromLastError();
    if (length == MAX_PATH)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

    LPOLESTR wideModule = T2OLE_EX(modulePath, _ATL_SAFE_ALLOCA_DEF_THRESHOLD);
    if (wideModule == NULL)
        return E_OUTOFMEMORY;

    OLECHAR unquotedModule[_MAX_PATH * 2];
    ATL::CAtlModule::EscapeSingleQuote(
        unquotedModule, _countof(unquotedModule), wideModule);

    HRESULT replacementResult;
    if (instance == NULL || instance == GetModuleHandle(NULL))
    {
        OLECHAR quotedModule[(_MAX_PATH + _ATL_QUOTES_SPACE) * 2];
        quotedModule[0] = OLESTR('"');
        if (!ocscpy_s(
                quotedModule + 1,
                (_MAX_PATH + _ATL_QUOTES_SPACE) * 2 - 1,
                unquotedModule))
            return E_FAIL;

        size_t quoteLength = ocslen(quotedModule);
        quotedModule[quoteLength] = OLESTR('"');
        quotedModule[quoteLength + 1] = 0;
        replacementResult = registrar.AddReplacement(
            OLESTR("Module"), quotedModule);
    }
    else
    {
        replacementResult = registrar.AddReplacement(
            OLESTR("Module"), unquotedModule);
    }

    if (FAILED(replacementResult))
        return replacementResult;

    replacementResult = registrar.AddReplacement(
        OLESTR("Module_Raw"), unquotedModule);
    if (FAILED(replacementResult))
        return replacementResult;

    LPCOLESTR type = OLESTR("REGISTRY");
    return registerResource
        ? registrar.ResourceRegisterSz(wideModule, resource, type)
        : registrar.ResourceUnregisterSz(wideModule, resource, type);
}

// from server: 100% by EspClaude
// roc 2009-06 0044f840  unit: VCWorkspace::?$CComObject  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044f840
//
// 0044f840  53                   push ebx
// 0044f841  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0044f845  56                   push esi
// 0044f846  57                   push edi
// 0044f847  85db                 test ebx, ebx
// 0044f849  7405                 je 0x44f850
// 0044f84b  8d43f8               lea eax, [ebx - 8]
// 0044f84e  eb02                 jmp 0x44f852
// 0044f850  33c0                 xor eax, eax
// 0044f852  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0044f856  85ff                 test edi, edi
// 0044f858  7460                 je 0x44f8ba
// 0044f85a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0044f85e  85f6                 test esi, esi
// 0044f860  7458                 je 0x44f8ba
// 0044f862  8b08                 mov ecx, dword ptr [eax]
// 0044f864  55                   push ebp
// 0044f865  8d542414             lea edx, [esp + 0x14]
// 0044f869  52                   push edx
// 0044f86a  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0044f86e  52                   push edx
// 0044f86f  50                   push eax
// 0044f870  8b01                 mov eax, dword ptr [ecx]
// 0044f872  ffd0                 call eax
// 0044f874  8be8                 mov ebp, eax
// 0044f876  85ed                 test ebp, ebp
// 0044f878  7c2b                 jl 0x44f8a5
// 0044f87a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044f87e  8b08                 mov ecx, dword ptr [eax]
// 0044f880  8b5108               mov edx, dword ptr [ecx + 8]
// 0044f883  50                   push eax
// 0044f884  ffd2                 call edx
// 0044f886  8bcb                 mov ecx, ebx
// 0044f888  e883fdffff           call 0x44f610
// 0044f88d  c70701000000         mov dword ptr [edi], 1
// 0044f893  85c0                 test eax, eax
// 0044f895  7514                 jne 0x44f8ab
// 0044f897  8b4304               mov eax, dword ptr [ebx + 4]
// 0044f89a  8906                 mov dword ptr [esi], eax
// 0044f89c  8bc5                 mov eax, ebp
// 0044f89e  5d                   pop ebp
// 0044f89f  5f                   pop edi
// 0044f8a0  5e                   pop esi
// 0044f8a1  5b                   pop ebx
// 0044f8a2  c21000               ret 0x10
// 0044f8a5  c70700000000         mov dword ptr [edi], 0
// 0044f8ab  8bc5                 mov eax, ebp
// 0044f8ad  5d                   pop ebp
// 0044f8ae  5f                   pop edi
// 0044f8af  c70600000000         mov dword ptr [esi], 0
// 0044f8b5  5e                   pop esi
// 0044f8b6  5b                   pop ebx
// 0044f8b7  c21000               ret 0x10
// 0044f8ba  5f                   pop edi
// 0044f8bb  5e                   pop esi
// 0044f8bc  b803400080           mov eax, 0x80004003
// 0044f8c1  5b                   pop ebx
// 0044f8c2  c21000               ret 0x10
// copied from an identical function in another client (function ?GetInterfaceSafetyOptions@?$IObjectSafetyRobloxImpl@VApp@@@@UAGJPBXPAK1@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct IUnk {
    virtual long __stdcall QueryInterface(const void *riid, void **ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct First { virtual void f0(); };

template <class T>
class IObjectSafetyRobloxImpl {
public:
    virtual long __stdcall GetInterfaceSafetyOptions(const void *riid, unsigned long *pdwSupportedOptions, unsigned long *pdwEnabledOptions);
    unsigned long m_dwCurrentSafety;
    int check();
};

struct Mid { virtual void m0(); int x; };
class App : public IUnk, public First, public IObjectSafetyRobloxImpl<App>, public Mid {
public:
    IUnk *GetUnknown() { return static_cast<IUnk *>(this); }
};

template <class T>
long __stdcall IObjectSafetyRobloxImpl<T>::GetInterfaceSafetyOptions(const void *riid, unsigned long *pdwSupportedOptions, unsigned long *pdwEnabledOptions)
{
    T *pT = static_cast<T *>(this);
    if (pdwSupportedOptions == 0 || pdwEnabledOptions == 0)
        return (long)0x80004003L;
    long hr;
    IUnk *pUnk;
    hr = pT->GetUnknown()->QueryInterface(riid, (void **)&pUnk);
    if (hr >= 0) {
        pUnk->Release();
        if (check()) {
            *pdwSupportedOptions = 1;
            *pdwEnabledOptions = 0;
        } else {
            *pdwSupportedOptions = 1;
            *pdwEnabledOptions = m_dwCurrentSafety;
        }
    } else {
        *pdwSupportedOptions = 0;
        *pdwEnabledOptions = 0;
    }
    return hr;
}

template class IObjectSafetyRobloxImpl<App>;
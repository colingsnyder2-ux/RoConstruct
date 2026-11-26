// from server: 100% by Xemicl
// roc 2012-06 0047ffb0  unit: VCWorkspace::?$CComObject  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0047ffb0
//
// 0047ffb0  53                   push ebx
// 0047ffb1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0047ffb5  56                   push esi
// 0047ffb6  57                   push edi
// 0047ffb7  85db                 test ebx, ebx
// 0047ffb9  7405                 je 0x47ffc0
// 0047ffbb  8d43f8               lea eax, [ebx - 8]
// 0047ffbe  eb02                 jmp 0x47ffc2
// 0047ffc0  33c0                 xor eax, eax
// 0047ffc2  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0047ffc6  85ff                 test edi, edi
// 0047ffc8  7460                 je 0x48002a
// 0047ffca  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0047ffce  85f6                 test esi, esi
// 0047ffd0  7458                 je 0x48002a
// 0047ffd2  8b08                 mov ecx, dword ptr [eax]
// 0047ffd4  55                   push ebp
// 0047ffd5  8d542414             lea edx, [esp + 0x14]
// 0047ffd9  52                   push edx
// 0047ffda  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0047ffde  52                   push edx
// 0047ffdf  50                   push eax
// 0047ffe0  8b01                 mov eax, dword ptr [ecx]
// 0047ffe2  ffd0                 call eax
// 0047ffe4  8be8                 mov ebp, eax
// 0047ffe6  85ed                 test ebp, ebp
// 0047ffe8  7c2b                 jl 0x480015
// 0047ffea  8b442414             mov eax, dword ptr [esp + 0x14]
// 0047ffee  8b08                 mov ecx, dword ptr [eax]
// 0047fff0  8b5108               mov edx, dword ptr [ecx + 8]
// 0047fff3  50                   push eax
// 0047fff4  ffd2                 call edx
// 0047fff6  8bcb                 mov ecx, ebx
// 0047fff8  e823ecffff           call 0x47ec20
// 0047fffd  c70701000000         mov dword ptr [edi], 1
// 00480003  85c0                 test eax, eax
// 00480005  7514                 jne 0x48001b
// 00480007  8b4304               mov eax, dword ptr [ebx + 4]
// 0048000a  8906                 mov dword ptr [esi], eax
// 0048000c  8bc5                 mov eax, ebp
// 0048000e  5d                   pop ebp
// 0048000f  5f                   pop edi
// 00480010  5e                   pop esi
// 00480011  5b                   pop ebx
// 00480012  c21000               ret 0x10
// 00480015  c70700000000         mov dword ptr [edi], 0
// 0048001b  8bc5                 mov eax, ebp
// 0048001d  5d                   pop ebp
// 0048001e  5f                   pop edi
// 0048001f  c70600000000         mov dword ptr [esi], 0
// 00480025  5e                   pop esi
// 00480026  5b                   pop ebx
// 00480027  c21000               ret 0x10
// 0048002a  5f                   pop edi
// 0048002b  5e                   pop esi
// 0048002c  b803400080           mov eax, 0x80004003
// 00480031  5b                   pop ebx
// 00480032  c21000               ret 0x10
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
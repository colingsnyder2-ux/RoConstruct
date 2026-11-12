// from server: 100% by EspClaude
// from server: 59% by colin
// roc 2007-08 00448420  unit: CIDEDocManager  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00448420
//
// 00448420  56                   push esi
// 00448421  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00448425  57                   push edi
// 00448426  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0044842a  8b07                 mov eax, dword ptr [edi]
// 0044842c  8d542414             lea edx, [esp + 0x14]
// 00448430  52                   push edx
// 00448431  8b542410             mov edx, dword ptr [esp + 0x10]
// 00448435  56                   push esi
// 00448436  8944241c             mov dword ptr [esp + 0x1c], eax
// 0044843a  8d442418             lea eax, [esp + 0x18]
// 0044843e  50                   push eax
// 0044843f  6a00                 push 0
// 00448441  c70700000000         mov dword ptr [edi], 0
// 00448447  8b01                 mov eax, dword ptr [ecx]
// 00448449  52                   push edx
// 0044844a  50                   push eax
// 0044844b  ff1520d07700         call dword ptr [0x77d020]
// 00448451  85c0                 test eax, eax
// 00448453  7532                 jne 0x448487
// 00448455  8b442410             mov eax, dword ptr [esp + 0x10]
// 00448459  83f801               cmp eax, 1
// 0044845c  7405                 je 0x448463
// 0044845e  83f802               cmp eax, 2
// 00448461  7513                 jne 0x448476
// 00448463  85f6                 test esi, esi
// 00448465  8b442414             mov eax, dword ptr [esp + 0x14]
// 00448469  7418                 je 0x448483
// 0044846b  85c0                 test eax, eax
// 0044846d  7411                 je 0x448480
// 0044846f  807c30ff00           cmp byte ptr [eax + esi - 1], 0
// 00448474  740d                 je 0x448483
// 00448476  5f                   pop edi
// 00448477  b80d000000           mov eax, 0xd
// 0044847c  5e                   pop esi
// 0044847d  c20c00               ret 0xc
// 00448480  c60600               mov byte ptr [esi], 0
// 00448483  8907                 mov dword ptr [edi], eax

typedef void* HKEY;
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(HKEY, const char*, unsigned long*, unsigned long*, unsigned char*, unsigned long*);

class CRegKey {
public:
    HKEY m_hKey;
    long QueryStringValue(const char* pszValueName, char* pszValue, unsigned long* pnChars) throw();
};

long CRegKey::QueryStringValue(const char* pszValueName, char* pszValue, unsigned long* pnChars) throw()
{
    long lRes;
    unsigned long dwType;
    unsigned long nBytes;

    nBytes = (*pnChars) * sizeof(char);
    *pnChars = 0;
    lRes = ::RegQueryValueExA(m_hKey, pszValueName, 0, &dwType, reinterpret_cast<unsigned char*>(pszValue), &nBytes);
    if (lRes != 0)
        return lRes;
    if (dwType != 1 && dwType != 2)
        return 13;
    if (pszValue != 0)
    {
        if (nBytes != 0)
        {
            if ((nBytes % sizeof(char) != 0) || (pszValue[nBytes / sizeof(char) - 1] != 0))
                return 13;
        }
        else
        {
            pszValue[0] = '\0';
        }
    }
    *pnChars = nBytes / sizeof(char);
    return 0;
}

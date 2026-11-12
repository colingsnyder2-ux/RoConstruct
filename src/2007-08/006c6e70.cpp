// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 006c6e70  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 229 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006c6e70
// 006c6e70  6aff                 push -1
// 006c6e72  68badd7500           push 0x75ddba
// 006c6e77  64a100000000         mov eax, dword ptr fs:[0]
// 006c6e7d  50                   push eax
// 006c6e7e  83ec08               sub esp, 8
// 006c6e81  53                   push ebx
// 006c6e82  55                   push ebp
// 006c6e83  56                   push esi
// 006c6e84  57                   push edi
// 006c6e85  a188518b00           mov eax, dword ptr [0x8b5188]
// 006c6e8a  33c4                 xor eax, esp
// 006c6e8c  50                   push eax
// 006c6e8d  8d44241c             lea eax, [esp + 0x1c]
// 006c6e91  64a300000000         mov dword ptr fs:[0], eax
// 006c6e97  8bf1                 mov esi, ecx
// 006c6e99  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 006c6e9d  33db                 xor ebx, ebx
// 006c6e9f  895c2414             mov dword ptr [esp + 0x14], ebx
// 006c6ea3  8b8668010000         mov eax, dword ptr [esi + 0x168]
// 006c6ea9  85c0                 test eax, eax
// 006c6eab  7437                 je 0x6c6ee4
// 006c6ead  395820               cmp dword ptr [eax + 0x20], ebx
// 006c6eb0  7432                 je 0x6c6ee4
// 006c6eb2  8d442418             lea eax, [esp + 0x18]
// 006c6eb6  50                   push eax
// 006c6eb7  e854ffffff           call 0x6c6e10
// 006c6ebc  8bf8                 mov edi, eax
// 006c6ebe  895c2424             mov dword ptr [esp + 0x24], ebx
// 006c6ec2  bb01000000           mov ebx, 1
// 006c6ec7  8bcd                 mov ecx, ebp
// 006c6ec9  895c2414             mov dword ptr [esp + 0x14], ebx
// 006c6ecd  ff1598dd7700         call dword ptr [0x77dd98]
// 006c6ed3  50                   push eax
// 006c6ed4  8bcf                 mov ecx, edi
// 006c6ed6  ff15b8dc7700         call dword ptr [0x77dcb8]
// 006c6edc  85c0                 test eax, eax
// 006c6ede  885c242c             mov byte ptr [esp + 0x2c], bl
// 006c6ee2  7505                 jne 0x6c6ee9
// 006c6ee4  c644242c00           mov byte ptr [esp + 0x2c], 0
// 006c6ee9  f6c301               test bl, 1
// 006c6eec  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 006c6ef4  740a                 je 0x6c6f00
// 006c6ef6  8d4c2418             lea ecx, [esp + 0x18]
// 006c6efa  ff15bcdd7700         call dword ptr [0x77ddbc]
// 006c6f00  807c242c00           cmp byte ptr [esp + 0x2c], 0
// 006c6f05  7421                 je 0x6c6f28
// 006c6f07  8b8e68010000         mov ecx, dword ptr [esi + 0x168]
// 006c6f0d  6a00                 push 0
// 006c6f0f  e80291f6ff           call 0x630016
// 006c6f14  8bcd                 mov ecx, ebp
// 006c6f16  ff1598dd7700         call dword ptr [0x77dd98]
// 006c6f1c  8b8e68010000         mov ecx, dword ptr [esi + 0x168]
// 006c6f22  50                   push eax
// 006c6f23  e8ee90f6ff           call 0x630016
// 006c6f28  55                   push ebp
// 006c6f29  8d8e8c010000         lea ecx, [esi + 0x18c]
// 006c6f2f  ff1534d47700         call dword ptr [0x77d434]
// 006c6f35  c7869001000000000000 mov dword ptr [esi + 0x190], 0
// 006c6f3f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006c6f43  64890d00000000       mov dword ptr fs:[0], ecx
// 006c6f4a  59                   pop ecx
// 006c6f4b  5f                   pop edi
// 006c6f4c  5e                   pop esi
// 006c6f4d  5d                   pop ebp
// 006c6f4e  5b                   pop ebx
// 006c6f4f  83c414               add esp, 0x14
// 006c6f52  c20400               ret 4

class CString {
public:
    __declspec(dllimport) ~CString();
    __declspec(dllimport) operator const char*() const;
    __declspec(dllimport) int Compare(const char* psz) const;
    __declspec(dllimport) CString& operator=(const CString& src);
    void* m_pszData;
};
inline bool operator!=(const CString& str1, const char* psz2)
{
    return str1.Compare(psz2) != 0;
}

class CWnd {
public:
    char pad[0x20];
    void* m_hWnd;             // +0x20
    void* GetSafeHwnd() const { return this == 0 ? 0 : m_hWnd; }
    void SetWindowText(const char* lpszString);
};

class CCustomizeEdit {
public:
    CString GetText();
    void SetText(const CString& str);
    char pad[0x168];
    CWnd* m_pWnd;             // +0x168
    char pad16c[0x18c - 0x16c];
    CString m_strText;        // +0x18c
    int m_field190;           // +0x190
};

void CCustomizeEdit::SetText(const CString& str)
{
    if (m_pWnd->GetSafeHwnd() && GetText() != str) {
        m_pWnd->SetWindowText(0);
        m_pWnd->SetWindowText(str);
    }
    m_strText = str;
    m_field190 = 0;
}

// from server: 100% by coldek
// from server: 100% by EspClaude
// roc 2008-06 0045d550  unit: G3D::TextureManager::VTextureArgs::?$Table  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045d550
//
// 0045d550  55                   push ebp
// 0045d551  8bec                 mov ebp, esp
// 0045d553  6aff                 push -1
// 0045d555  68292e7c00           push 0x7c2e29
// 0045d55a  64a100000000         mov eax, dword ptr fs:[0]
// 0045d560  50                   push eax
// 0045d561  64892500000000       mov dword ptr fs:[0], esp
// 0045d568  83ec1c               sub esp, 0x1c
// 0045d56b  53                   push ebx
// 0045d56c  56                   push esi
// 0045d56d  57                   push edi
// 0045d56e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0045d571  8bf1                 mov esi, ecx
// 0045d573  e8f0362400           call 0x6a0c68
// 0045d578  83f8ff               cmp eax, -1
// 0045d57b  0f84b8000000         je 0x45d639
// 0045d581  ff1598218000         call dword ptr [0x802198]
// 0045d587  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0045d58a  8986a0000000         mov dword ptr [esi + 0xa0], eax
// 0045d590  8d45d8               lea eax, [ebp - 0x28]
// 0045d593  50                   push eax
// 0045d594  51                   push ecx
// 0045d595  ff15842d8000         call dword ptr [0x802d84]
// 0045d59b  8b55e4               mov edx, dword ptr [ebp - 0x1c]
// 0045d59e  2b55dc               sub edx, dword ptr [ebp - 0x24]
// 0045d5a1  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0045d5a4  2b45d8               sub eax, dword ptr [ebp - 0x28]
// 0045d5a7  52                   push edx
// 0045d5a8  50                   push eax
// 0045d5a9  8bce                 mov ecx, esi
// 0045d5ab  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0045d5b2  e809ffffff           call 0x45d4c0
// 0045d5b7  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0045d5ba  8b3d7c2d8000         mov edi, dword ptr [0x802d7c]
// 0045d5c0  6a00                 push 0
// 0045d5c2  68c8000000           push 0xc8
// 0045d5c7  6a00                 push 0
// 0045d5c9  51                   push ecx
// 0045d5ca  ffd7                 call edi
// 0045d5cc  8b5620               mov edx, dword ptr [esi + 0x20]
// 0045d5cf  6a00                 push 0
// 0045d5d1  6a64                 push 0x64
// 0045d5d3  6a01                 push 1
// 0045d5d5  52                   push edx
// 0045d5d6  ffd7                 call edi
// 0045d5d8  33c0                 xor eax, eax
// 0045d5da  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0045d5dd  64890d00000000       mov dword ptr fs:[0], ecx
// 0045d5e4  5f                   pop edi
// 0045d5e5  5e                   pop esi
// 0045d5e6  5b                   pop ebx
// 0045d5e7  8be5                 mov esp, ebp
// 0045d5e9  5d                   pop ebp
// 0045d5ea  c20400               ret 4

// from server: 88% by king_originala
// roc 2008-06 0045d550  unit: G3D::TextureManager::VTextureArgs::?$Table  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045d550
//
// 0045d550  55                   push ebp
// 0045d551  8bec                 mov ebp, esp
// 0045d553  6aff                 push -1
// 0045d555  68292e7c00           push 0x7c2e29
// 0045d55a  64a100000000         mov eax, dword ptr fs:[0]
// 0045d560  50                   push eax
// 0045d561  64892500000000       mov dword ptr fs:[0], esp
// 0045d568  83ec1c               sub esp, 0x1c
// 0045d56b  53                   push ebx
// 0045d56c  56                   push esi
// 0045d56d  57                   push edi
// 0045d56e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0045d571  8bf1                 mov esi, ecx
// 0045d573  e8f0362400           call 0x6a0c68
// 0045d578  83f8ff               cmp eax, -1
// 0045d57b  0f84b8000000         je 0x45d639
// 0045d581  ff1598218000         call dword ptr [0x802198]
// 0045d587  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0045d58a  8986a0000000         mov dword ptr [esi + 0xa0], eax
// 0045d590  8d45d8               lea eax, [ebp - 0x28]
// 0045d593  50                   push eax
// 0045d594  51                   push ecx
// 0045d595  ff15842d8000         call dword ptr [0x802d84]
// 0045d59b  8b55e4               mov edx, dword ptr [ebp - 0x1c]
// 0045d59e  2b55dc               sub edx, dword ptr [ebp - 0x24]
// 0045d5a1  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0045d5a4  2b45d8               sub eax, dword ptr [ebp - 0x28]
// 0045d5a7  52                   push edx
// 0045d5a8  50                   push eax
// 0045d5a9  8bce                 mov ecx, esi
// 0045d5ab  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0045d5b2  e809ffffff           call 0x45d4c0
// 0045d5b7  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0045d5ba  8b3d7c2d8000         mov edi, dword ptr [0x802d7c]
// 0045d5c0  6a00                 push 0
// 0045d5c2  68c8000000           push 0xc8
// 0045d5c7  6a00                 push 0
// 0045d5c9  51                   push ecx
// 0045d5ca  ffd7                 call edi
// 0045d5cc  8b5620               mov edx, dword ptr [esi + 0x20]
// 0045d5cf  6a00                 push 0
// 0045d5d1  6a64                 push 0x64
// 0045d5d3  6a01                 push 1
// 0045d5d5  52                   push edx
// 0045d5d6  ffd7                 call edi
// 0045d5d8  33c0                 xor eax, eax
// 0045d5da  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0045d5dd  64890d00000000       mov dword ptr fs:[0], ecx
// 0045d5e4  5f                   pop edi
// 0045d5e5  5e                   pop esi
// 0045d5e6  5b                   pop ebx
// 0045d5e7  8be5                 mov esp, ebp
// 0045d5e9  5d                   pop ebp
// 0045d5ea  c20400               ret 4

typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef unsigned int UINT_PTR;
typedef void* HWND;
typedef void (__stdcall *TimerCallback)(HWND, UINT, UINT_PTR, DWORD);
typedef UINT_PTR (__stdcall *TimerFunction)(HWND, UINT_PTR, UINT, TimerCallback);

struct RECT {
    long left;
    long top;
    long right;
    long bottom;
};

extern "C" {
    extern DWORD (__stdcall * const GetCurrentThreadId)();
    extern int (__stdcall * const GetClientRect)(HWND, RECT*);
    extern TimerFunction const SetTimer;
}

namespace std {
    class exception {
        const char* message;
    public:
        virtual ~exception();
        virtual const char* what() const;
    };
}

struct CString {
    void* data;
    __declspec(dllimport) CString() throw();
    __declspec(dllimport) ~CString() throw();
    __declspec(dllimport) void __cdecl Format(const char*, ...);
    __declspec(dllimport) operator const char*() const throw();
};

int __stdcall AfxMessageBox(const char*, UINT = 0, UINT = 0);

struct S {
    char padding0[0x20];
    HWND window;
    char padding1[0x38];
    int mode;
    char padding2[0x40];
    DWORD threadId;

    int defaultHandler();
    void update(int, int);
    int create(void*);
};

int S::create(void*)
{
    if (defaultHandler() == -1)
        return -1;

    threadId = GetCurrentThreadId();

    RECT rect;
    GetClientRect(window, &rect);

    try {
        update(rect.right - rect.left, rect.bottom - rect.top);
        TimerFunction timer = SetTimer;
        timer(window, 0, 200, 0);
        timer(window, 1, 100, 0);
    }
    catch (std::exception& e) {
        CString message;
        message.Format("Unable to run Roblox.\n\n%s", e.what());
        AfxMessageBox(message);
        return -1;
    }

    return 0;
}

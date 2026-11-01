// from server: 100% by EspClaude
// from server: 72% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS /EHsc /MD
// roc 2008-06 006a94c0  unit: CXTPControlEditCtrl  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a94c0
//
// 006a94c0  81ec04010000         sub esp, 0x104
// 006a94c6  a1c05c9600           mov eax, dword ptr [0x965cc0]
// 006a94cb  33c4                 xor eax, esp
// 006a94cd  89842400010000       mov dword ptr [esp + 0x100], eax
// 006a94d4  57                   push edi
// 006a94d5  8bbc2414010000       mov edi, dword ptr [esp + 0x114]
// 006a94dc  85ff                 test edi, edi
// 006a94de  0f8483000000         je 0x6a9567
// 006a94e4  8b0d44e09700         mov ecx, dword ptr [0x97e044]
// 006a94ea  85c9                 test ecx, ecx
// 006a94ec  7479                 je 0x6a9567
// 006a94ee  837f0846             cmp dword ptr [edi + 8], 0x46
// 006a94f2  7573                 jne 0x6a9567
// 006a94f4  8b4108               mov eax, dword ptr [ecx + 8]
// 006a94f7  8b17                 mov edx, dword ptr [edi]
// 006a94f9  85c0                 test eax, eax
// 006a94fb  7413                 je 0x6a9510
// 006a94fd  3b02                 cmp eax, dword ptr [edx]
// 006a94ff  7566                 jne 0x6a9567
// 006a9501  f6421880             test byte ptr [edx + 0x18], 0x80
// 006a9505  7460                 je 0x6a9567
// 006a9507  6a00                 push 0
// 006a9509  e852ffffff           call 0x6a9460
// 006a950e  eb57                 jmp 0x6a9567
// 006a9510  f6421840             test byte ptr [edx + 0x18], 0x40
// 006a9514  7451                 je 0x6a9567
// 006a9516  56                   push esi
// 006a9517  8b32                 mov esi, dword ptr [edx]
// 006a9519  68ff000000           push 0xff
// 006a951e  8d44240c             lea eax, [esp + 0xc]
// 006a9522  50                   push eax
// 006a9523  56                   push esi
// 006a9524  ff155c2c8000         call dword ptr [0x802c5c]
// 006a952a  8d4c2408             lea ecx, [esp + 8]
// 006a952e  6878148500           push 0x851478
// 006a9533  51                   push ecx
// 006a9534  ff153c288000         call dword ptr [0x80283c]
// 006a953a  83c408               add esp, 8
// 006a953d  85c0                 test eax, eax
// 006a953f  7525                 jne 0x6a9566
// 006a9541  8b0d44e09700         mov ecx, dword ptr [0x97e044]
// 006a9547  56                   push esi
// 006a9548  e813ffffff           call 0x6a9460
// 006a954d  8b1544e09700         mov edx, dword ptr [0x97e044]
// 006a9553  8b420c               mov eax, dword ptr [edx + 0xc]
// 006a9556  6a00                 push 0
// 006a9558  6a00                 push 0
// 006a955a  6872280000           push 0x2872
// 006a955f  50                   push eax
// 006a9560  ff150c2e8000         call dword ptr [0x802e0c]
// 006a9566  5e                   pop esi
// 006a9567  8b8c2410010000       mov ecx, dword ptr [esp + 0x110]
// 006a956e  8b94240c010000       mov edx, dword ptr [esp + 0x10c]
// 006a9575  a140e09700           mov eax, dword ptr [0x97e040]
// 006a957a  57                   push edi
// 006a957b  51                   push ecx
// 006a957c  52                   push edx
// 006a957d  50                   push eax
// 006a957e  ff15602c8000         call dword ptr [0x802c60]
// 006a9584  8b8c2404010000       mov ecx, dword ptr [esp + 0x104]
// 006a958b  5f                   pop edi
// 006a958c  33cc                 xor ecx, esp
// 006a958e  e83f88ffff           call 0x6a1dd2
// 006a9593  81c404010000         add esp, 0x104
// 006a9599  c20c00               ret 0xc

extern "C" {
    __declspec(dllimport) int __stdcall GetClassNameA(void* hWnd, char* lpClassName, int nMaxCount);
    __declspec(dllimport) int __cdecl _mbscmp(const unsigned char* s1, const unsigned char* s2);
    __declspec(dllimport) int __stdcall PostMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);
    __declspec(dllimport) long __stdcall CallNextHookEx(void* hhk, int nCode, unsigned int wParam, long lParam);
}

struct CXTPControlEditCtrl {
    void sub_6a9460(void* p);
};

extern void* g_97e044;
extern void* g_97e040;
extern void* g_965cc0;
extern void* g_802c5c;
extern void* g_80283c;
extern void* g_802c60;
extern void* g_802e0c;
extern const char* g_851478;

void __stdcall func_6a94c0(int a1, int a2, int a3)
{
    char className[256];
    void* p = (void*)a3;
    if (p != 0) {
        void* ctrl = g_97e044;
        if (ctrl != 0) {
            if (*(int*)((char*)p + 8) == 0x46) {
                int v = *(int*)((char*)ctrl + 8);
                int* edx = *(int**)p;
                if (v != 0) {
                    if (v == *edx) {
                        if ((*(unsigned char*)((char*)edx + 0x18) & 0x80) != 0) {
                            ((CXTPControlEditCtrl*)ctrl)->sub_6a9460(0);
                        }
                    }
                } else {
                    if ((*(unsigned char*)((char*)edx + 0x18) & 0x40) != 0) {
                        void* hwnd = (void*)*edx;
                        GetClassNameA(hwnd, className, 0xff);
                        if (_mbscmp((const unsigned char*)className, (const unsigned char*)"Auto-Suggest Dropdown") == 0) {
                            void* ctrl2 = g_97e044;
                            ((CXTPControlEditCtrl*)ctrl2)->sub_6a9460(hwnd);
                            void* ctrl3 = g_97e044;
                            void* h = *(void**)((char*)ctrl3 + 0xc);
                            PostMessageA(h, 0x2872, 0, 0);
                        }
                    }
                }
            }
        }
    }
    CallNextHookEx(g_97e040, a1, (unsigned int)a2, (long)a3);
}

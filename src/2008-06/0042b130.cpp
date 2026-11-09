// from server: 100% by king_originala
#include <string>
#include <exception>
struct StandardOut {
    void print(int, const std::exception&);
};

struct OutHandle {
    StandardOut *pointer;
    void *count;
    ~OutHandle();
    StandardOut *operator->() const { return pointer; }
};

OutHandle __cdecl singleton();


// from server: 100% by king_originala
// roc 2008-06 0042b130  unit: EventHandler  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042b130
//
// 0042b130  55                   push ebp
// 0042b131  8bec                 mov ebp, esp
// 0042b133  6aff                 push -1
// 0042b135  68f8f47b00           push 0x7bf4f8
// 0042b13a  64a100000000         mov eax, dword ptr fs:[0]
// 0042b140  50                   push eax
// 0042b141  64892500000000       mov dword ptr fs:[0], esp
// 0042b148  83ec10               sub esp, 0x10
// 0042b14b  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0042b14e  53                   push ebx
// 0042b14f  56                   push esi
// 0042b150  8b7520               mov esi, dword ptr [ebp + 0x20]
// 0042b153  57                   push edi
// 0042b154  b80b000000           mov eax, 0xb
// 0042b159  83c108               add ecx, 8
// 0042b15c  8965f0               mov dword ptr [ebp - 0x10], esp
// 0042b15f  668906               mov word ptr [esi], ax
// 0042b162  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0042b169  e852feffff           call 0x42afc0
// 0042b16e  33c9                 xor ecx, ecx
// 0042b170  84c0                 test al, al
// 0042b172  0f95c1               setne cl
// 0042b175  b801000000           mov eax, 1
// 0042b17a  66894e08             mov word ptr [esi + 8], cx
// 0042b17e  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0042b181  64890d00000000       mov dword ptr fs:[0], ecx
// 0042b188  5f                   pop edi
// 0042b189  5e                   pop esi
// 0042b18a  5b                   pop ebx
// 0042b18b  8be5                 mov esp, ebp
// 0042b18d  5d                   pop ebp
// 0042b18e  c22400               ret 0x24

struct State {
    bool query();
};

struct EventHandler {
    unsigned char padding[8];
    State state;
};

struct Result {
    unsigned short type;
    unsigned short reserved[3];
    short value;
};

int __stdcall invoke(EventHandler* object, unsigned long arg2,
                     void* arg3, unsigned long arg4,
                     unsigned long arg5, void* arg6,
                     Result* result, void* arg8, void* arg9)
{
    result->type = 11;
    try {
        result->value = object->state.query() ? 1 : 0;
        return 1;
    }
    catch (std::exception& error) {
        singleton()->print(2, error);
        return static_cast<int>(0x80004005UL);
    }
}

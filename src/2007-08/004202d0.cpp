// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 004202d0  unit: CRobloxTreeCtrl  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004202d0
//
// 004202d0  6aff                 push -1
// 004202d2  68f8227400           push 0x7422f8
// 004202d7  64a100000000         mov eax, dword ptr fs:[0]
// 004202dd  50                   push eax
// 004202de  83ec08               sub esp, 8
// 004202e1  53                   push ebx
// 004202e2  56                   push esi
// 004202e3  57                   push edi
// 004202e4  a188518b00           mov eax, dword ptr [0x8b5188]
// 004202e9  33c4                 xor eax, esp
// 004202eb  50                   push eax
// 004202ec  8d442418             lea eax, [esp + 0x18]
// 004202f0  64a300000000         mov dword ptr fs:[0], eax
// 004202f6  8bf1                 mov esi, ecx
// 004202f8  e899012100           call 0x630496
// 004202fd  8a9ea4000000         mov bl, byte ptr [esi + 0xa4]
// 00420303  8dbea4000000         lea edi, [esi + 0xa4]
// 00420309  897c2410             mov dword ptr [esp + 0x10], edi
// 0042030d  885c2414             mov byte ptr [esp + 0x14], bl
// 00420311  c60701               mov byte ptr [edi], 1
// 00420314  8b4620               mov eax, dword ptr [esi + 0x20]
// 00420317  680000ffff           push 0xffff0000
// 0042031c  6a00                 push 0
// 0042031e  6801110000           push 0x1101
// 00420323  50                   push eax
// 00420324  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0042032c  ff15d8ec7700         call dword ptr [0x77ecd8]
// 00420332  8b8e94000000         mov ecx, dword ptr [esi + 0x94]
// 00420338  85c9                 test ecx, ecx
// 0042033a  7413                 je 0x42034f
// 0042033c  8b11                 mov edx, dword ptr [ecx]
// 0042033e  8b4204               mov eax, dword ptr [edx + 4]
// 00420341  6a01                 push 1
// 00420343  ffd0                 call eax
// 00420345  c7869400000000000000 mov dword ptr [esi + 0x94], 0
// 0042034f  881f                 mov byte ptr [edi], bl
// 00420351  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00420355  64890d00000000       mov dword ptr fs:[0], ecx
// 0042035c  59                   pop ecx
// 0042035d  5f                   pop edi
// 0042035e  5e                   pop esi
// 0042035f  5b                   pop ebx
// 00420360  83c414               add esp, 0x14
// 00420363  c3                   ret 

extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

template <class T>
struct ValueChanger {
    T* p;
    T old;
    ValueChanger(T* q, T v) : p(q), old(*q) { *q = v; }
    ~ValueChanger() { *p = old; }
};

struct Item {
    virtual void f0();
    virtual ~Item();
};

struct CRobloxTreeCtrl {
    char pad[0x20];
    void* hwnd;
    char pad2[0x70];
    Item* field94;
    char pad3[0x0c];
    bool fieldA4;
    void sub_630496();
    void func();
};

void CRobloxTreeCtrl::func()
{
    sub_630496();
    ValueChanger<bool> guard(&fieldA4, true);
    SendMessageA(hwnd, 0x1101, 0, 0xffff0000);
    if (field94) {
        delete field94;
        field94 = 0;
    }
}

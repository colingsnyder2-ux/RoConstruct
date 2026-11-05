// from server: 100% by EspClaude
// roc 2009-06 00410120  unit: boost::Vbad_weak_ptr::?$error_info_injector  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00410120
//
// 00410120  6aff                 push -1
// 00410122  687aef8400           push 0x84ef7a
// 00410127  64a100000000         mov eax, dword ptr fs:[0]
// 0041012d  50                   push eax
// 0041012e  64892500000000       mov dword ptr fs:[0], esp
// 00410135  51                   push ecx
// 00410136  68a8000000           push 0xa8
// 0041013b  e8f8883000           call 0x718a38
// 00410140  83c404               add esp, 4
// 00410143  890424               mov dword ptr [esp], eax
// 00410146  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0041014e  85c0                 test eax, eax
// 00410150  7416                 je 0x410168
// 00410152  8bc8                 mov ecx, eax
// 00410154  e8b7fcffff           call 0x40fe10
// 00410159  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041015d  64890d00000000       mov dword ptr fs:[0], ecx
// 00410164  83c410               add esp, 0x10
// 00410167  c3                   ret 
// 00410168  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041016c  33c0                 xor eax, eax
// 0041016e  64890d00000000       mov dword ptr fs:[0], ecx
// 00410175  83c410               add esp, 0x10
// 00410178  c3                   ret 
// copied from an identical function in another client (function ?createColorSelector@@YAPAUCRobloxControlColorSelector@@XZ)

// 0044edf0  6aff                 push -1
// 0044edf2  681afa7b00           push 0x7bfa1a
// 0044edf7  64a100000000         mov eax, dword ptr fs:[0]
// 0044edfd  50                   push eax
// 0044edfe  64892500000000       mov dword ptr fs:[0], esp
// 0044ee05  51                   push ecx
// 0044ee06  6884010000           push 0xa8
// 0044ee0b  e8101b2500           call 0x6a0920
// 0044ee10  83c404               add esp, 4
// 0044ee13  890424               mov dword ptr [esp], eax
// 0044ee16  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0044ee1e  85c0                 test eax, eax
// 0044ee20  7416                 je 0x44ee38
// 0044ee22  8bc8                 mov ecx, eax
// 0044ee24  e837feffff           call 0x44ec60
// 0044ee29  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044ee2d  64890d00000000       mov dword ptr fs:[0], ecx
// 0044ee34  83c410               add esp, 0x10
// 0044ee37  c3                   ret 
// 0044ee38  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044ee3c  33c0                 xor eax, eax
// 0044ee3e  64890d00000000       mov dword ptr fs:[0], ecx
// 0044ee45  83c410               add esp, 0x10
// 0044ee48  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct CRobloxControlColorSelector
{
    char storage[0xa8];
    CRobloxControlColorSelector();
};

CRobloxControlColorSelector* createColorSelector()
{
    return new CRobloxControlColorSelector;
}
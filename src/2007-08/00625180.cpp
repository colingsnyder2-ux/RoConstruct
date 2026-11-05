// from server: 100% by atomic.potato
// roc 2007-08 00625180  unit: RBX::ArrowButton  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00625180
//
// 00625180  8b442404             mov eax, dword ptr [esp + 4]
// 00625184  50                   push eax
// 00625185  e8b6ebf4ff           call 0x573d40
// 0062518a  33c9                 xor ecx, ecx
// 0062518c  83c404               add esp, 4
// 0062518f  3888a0010000         cmp byte ptr [eax + 0x1a0], cl
// 00625195  0f94c1               sete cl
// 00625198  8ac1                 mov al, cl
// 0062519a  c3                   ret 

extern "C" void* __cdecl sub_573D40(void*);

bool __cdecl sub_625180(void* a)
{
    void* p = sub_573D40(a);
    return *(unsigned char*)((char*)p + 0x1a0) == 0;
}

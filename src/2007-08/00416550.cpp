// from server: 100% by EspClaude
// from server: 85% by colin
// roc 2007-08 00416550  unit: VCLuaFunction::?$CComObject  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00416550
// 00416550  53                   push ebx
// 00416551  56                   push esi
// 00416552  8bf1                 mov esi, ecx
// 00416554  33db                 xor ebx, ebx
// 00416556  395e10               cmp dword ptr [esi + 0x10], ebx
// 00416559  57                   push edi
// 0041655a  7448                 je 0x4165a4
// 0041655c  8d642400             lea esp, [esp]
// 00416560  8b4610               mov eax, dword ptr [esi + 0x10]
// 00416563  3bc3                 cmp eax, ebx
// 00416565  7438                 je 0x41659f
// 00416567  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0041656a  8d4408ff             lea eax, [eax + ecx - 1]
// 0041656e  8b4e08               mov ecx, dword ptr [esi + 8]
// 00416571  3bc8                 cmp ecx, eax
// 00416573  7702                 ja 0x416577
// 00416575  2bc1                 sub eax, ecx
// 00416577  8b5604               mov edx, dword ptr [esi + 4]
// 0041657a  8b3c82               mov edi, dword ptr [edx + eax*4]
// 0041657d  391f                 cmp dword ptr [edi], ebx
// 0041657f  7410                 je 0x416591
// 00416581  8b4704               mov eax, dword ptr [edi + 4]
// 00416584  8b0f                 mov ecx, dword ptr [edi]
// 00416586  6a01                 push 1
// 00416588  50                   push eax
// 00416589  ffd1                 call ecx
// 0041658b  83c408               add esp, 8
// 0041658e  894704               mov dword ptr [edi + 4], eax
// 00416591  891f                 mov dword ptr [edi], ebx
// 00416593  895f08               mov dword ptr [edi + 8], ebx
// 00416596  834610ff             add dword ptr [esi + 0x10], -1
// 0041659a  7503                 jne 0x41659f
// 0041659c  895e0c               mov dword ptr [esi + 0xc], ebx
// 0041659f  395e10               cmp dword ptr [esi + 0x10], ebx
// 004165a2  75bc                 jne 0x416560
// 004165a4  8b7e08               mov edi, dword ptr [esi + 8]
// 004165a7  3bfb                 cmp edi, ebx
// 004165a9  7622                 jbe 0x4165cd
// 004165ab  eb03                 jmp 0x4165b0
// 004165ad  8d4900               lea ecx, [ecx]
// 004165b0  8b5604               mov edx, dword ptr [esi + 4]
// 004165b3  83ef01               sub edi, 1
// 004165b6  391cba               cmp dword ptr [edx + edi*4], ebx
// 004165b9  8d04ba               lea eax, [edx + edi*4]
// 004165bc  740b                 je 0x4165c9
// 004165be  8b00                 mov eax, dword ptr [eax]
// 004165c0  50                   push eax
// 004165c1  e89c962100           call 0x62fc62
// 004165c6  83c404               add esp, 4
// 004165c9  3bfb                 cmp edi, ebx
// 004165cb  77e3                 ja 0x4165b0
// 004165cd  8b4604               mov eax, dword ptr [esi + 4]
// 004165d0  3bc3                 cmp eax, ebx
// 004165d2  7409                 je 0x4165dd
// 004165d4  50                   push eax
// 004165d5  e888962100           call 0x62fc62
// 004165da  83c404               add esp, 4
// 004165dd  5f                   pop edi
// 004165de  895e04               mov dword ptr [esi + 4], ebx
// 004165e1  895e08               mov dword ptr [esi + 8], ebx
// 004165e4  5e                   pop esi
// 004165e5  5b                   pop ebx
// 004165e6  c3                   ret 

// Element: 12 bytes (one per deque block); destructor clears a manager-based
// functor: if (+0) +4 = (+0)(+4, 1); +0 = 0; +8 = 0.
union any_pointer { void* obj_ptr; const void* const_obj_ptr; void (*func_ptr)(); char data[1]; };
struct F {
    any_pointer (*manager)(any_pointer, int);
    any_pointer functor;
    void* invoker;
    ~F()
    {
        if (manager)
            functor = manager(functor, 1);
        manager = 0;
        invoker = 0;
    }
};
#include <deque>
struct D : std::deque<F> {
    void tidy() { _Tidy(); }
};
template class std::deque<F>;

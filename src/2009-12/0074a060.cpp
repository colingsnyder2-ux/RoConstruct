// from server: 100% by nuck16
// roc 2009-12 0074a060  unit: RBX::VHandles::?$EventDesc  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074a060
//
// 0074a060  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0074a064  83f804               cmp eax, 4
// 0074a067  7409                 je 0x74a072
// 0074a069  8944240c             mov dword ptr [esp + 0xc], eax
// 0074a06d  e9befbffff           jmp 0x749c30
// 0074a072  8b442408             mov eax, dword ptr [esp + 8]
// 0074a076  32c9                 xor cl, cl
// 0074a078  c700587bb500         mov dword ptr [eax], 0xb57b58
// 0074a07e  884804               mov byte ptr [eax + 4], cl
// 0074a081  884805               mov byte ptr [eax + 5], cl
// 0074a084  c3                   ret 

// 0xb57b58 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b57b58[];
extern "C" void func_749c30(int, int, int);

void func_0074a060(int a, int b, int c)
{
    if (c != 4)
    {
        func_749c30(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b57b58;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

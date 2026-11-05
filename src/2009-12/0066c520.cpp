// from server: 100% by nuck16
// roc 2009-12 0066c520  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::slot  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0066c520
//
// 0066c520  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0066c524  83f804               cmp eax, 4
// 0066c527  7409                 je 0x66c532
// 0066c529  8944240c             mov dword ptr [esp + 0xc], eax
// 0066c52d  e9defaffff           jmp 0x66c010
// 0066c532  8b442408             mov eax, dword ptr [esp + 8]
// 0066c536  32c9                 xor cl, cl
// 0066c538  c700f03fb300         mov dword ptr [eax], 0xb33ff0
// 0066c53e  884804               mov byte ptr [eax + 4], cl
// 0066c541  884805               mov byte ptr [eax + 5], cl
// 0066c544  c3                   ret 

// 0xb33ff0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b33ff0[];
extern "C" void func_66c010(int, int, int);

void func_0066c520(int a, int b, int c)
{
    if (c != 4)
    {
        func_66c010(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b33ff0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

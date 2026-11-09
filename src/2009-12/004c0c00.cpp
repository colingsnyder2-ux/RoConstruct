// from server: 100% by nuck16
// roc 2009-12 004c0c00  unit: RBX::RbxParticleEmitter  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c0c00
//
// 004c0c00  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c0c04  83f804               cmp eax, 4
// 004c0c07  7409                 je 0x4c0c12
// 004c0c09  8944240c             mov dword ptr [esp + 0xc], eax
// 004c0c0d  e9aef5ffff           jmp 0x4c01c0
// 004c0c12  8b442408             mov eax, dword ptr [esp + 8]
// 004c0c16  32c9                 xor cl, cl
// 004c0c18  c7009806b100         mov dword ptr [eax], 0xb10698
// 004c0c1e  884804               mov byte ptr [eax + 4], cl
// 004c0c21  884805               mov byte ptr [eax + 5], cl
// 004c0c24  c3                   ret 

// 0xb10698 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b10698[];
extern "C" void func_4c01c0(int, int, int);

void func_004c0c00(int a, int b, int c)
{
    if (c != 4)
    {
        func_4c01c0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b10698;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

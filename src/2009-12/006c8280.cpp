// from server: 100% by nuck16
// roc 2009-12 006c8280  unit: RBX::VExplosion::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c8280
//
// 006c8280  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006c8284  83f804               cmp eax, 4
// 006c8287  7409                 je 0x6c8292
// 006c8289  8944240c             mov dword ptr [esp + 0xc], eax
// 006c828d  e99ef7ffff           jmp 0x6c7a30
// 006c8292  8b442408             mov eax, dword ptr [esp + 8]
// 006c8296  32c9                 xor cl, cl
// 006c8298  c70068cfb300         mov dword ptr [eax], 0xb3cf68
// 006c829e  884804               mov byte ptr [eax + 4], cl
// 006c82a1  884805               mov byte ptr [eax + 5], cl
// 006c82a4  c3                   ret 

// 0xb3cf68 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b3cf68[];
extern "C" void func_6c7a30(int, int, int);

void func_006c8280(int a, int b, int c)
{
    if (c != 4)
    {
        func_6c7a30(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b3cf68;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

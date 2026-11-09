// from server: 100% by nuck16
// roc 2009-12 007a5810  unit: RBX::Effect  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007a5810
//
// 007a5810  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007a5814  83f804               cmp eax, 4
// 007a5817  7409                 je 0x7a5822
// 007a5819  8944240c             mov dword ptr [esp + 0xc], eax
// 007a581d  e9eefeffff           jmp 0x7a5710
// 007a5822  8b442408             mov eax, dword ptr [esp + 8]
// 007a5826  32c9                 xor cl, cl
// 007a5828  c700e82fb600         mov dword ptr [eax], 0xb62fe8
// 007a582e  884804               mov byte ptr [eax + 4], cl
// 007a5831  884805               mov byte ptr [eax + 5], cl
// 007a5834  c3                   ret 

// 0xb62fe8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b62fe8[];
extern "C" void func_7a5710(int, int, int);

void func_007a5810(int a, int b, int c)
{
    if (c != 4)
    {
        func_7a5710(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b62fe8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

// from server: 100% by nuck16
// roc 2009-12 0074fec0  unit: RBX::LocalBackpackTool  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074fec0
//
// 0074fec0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0074fec4  83f804               cmp eax, 4
// 0074fec7  7409                 je 0x74fed2
// 0074fec9  8944240c             mov dword ptr [esp + 0xc], eax
// 0074fecd  e9eef7ffff           jmp 0x74f6c0
// 0074fed2  8b442408             mov eax, dword ptr [esp + 8]
// 0074fed6  32c9                 xor cl, cl
// 0074fed8  c700a892b500         mov dword ptr [eax], 0xb592a8
// 0074fede  884804               mov byte ptr [eax + 4], cl
// 0074fee1  884805               mov byte ptr [eax + 5], cl
// 0074fee4  c3                   ret 

// 0xb592a8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b592a8[];
extern "C" void func_74f6c0(int, int, int);

void func_0074fec0(int a, int b, int c)
{
    if (c != 4)
    {
        func_74f6c0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b592a8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

// from server: 100% by nuck16
// roc 2009-12 0052c4a0  unit: RBX::Network::Server  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052c4a0
//
// 0052c4a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0052c4a4  83f804               cmp eax, 4
// 0052c4a7  7409                 je 0x52c4b2
// 0052c4a9  8944240c             mov dword ptr [esp + 0xc], eax
// 0052c4ad  e93ef7ffff           jmp 0x52bbf0
// 0052c4b2  8b442408             mov eax, dword ptr [esp + 8]
// 0052c4b6  32c9                 xor cl, cl
// 0052c4b8  c70050bfb100         mov dword ptr [eax], 0xb1bf50
// 0052c4be  884804               mov byte ptr [eax + 4], cl
// 0052c4c1  884805               mov byte ptr [eax + 5], cl
// 0052c4c4  c3                   ret 

// 0xb1bf50 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b1bf50[];
extern "C" void func_52bbf0(int, int, int);

void func_0052c4a0(int a, int b, int c)
{
    if (c != 4)
    {
        func_52bbf0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b1bf50;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

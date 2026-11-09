// from server: 100% by nuck16
// roc 2009-12 007453c0  unit: RBX::P8ModelInstance::?$GetSetImpl  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007453c0
//
// 007453c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007453c4  83f804               cmp eax, 4
// 007453c7  7409                 je 0x7453d2
// 007453c9  8944240c             mov dword ptr [esp + 0xc], eax
// 007453cd  e94efbffff           jmp 0x744f20
// 007453d2  8b442408             mov eax, dword ptr [esp + 8]
// 007453d6  32c9                 xor cl, cl
// 007453d8  c700305fb500         mov dword ptr [eax], 0xb55f30
// 007453de  884804               mov byte ptr [eax + 4], cl
// 007453e1  884805               mov byte ptr [eax + 5], cl
// 007453e4  c3                   ret 

// 0xb55f30 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b55f30[];
extern "C" void func_744f20(int, int, int);

void func_007453c0(int a, int b, int c)
{
    if (c != 4)
    {
        func_744f20(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b55f30;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

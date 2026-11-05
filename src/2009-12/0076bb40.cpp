// from server: 100% by nuck16
// roc 2009-12 0076bb40  unit: RBX::P8PlayerMouse::?$GetSetImpl  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0076bb40
//
// 0076bb40  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0076bb44  83f804               cmp eax, 4
// 0076bb47  7409                 je 0x76bb52
// 0076bb49  8944240c             mov dword ptr [esp + 0xc], eax
// 0076bb4d  e94ef8ffff           jmp 0x76b3a0
// 0076bb52  8b442408             mov eax, dword ptr [esp + 8]
// 0076bb56  32c9                 xor cl, cl
// 0076bb58  c70030f3b500         mov dword ptr [eax], 0xb5f330
// 0076bb5e  884804               mov byte ptr [eax + 4], cl
// 0076bb61  884805               mov byte ptr [eax + 5], cl
// 0076bb64  c3                   ret 

// 0xb5f330 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b5f330[];
extern "C" void func_76b3a0(int, int, int);

void func_0076bb40(int a, int b, int c)
{
    if (c != 4)
    {
        func_76b3a0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b5f330;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

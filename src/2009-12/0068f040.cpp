// from server: 100% by nuck16
// roc 2009-12 0068f040  unit: RBX::VContentId::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068f040
//
// 0068f040  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068f044  83f804               cmp eax, 4
// 0068f047  7409                 je 0x68f052
// 0068f049  8944240c             mov dword ptr [esp + 0xc], eax
// 0068f04d  e94ef2ffff           jmp 0x68e2a0
// 0068f052  8b442408             mov eax, dword ptr [esp + 8]
// 0068f056  32c9                 xor cl, cl
// 0068f058  c700306bb300         mov dword ptr [eax], 0xb36b30
// 0068f05e  884804               mov byte ptr [eax + 4], cl
// 0068f061  884805               mov byte ptr [eax + 5], cl
// 0068f064  c3                   ret 

// 0xb36b30 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b36b30[];
extern "C" void func_68e2a0(int, int, int);

void func_0068f040(int a, int b, int c)
{
    if (c != 4)
    {
        func_68e2a0(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b36b30;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

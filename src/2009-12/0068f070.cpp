// from server: 100% by nuck16
// roc 2009-12 0068f070  unit: RBX::VContentId::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068f070
//
// 0068f070  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068f074  83f804               cmp eax, 4
// 0068f077  7409                 je 0x68f082
// 0068f079  8944240c             mov dword ptr [esp + 0xc], eax
// 0068f07d  e98ef2ffff           jmp 0x68e310
// 0068f082  8b442408             mov eax, dword ptr [esp + 8]
// 0068f086  32c9                 xor cl, cl
// 0068f088  c700b06bb300         mov dword ptr [eax], 0xb36bb0
// 0068f08e  884804               mov byte ptr [eax + 4], cl
// 0068f091  884805               mov byte ptr [eax + 5], cl
// 0068f094  c3                   ret 

// 0xb36bb0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b36bb0[];
extern "C" void func_68e310(int, int, int);

void func_0068f070(int a, int b, int c)
{
    if (c != 4)
    {
        func_68e310(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b36bb0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

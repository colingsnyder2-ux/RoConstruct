// from server: 100% by nuck16
// roc 2009-12 0068f120  unit: RBX::VContentId::?$TypedPropertyDescriptor  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068f120
//
// 0068f120  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068f124  83f804               cmp eax, 4
// 0068f127  7409                 je 0x68f132
// 0068f129  8944240c             mov dword ptr [esp + 0xc], eax
// 0068f12d  e90ef7ffff           jmp 0x68e840
// 0068f132  8b442408             mov eax, dword ptr [esp + 8]
// 0068f136  32c9                 xor cl, cl
// 0068f138  c700c871b300         mov dword ptr [eax], 0xb371c8
// 0068f13e  884804               mov byte ptr [eax + 4], cl
// 0068f141  884805               mov byte ptr [eax + 5], cl
// 0068f144  c3                   ret 

// 0xb371c8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b371c8[];
extern "C" void func_68e840(int, int, int);

void func_0068f120(int a, int b, int c)
{
    if (c != 4)
    {
        func_68e840(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b371c8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

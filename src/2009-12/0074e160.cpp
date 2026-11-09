// from server: 100% by nuck16
// roc 2009-12 0074e160  unit: RBX::VArcHandles::?$EventDesc  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074e160
//
// 0074e160  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0074e164  83f804               cmp eax, 4
// 0074e167  7409                 je 0x74e172
// 0074e169  8944240c             mov dword ptr [esp + 0xc], eax
// 0074e16d  e90efbffff           jmp 0x74dc80
// 0074e172  8b442408             mov eax, dword ptr [esp + 8]
// 0074e176  32c9                 xor cl, cl
// 0074e178  c700e88db500         mov dword ptr [eax], 0xb58de8
// 0074e17e  884804               mov byte ptr [eax + 4], cl
// 0074e181  884805               mov byte ptr [eax + 5], cl
// 0074e184  c3                   ret 

// 0xb58de8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b58de8[];
extern "C" void func_74dc80(int, int, int);

void func_0074e160(int a, int b, int c)
{
    if (c != 4)
    {
        func_74dc80(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b58de8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

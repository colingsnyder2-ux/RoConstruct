// from server: 100% by nuck16
// roc 2009-12 0041b620  unit: CInstanceRecord  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041b620
//
// 0041b620  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b624  83f804               cmp eax, 4
// 0041b627  7409                 je 0x41b632
// 0041b629  8944240c             mov dword ptr [esp + 0xc], eax
// 0041b62d  e9cef7ffff           jmp 0x41ae00
// 0041b632  8b442408             mov eax, dword ptr [esp + 8]
// 0041b636  32c9                 xor cl, cl
// 0041b638  c700d03bb000         mov dword ptr [eax], 0xb03bd0
// 0041b63e  884804               mov byte ptr [eax + 4], cl
// 0041b641  884805               mov byte ptr [eax + 5], cl
// 0041b644  c3                   ret 

// 0xb03bd0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b03bd0[];
extern "C" void func_41ae00(int, int, int);

void func_0041b620(int a, int b, int c)
{
    if (c != 4)
    {
        func_41ae00(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b03bd0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

// from server: 100% by nuck16
// roc 2009-12 0074ba00  unit: RBX::GroundStage  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074ba00
//
// 0074ba00  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0074ba04  83f804               cmp eax, 4
// 0074ba07  7409                 je 0x74ba12
// 0074ba09  8944240c             mov dword ptr [esp + 0xc], eax
// 0074ba0d  e9eefaffff           jmp 0x74b500
// 0074ba12  8b442408             mov eax, dword ptr [esp + 8]
// 0074ba16  32c9                 xor cl, cl
// 0074ba18  c700a07fb500         mov dword ptr [eax], 0xb57fa0
// 0074ba1e  884804               mov byte ptr [eax + 4], cl
// 0074ba21  884805               mov byte ptr [eax + 5], cl
// 0074ba24  c3                   ret 

// 0xb57fa0 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b57fa0[];
extern "C" void func_74b500(int, int, int);

void func_0074ba00(int a, int b, int c)
{
    if (c != 4)
    {
        func_74b500(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b57fa0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

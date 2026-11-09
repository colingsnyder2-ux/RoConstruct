// from server: 100% by nuck16
// roc 2009-12 0074ba30  unit: RBX::GroundStage  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074ba30
//
// 0074ba30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0074ba34  83f804               cmp eax, 4
// 0074ba37  7409                 je 0x74ba42
// 0074ba39  8944240c             mov dword ptr [esp + 0xc], eax
// 0074ba3d  e92efbffff           jmp 0x74b570
// 0074ba42  8b442408             mov eax, dword ptr [esp + 8]
// 0074ba46  32c9                 xor cl, cl
// 0074ba48  c700a880b500         mov dword ptr [eax], 0xb580a8
// 0074ba4e  884804               mov byte ptr [eax + 4], cl
// 0074ba51  884805               mov byte ptr [eax + 5], cl
// 0074ba54  c3                   ret 

// 0xb580a8 is the RTTI type descriptor of the stored functor (boost functor_manager type tag)
extern "C" const char type_descriptor_b580a8[];
extern "C" void func_74b570(int, int, int);

void func_0074ba30(int a, int b, int c)
{
    if (c != 4)
    {
        func_74b570(a, b, c);
        return;
    }

    *(const void **)b = type_descriptor_b580a8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}

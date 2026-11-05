// from server: 84% by colin
// roc 2007-08 0042f070  unit: CWrapperView  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042f070
//
// 0042f070  e8a9192000           call 0x630a1e
// 0042f075  83c430               add esp, 0x30
// 0042f078  c20400               ret 4

extern "C" void __cdecl func_00630a1e();

void __stdcall func_0042f070(int)
{
    func_00630a1e();
}

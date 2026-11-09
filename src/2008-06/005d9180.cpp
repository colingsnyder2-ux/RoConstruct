// from server: 100% by EspClaude
// roc-flags: /O1 /GS- /EHsc /MD
// from server: 89% by atomic.potato
// roc 2008-06 005d9180  unit: RBX::VPartInstance::?$FilteredSelection  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d9180
//
// 005d9180  e88bf9ffff           call 0x5d8b10
// 005d9185  85c0                 test eax, eax
// 005d9187  7408                 je 0x5d9191
// 005d9189  8b80c8020000         mov eax, dword ptr [eax + 0x2c8]
// 005d918f  eb02                 jmp 0x5d9193
// 005d9191  33c0                 xor eax, eax
// 005d9193  85c0                 test eax, eax
// 005d9195  7404                 je 0x5d919b
// 005d9197  8b4010               mov eax, dword ptr [eax + 0x10]
// 005d919a  c3                   ret 
// 005d919b  33c0                 xor eax, eax
// 005d919d  c3                   ret 

struct S
{
    S* GetValue();
    int f();
};

int S::f()
{
    S* p = this->GetValue();
    S* q = p ? *(S**)((char*)p + 0x2c8) : 0;
    return q ? *(int*)((char*)q + 0x10) : 0;
}

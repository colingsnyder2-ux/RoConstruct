// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00643eb0  unit: RBX::HUMAN::HumanoidState  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00643eb0
//
// 00643eb0  8b4108               mov eax, dword ptr [ecx + 8]
// 00643eb3  50                   push eax
// 00643eb4  e8b737f9ff           call 0x5d7670
// 00643eb9  83c404               add esp, 4
// 00643ebc  8bc8                 mov ecx, eax
// 00643ebe  e87dfeffff           call 0x643d40
// 00643ec3  f7d8                 neg eax
// 00643ec5  1bc0                 sbb eax, eax
// 00643ec7  f7d8                 neg eax
// 00643ec9  c3                   ret 

struct S;
void* __cdecl func_005d7670(S* object);

struct Model
{
    int func_00643d40();
};

struct HumanoidState
{
    char padding[8];
    S* object;

    int func_00643eb0();
};

int HumanoidState::func_00643eb0()
{
    return static_cast<Model*>(func_005d7670(object))->func_00643d40() != 0;
}

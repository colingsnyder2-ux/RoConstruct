// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00540530  unit: RBX::RenderBase::AggregatingSceneManager::Bucket  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540530
//
// 00540530  55                   push ebp
// 00540531  8bec                 mov ebp, esp
// 00540533  51                   push ecx
// 00540534  894dfc               mov dword ptr [ebp - 4], ecx
// 00540537  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0054053a  e841090000           call 0x540e80
// 0054053f  50                   push eax
// 00540540  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00540543  e8680d0000           call 0x5412b0
// 00540548  8b45fc               mov eax, dword ptr [ebp - 4]
// 0054054b  8be5                 mov esp, ebp
// 0054054d  5d                   pop ebp
// 0054054e  c20400               ret 4

struct S {
    int get() const;
    void set(int value);
    S& operator=(const S& other);
};

#pragma optimize("", off)
S& S::operator=(const S& other)
{
    set(other.get());
    return *this;
}
#pragma optimize("", on)

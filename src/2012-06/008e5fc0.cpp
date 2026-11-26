// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 0040d570  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040d570
//
// 0040d570  8b542404             mov edx, dword ptr [esp + 4]
// 0040d574  56                   push esi
// 0040d575  8bf1                 mov esi, ecx
// 0040d577  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 0040d57a  8b01                 mov eax, dword ptr [ecx]
// 0040d57c  8b4008               mov eax, dword ptr [eax + 8]
// 0040d57f  57                   push edi
// 0040d580  52                   push edx
// 0040d581  ffd0                 call eax
// 0040d583  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 0040d586  8b11                 mov edx, dword ptr [ecx]
// 0040d588  8b5208               mov edx, dword ptr [edx + 8]
// 0040d58b  8bf8                 mov edi, eax
// 0040d58d  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040d591  50                   push eax
// 0040d592  ffd2                 call edx
// 0040d594  33c9                 xor ecx, ecx
// 0040d596  3bf8                 cmp edi, eax
// 0040d598  0f94c1               sete cl
// 0040d59b  5f                   pop edi
// 0040d59c  8ac1                 mov al, cl
// 0040d59e  5e                   pop esi
// 0040d59f  c20800               ret 8

struct GetSet {
    virtual void slot0();
    virtual void slot1();
    virtual int getValue(const void* instance) const;
};

struct TypedPropertyDescriptor {
    char pad[0x2c];
    GetSet* getset;
    bool equalValue(const void* a, const void* b) const;
};

bool TypedPropertyDescriptor::equalValue(const void* a, const void* b) const {
    int va = getset->getValue(a);
    return va == getset->getValue(b);
}

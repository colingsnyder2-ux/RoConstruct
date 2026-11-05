// from server: 100% by coldek
// from server: 100% by king_originala
// roc 2008-06 00553810  unit: RBX::RenderBase::AggregateChunk  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00553810
//
// 00553810  55                   push ebp
// 00553811  8bec                 mov ebp, esp
// 00553813  51                   push ecx
// 00553814  894dfc               mov dword ptr [ebp - 4], ecx
// 00553817  8b45fc               mov eax, dword ptr [ebp - 4]
// 0055381a  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0055381d  8b10                 mov edx, dword ptr [eax]
// 0055381f  ffd2                 call edx
// 00553821  8be5                 mov esp, ebp
// 00553823  5d                   pop ebp
// 00553824  c20400               ret 4

typedef void (__thiscall *Callback)(void *);

struct S {
    Callback callback;
    void invoke(void *object);
};

#pragma optimize("", off)
void S::invoke(void *object)
{
    callback(object);
}
#pragma optimize("", on)

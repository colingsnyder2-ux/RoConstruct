// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0064e1a0  unit: RBX::P8Camera::?$GetSetImpl  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064e1a0
//
// 0064e1a0  56                   push esi
// 0064e1a1  57                   push edi
// 0064e1a2  8bf1                 mov esi, ecx
// 0064e1a4  e8674dffff           call 0x642f10
// 0064e1a9  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0064e1ad  57                   push edi
// 0064e1ae  8bce                 mov ecx, esi
// 0064e1b0  e89bfeffff           call 0x64e050
// 0064e1b5  8b8e64010000         mov ecx, dword ptr [esi + 0x164]
// 0064e1bb  85c9                 test ecx, ecx
// 0064e1bd  7410                 je 0x64e1cf
// 0064e1bf  8d4724               lea eax, [edi + 0x24]
// 0064e1c2  50                   push eax
// 0064e1c3  81c630010000         add esi, 0x130
// 0064e1c9  56                   push esi
// 0064e1ca  e8c17dfcff           call 0x615f90
// 0064e1cf  8bc7                 mov eax, edi
// 0064e1d1  5f                   pop edi
// 0064e1d2  5e                   pop esi
// 0064e1d3  c20400               ret 4

struct Callback {
    void apply(void* source, void* destination);
};

struct Result {
    char prefix[0x24];
    char value;
};

struct S {
    char prefix[0x8c];
    char value[0x34];
    Callback* callback;

    void prepare();
    void populate(Result* result);
    Result* get(Result* result);
};

Result* S::get(Result* result)
{
    prepare();
    populate(result);
    if (callback)
        callback->apply(value, &result->value);
    return result;
}

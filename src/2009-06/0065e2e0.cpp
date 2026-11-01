// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0059abb0  unit: RBX::PartInstance  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059abb0
//
// 0059abb0  8b442408             mov eax, dword ptr [esp + 8]
// 0059abb4  8b542404             mov edx, dword ptr [esp + 4]
// 0059abb8  50                   push eax
// 0059abb9  52                   push edx
// 0059abba  81c134feffff         add ecx, 0xfffffe34
// 0059abc0  e8cbfeffff           call 0x59aa90
// 0059abc5  50                   push eax
// 0059abc6  e865c40d00           call 0x677030
// 0059abcb  83c40c               add esp, 0xc
// 0059abce  c20800               ret 8

struct PartInstance {
    int get();
};

extern "C" int __cdecl process(int value, int a, int b);

struct S {
    int f(int a, int b);
};

int S::f(int a, int b) {
    return process(((PartInstance*)((char*)this - 0xa8))->get(), a, b);
}

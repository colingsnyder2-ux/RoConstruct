// roc 2009-12 0046dae0  unit: CScriptEditor  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0046dae0
//
// 0046dae0  56                   push esi
// 0046dae1  e8fad0ffff           call 0x46abe0
// 0046dae6  8bf0                 mov esi, eax
// 0046dae8  6a01                 push 1
// 0046daea  6a01                 push 1
// 0046daec  8bce                 mov ecx, esi
// 0046daee  e83dc3ffff           call 0x469e30
// 0046daf3  6a01                 push 1
// 0046daf5  8bce                 mov ecx, esi
// 0046daf7  85c0                 test eax, eax
// 0046daf9  740b                 je 0x46db06
// 0046dafb  6a00                 push 0
// 0046dafd  6a01                 push 1
// 0046daff  e8dcc2ffff           call 0x469de0
// 0046db04  5e                   pop esi
// 0046db05  c3                   ret 
// 0046db06  6a10                 push 0x10
// 0046db08  6a01                 push 1
// 0046db0a  e8d1c2ffff           call 0x469de0
// 0046db0f  5e                   pop esi
// 0046db10  c3                   ret 
// copied from an identical function in another client (function ?init@CScriptEditor@ns_ROCX000000@@QAEXXZ)

namespace ns_ROCX000000 {
struct CScriptEditor {
    void init();
};

struct Helper {
    int f1(int a, int b);
    int f2(int a, int b, int c);
};

extern "C" void* __cdecl sub_45D230();

void CScriptEditor::init()
{
    Helper* p = (Helper*)sub_45D230();
    if (p->f1(1, 1)) {
        p->f2(1, 0, 1);
    } else {
        p->f2(1, 0x10, 1);
    }
}
}

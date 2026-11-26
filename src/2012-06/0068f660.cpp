// from server: 100% by Xemicl
// roc 2012-06 0068f660  unit: RBX::ModelInstance  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0068f660
//
// 0068f660  83ec10               sub esp, 0x10
// 0068f663  8b442414             mov eax, dword ptr [esp + 0x14]
// 0068f667  89442408             mov dword ptr [esp + 8], eax
// 0068f66b  8d442404             lea eax, [esp + 4]
// 0068f66f  8d542403             lea edx, [esp + 3]
// 0068f673  50                   push eax
// 0068f674  c644240701           mov byte ptr [esp + 7], 1
// 0068f679  c744240890f56800     mov dword ptr [esp + 8], 0x68f590
// 0068f681  89542410             mov dword ptr [esp + 0x10], edx
// 0068f685  e826efffff           call 0x68e5b0
// 0068f68a  8a442403             mov al, byte ptr [esp + 3]
// 0068f68e  83c410               add esp, 0x10
// 0068f691  c20400               ret 4
// copied from an identical function in another client (function ??RSignal@@QAE_NPAUArg@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Arg;
struct Slot;
void invokeSlot(const Slot& slot, Arg* arg, bool* result);
struct Invoker {
    void (*fn)(const Slot&, Arg*, bool*);
    Arg* arg;
    bool* result;
};
class Signal {
public:
    void call(const Invoker& inv);
    bool operator()(Arg* arg);
};
bool Signal::operator()(Arg* arg)
{
    bool result = true;
    Invoker inv = { &invokeSlot, arg, &result };
    call(inv);
    return result;
}
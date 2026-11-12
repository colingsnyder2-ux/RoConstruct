// from server: 100% by EspClaude
// from server: 48% by Intel
// roc 2007-08 0055bac0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055bac0
// 0055bac0  6aff                 push -1
// 0055bac2  683b387500           push 0x75383b
// 0055bac7  64a100000000         mov eax, dword ptr fs:[0]
// 0055bacd  50                   push eax
// 0055bace  64892500000000       mov dword ptr fs:[0], esp
// 0055bad5  51                   push ecx
// 0055bad6  56                   push esi
// 0055bad7  8bf1                 mov esi, ecx
// 0055bad9  89742404             mov dword ptr [esp + 4], esi
// 0055badd  c7060c8a7a00         mov dword ptr [esi], 0x7a8a0c
// 0055bae3  6aff                 push -1
// 0055bae5  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0055baed  e8be4debff           call 0x4108b0
// 0055baf2  8d4e08               lea ecx, [esi + 8]
// 0055baf5  c74604ffffffff       mov dword ptr [esi + 4], 0xffffffff
// 0055bafc  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0055bb04  e897ddffff           call 0x5598a0
// 0055bb09  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0055bb0d  5e                   pop esi
// 0055bb0e  64890d00000000       mov dword ptr fs:[0], ecx
// 0055bb15  83c410               add esp, 0x10
// 0055bb18  c3                   ret 
// StateStack<XmlState>::~StateStack (rbxgs util/StateStack.h shape):
// vptr, currentState at +4 (set -1), vector<StateEntry> at +8; StateEntry is
// 0x24 bytes (imul 0x38e38e39 in clearStackAfter) with std::string first.
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <string>

namespace RBX {
class XmlState {
public:
    virtual ~XmlState();
};

template<class T>
class StateStack
{
    struct StateEntry
    {
    public:
        std::string name;
        T* undoState;
        T* redoState;
    };

private:
    int currentState;
    std::vector<StateEntry> stack;
public:
    StateStack()
    {
        currentState = -1;
    }

    ~StateStack()
    {
        clearStackAfter(-1);
        currentState = -1;
    }
protected:
    virtual bool isStackTooBig() const
    {
        return false;
    }
private:
    void clearStackAfter(int index)
    {
        for (int i = stack.size() - 1; i > index; i--)
        {
            delete stack[i].redoState;
            delete stack[i].undoState;
        }

        stack.resize(index + 1);
    }
};

template StateStack<XmlState>::~StateStack();
}

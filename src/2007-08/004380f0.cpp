// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 004380f0  unit: RBX::VStandardOut::?$MarshaledListener  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004380f0
// 004380f0  51                   push ecx
// 004380f1  53                   push ebx
// 004380f2  55                   push ebp
// 004380f3  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 004380f7  56                   push esi
// 004380f8  57                   push edi
// 004380f9  6a38                 push 0x38
// 004380fb  8bd9                 mov ebx, ecx
// 004380fd  e8f47d1f00           call 0x62fef6
// 00438102  8bf8                 mov edi, eax
// 00438104  83c404               add esp, 4
// 00438107  85ff                 test edi, edi
// 00438109  7438                 je 0x438143
// 0043810b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043810f  83ec28               sub esp, 0x28
// 00438112  8bf4                 mov esi, esp
// 00438114  8d4c2448             lea ecx, [esp + 0x48]
// 00438118  89642438             mov dword ptr [esp + 0x38], esp
// 0043811c  51                   push ecx
// 0043811d  8d4e04               lea ecx, [esi + 4]
// 00438120  8906                 mov dword ptr [esi], eax
// 00438122  ff159ce67700         call dword ptr [0x77e69c]
// 00438128  8b542464             mov edx, dword ptr [esp + 0x64]
// 0043812c  895620               mov dword ptr [esi + 0x20], edx
// 0043812f  8b442468             mov eax, dword ptr [esp + 0x68]
// 00438133  55                   push ebp
// 00438134  53                   push ebx
// 00438135  8bcf                 mov ecx, edi
// 00438137  894624               mov dword ptr [esi + 0x24], eax
// 0043813a  e891f9ffff           call 0x437ad0
// 0043813f  8bf0                 mov esi, eax
// 00438141  eb02                 jmp 0x438145
// 00438143  33f6                 xor esi, esi
// 00438145  8d4c2410             lea ecx, [esp + 0x10]
// 00438149  51                   push ecx
// 0043814a  8d4b04               lea ecx, [ebx + 4]
// 0043814d  89742414             mov dword ptr [esp + 0x14], esi
// 00438151  e86acd0200           call 0x464ec0
// 00438156  8b4b18               mov ecx, dword ptr [ebx + 0x18]
// 00438159  56                   push esi
// 0043815a  e8e1afffff           call 0x433140
// 0043815f  8d4c2420             lea ecx, [esp + 0x20]
// 00438163  ff15ace67700         call dword ptr [0x77e6ac]
// 00438169  5f                   pop edi
// 0043816a  5e                   pop esi
// 0043816b  5d                   pop ebp
// 0043816c  5b                   pop ebx
// 0043816d  59                   pop ecx
// 0043816e  c22c00               ret 0x2c

#include <string>

// by-value message: 0x28 bytes on the stack (int, std::string at +4, ints at +0x20/+0x24)
struct Message {
    int type;
    std::string text;
    int a;
    int b;
};

class StandardOut;

// 0x38-byte item, ctor 0x437ad0 (owner, arg, Message by value)
class ItemBase {
};

class Item : public ItemBase {
public:
    Item(StandardOut* owner, const int& arg, Message m) throw();
private:
    int data[14];
};

struct ItemList {               // at this+4, push at 0x464ec0
    void push_back(ItemBase* const& item) throw();
    int pad[5];
};

struct Sink {                   // [this+0x18], 0x433140
    void post(Item* item) throw();
};

class StandardOut {
    int pad0;
    ItemList items;             // +4
    Sink* sink;                 // +0x18
public:
    void marshaledListener(const int& arg, Message m) throw();
};

void StandardOut::marshaledListener(const int& arg, Message m)
{
    Item* item = new Item(this, arg, m);
    items.push_back(item);
    sink->post(item);
}

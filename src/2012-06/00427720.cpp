// from server: 100% by Xemicl
// roc 2012-06 00427720  unit: CInsertObjectDialog  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00427720
//
// 00427720  51                   push ecx
// 00427721  56                   push esi
// 00427722  68d0764200           push 0x4276d0
// 00427727  685c82e100           push 0xe1825c
// 0042772c  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00427734  e8679efdff           call 0x4015a0
// 00427739  8b742414             mov esi, dword ptr [esp + 0x14]
// 0042773d  56                   push esi
// 0042773e  e83dca0300           call 0x464180
// 00427743  83c40c               add esp, 0xc
// 00427746  8bc6                 mov eax, esi
// 00427748  5e                   pop esi
// 00427749  59                   pop ecx
// 0042774a  c3                   ret 
// copied from an identical function in another client (function ?getInstance@@YA?AV?$shared_ptr@VItem@@@boost@@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace boost {
struct once_flag { long state; };
void call_once(once_flag& flag, void (*f)());
template<class T> class shared_ptr { public: T* px; void* pn; shared_ptr() : px(0), pn(0) {} shared_ptr(const shared_ptr&); ~shared_ptr(); };
}
class Item;
boost::shared_ptr<Item> createInstance();
static void initInstance();
static boost::once_flag flag;
boost::shared_ptr<Item> getInstance()
{
    boost::call_once(flag, &initInstance);
    return createInstance();
}
static void initInstance() { createInstance(); }
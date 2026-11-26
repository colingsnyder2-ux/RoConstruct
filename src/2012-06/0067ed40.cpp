// from server: 100% by Xemicl
// roc 2012-06 0067ed40  unit: RBX::VTaskSchedulerSettings::?$GlobalAdvancedSettingsItem  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0067ed40
//
// 0067ed40  6810ed6700           push 0x67ed10
// 0067ed45  68b0a1e200           push 0xe2a1b0
// 0067ed4a  e85128d8ff           call 0x4015a0
// 0067ed4f  b801000000           mov eax, 1
// 0067ed54  83c408               add esp, 8
// 0067ed57  8405c4a1e200         test byte ptr [0xe2a1c4], al
// 0067ed5d  751d                 jne 0x67ed7c
// 0067ed5f  0905c4a1e200         or dword ptr [0xe2a1c4], eax
// 0067ed65  680057b100           push 0xb15700
// 0067ed6a  c705c0a1e20000000000 mov dword ptr [0xe2a1c0], 0
// 0067ed74  e87c443000           call 0x9831f5
// 0067ed79  83c404               add esp, 4
// 0067ed7c  b8c0a1e200           mov eax, 0xe2a1c0
// 0067ed81  c3                   ret 
// copied from an identical function in another client (function ?getInstance@@YAAAV?$scoped_ptr@VItem@@@boost@@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace boost {
struct once_flag { long state; };
void call_once(once_flag& flag, void (*f)());
template<class T> class scoped_ptr { public: T* px; scoped_ptr() : px(0) {} ~scoped_ptr(); };
}
class Item;
static boost::scoped_ptr<Item>& instance() { static boost::scoped_ptr<Item> sp; return sp; }
static void initInstance() { instance(); }
static boost::once_flag flag;
boost::scoped_ptr<Item>& getInstance()
{
    boost::call_once(flag, &initInstance);
    return instance();
}
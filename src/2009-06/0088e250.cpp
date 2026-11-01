// from server: 100% by EspClaude
// roc 2009-06 0088e250  unit: seg_00880000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0088e250
//
// 0088e250  d9ee                 fldz 
// 0088e252  6a01                 push 1
// 0088e254  83ec08               sub esp, 8
// 0088e257  dd1c24               fstp qword ptr [esp]
// 0088e25a  6860238c00           push 0x8c2360
// 0088e25f  33c9                 xor ecx, ecx
// 0088e261  68c80d8e00           push 0x8e0dc8
// 0088e266  51                   push ecx
// 0088e267  b8f0706500           mov eax, 0x6570f0
// 0088e26c  50                   push eax
// 0088e26d  b920cba400           mov ecx, 0xa4cb20
// 0088e272  e81992dcff           call 0x657490
// 0088e277  6860a88900           push 0x89a860
// 0088e27c  e87ab8e8ff           call 0x719afb
// 0088e281  59                   pop ecx
// 0088e282  c3                   ret 
// copied from an identical function in another client (function ??__Efunc_getTimes@RBX@@YAXXZ)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class FunctionDescriptor
{
public:
    enum Security { None = 0, Plugin = 1 };
};
template<class Class, class Signature, int N>
class BoundFuncDesc
{
    char data[0x50];
public:
    BoundFuncDesc(Signature (Class::*function), const char* name, const char* arg1name, double arg1default, FunctionDescriptor::Security security);
    ~BoundFuncDesc();
};
}
class Instance { public: virtual ~Instance(); };
class Listener { public: virtual ~Listener(); };
class Stats : public Instance, public Listener
{
public:
    int getTimes(double window);
};
static Reflection::BoundFuncDesc<Stats, int(double), 1> func_getTimes(&Stats::getTimes, "GetTimes", "window", 0.0, Reflection::FunctionDescriptor::Plugin);
}
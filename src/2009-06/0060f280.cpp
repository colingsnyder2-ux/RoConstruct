// from server: 83% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005812b0  unit: RBX::RotateAxisCommand  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005812b0
//
// 005812b0  83ec28               sub esp, 0x28
// 005812b3  56                   push esi
// 005812b4  57                   push edi
// 005812b5  8bf9                 mov edi, ecx
// 005812b7  8b7720               mov esi, dword ptr [edi + 0x20]
// 005812ba  e891bfffff           call 0x57d250
// 005812bf  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 005812c2  85c9                 test ecx, ecx
// 005812c4  7407                 je 0x5812cd
// 005812c6  e805f3ffff           call 0x5805d0
// 005812cb  eb02                 jmp 0x5812cf
// 005812cd  33c0                 xor eax, eax
// 005812cf  053c010000           add eax, 0x13c
// 005812d4  50                   push eax
// 005812d5  8b07                 mov eax, dword ptr [edi]
// 005812d7  8b5014               mov edx, dword ptr [eax + 0x14]
// 005812da  8d4c2410             lea ecx, [esp + 0x10]
// 005812de  51                   push ecx
// 005812df  8bcf                 mov ecx, edi
// 005812e1  ffd2                 call edx
// 005812e3  50                   push eax
// 005812e4  8bcf                 mov ecx, edi
// 005812e6  e8c5e2ffff           call 0x57f5b0
// 005812eb  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 005812ee  85c9                 test ecx, ecx
// 005812f0  7407                 je 0x5812f9
// 005812f2  e8e91eedff           call 0x4531e0
// 005812f7  eb02                 jmp 0x5812fb
// 005812f9  33c0                 xor eax, eax
// 005812fb  6a04                 push 4
// 005812fd  8bc8                 mov ecx, eax
// 005812ff  e81cc50300           call 0x5bd820
// 00581304  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00581307  c644240800           mov byte ptr [esp + 8], 0
// 0058130c  8b442408             mov eax, dword ptr [esp + 8]
// 00581310  50                   push eax
// 00581311  81c144030000         add ecx, 0x344
// 00581317  e82456ffff           call 0x576940
// 0058131c  8b4704               mov eax, dword ptr [edi + 4]
// 0058131f  83c004               add eax, 4
// 00581322  83781810             cmp dword ptr [eax + 0x18], 0x10
// 00581326  7205                 jb 0x58132d
// 00581328  8b4004               mov eax, dword ptr [eax + 4]
// 0058132b  eb03                 jmp 0x581330
// 0058132d  83c004               add eax, 4
// 00581330  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00581333  51                   push ecx
// 00581334  50                   push eax
// 00581335  e886b20000           call 0x58c5c0
// 0058133a  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0058133e  8b11                 mov edx, dword ptr [ecx]
// 00581340  83c408               add esp, 8
// 00581343  5f                   pop edi
// 00581344  5e                   pop esi
// 00581345  83c428               add esp, 0x28
// 00581348  c744240401000000     mov dword ptr [esp + 4], 1
// 00581350  8b02                 mov eax, dword ptr [edx]
// 00581352  ffe0                 jmp eax

// from server: 95% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <exception>
namespace RBX {
class Instance;
bool checkA(Instance* instance, int role);
bool checkB(Instance* instance, int role);
class runtime_error : public std::exception
{
    std::string message;
public:
    runtime_error(const std::string& m);
};
static __declspec(noinline) void checkPermissions(Instance* instance)
{
    if (checkA(instance, 1) && !checkB(instance, 1))
    {
        std::string msg("Insufficinet permissions");
        throw runtime_error(msg);
    }
}
}

namespace RBX {
struct Matrix3 {float data[9];Matrix3(const Matrix3&);};
struct Name {int id;std::string text;const char* c_str()const{return text.c_str();}};
struct Flag {bool value;Flag():value(false){}};
struct Changed {void notify(Flag);};
struct Workspace {char pad[0x344];Changed changed;};
struct History {void record(int);};
struct Selection;
// These getters are normal thiscall members on the context.
struct Context {
 Selection* selection();
 History* history();
};
struct IDataState {virtual void setDirty(bool)=0;};
void __cdecl trackVerb(const char*,Context*);
struct RotateAxisCommand {
 virtual ~RotateAxisCommand();
 virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();
 virtual Matrix3 axis();
 const Name* name;
 void* unused;
 Workspace* workspace;
 char pad[0x10];
 Context* context;
 void apply(const Matrix3&,void*);
 void doIt(IDataState*);
};
void RotateAxisCommand::doIt(IDataState* state){
 checkPermissions(reinterpret_cast<Instance*>(context));
 Selection* selected=context?context->selection():0;
 apply(axis(),reinterpret_cast<char*>(selected)+0x13c);
 History* history=context?context->history():0;
 history->record(4);
 workspace->changed.notify(Flag());
 trackVerb(name->c_str(),context);
 state->setDirty(true);
}
}

// from server: 94% by EspClaude
// from server: 53% by colin
// roc 2007-08 00425910  unit: CSelectionTreeCtrl  size: 269 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00425910
//
// 00425910  6aff                 push -1
// 00425912  68f0c47300           push 0x73c4f0
// 00425917  64a100000000         mov eax, dword ptr fs:[0]
// 0042591d  50                   push eax
// 0042591e  83ec10               sub esp, 0x10
// 00425921  53                   push ebx
// 00425922  55                   push ebp
// 00425923  56                   push esi
// 00425924  57                   push edi
// 00425925  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042592a  33c4                 xor eax, esp
// 0042592c  50                   push eax
// 0042592d  8d442424             lea eax, [esp + 0x24]
// 00425931  64a300000000         mov dword ptr fs:[0], eax
// 00425937  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 0042593b  8b87bc000000         mov eax, dword ptr [edi + 0xbc]
// 00425941  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00425945  33db                 xor ebx, ebx
// 00425947  3bc5                 cmp eax, ebp
// 00425949  895c242c             mov dword ptr [esp + 0x2c], ebx
// 0042594d  7520                 jne 0x42596f
// 0042594f  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 00425953  3bf3                 cmp esi, ebx
// 00425955  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0042595d  0f84a6000000         je 0x425a09
// 00425963  8d4604               lea eax, [esi + 4]
// 00425966  83c9ff               or ecx, 0xffffffff
// 00425969  f00fc108             lock xadd dword ptr [eax], ecx
// 0042596d  eb7a                 jmp 0x4259e9
// 0042596f  55                   push ebp
// 00425970  e8ab7b1500           call 0x57d520
// 00425975  8bf0                 mov esi, eax
// 00425977  83c404               add esp, 4
// 0042597a  3bf3                 cmp esi, ebx
// 0042597c  7449                 je 0x4259c7
// 0042597e  56                   push esi
// 0042597f  8bcf                 mov ecx, edi
// 00425981  e83aa7ffff           call 0x4200c0
// 00425986  3ac3                 cmp al, bl
// 00425988  753d                 jne 0x4259c7
// 0042598a  895c2418             mov dword ptr [esp + 0x18], ebx
// 0042598e  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00425992  895c2420             mov dword ptr [esp + 0x20], ebx
// 00425996  8d442438             lea eax, [esp + 0x38]
// 0042599a  50                   push eax
// 0042599b  8d4c2418             lea ecx, [esp + 0x18]
// 0042599f  c644243001           mov byte ptr [esp + 0x30], 1
// 004259a4  e867eaffff           call 0x424410
// 004259a9  6a01                 push 1
// 004259ab  6a01                 push 1
// 004259ad  56                   push esi
// 004259ae  8d4c2420             lea ecx, [esp + 0x20]
// 004259b2  51                   push ecx
// 004259b3  8bce                 mov ecx, esi
// 004259b5  e866321400           call 0x568c20
// 004259ba  8d4c2414             lea ecx, [esp + 0x14]
// 004259be  885c242c             mov byte ptr [esp + 0x2c], bl
// 004259c2  e8a9381100           call 0x539270
// 004259c7  55                   push ebp
// 004259c8  8bcf                 mov ecx, edi
// 004259ca  e861bc1100           call 0x541630
// 004259cf  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 004259d3  3bf3                 cmp esi, ebx
// 004259d5  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004259dd  742a                 je 0x425a09
// 004259df  8d5604               lea edx, [esi + 4]
// 004259e2  83c8ff               or eax, 0xffffffff
// 004259e5  f00fc102             lock xadd dword ptr [edx], eax
// 004259e9  751e                 jne 0x425a09
// 004259eb  8b16                 mov edx, dword ptr [esi]
// 004259ed  8b4204               mov eax, dword ptr [edx + 4]
// 004259f0  8bce                 mov ecx, esi
// 004259f2  ffd0                 call eax
// 004259f4  83caff               or edx, 0xffffffff
// 004259f7  8d4e08               lea ecx, [esi + 8]
// 004259fa  f00fc111             lock xadd dword ptr [ecx], edx
// 004259fe  7509                 jne 0x425a09
// 00425a00  8b06                 mov eax, dword ptr [esi]
// 00425a02  8b5008               mov edx, dword ptr [eax + 8]
// 00425a05  8bce                 mov ecx, esi
// 00425a07  ffd2                 call edx
// 00425a09  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00425a0d  64890d00000000       mov dword ptr fs:[0], ecx
// 00425a14  59                   pop ecx
// 00425a15  5f                   pop edi
// 00425a16  5e                   pop esi
// 00425a17  5d                   pop ebp
// 00425a18  5b                   pop ebx
// 00425a19  83c41c               add esp, 0x1c
// 00425a1c  c3                   ret 

#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* operator->() const { return px; }
};

class Instance;
class Target;

// 16-byte container on the stack: +4,+8,+0xc zeroed inline, push_back = 0x424410,
// destructor = 0x539270.
struct TargetVector {
    int alval;
    void* first;
    void* last;
    void* end;
    TargetVector() : first(0), last(0), end(0) {}
    ~TargetVector();
    void push_back(const shared_ptr<Target>& v);
};

class Selection {
public:
    void apply(TargetVector& targets, Selection* sel, bool a, bool b); // 0x568c20
};

Selection* __cdecl findSelection(Instance* inst);                     // 0x57d520

class Target {
public:
    char pad[0xbc];
    Instance* current;                                                // +0xbc
    bool contains(Selection* sel);                                    // 0x4200c0
    void setCurrent(Instance* inst);                                  // 0x541630
};

struct CSelectionTreeCtrl {
    static void select(Instance* inst, shared_ptr<Target> target);
};

void CSelectionTreeCtrl::select(Instance* inst, shared_ptr<Target> target)
{
    Target* t = target.px;
    if (t->current == inst)
        return;
    Selection* sel = findSelection(inst);
    if (sel != 0 && !t->contains(sel)) {
        TargetVector targets;
        targets.push_back(target);
        sel->apply(targets, sel, true, true);
    }
    t->setCurrent(inst);
}

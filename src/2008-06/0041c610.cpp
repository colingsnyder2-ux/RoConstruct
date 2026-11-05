// from server: 100% by colin
// from server: 99% by colin
// roc 2008-06 0041c610  unit: DHTMLWindow::?$BoundFuncDesc  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041c610
//
// 0041c610  6aff                 push -1
// 0041c612  6888e17b00           push 0x7be188
// 0041c617  64a100000000         mov eax, dword ptr fs:[0]
// 0041c61d  50                   push eax
// 0041c61e  64892500000000       mov dword ptr fs:[0], esp
// 0041c625  83ec24               sub esp, 0x24
// 0041c628  56                   push esi
// 0041c629  57                   push edi
// 0041c62a  8bf9                 mov edi, ecx
// 0041c62c  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 0041c62f  8b4740               mov eax, dword ptr [edi + 0x40]
// 0041c632  89442418             mov dword ptr [esp + 0x18], eax
// 0041c636  85c9                 test ecx, ecx
// 0041c638  7409                 je 0x41c643
// 0041c63a  8b11                 mov edx, dword ptr [ecx]
// 0041c63c  8b4208               mov eax, dword ptr [edx + 8]
// 0041c63f  ffd0                 call eax
// 0041c641  eb02                 jmp 0x41c645
// 0041c643  33c0                 xor eax, eax
// 0041c645  8944241c             mov dword ptr [esp + 0x1c], eax
// 0041c649  8b742440             mov esi, dword ptr [esp + 0x40]
// 0041c64d  8b16                 mov edx, dword ptr [esi]
// 0041c64f  8b5204               mov edx, dword ptr [edx + 4]
// 0041c652  8d442418             lea eax, [esp + 0x18]
// 0041c656  50                   push eax
// 0041c657  6a01                 push 1
// 0041c659  8bce                 mov ecx, esi
// 0041c65b  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 0041c663  ffd2                 call edx
// 0041c665  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 0041c668  8b4748               mov eax, dword ptr [edi + 0x48]
// 0041c66b  89442410             mov dword ptr [esp + 0x10], eax
// 0041c66f  85c9                 test ecx, ecx
// 0041c671  7409                 je 0x41c67c
// 0041c673  8b11                 mov edx, dword ptr [ecx]
// 0041c675  8b4208               mov eax, dword ptr [edx + 8]
// 0041c678  ffd0                 call eax
// 0041c67a  eb02                 jmp 0x41c67e
// 0041c67c  33c0                 xor eax, eax
// 0041c67e  89442414             mov dword ptr [esp + 0x14], eax
// 0041c682  8b16                 mov edx, dword ptr [esi]
// 0041c684  8b5204               mov edx, dword ptr [edx + 4]
// 0041c687  8d442410             lea eax, [esp + 0x10]
// 0041c68b  50                   push eax
// 0041c68c  6a02                 push 2
// 0041c68e  8bce                 mov ecx, esi
// 0041c690  c644243c01           mov byte ptr [esp + 0x3c], 1
// 0041c695  ffd2                 call edx
// 0041c697  8b4f54               mov ecx, dword ptr [edi + 0x54]
// 0041c69a  8b4750               mov eax, dword ptr [edi + 0x50]
// 0041c69d  89442408             mov dword ptr [esp + 8], eax
// 0041c6a1  85c9                 test ecx, ecx
// 0041c6a3  7409                 je 0x41c6ae
// 0041c6a5  8b11                 mov edx, dword ptr [ecx]
// 0041c6a7  8b4208               mov eax, dword ptr [edx + 8]
// 0041c6aa  ffd0                 call eax
// 0041c6ac  eb02                 jmp 0x41c6b0
// 0041c6ae  33c0                 xor eax, eax
// 0041c6b0  8944240c             mov dword ptr [esp + 0xc], eax
// 0041c6b4  8b16                 mov edx, dword ptr [esi]
// 0041c6b6  8b5204               mov edx, dword ptr [edx + 4]
// 0041c6b9  8d442408             lea eax, [esp + 8]
// 0041c6bd  50                   push eax
// 0041c6be  6a03                 push 3
// 0041c6c0  8bce                 mov ecx, esi
// 0041c6c2  c644243c02           mov byte ptr [esp + 0x3c], 2
// 0041c6c7  ffd2                 call edx
// 0041c6c9  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0041c6cd  6a00                 push 0
// 0041c6cf  6810c29200           push 0x92c210
// 0041c6d4  68fc919200           push 0x9291fc
// 0041c6d9  6a00                 push 0
// 0041c6db  50                   push eax
// 0041c6dc  e8e5502800           call 0x6a17c6
// 0041c6e1  83c414               add esp, 0x14
// 0041c6e4  85c0                 test eax, eax
// 0041c6e6  751e                 jne 0x41c706
// 0041c6e8  6834ba8000           push 0x80ba34
// 0041c6ed  8d4c2424             lea ecx, [esp + 0x24]
// 0041c6f1  ff1564288000         call dword ptr [0x802864]
// 0041c6f7  682c368d00           push 0x8d362c
// 0041c6fc  8d4c2424             lea ecx, [esp + 0x24]
// 0041c700  51                   push ecx
// 0041c701  e8864e2800           call 0x6a158c
// 0041c706  8d542408             lea edx, [esp + 8]
// 0041c70a  52                   push edx
// 0041c70b  8d4c2414             lea ecx, [esp + 0x14]
// 0041c70f  51                   push ecx
// 0041c710  8d542420             lea edx, [esp + 0x20]
// 0041c714  52                   push edx
// 0041c715  83c604               add esi, 4
// 0041c718  56                   push esi
// 0041c719  50                   push eax
// 0041c71a  8bcf                 mov ecx, edi
// 0041c71c  e83ffeffff           call 0x41c560
// 0041c721  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041c725  c644243401           mov byte ptr [esp + 0x34], 1
// 0041c72a  85c9                 test ecx, ecx
// 0041c72c  7408                 je 0x41c736
// 0041c72e  8b01                 mov eax, dword ptr [ecx]
// 0041c730  8b10                 mov edx, dword ptr [eax]
// 0041c732  6a01                 push 1
// 0041c734  ffd2                 call edx
// 0041c736  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0041c73a  c644243400           mov byte ptr [esp + 0x34], 0
// 0041c73f  85c9                 test ecx, ecx
// 0041c741  7408                 je 0x41c74b
// 0041c743  8b01                 mov eax, dword ptr [ecx]
// 0041c745  8b10                 mov edx, dword ptr [eax]
// 0041c747  6a01                 push 1
// 0041c749  ffd2                 call edx
// 0041c74b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0041c74f  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 0041c757  85c9                 test ecx, ecx
// 0041c759  7408                 je 0x41c763
// 0041c75b  8b01                 mov eax, dword ptr [ecx]
// 0041c75d  8b10                 mov edx, dword ptr [eax]
// 0041c75f  6a01                 push 1
// 0041c761  ffd2                 call edx
// 0041c763  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0041c767  5f                   pop edi
// 0041c768  5e                   pop esi
// 0041c769  64890d00000000       mov dword ptr fs:[0], ecx
// 0041c770  83c430               add esp, 0x30
// 0041c773  c20800               ret 8

namespace std {
    class bad_cast {
        const char* message;
        int owned;
    public:
        __declspec(dllimport) explicit bad_cast(const char*);
        virtual ~bad_cast();
    };
}

struct Value {
    virtual ~Value();
    virtual void reserved();
    virtual Value* clone() const;
};

inline Value* copyValue(Value* source) {
    if (source)
        return source->clone();
    return 0;
}

struct Argument {
    unsigned long value;
    Value* object;

    Argument(const Argument&);
    ~Argument();
};

inline Argument::Argument(const Argument& other)
    : value(other.value), object(copyValue(other.object)) {}

inline Argument::~Argument() {
    if (object)
        delete object;
}

namespace RBX {
    namespace Reflection {
        class DescribedBase {
            virtual ~DescribedBase();
            virtual void reserved();
        };
    }
}

class DHTMLWindow : public RBX::Reflection::DescribedBase {
    virtual void reserved();
};

struct Arguments {
    virtual void reserved();
    virtual void set(int, Argument*);
};

struct S {
    char padding[64];
    Argument first;
    Argument second;
    Argument third;

    void invoke(RBX::Reflection::DescribedBase*, Arguments*);
    void dispatch(DHTMLWindow*, void*, Argument*, Argument*, Argument*);
};

void S::invoke(RBX::Reflection::DescribedBase* instance, Arguments* arguments) {
    Argument a(first);
    arguments->set(1, &a);

    Argument b(second);
    arguments->set(2, &b);

    Argument c(third);
    arguments->set(3, &c);

    DHTMLWindow* window = dynamic_cast<DHTMLWindow*>(instance);
    if (!window)
        throw std::bad_cast("bad cast");

    dispatch(window, reinterpret_cast<char*>(arguments) + 4, &a, &b, &c);
}

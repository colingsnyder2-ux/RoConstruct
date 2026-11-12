// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 00434e40  unit: CMemberTreeView  size: 277 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434e40
//
// 00434e40  6aff                 push -1
// 00434e42  6838e07300           push 0x73e038
// 00434e47  64a100000000         mov eax, dword ptr fs:[0]
// 00434e4d  50                   push eax
// 00434e4e  83ec08               sub esp, 8
// 00434e51  53                   push ebx
// 00434e52  55                   push ebp
// 00434e53  56                   push esi
// 00434e54  57                   push edi
// 00434e55  a188518b00           mov eax, dword ptr [0x8b5188]
// 00434e5a  33c4                 xor eax, esp
// 00434e5c  50                   push eax
// 00434e5d  8d44241c             lea eax, [esp + 0x1c]
// 00434e61  64a300000000         mov dword ptr fs:[0], eax
// 00434e67  8bf9                 mov edi, ecx
// 00434e69  80bfa800000000       cmp byte ptr [edi + 0xa8], 0
// 00434e70  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 00434e74  750f                 jne 0x434e85
// 00434e76  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00434e79  3b87ac000000         cmp eax, dword ptr [edi + 0xac]
// 00434e7f  0f85ba000000         jne 0x434f3f
// 00434e85  8d4c2414             lea ecx, [esp + 0x14]
// 00434e89  51                   push ecx
// 00434e8a  e8e1fc0000           call 0x444b70
// 00434e8f  83c404               add esp, 4
// 00434e92  8b00                 mov eax, dword ptr [eax]
// 00434e94  53                   push ebx
// 00434e95  8bc8                 mov ecx, eax
// 00434e97  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00434e9f  e89ce40000           call 0x443340
// 00434ea4  8be8                 mov ebp, eax
// 00434ea6  8b442418             mov eax, dword ptr [esp + 0x18]
// 00434eaa  85c0                 test eax, eax
// 00434eac  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00434eb4  742c                 je 0x434ee2
// 00434eb6  8bf0                 mov esi, eax
// 00434eb8  83c004               add eax, 4
// 00434ebb  83caff               or edx, 0xffffffff
// 00434ebe  f00fc110             lock xadd dword ptr [eax], edx
// 00434ec2  751e                 jne 0x434ee2
// 00434ec4  8b06                 mov eax, dword ptr [esi]
// 00434ec6  8b5004               mov edx, dword ptr [eax + 4]
// 00434ec9  8bce                 mov ecx, esi
// 00434ecb  ffd2                 call edx
// 00434ecd  8d4608               lea eax, [esi + 8]
// 00434ed0  83c9ff               or ecx, 0xffffffff
// 00434ed3  f00fc108             lock xadd dword ptr [eax], ecx
// 00434ed7  7509                 jne 0x434ee2
// 00434ed9  8b16                 mov edx, dword ptr [esi]
// 00434edb  8b4208               mov eax, dword ptr [edx + 8]
// 00434ede  8bce                 mov ecx, esi
// 00434ee0  ffd0                 call eax
// 00434ee2  85ed                 test ebp, ebp
// 00434ee4  7409                 je 0x434eef
// 00434ee6  80bde800000000       cmp byte ptr [ebp + 0xe8], 0
// 00434eed  7450                 je 0x434f3f
// 00434eef  f6431001             test byte ptr [ebx + 0x10], 1
// 00434ef3  744a                 je 0x434f3f
// 00434ef5  8b4304               mov eax, dword ptr [ebx + 4]
// 00434ef8  8d4804               lea ecx, [eax + 4]
// 00434efb  ff15a8e67700         call dword ptr [0x77e6a8]
// 00434f01  680200ffff           push 0xffff0002
// 00434f06  680000ffff           push 0xffff0000
// 00434f0b  6a00                 push 0
// 00434f0d  6a00                 push 0
// 00434f0f  6a00                 push 0
// 00434f11  6a06                 push 6
// 00434f13  6a06                 push 6
// 00434f15  50                   push eax
// 00434f16  6a23                 push 0x23
// 00434f18  8bcf                 mov ecx, edi
// 00434f1a  e815b71f00           call 0x630634
// 00434f1f  53                   push ebx
// 00434f20  6a00                 push 0
// 00434f22  6a00                 push 0
// 00434f24  6a00                 push 0
// 00434f26  6a00                 push 0
// 00434f28  6a00                 push 0
// 00434f2a  8bf0                 mov esi, eax
// 00434f2c  6a04                 push 4
// 00434f2e  56                   push esi
// 00434f2f  8bcf                 mov ecx, edi
// 00434f31  e804b71f00           call 0x63063a
// 00434f36  55                   push ebp
// 00434f37  56                   push esi
// 00434f38  8bcf                 mov ecx, edi
// 00434f3a  e831fdffff           call 0x434c70
// 00434f3f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00434f43  64890d00000000       mov dword ptr fs:[0], ecx
// 00434f4a  59                   pop ecx
// 00434f4b  5f                   pop edi
// 00434f4c  5e                   pop esi
// 00434f4d  5d                   pop ebp
// 00434f4e  5b                   pop ebx
// 00434f4f  83c414               add esp, 0x14
// 00434f52  c20400               ret 4

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

// boost 1.34 sp_counted_base: dispose at vtable+4, destroy at vtable+8, use_count +4, weak_count +8
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

template<class T> struct shared_ptr {
    T* px;
    sp_counted_base* pn;
    ~shared_ptr() { if (pn != 0) pn->release(); }
    T* operator->() const { return px; }
};

struct Node {
    char pad[0xe8];
    bool shown;                                 // +0xe8
};

struct String {
    __declspec(dllimport) const char* c_str() const;   // [0x77e6a8]
};

struct Named {
    int pad0;
    String name;                                // +4
};

struct Member {
    int pad0;
    Named* desc;                                // +4
    int pad8;
    int owner;                                  // +0xc
    unsigned char flags;                        // +0x10
};

struct Registry {
    Node* find(Member*);                        // 0x443340
};

shared_ptr<Registry> __cdecl getRegistry();     // 0x444b70

typedef struct _TREEITEM* HTREEITEM;
#define TVI_ROOT ((HTREEITEM)(unsigned long)-0x10000)
#define TVI_LAST ((HTREEITEM)(unsigned long)-0xfffe)

struct CMemberTreeView {
    char pad[0xa8];
    bool showAll;                               // +0xa8
    char pad2[3];
    int owner;                                  // +0xac

    HTREEITEM InsertItem(unsigned, const char*, int, int, unsigned, unsigned, long, HTREEITEM, HTREEITEM); // 0x630634
    int SetItem(HTREEITEM, unsigned, const char*, int, int, unsigned, unsigned, long);                     // 0x63063a
    void addChildren(HTREEITEM, Node*);         // 0x434c70
    void addMember(Member*);
};

void CMemberTreeView::addMember(Member* member)
{
    if (!showAll && member->owner != owner)
        return;
    Node* node = getRegistry()->find(member);
    if (node != 0 && !node->shown)
        return;
    if (!(member->flags & 1))
        return;
    Named* desc = member->desc;
    const char* text = desc->name.c_str();
    HTREEITEM item = InsertItem(0x23, text, 6, 6, 0, 0, 0, TVI_ROOT, TVI_LAST);
    SetItem(item, 4, 0, 0, 0, 0, 0, (long)member);
    addChildren(item, node);
}

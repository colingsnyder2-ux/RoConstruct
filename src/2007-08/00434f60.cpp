// from server: 100% by EspClaude
// from server: 40% by colin
// roc 2007-08 00434f60  unit: CMemberTreeView  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434f60
//
// 00434f60  6aff                 push -1
// 00434f62  6838e07300           push 0x73e038
// 00434f67  64a100000000         mov eax, dword ptr fs:[0]
// 00434f6d  50                   push eax
// 00434f6e  83ec08               sub esp, 8
// 00434f71  53                   push ebx
// 00434f72  55                   push ebp
// 00434f73  56                   push esi
// 00434f74  57                   push edi
// 00434f75  a188518b00           mov eax, dword ptr [0x8b5188]
// 00434f7a  33c4                 xor eax, esp
// 00434f7c  50                   push eax
// 00434f7d  8d44241c             lea eax, [esp + 0x1c]
// 00434f81  64a300000000         mov dword ptr fs:[0], eax
// 00434f87  8bf9                 mov edi, ecx
// 00434f89  80bfa800000000       cmp byte ptr [edi + 0xa8], 0
// 00434f90  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 00434f94  750f                 jne 0x434fa5
// 00434f96  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00434f99  3b87ac000000         cmp eax, dword ptr [edi + 0xac]
// 00434f9f  0f85b4000000         jne 0x435059
// 00434fa5  8d4c2414             lea ecx, [esp + 0x14]
// 00434fa9  51                   push ecx
// 00434faa  e8c1fb0000           call 0x444b70
// 00434faf  83c404               add esp, 4
// 00434fb2  8b00                 mov eax, dword ptr [eax]
// 00434fb4  53                   push ebx
// 00434fb5  8bc8                 mov ecx, eax
// 00434fb7  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00434fbf  e81ce40000           call 0x4433e0
// 00434fc4  8be8                 mov ebp, eax
// 00434fc6  8b442418             mov eax, dword ptr [esp + 0x18]
// 00434fca  85c0                 test eax, eax
// 00434fcc  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00434fd4  742c                 je 0x435002
// 00434fd6  8bf0                 mov esi, eax
// 00434fd8  83c004               add eax, 4
// 00434fdb  83caff               or edx, 0xffffffff
// 00434fde  f00fc110             lock xadd dword ptr [eax], edx
// 00434fe2  751e                 jne 0x435002
// 00434fe4  8b06                 mov eax, dword ptr [esi]
// 00434fe6  8b5004               mov edx, dword ptr [eax + 4]
// 00434fe9  8bce                 mov ecx, esi
// 00434feb  ffd2                 call edx
// 00434fed  8d4608               lea eax, [esi + 8]
// 00434ff0  83c9ff               or ecx, 0xffffffff
// 00434ff3  f00fc108             lock xadd dword ptr [eax], ecx
// 00434ff7  7509                 jne 0x435002
// 00434ff9  8b16                 mov edx, dword ptr [esi]
// 00434ffb  8b4208               mov eax, dword ptr [edx + 8]
// 00434ffe  8bce                 mov ecx, esi
// 00435000  ffd0                 call eax
// 00435002  85ed                 test ebp, ebp
// 00435004  7409                 je 0x43500f
// 00435006  80bde800000000       cmp byte ptr [ebp + 0xe8], 0
// 0043500d  744a                 je 0x435059
// 0043500f  8b4304               mov eax, dword ptr [ebx + 4]
// 00435012  8d4804               lea ecx, [eax + 4]
// 00435015  ff15a8e67700         call dword ptr [0x77e6a8]
// 0043501b  680200ffff           push 0xffff0002
// 00435020  680000ffff           push 0xffff0000
// 00435025  6a00                 push 0
// 00435027  6a00                 push 0
// 00435029  6a00                 push 0
// 0043502b  6a08                 push 8
// 0043502d  6a08                 push 8
// 0043502f  50                   push eax
// 00435030  6a23                 push 0x23
// 00435032  8bcf                 mov ecx, edi
// 00435034  e8fbb51f00           call 0x630634
// 00435039  53                   push ebx
// 0043503a  6a00                 push 0
// 0043503c  6a00                 push 0
// 0043503e  6a00                 push 0
// 00435040  6a00                 push 0
// 00435042  6a00                 push 0
// 00435044  8bf0                 mov esi, eax
// 00435046  6a04                 push 4
// 00435048  56                   push esi
// 00435049  8bcf                 mov ecx, edi
// 0043504b  e8eab51f00           call 0x63063a
// 00435050  55                   push ebp
// 00435051  56                   push esi
// 00435052  8bcf                 mov ecx, edi
// 00435054  e817fcffff           call 0x434c70
// 00435059  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0043505d  64890d00000000       mov dword ptr fs:[0], ecx
// 00435064  59                   pop ecx
// 00435065  5f                   pop edi
// 00435066  5e                   pop esi
// 00435067  5d                   pop ebp
// 00435068  5b                   pop ebx
// 00435069  83c414               add esp, 0x14
// 0043506c  c20400               ret 4
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
};

struct Registry {
    Node* find(Member*);                        // 0x4433e0
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
    Named* desc = member->desc;
    const char* text = desc->name.c_str();
    HTREEITEM item = InsertItem(0x23, text, 8, 8, 0, 0, 0, TVI_ROOT, TVI_LAST);
    SetItem(item, 4, 0, 0, 0, 0, 0, (long)member);
    addChildren(item, node);
}

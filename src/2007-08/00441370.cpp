// from server: 96% by EspClaude
// from server: 42% by colin
// roc 2007-08 00441370  unit: RBX::VSoundId::?$ContentItem  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00441370
//
// 00441370  6aff                 push -1
// 00441372  6839f07300           push 0x73f039
// 00441377  64a100000000         mov eax, dword ptr fs:[0]
// 0044137d  50                   push eax
// 0044137e  83ec40               sub esp, 0x40
// 00441381  56                   push esi
// 00441382  a188518b00           mov eax, dword ptr [0x8b5188]
// 00441387  33c4                 xor eax, esp
// 00441389  50                   push eax
// 0044138a  8d442448             lea eax, [esp + 0x48]
// 0044138e  64a300000000         mov dword ptr fs:[0], eax
// 00441394  8bf1                 mov esi, ecx
// 00441396  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 0044139c  8b4034               mov eax, dword ptr [eax + 0x34]
// 0044139f  83e800               sub eax, 0
// 004413a2  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004413aa  7466                 je 0x441412
// 004413ac  83e801               sub eax, 1
// 004413af  7436                 je 0x4413e7
// 004413b1  8d4c2458             lea ecx, [esp + 0x58]
// 004413b5  ff1598dd7700         call dword ptr [0x77dd98]
// 004413bb  50                   push eax
// 004413bc  8d4c240c             lea ecx, [esp + 0xc]
// 004413c0  e8cb72ffff           call 0x438690
// 004413c5  8d442408             lea eax, [esp + 8]
// 004413c9  50                   push eax
// 004413ca  8bce                 mov ecx, esi
// 004413cc  c644245401           mov byte ptr [esp + 0x54], 1
// 004413d1  e86af0ffff           call 0x440440
// 004413d6  8d4c2408             lea ecx, [esp + 8]
// 004413da  c644245000           mov byte ptr [esp + 0x50], 0
// 004413df  ff15ace67700         call dword ptr [0x77e6ac]
// 004413e5  eb37                 jmp 0x44141e
// 004413e7  8d4c2428             lea ecx, [esp + 0x28]
// 004413eb  e890c3ffff           call 0x43d780
// 004413f0  8d4c2428             lea ecx, [esp + 0x28]
// 004413f4  51                   push ecx
// 004413f5  8bce                 mov ecx, esi
// 004413f7  c644245402           mov byte ptr [esp + 0x54], 2
// 004413fc  e83ff0ffff           call 0x440440
// 00441401  8d4c2428             lea ecx, [esp + 0x28]
// 00441405  c644245000           mov byte ptr [esp + 0x50], 0
// 0044140a  ff15ace67700         call dword ptr [0x77e6ac]
// 00441410  eb0c                 jmp 0x44141e
// 00441412  8b16                 mov edx, dword ptr [esi]
// 00441414  8b82f8000000         mov eax, dword ptr [edx + 0xf8]
// 0044141a  8bce                 mov ecx, esi
// 0044141c  ffd0                 call eax
// 0044141e  8d4c2458             lea ecx, [esp + 0x58]
// 00441422  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00441428  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0044142c  64890d00000000       mov dword ptr fs:[0], ecx
// 00441433  59                   pop ecx
// 00441434  5e                   pop esi
// 00441435  83c44c               add esp, 0x4c
// 00441438  c20400               ret 4

struct Name {
    void* p;
    __declspec(dllimport) const char* c_str() const;
    __declspec(dllimport) ~Name() throw();
};

struct StdString {
    char storage[28];
    __declspec(dllimport) ~StdString();
};

struct ContentId {
    StdString s;
    ContentId();
    ContentId(const char* id);
};

struct TypedId : ContentId {
    int extra;
    TypedId() {}
    TypedId(const char* id) : ContentId(id) {}
};

struct Desc { char pad[0x34]; int kind; };

struct V0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61();
    virtual void clearContent();
};

struct SoundItem : V0 {
    char pad[0xbc - 4];
    Desc* desc;
    void setContent(const ContentId& id);
    void apply(Name name);
};

void SoundItem::apply(Name name)
{
    switch (desc->kind) {
    default:
        setContent(TypedId(name.c_str()));
        break;
    case 1:
        setContent(TypedId());
        break;
    case 0:
        clearContent();
        break;
    }
}

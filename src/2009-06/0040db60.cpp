// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0040ed50  unit: CBrowserView  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040ed50
//
// 0040ed50  56                   push esi
// 0040ed51  57                   push edi
// 0040ed52  8bf1                 mov esi, ecx
// 0040ed54  e8771d2900           call 0x6a0ad0
// 0040ed59  8b4654               mov eax, dword ptr [esi + 0x54]
// 0040ed5c  85c0                 test eax, eax
// 0040ed5e  7403                 je 0x40ed63
// 0040ed60  897054               mov dword ptr [eax + 0x54], esi
// 0040ed63  8dbecc020000         lea edi, [esi + 0x2cc]
// 0040ed69  6816b78000           push 0x80b716
// 0040ed6e  8bcf                 mov ecx, edi
// 0040ed70  ff15f02f8000         call dword ptr [0x802ff0]
// 0040ed76  85c0                 test eax, eax
// 0040ed78  741a                 je 0x40ed94
// 0040ed7a  6a00                 push 0
// 0040ed7c  6a00                 push 0
// 0040ed7e  6a00                 push 0
// 0040ed80  6a00                 push 0
// 0040ed82  6a00                 push 0
// 0040ed84  8bcf                 mov ecx, edi
// 0040ed86  ff15e03e8000         call dword ptr [0x803ee0]
// 0040ed8c  50                   push eax
// 0040ed8d  8bce                 mov ecx, esi
// 0040ed8f  e8e61b2900           call 0x6a097a
// 0040ed94  5f                   pop edi
// 0040ed95  5e                   pop esi
// 0040ed96  c3                   ret 

struct Control {
    char data;
};

extern int (__thiscall *lookup)(Control*, const char*);
extern int (__thiscall *query)(Control*, int, int, int, int, int);

static const char key[11] = {
    0, 0, (char)0xf1, 0x68, (char)0xe3, (char)0x88,
    (char)0xb5, (char)0xf8, (char)0xe4, 0x3e, 0x41
};

struct CBrowserView {
    char padding0[0x54];
    CBrowserView* link;
    char padding1[0x2b0 - 0x58];
    Control control;

    void initialize();
    void apply(int value);
    void invoke();
};

void CBrowserView::invoke() {
    initialize();

    if (link)
        link->link = this;

    if (lookup(&control, key))
        apply(query(&control, 0, 0, 0, 0, 0));
}

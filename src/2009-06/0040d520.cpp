// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0040e790  unit: CBrowserView  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e790
//
// 0040e790  56                   push esi
// 0040e791  8bf1                 mov esi, ecx
// 0040e793  57                   push edi
// 0040e794  8dbecc020000         lea edi, [esi + 0x2cc]
// 0040e79a  6816b78000           push 0x80b716
// 0040e79f  8bcf                 mov ecx, edi
// 0040e7a1  ff15f02f8000         call dword ptr [0x802ff0]
// 0040e7a7  85c0                 test eax, eax
// 0040e7a9  741a                 je 0x40e7c5
// 0040e7ab  6a00                 push 0
// 0040e7ad  6a00                 push 0
// 0040e7af  6a00                 push 0
// 0040e7b1  6a00                 push 0
// 0040e7b3  6a00                 push 0
// 0040e7b5  8bcf                 mov ecx, edi
// 0040e7b7  ff15e03e8000         call dword ptr [0x803ee0]
// 0040e7bd  50                   push eax
// 0040e7be  8bce                 mov ecx, esi
// 0040e7c0  e8b5212900           call 0x6a097a
// 0040e7c5  5f                   pop edi
// 0040e7c6  5e                   pop esi
// 0040e7c7  c3                   ret 

struct P {};

extern int (__thiscall *check)(P*, const char*);
extern void* (__thiscall *obtain)(P*, int, int, int, int, int);

static const char authoring[11] = {
    0, 0, '\xf1', 'h', '\xe3', '\x88',
    '\xb5', '\xf8', '\xe4', '>', 'A'
};

struct CBrowserView {
    char padding[0x2cc];
    P p;

    void update();
    void apply(void*);
};

void CBrowserView::update()
{
    P* object = &p;
    if (check(object, authoring))
        apply(obtain(object, 0, 0, 0, 0, 0));
}

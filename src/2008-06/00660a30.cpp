// from server: 100% by colin
// from server: 94% by king_originala
// roc 2008-06 00660a30  unit: RBX::FilterStairs  size: 311 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00660a30
//
// 00660a30  83ec08               sub esp, 8
// 00660a33  53                   push ebx
// 00660a34  55                   push ebp
// 00660a35  56                   push esi
// 00660a36  8b37                 mov esi, dword ptr [edi]
// 00660a38  0fb64e48             movzx ecx, byte ptr [esi + 0x48]
// 00660a3c  8b6e24               mov ebp, dword ptr [esi + 0x24]
// 00660a3f  8d5e24               lea ebx, [esi + 0x24]
// 00660a42  33c0                 xor eax, eax
// 00660a44  896c2410             mov dword ptr [esp + 0x10], ebp
// 00660a48  85c9                 test ecx, ecx
// 00660a4a  7e3e                 jle 0x660a8a
// 00660a4c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00660a50  8b11                 mov edx, dword ptr [ecx]
// 00660a52  8954240c             mov dword ptr [esp + 0xc], edx
// 00660a56  8d4f34               lea ecx, [edi + 0x34]
// 00660a59  8da42400000000       lea esp, [esp]
// 00660a60  0fb651ff             movzx edx, byte ptr [ecx - 1]
// 00660a64  3b54240c             cmp edx, dword ptr [esp + 0xc]
// 00660a68  7510                 jne 0x660a7a
// 00660a6a  0fb611               movzx edx, byte ptr [ecx]
// 00660a6d  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00660a71  3b5508               cmp edx, dword ptr [ebp + 8]
// 00660a74  0f84e6000000         je 0x660b60
// 00660a7a  0fb65648             movzx edx, byte ptr [esi + 0x48]
// 00660a7e  40                   inc eax
// 00660a7f  83c102               add ecx, 2
// 00660a82  3bc2                 cmp eax, edx
// 00660a84  7cda                 jl 0x660a60
// 00660a86  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00660a8a  0fb64648             movzx eax, byte ptr [esi + 0x48]
// 00660a8e  40                   inc eax
// 00660a8f  83f83c               cmp eax, 0x3c
// 00660a92  7e42                 jle 0x660ad6
// 00660a94  8b463c               mov eax, dword ptr [esi + 0x3c]
// 00660a97  6874c58400           push 0x84c574
// 00660a9c  6a3c                 push 0x3c
// 00660a9e  85c0                 test eax, eax
// 00660aa0  7513                 jne 0x660ab5
// 00660aa2  8b4710               mov eax, dword ptr [edi + 0x10]
// 00660aa5  68f8c48400           push 0x84c4f8
// 00660aaa  50                   push eax
// 00660aab  e81020fcff           call 0x622ac0
// 00660ab0  83c410               add esp, 0x10
// 00660ab3  eb12                 jmp 0x660ac7
// 00660ab5  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00660ab8  50                   push eax
// 00660ab9  68d0c48400           push 0x84c4d0
// 00660abe  51                   push ecx
// 00660abf  e8fc1ffcff           call 0x622ac0
// 00660ac4  83c414               add esp, 0x14
// 00660ac7  8b570c               mov edx, dword ptr [edi + 0xc]
// 00660aca  6a00                 push 0
// 00660acc  50                   push eax
// 00660acd  52                   push edx
// 00660ace  e89d360000           call 0x664170
// 00660ad3  83c40c               add esp, 0xc
// 00660ad6  0fb64648             movzx eax, byte ptr [esi + 0x48]
// 00660ada  40                   inc eax
// 00660adb  3b03                 cmp eax, dword ptr [ebx]
// 00660add  7e20                 jle 0x660aff
// 00660adf  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00660ae2  8b5710               mov edx, dword ptr [edi + 0x10]
// 00660ae5  6816b78000           push 0x80b716
// 00660aea  68fdffff7f           push 0x7ffffffd
// 00660aef  6a04                 push 4
// 00660af1  53                   push ebx
// 00660af2  51                   push ecx
// 00660af3  52                   push edx
// 00660af4  e847fcffff           call 0x660740
// 00660af9  83c418               add esp, 0x18
// 00660afc  89461c               mov dword ptr [esi + 0x1c], eax
// 00660aff  3b2b                 cmp ebp, dword ptr [ebx]
// 00660b01  7d0f                 jge 0x660b12
// 00660b03  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00660b06  c704a800000000       mov dword ptr [eax + ebp*4], 0
// 00660b0d  45                   inc ebp
// 00660b0e  3b2b                 cmp ebp, dword ptr [ebx]
// 00660b10  7cf1                 jl 0x660b03
// 00660b12  0fb64e48             movzx ecx, byte ptr [esi + 0x48]
// 00660b16  8b442418             mov eax, dword ptr [esp + 0x18]
// 00660b1a  8b561c               mov edx, dword ptr [esi + 0x1c]
// 00660b1d  89048a               mov dword ptr [edx + ecx*4], eax
// 00660b20  f6400503             test byte ptr [eax + 5], 3
// 00660b24  7414                 je 0x660b3a
// 00660b26  f6460504             test byte ptr [esi + 5], 4
// 00660b2a  740e                 je 0x660b3a
// 00660b2c  50                   push eax
// 00660b2d  8b4710               mov eax, dword ptr [edi + 0x10]
// 00660b30  56                   push esi
// 00660b31  50                   push eax
// 00660b32  e849b9ffff           call 0x65c480
// 00660b37  83c40c               add esp, 0xc
// 00660b3a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00660b3e  0fb610               movzx edx, byte ptr [eax]
// 00660b41  0fb64e48             movzx ecx, byte ptr [esi + 0x48]
// 00660b45  88544f33             mov byte ptr [edi + ecx*2 + 0x33], dl
// 00660b49  0fb64e48             movzx ecx, byte ptr [esi + 0x48]
// 00660b4d  0fb65008             movzx edx, byte ptr [eax + 8]
// 00660b51  88544f34             mov byte ptr [edi + ecx*2 + 0x34], dl
// 00660b55  8a4e48               mov cl, byte ptr [esi + 0x48]
// 00660b58  0fb6c1               movzx eax, cl
// 00660b5b  fec1                 inc cl
// 00660b5d  884e48               mov byte ptr [esi + 0x48], cl
// 00660b60  5e                   pop esi
// 00660b61  5d                   pop ebp
// 00660b62  5b                   pop ebx
// 00660b63  83c408               add esp, 8
// 00660b66  c3                   ret 

struct String {
    unsigned char padding[5];
    unsigned char marked;
};

struct Proto {
    unsigned char padding0[5];
    unsigned char marked;
    unsigned char padding1[22];
    String **upvalues;
    unsigned char padding2[4];
    int sizeupvalues;
    unsigned char padding3[20];
    int linedefined;
    unsigned char padding4[8];
    unsigned char nups;
};

struct Exp {
    int kind;
    int padding;
    int info;
};

struct Upvalue {
    unsigned char kind;
    unsigned char info;
};

struct FuncState {
    Proto *proto;
    unsigned char padding0[8];
    void *lexer;
    void *state;
    unsigned char padding1[31];
    Upvalue upvalues[60];
};

extern const char *__cdecl format(void *, const char *, ...);
extern void __cdecl report(void *, const char *, int);
extern void *__cdecl grow(void *, void *, int *, int, int, const char *);
extern void __cdecl barrier(void *, Proto *, String *);

static __declspec(noinline) int __cdecl indexupvalue(FuncState *fs, String *name, Exp *value)
{
    Proto *f = fs->proto;
    int oldsize = f->sizeupvalues;
    int i;

    for (i = 0; i < f->nups; ++i) {
        if (fs->upvalues[i].kind == value->kind &&
            fs->upvalues[i].info == value->info)
            return i;
    }

    if (f->nups + 1 > 60) {
        const char *message;
        if (f->linedefined == 0)
            message = format(fs->state,
                             "main function has more than %d %s",
                             60, "upvalues");
        else
            message = format(fs->state,
                             "function at line %d has more than %d %s",
                             f->linedefined, 60,
                             "upvalues");
        report(fs->lexer, message, 0);
    }

    if (f->nups + 1 > f->sizeupvalues)
        f->upvalues = (String **)grow(fs->state, f->upvalues,
                                     &f->sizeupvalues, 4, 0x7ffffffd,
                                     "");

    for (; oldsize < f->sizeupvalues; ++oldsize)
        f->upvalues[oldsize] = 0;

    f->upvalues[f->nups] = name;
    if ((name->marked & 3) && (f->marked & 4))
        barrier(fs->state, f, name);

    fs->upvalues[f->nups].kind = (unsigned char)value->kind;
    fs->upvalues[f->nups].info = (unsigned char)value->info;
    return f->nups++;
}

int __cdecl caller(FuncState *fs, String *name, Exp *value)
{
    return indexupvalue(fs, name, value) + 1;
}

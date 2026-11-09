// from server: 100% by colin
// from server: 93% by king_originala
// roc 2008-06 00581510  unit: RBX::FollowCameraCommand  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00581510
//
// 00581510  56                   push esi
// 00581511  8bf1                 mov esi, ecx
// 00581513  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00581516  57                   push edi
// 00581517  85c9                 test ecx, ecx
// 00581519  7407                 je 0x581522
// 0058151b  e8b0f0ffff           call 0x5805d0
// 00581520  eb02                 jmp 0x581524
// 00581522  33c0                 xor eax, eax
// 00581524  8bc8                 mov ecx, eax
// 00581526  e815d5ffff           call 0x57ea40
// 0058152b  8bf8                 mov edi, eax
// 0058152d  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581530  8d8888020000         lea ecx, [eax + 0x288]
// 00581536  8b01                 mov eax, dword ptr [ecx]
// 00581538  8b5004               mov edx, dword ptr [eax + 4]
// 0058153b  6a04                 push 4
// 0058153d  ffd2                 call edx
// 0058153f  8bc8                 mov ecx, eax
// 00581541  e88ac80400           call 0x5cddd0
// 00581546  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581549  8d8888020000         lea ecx, [eax + 0x288]
// 0058154f  8b01                 mov eax, dword ptr [ecx]
// 00581551  8b5004               mov edx, dword ptr [eax + 4]
// 00581554  57                   push edi
// 00581555  ffd2                 call edx
// 00581557  8bc8                 mov ecx, eax
// 00581559  e8b2c80400           call 0x5cde10
// 0058155e  8b4604               mov eax, dword ptr [esi + 4]
// 00581561  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00581564  83c004               add eax, 4
// 00581567  83781810             cmp dword ptr [eax + 0x18], 0x10
// 0058156b  5f                   pop edi
// 0058156c  5e                   pop esi
// 0058156d  7205                 jb 0x581574
// 0058156f  8b4004               mov eax, dword ptr [eax + 4]
// 00581572  eb03                 jmp 0x581577
// 00581574  83c004               add eax, 4
// 00581577  51                   push ecx
// 00581578  50                   push eax
// 00581579  e842b00000           call 0x58c5c0
// 0058157e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00581582  8b01                 mov eax, dword ptr [ecx]
// 00581584  8b10                 mov edx, dword ptr [eax]
// 00581586  83c408               add esp, 8
// 00581589  c744240401000000     mov dword ptr [esp + 4], 1
// 00581591  ffe2                 jmp edx

struct Result {
    void first();
    void second();
};

struct Interface {
    virtual void unused();
    virtual Result* get(int);
};

struct Container {
    char padding[0x288];
    Interface interfaceObject;
};

struct Intermediate {
    int get();
};

struct Source {
    Intermediate* get();
};

struct String {
    unsigned unused;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned length;
    unsigned capacity;
};

struct Owner {
    unsigned unused;
    String text;
};

struct Callback {
    virtual void invoke(int);
};

void __cdecl notify(const char*, Container*);

struct S {
    unsigned unused0;
    Owner* owner;
    unsigned unused8;
    Container* container;
    char padding[16];
    Source* source;

    void f(Callback*);
};

void S::f(Callback* callback)
{
    int value = (source ? source->get() : 0)->get();

    container->interfaceObject.get(4)->first();
    container->interfaceObject.get(value)->second();

    Container* destination = container;
    String* text = &owner->text;
    const char* characters = text->capacity >= 16
        ? text->storage.pointer
        : text->storage.buffer;

    notify(characters, destination);
    callback->invoke(1);
}

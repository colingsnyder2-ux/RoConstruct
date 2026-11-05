// from server: 100% by colin
// from server: 93% by king_originala
// roc 2008-06 00581360  unit: RBX::AttachCameraCommand  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00581360
//
// 00581360  56                   push esi
// 00581361  8bf1                 mov esi, ecx
// 00581363  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00581366  57                   push edi
// 00581367  85c9                 test ecx, ecx
// 00581369  7407                 je 0x581372
// 0058136b  e860f2ffff           call 0x5805d0
// 00581370  eb02                 jmp 0x581374
// 00581372  33c0                 xor eax, eax
// 00581374  8bc8                 mov ecx, eax
// 00581376  e8c5d6ffff           call 0x57ea40
// 0058137b  8bf8                 mov edi, eax
// 0058137d  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581380  8d8888020000         lea ecx, [eax + 0x288]
// 00581386  8b01                 mov eax, dword ptr [ecx]
// 00581388  8b5004               mov edx, dword ptr [eax + 4]
// 0058138b  6a01                 push 1
// 0058138d  ffd2                 call edx
// 0058138f  8bc8                 mov ecx, eax
// 00581391  e83aca0400           call 0x5cddd0
// 00581396  8b460c               mov eax, dword ptr [esi + 0xc]
// 00581399  8d8888020000         lea ecx, [eax + 0x288]
// 0058139f  8b01                 mov eax, dword ptr [ecx]
// 005813a1  8b5004               mov edx, dword ptr [eax + 4]
// 005813a4  57                   push edi
// 005813a5  ffd2                 call edx
// 005813a7  8bc8                 mov ecx, eax
// 005813a9  e862ca0400           call 0x5cde10
// 005813ae  8b4604               mov eax, dword ptr [esi + 4]
// 005813b1  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005813b4  83c004               add eax, 4
// 005813b7  83781810             cmp dword ptr [eax + 0x18], 0x10
// 005813bb  5f                   pop edi
// 005813bc  5e                   pop esi
// 005813bd  7205                 jb 0x5813c4
// 005813bf  8b4004               mov eax, dword ptr [eax + 4]
// 005813c2  eb03                 jmp 0x5813c7
// 005813c4  83c004               add eax, 4
// 005813c7  51                   push ecx
// 005813c8  50                   push eax
// 005813c9  e8f2b10000           call 0x58c5c0
// 005813ce  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005813d2  8b01                 mov eax, dword ptr [ecx]
// 005813d4  8b10                 mov edx, dword ptr [eax]
// 005813d6  83c408               add esp, 8
// 005813d9  c744240401000000     mov dword ptr [esp + 4], 1
// 005813e1  ffe2                 jmp edx

struct Subject;

struct Intermediate {
    Subject* resolve();
};

struct Source {
    Intermediate* get();
};

struct Camera {
    void setType(int);
    void setSubject(Subject*);
};

struct CameraProvider {
    virtual void unused();
    virtual Camera* getCamera();
};

struct Model {
    char padding[0x288];
    CameraProvider cameras;
};

struct String {
    unsigned int unused;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int size;
    unsigned int capacity;
};

struct Descriptor {
    unsigned int unused;
    String name;
};

struct Disposable {
    virtual void release(int);
};

extern "C" void __cdecl notify(const char*, Model*);

struct Command {
    unsigned int unused0;
    Descriptor* descriptor;
    unsigned int unused8;
    Model* model;
    char padding[16];
    Source* source;

    void execute(Disposable*);
};

void Command::execute(Disposable* disposable)
{
    Subject* subject = (source ? source->get() : 0)->resolve();

    model->cameras.getCamera()->setType(1);
    model->cameras.getCamera()->setSubject(subject);

    Model* target = model;
    String* name = &descriptor->name;
    const char* text = name->capacity >= 16
        ? name->storage.pointer
        : name->storage.buffer;

    notify(text, target);
    disposable->release(1);
}

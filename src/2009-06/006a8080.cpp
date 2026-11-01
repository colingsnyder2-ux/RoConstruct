// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005fad80  unit: UString_sink::?$stream_buffer  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fad80
//
// 005fad80  53                   push ebx
// 005fad81  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005fad85  56                   push esi
// 005fad86  8b7110               mov esi, dword ptr [ecx + 0x10]
// 005fad89  57                   push edi
// 005fad8a  8bcb                 mov ecx, ebx
// 005fad8c  83c630               add esi, 0x30
// 005fad8f  e87cf8ffff           call 0x5fa610
// 005fad94  8b38                 mov edi, dword ptr [eax]
// 005fad96  8b06                 mov eax, dword ptr [esi]
// 005fad98  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fad9b  8b4c88fc             mov ecx, dword ptr [eax + ecx*4 - 4]
// 005fad9f  890cb8               mov dword ptr [eax + edi*4], ecx
// 005fada2  e869f8ffff           call 0x5fa610
// 005fada7  8938                 mov dword ptr [eax], edi
// 005fada9  8b5604               mov edx, dword ptr [esi + 4]
// 005fadac  6a00                 push 0
// 005fadae  4a                   dec edx
// 005fadaf  52                   push edx
// 005fadb0  8bce                 mov ecx, esi
// 005fadb2  e8b9f8ffff           call 0x5fa670
// 005fadb7  8bcb                 mov ecx, ebx
// 005fadb9  e852f8ffff           call 0x5fa610
// 005fadbe  5f                   pop edi
// 005fadbf  5e                   pop esi
// 005fadc0  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 005fadc6  5b                   pop ebx
// 005fadc7  c20400               ret 4

struct Item {
    char pad[4];
    int index;
    int* f();
};

struct Buffer {
    Item** data;
    int count;
    void resize(int, int);
};

struct Storage {
    char pad[48];
    Buffer buffer;
};

struct Sink {
    char pad[16];
    Storage* storage;
    void f(Item*);
};

void Sink::f(Item* item)
{
    Buffer* buffer = &storage->buffer;
    int index = *item->f();
    Item* last = buffer->data[buffer->count - 1];
    buffer->data[index] = last;
    *last->f() = index;
    buffer->resize(buffer->count - 1, 0);
    *item->f() = -1;
}

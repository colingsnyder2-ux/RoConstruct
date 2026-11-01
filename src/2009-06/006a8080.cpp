// from server: 100% by EspClaude
// from server: 98% by EspClaude
// roc 2009-06 006a8080  unit: RBX::Kernel  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006a8080
//
// 006a8080  53                   push ebx
// 006a8081  8b5c2408             mov ebx, dword ptr [esp + 8]
// 006a8085  56                   push esi
// 006a8086  8b7114               mov esi, dword ptr [ecx + 0x14]
// 006a8089  57                   push edi
// 006a808a  8bcb                 mov ecx, ebx
// 006a808c  83c630               add esi, 0x30
// 006a808f  e81cf9ffff           call 0x6a79b0
// 006a8094  8b38                 mov edi, dword ptr [eax]
// 006a8096  8b06                 mov eax, dword ptr [esi]
// 006a8098  8b4e04               mov ecx, dword ptr [esi + 4]
// 006a809b  8b4c88fc             mov ecx, dword ptr [eax + ecx*4 - 4]
// 006a809f  890cb8               mov dword ptr [eax + edi*4], ecx
// 006a80a2  e809f9ffff           call 0x6a79b0
// 006a80a7  8938                 mov dword ptr [eax], edi
// 006a80a9  8b5604               mov edx, dword ptr [esi + 4]
// 006a80ac  6a00                 push 0
// 006a80ae  4a                   dec edx
// 006a80af  52                   push edx
// 006a80b0  8bce                 mov ecx, esi
// 006a80b2  e859f9ffff           call 0x6a7a10
// 006a80b7  8bcb                 mov ecx, ebx
// 006a80b9  e8f2f8ffff           call 0x6a79b0
// 006a80be  5f                   pop edi
// 006a80bf  5e                   pop esi
// 006a80c0  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 006a80c6  5b                   pop ebx
// 006a80c7  c20400               ret 4

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
    char pad[20];
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

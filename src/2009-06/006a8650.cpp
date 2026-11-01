// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005fb1a0  unit: RBX::Kernel  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fb1a0
//
// 005fb1a0  53                   push ebx
// 005fb1a1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005fb1a5  56                   push esi
// 005fb1a6  8b7110               mov esi, dword ptr [ecx + 0x10]
// 005fb1a9  57                   push edi
// 005fb1aa  8bcb                 mov ecx, ebx
// 005fb1ac  83c618               add esi, 0x18
// 005fb1af  e85cf4ffff           call 0x5fa610
// 005fb1b4  8b38                 mov edi, dword ptr [eax]
// 005fb1b6  8b06                 mov eax, dword ptr [esi]
// 005fb1b8  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fb1bb  8b4c88fc             mov ecx, dword ptr [eax + ecx*4 - 4]
// 005fb1bf  890cb8               mov dword ptr [eax + edi*4], ecx
// 005fb1c2  e849f4ffff           call 0x5fa610
// 005fb1c7  8938                 mov dword ptr [eax], edi
// 005fb1c9  8b5604               mov edx, dword ptr [esi + 4]
// 005fb1cc  6a00                 push 0
// 005fb1ce  4a                   dec edx
// 005fb1cf  52                   push edx
// 005fb1d0  8bce                 mov ecx, esi
// 005fb1d2  e899f6ffff           call 0x5fa870
// 005fb1d7  8bcb                 mov ecx, ebx
// 005fb1d9  e832f4ffff           call 0x5fa610
// 005fb1de  5f                   pop edi
// 005fb1df  5e                   pop esi
// 005fb1e0  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 005fb1e6  5b                   pop ebx
// 005fb1e7  c20400               ret 4

struct S_func_005fa610 {
    char pad0[4];
    int m_x;
    int* f();
};

struct Array {
    S_func_005fa610** data;
    int count;
    void resize(int count, int value);
};

struct Storage {
    char pad0[24];
    Array array;
};

struct Kernel {
    char pad0[16];
    Storage* storage;
    void remove(S_func_005fa610* object);
};

void Kernel::remove(S_func_005fa610* object)
{
    Array* array = &storage->array;
    int index = *object->f();
    S_func_005fa610* last = array->data[array->count - 1];
    array->data[index] = last;
    *last->f() = index;
    array->resize(array->count - 1, 0);
    *object->f() = -1;
}

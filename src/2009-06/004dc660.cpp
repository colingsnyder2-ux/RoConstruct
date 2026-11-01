// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 004a5a30  unit: RBX::VHint::?$FactoryProduct::Creator  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a5a30
//
// 004a5a30  8b442404             mov eax, dword ptr [esp + 4]
// 004a5a34  56                   push esi
// 004a5a35  8b30                 mov esi, dword ptr [eax]
// 004a5a37  8b4004               mov eax, dword ptr [eax + 4]
// 004a5a3a  8b16                 mov edx, dword ptr [esi]
// 004a5a3c  50                   push eax
// 004a5a3d  8b4230               mov eax, dword ptr [edx + 0x30]
// 004a5a40  8bce                 mov ecx, esi
// 004a5a42  ffd0                 call eax
// 004a5a44  89442408             mov dword ptr [esp + 8], eax
// 004a5a48  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004a5a4b  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 004a5a4e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a5a52  6a01                 push 1
// 004a5a54  42                   inc edx
// 004a5a55  52                   push edx
// 004a5a56  8d442410             lea eax, [esp + 0x10]
// 004a5a5a  50                   push eax
// 004a5a5b  e8a0fbffff           call 0x4a5600
// 004a5a60  5e                   pop esi
// 004a5a61  c3                   ret 

struct Object;
struct Input;

typedef Input* (__thiscall *Method)(Object*, int);

struct VTable {
    Method slots[13];
};

struct Context {
    char padding[48];
    int count;
};

struct Object {
    VTable* table;
    char padding[20];
    Context* context;
};

struct Input {
    Object* object;
    int value;
};

struct Sink {
    void write(Input** value, int count, bool flag);
};

void __cdecl process(Input* input, Sink* sink)
{
    Object* object = input->object;
    int value = input->value;
    Input* result = object->table->slots[12](object, value);
    int count = object->context->count + 1;
    sink->write(&result, count, true);
}

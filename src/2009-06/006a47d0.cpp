// from server: 80% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0064df60  unit: RBX::ToolMouseCommand  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064df60
//
// 0064df60  8b442404             mov eax, dword ptr [esp + 4]
// 0064df64  8b10                 mov edx, dword ptr [eax]
// 0064df66  899130010000         mov dword ptr [ecx + 0x130], edx
// 0064df6c  8b5004               mov edx, dword ptr [eax + 4]
// 0064df6f  899134010000         mov dword ptr [ecx + 0x134], edx
// 0064df75  8b5008               mov edx, dword ptr [eax + 8]
// 0064df78  899138010000         mov dword ptr [ecx + 0x138], edx
// 0064df7e  8b500c               mov edx, dword ptr [eax + 0xc]
// 0064df81  89913c010000         mov dword ptr [ecx + 0x13c], edx
// 0064df87  8b4010               mov eax, dword ptr [eax + 0x10]
// 0064df8a  898140010000         mov dword ptr [ecx + 0x140], eax
// 0064df90  c7813001000000000000 mov dword ptr [ecx + 0x130], 0
// 0064df9a  c20400               ret 4

struct Value {
    int fields[5];
};

struct S {
    char pad[0x130];
    Value value;
    void set(const Value& source);
};

void S::set(const Value& source)
{
    value = source;
    value.fields[0] = 0;
}

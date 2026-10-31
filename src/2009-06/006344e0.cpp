// from server: 100% by EspClaude
// roc 2009-06 006344e0  unit: RBX::VScriptContext::?$FactoryProduct  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006344e0
//
// 006344e0  a1f02aa200           mov eax, dword ptr [0xa22af0]
// 006344e5  56                   push esi
// 006344e6  57                   push edi
// 006344e7  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006344eb  50                   push eax
// 006344ec  6a02                 push 2
// 006344ee  57                   push edi
// 006344ef  e8bc660800           call 0x6babb0
// 006344f4  8b0df02aa200         mov ecx, dword ptr [0xa22af0]
// 006344fa  51                   push ecx
// 006344fb  6a01                 push 1
// 006344fd  57                   push edi
// 006344fe  8bf0                 mov esi, eax
// 00634500  e8ab660800           call 0x6babb0
// 00634505  d906                 fld dword ptr [esi]
// 00634507  8bc8                 mov ecx, eax
// 00634509  d819                 fcomp dword ptr [ecx]
// 0063450b  83c418               add esp, 0x18
// 0063450e  dfe0                 fnstsw ax
// 00634510  f6c444               test ah, 0x44
// 00634513  7a21                 jp 0x634536
// 00634515  d94604               fld dword ptr [esi + 4]
// 00634518  d85904               fcomp dword ptr [ecx + 4]
// 0063451b  dfe0                 fnstsw ax
// 0063451d  f6c444               test ah, 0x44
// 00634520  7a14                 jp 0x634536
// 00634522  d94608               fld dword ptr [esi + 8]
// 00634525  d85908               fcomp dword ptr [ecx + 8]
// 00634528  dfe0                 fnstsw ax
// 0063452a  f6c444               test ah, 0x44
// 0063452d  7a07                 jp 0x634536
// 0063452f  b801000000           mov eax, 1
// 00634534  eb02                 jmp 0x634538
// 00634536  33c0                 xor eax, eax
// 00634538  0fb6d0               movzx edx, al
// 0063453b  52                   push edx
// 0063453c  57                   push edi
// 0063453d  e8ee4f0800           call 0x6b9530
// 00634542  83c408               add esp, 8
// 00634545  5f                   pop edi
// 00634546  b801000000           mov eax, 1
// 0063454b  5e                   pop esi
// 0063454c  c3                   ret 
// copied from an identical function in another client (function ?vectorsEqual@ns_ROCX00001d@@YAHPAUState@1@@Z)

namespace ns_ROCX00001d {
struct State;

struct Vector3 {
    float x, y, z;
};

extern const char* vectorType;

extern "C" Vector3* __cdecl checkVector(State*, int, const char*);
extern "C" void __cdecl pushBoolean(State*, int);

#pragma float_control(precise, off)

int __cdecl vectorsEqual(State* state)
{
    Vector3* second = checkVector(state, 2, vectorType);
    Vector3* first = checkVector(state, 1, vectorType);

    int equal = (static_cast<double>(first->x) == second->x
              && static_cast<double>(first->y) == second->y
              && static_cast<double>(first->z) == second->z) ? 1 : 0;

    pushBoolean(state, static_cast<unsigned char>(equal));
    return 1;
}
}

// from server: 100% by EspClaude
// roc 2009-06 006348e0  unit: RBX::VScriptContext::?$FactoryProduct  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006348e0
//
// 006348e0  a1ec2aa200           mov eax, dword ptr [0xa22aec]
// 006348e5  56                   push esi
// 006348e6  57                   push edi
// 006348e7  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006348eb  50                   push eax
// 006348ec  6a02                 push 2
// 006348ee  57                   push edi
// 006348ef  e8bc620800           call 0x6babb0
// 006348f4  8b0dec2aa200         mov ecx, dword ptr [0xa22aec]
// 006348fa  51                   push ecx
// 006348fb  6a01                 push 1
// 006348fd  57                   push edi
// 006348fe  8bf0                 mov esi, eax
// 00634900  e8ab620800           call 0x6babb0
// 00634905  d906                 fld dword ptr [esi]
// 00634907  8bc8                 mov ecx, eax
// 00634909  d819                 fcomp dword ptr [ecx]
// 0063490b  83c418               add esp, 0x18
// 0063490e  dfe0                 fnstsw ax
// 00634910  f6c444               test ah, 0x44
// 00634913  7a21                 jp 0x634936
// 00634915  d94604               fld dword ptr [esi + 4]
// 00634918  d85904               fcomp dword ptr [ecx + 4]
// 0063491b  dfe0                 fnstsw ax
// 0063491d  f6c444               test ah, 0x44
// 00634920  7a14                 jp 0x634936
// 00634922  d94608               fld dword ptr [esi + 8]
// 00634925  d85908               fcomp dword ptr [ecx + 8]
// 00634928  dfe0                 fnstsw ax
// 0063492a  f6c444               test ah, 0x44
// 0063492d  7a07                 jp 0x634936
// 0063492f  b801000000           mov eax, 1
// 00634934  eb02                 jmp 0x634938
// 00634936  33c0                 xor eax, eax
// 00634938  0fb6d0               movzx edx, al
// 0063493b  52                   push edx
// 0063493c  57                   push edi
// 0063493d  e8ee4b0800           call 0x6b9530
// 00634942  83c408               add esp, 8
// 00634945  5f                   pop edi
// 00634946  b801000000           mov eax, 1
// 0063494b  5e                   pop esi
// 0063494c  c3                   ret 
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

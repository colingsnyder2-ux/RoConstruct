// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00599220  unit: RBX::VPartInstance::?$FactoryProduct  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00599220
//
// 00599220  53                   push ebx
// 00599221  56                   push esi
// 00599222  57                   push edi
// 00599223  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00599227  8bd9                 mov ebx, ecx
// 00599229  33f6                 xor esi, esi
// 0059922b  eb03                 jmp 0x599230
// 0059922d  8d4900               lea ecx, [ecx]
// 00599230  56                   push esi
// 00599231  8bcb                 mov ecx, ebx
// 00599233  e8c8390500           call 0x5ecc00
// 00599238  8bc8                 mov ecx, eax
// 0059923a  e851800500           call 0x5f1290
// 0059923f  8904b7               mov dword ptr [edi + esi*4], eax
// 00599242  46                   inc esi
// 00599243  83fe06               cmp esi, 6
// 00599246  7ce8                 jl 0x599230
// 00599248  8bc7                 mov eax, edi
// 0059924a  5f                   pop edi
// 0059924b  5e                   pop esi
// 0059924c  5b                   pop ebx
// 0059924d  c20400               ret 4

struct FaceInstance {
    int getSurfaceType() const;
};

struct S {
    FaceInstance* getFace(int index);
    int* getSurfaceTypes(int* result);
};

int* S::getSurfaceTypes(int* result)
{
    for (int i = 0; i < 6; ++i)
        result[i] = getFace(i)->getSurfaceType();
    return result;
}

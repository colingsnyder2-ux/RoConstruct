// from server: 100% by EspClaude
// from server: 78% by EspClaude
// roc 2007-08 005b9520  unit: RBX::VFaceInstance::?$EnumPropDescriptor  size: 267 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b9520
//
// 005b9520  53                   push ebx
// 005b9521  56                   push esi
// 005b9522  8bf1                 mov esi, ecx
// 005b9524  8b0e                 mov ecx, dword ptr [esi]
// 005b9526  8b4604               mov eax, dword ptr [esi + 4]
// 005b9529  8b89d8010000         mov ecx, dword ptr [ecx + 0x1d8]
// 005b952f  837c817c00           cmp dword ptr [ecx + eax*4 + 0x7c], 0
// 005b9534  742d                 je 0x5b9563
// 005b9536  6a00                 push 0
// 005b9538  50                   push eax
// 005b9539  e8d2b5ffff           call 0x5b4b10
// 005b953e  8b5604               mov edx, dword ptr [esi + 4]
// 005b9541  8b0e                 mov ecx, dword ptr [esi]
// 005b9543  52                   push edx
// 005b9544  e857a9fbff           call 0x573ea0
// 005b9549  8b4604               mov eax, dword ptr [esi + 4]
// 005b954c  8b0e                 mov ecx, dword ptr [esi]
// 005b954e  50                   push eax
// 005b954f  e83ca3fbff           call 0x573890
// 005b9554  8bc8                 mov ecx, eax
// 005b9556  e885d5ffff           call 0x5b6ae0
// 005b955b  8b0e                 mov ecx, dword ptr [esi]
// 005b955d  50                   push eax
// 005b955e  e8adb1e8ff           call 0x444710
// 005b9563  bb01000000           mov ebx, 1
// 005b9568  841dbc5e8c00         test byte ptr [0x8c5ebc], bl
// 005b956e  7528                 jne 0x5b9598
// 005b9570  d905f0547b00         fld dword ptr [0x7b54f0]
// 005b9576  091dbc5e8c00         or dword ptr [0x8c5ebc], ebx
// 005b957c  d91db45e8c00         fstp dword ptr [0x8c5eb4]
// 005b9582  c705b05e8c0000000000 mov dword ptr [0x8c5eb0], 0
// 005b958c  d9059c7e7900         fld dword ptr [0x797e9c]
// 005b9592  d91db85e8c00         fstp dword ptr [0x8c5eb8]
// 005b9598  8b0db05e8c00         mov ecx, dword ptr [0x8c5eb0]
// 005b959e  51                   push ecx
// 005b959f  8bce                 mov ecx, esi
// 005b95a1  e81afdffff           call 0x5b92c0
// 005b95a6  841dbc5e8c00         test byte ptr [0x8c5ebc], bl
// 005b95ac  7528                 jne 0x5b95d6
// 005b95ae  d905f0547b00         fld dword ptr [0x7b54f0]
// 005b95b4  091dbc5e8c00         or dword ptr [0x8c5ebc], ebx
// 005b95ba  d91db45e8c00         fstp dword ptr [0x8c5eb4]
// 005b95c0  c705b05e8c0000000000 mov dword ptr [0x8c5eb0], 0
// 005b95ca  d9059c7e7900         fld dword ptr [0x797e9c]
// 005b95d0  d91db85e8c00         fstp dword ptr [0x8c5eb8]
// 005b95d6  d905b45e8c00         fld dword ptr [0x8c5eb4]
// 005b95dc  51                   push ecx
// 005b95dd  8bce                 mov ecx, esi
// 005b95df  d91c24               fstp dword ptr [esp]
// 005b95e2  e899fdffff           call 0x5b9380
// 005b95e7  841dbc5e8c00         test byte ptr [0x8c5ebc], bl
// 005b95ed  7528                 jne 0x5b9617
// 005b95ef  d905f0547b00         fld dword ptr [0x7b54f0]
// 005b95f5  091dbc5e8c00         or dword ptr [0x8c5ebc], ebx
// 005b95fb  d91db45e8c00         fstp dword ptr [0x8c5eb4]
// 005b9601  c705b05e8c0000000000 mov dword ptr [0x8c5eb0], 0
// 005b960b  d9059c7e7900         fld dword ptr [0x797e9c]
// 005b9611  d91db85e8c00         fstp dword ptr [0x8c5eb8]
// 005b9617  d905b85e8c00         fld dword ptr [0x8c5eb8]
// 005b961d  51                   push ecx
// 005b961e  8bce                 mov ecx, esi
// 005b9620  d91c24               fstp dword ptr [esp]
// 005b9623  e828feffff           call 0x5b9450
// 005b9628  5e                   pop esi
// 005b9629  5b                   pop ebx
// 005b962a  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 005f1690  unit: RBX::FaceInstance  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f1690
//
// 005f1690  53                   push ebx
// 005f1691  56                   push esi
// 005f1692  8bf1                 mov esi, ecx
// 005f1694  8b4604               mov eax, dword ptr [esi + 4]
// 005f1697  8b0e                 mov ecx, dword ptr [esi]
// 005f1699  83bc81e002000000     cmp dword ptr [ecx + eax*4 + 0x2e0], 0
// 005f16a1  7433                 je 0x5f16d6
// 005f16a3  6a00                 push 0
// 005f16a5  50                   push eax
// 005f16a6  81c128020000         add ecx, 0x228
// 005f16ac  e89f61ffff           call 0x5e7850
// 005f16b1  8b4604               mov eax, dword ptr [esi + 4]
// 005f16b4  8b0e                 mov ecx, dword ptr [esi]
// 005f16b6  50                   push eax
// 005f16b7  e80481faff           call 0x5997c0
// 005f16bc  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f16bf  51                   push ecx
// 005f16c0  8b0e                 mov ecx, dword ptr [esi]
// 005f16c2  e81977faff           call 0x598de0
// 005f16c7  8bc8                 mov ecx, eax
// 005f16c9  e862b3ffff           call 0x5eca30
// 005f16ce  8b0e                 mov ecx, dword ptr [esi]
// 005f16d0  50                   push eax
// 005f16d1  e82ac4e1ff           call 0x40db00
// 005f16d6  bb01000000           mov ebx, 1
// 005f16db  841dd0ab9700         test byte ptr [0x97abd0], bl
// 005f16e1  7528                 jne 0x5f170b
// 005f16e3  d905dc828200         fld dword ptr [0x8282dc]
// 005f16e9  091dd0ab9700         or dword ptr [0x97abd0], ebx
// 005f16ef  d91dc8ab9700         fstp dword ptr [0x97abc8]
// 005f16f5  c705c4ab970000000000 mov dword ptr [0x97abc4], 0
// 005f16ff  d905ac9b8100         fld dword ptr [0x819bac]
// 005f1705  d91dccab9700         fstp dword ptr [0x97abcc]
// 005f170b  8b15c4ab9700         mov edx, dword ptr [0x97abc4]
// 005f1711  52                   push edx
// 005f1712  8bce                 mov ecx, esi
// 005f1714  e817fdffff           call 0x5f1430
// 005f1719  841dd0ab9700         test byte ptr [0x97abd0], bl
// 005f171f  7528                 jne 0x5f1749
// 005f1721  d905dc828200         fld dword ptr [0x8282dc]
// 005f1727  091dd0ab9700         or dword ptr [0x97abd0], ebx
// 005f172d  d91dc8ab9700         fstp dword ptr [0x97abc8]
// 005f1733  c705c4ab970000000000 mov dword ptr [0x97abc4], 0
// 005f173d  d905ac9b8100         fld dword ptr [0x819bac]
// 005f1743  d91dccab9700         fstp dword ptr [0x97abcc]
// 005f1749  d905c8ab9700         fld dword ptr [0x97abc8]
// 005f174f  51                   push ecx
// 005f1750  8bce                 mov ecx, esi
// 005f1752  d91c24               fstp dword ptr [esp]
// 005f1755  e896fdffff           call 0x5f14f0
// 005f175a  841dd0ab9700         test byte ptr [0x97abd0], bl
// 005f1760  7528                 jne 0x5f178a
// 005f1762  d905dc828200         fld dword ptr [0x8282dc]
// 005f1768  091dd0ab9700         or dword ptr [0x97abd0], ebx
// 005f176e  d91dc8ab9700         fstp dword ptr [0x97abc8]
// 005f1774  c705c4ab970000000000 mov dword ptr [0x97abc4], 0
// 005f177e  d905ac9b8100         fld dword ptr [0x819bac]
// 005f1784  d91dccab9700         fstp dword ptr [0x97abcc]
// 005f178a  d905ccab9700         fld dword ptr [0x97abcc]
// 005f1790  51                   push ecx
// 005f1791  8bce                 mov ecx, esi
// 005f1793  d91c24               fstp dword ptr [esp]
// 005f1796  e825feffff           call 0x5f15c0
// 005f179b  5e                   pop esi
// 005f179c  5b                   pop ebx
// 005f179d  c3                   ret 

extern float g_8282dc;
extern float g_819bac;
extern int g_97abc4;
extern float g_97abc8;
extern float g_97abcc;
extern unsigned int g_97abd0;

struct Ball {
    char padding[0x7C];
    int values[1];
    void set(int index, int value);
};

struct Value {
    int get();
};

struct PartInstance {
    char padding[0x1D8];
    Ball* ball;
    void setShouldRender(int);
    int* f(int);
    void notify(int);
};

struct FaceInstance {
    PartInstance* part;
    int face;
    void setFirst(int);
    void setSecond(float);
    void setThird(float);
    void reset();
};

void FaceInstance::reset()
{
    if (part->ball->values[face] != 0) {
        part->ball->set(face, 0);
        part->setShouldRender(face);
        int* value = part->f(face);
        part->notify(((Value*)value)->get());
    }

    if (((unsigned char)g_97abd0 & 1) == 0) {
        g_97abd0 |= 1;
        g_97abc8 = g_8282dc;
        g_97abc4 = 0;
        g_97abcc = g_819bac;
    }
    setFirst(g_97abc4);

    if (((unsigned char)g_97abd0 & 1) == 0) {
        g_97abd0 |= 1;
        g_97abc8 = g_8282dc;
        g_97abc4 = 0;
        g_97abcc = g_819bac;
    }
    setSecond(g_97abc8);

    if (((unsigned char)g_97abd0 & 1) == 0) {
        g_97abd0 |= 1;
        g_97abc8 = g_8282dc;
        g_97abc4 = 0;
        g_97abcc = g_819bac;
    }
    setThird(g_97abcc);
}

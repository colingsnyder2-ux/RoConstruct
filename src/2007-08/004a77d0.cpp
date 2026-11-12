// from server: 62% by EspClaude
// from server: 57% by colin
// roc 2007-08 004a77d0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a77d0
//
// 004a77d0  83ec10               sub esp, 0x10
// 004a77d3  8d442403             lea eax, [esp + 3]
// 004a77d7  50                   push eax
// 004a77d8  57                   push edi
// 004a77d9  e8728affff           call 0x4a0250
// 004a77de  83c408               add esp, 8
// 004a77e1  807c240300           cmp byte ptr [esp + 3], 0
// 004a77e6  0f8499000000         je 0x4a7885
// 004a77ec  6a01                 push 1
// 004a77ee  6a0f                 push 0xf
// 004a77f0  8d4c240c             lea ecx, [esp + 0xc]
// 004a77f4  51                   push ecx
// 004a77f5  8bcf                 mov ecx, edi
// 004a77f7  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004a77ff  e89c81ffff           call 0x49f9a0
// 004a7804  6a01                 push 1
// 004a7806  6a0e                 push 0xe
// 004a7808  8d542410             lea edx, [esp + 0x10]
// 004a780c  52                   push edx
// 004a780d  8bcf                 mov ecx, edi
// 004a780f  e88c81ffff           call 0x49f9a0
// 004a7814  6a01                 push 1
// 004a7816  6a0f                 push 0xf
// 004a7818  8d442414             lea eax, [esp + 0x14]
// 004a781c  50                   push eax
// 004a781d  8bcf                 mov ecx, edi
// 004a781f  e87c81ffff           call 0x49f9a0
// 004a7824  0fb74c2404           movzx ecx, word ptr [esp + 4]
// 004a7829  0fb7542408           movzx edx, word ptr [esp + 8]
// 004a782e  0fb744240c           movzx eax, word ptr [esp + 0xc]
// 004a7833  894c2404             mov dword ptr [esp + 4], ecx
// 004a7837  89542408             mov dword ptr [esp + 8], edx
// 004a783b  db442404             fild dword ptr [esp + 4]
// 004a783f  8944240c             mov dword ptr [esp + 0xc], eax
// 004a7843  dd05308b7900         fld qword ptr [0x798b30]
// 004a7849  dcc9                 fmul st(1), st(0)
// 004a784b  dd0510d67900         fld qword ptr [0x79d610]
// 004a7851  dcca                 fmul st(2), st(0)
// 004a7853  dd0508d67900         fld qword ptr [0x79d608]
// 004a7859  dceb                 fsub st(3), st(0)
// 004a785b  d9cb                 fxch st(3)
// 004a785d  d91e                 fstp dword ptr [esi]
// 004a785f  db442408             fild dword ptr [esp + 8]
// 004a7863  dc0d00d67900         fmul qword ptr [0x79d600]
// 004a7869  d8cb                 fmul st(3)
// 004a786b  dc25f8d57900         fsub qword ptr [0x79d5f8]
// 004a7871  d95e04               fstp dword ptr [esi + 4]
// 004a7874  db44240c             fild dword ptr [esp + 0xc]
// 004a7878  deca                 fmulp st(2)
// 004a787a  dec9                 fmulp st(1)
// 004a787c  dee1                 fsubrp st(1)
// 004a787e  d95e08               fstp dword ptr [esi + 8]
// 004a7881  83c410               add esp, 0x10
// 004a7884  c3                   ret 
// 004a7885  8d4e08               lea ecx, [esi + 8]
// 004a7888  51                   push ecx
// 004a7889  8d5604               lea edx, [esi + 4]
// 004a788c  52                   push edx
// 004a788d  56                   push esi
// 004a788e  8bcf                 mov ecx, edi
// 004a7890  e8fbf3ffff           call 0x4a6c90
// 004a7895  83c410               add esp, 0x10
// 004a7898  c3                   ret 

struct Vector3 {
    float x;
    float y;
    float z;
};

struct BitStream {
    void readBits(void* out, int numberOfBits, bool alignRight);
    void readVector(float* x, float* y, float* z);
};

void readBool(BitStream* stream, bool* value);

void readPosition(BitStream* stream, Vector3* position)
{
    bool compressed;
    readBool(stream, &compressed);
    if (compressed) {
        unsigned int x = 0;
        unsigned int y;
        unsigned int z;
        stream->readBits(&x, 15, true);
        stream->readBits(&y, 14, true);
        stream->readBits(&z, 15, true);
        int ix = (unsigned short)x;
        int iy = (unsigned short)y;
        int iz = (unsigned short)z;
        position->x = (float)(ix * (1.0 / 32768.0) * 2048.0 - 1024.0);
        position->y = (float)(iy * (1.0 / 16384.0) * 1024.0 - 512.0);
        position->z = (float)(iz * (1.0 / 32768.0) * 2048.0 - 1024.0);
    } else {
        stream->readVector(&position->x, &position->y, &position->z);
    }
}

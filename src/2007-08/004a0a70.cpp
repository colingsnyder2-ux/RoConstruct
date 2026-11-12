// from server: 100% by EspClaude
// from server: 46% by colin
// roc 2007-08 004a0a70  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 484 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a0a70
//
// 004a0a70  83ec1c               sub esp, 0x1c
// 004a0a73  53                   push ebx
// 004a0a74  56                   push esi
// 004a0a75  8b742428             mov esi, dword ptr [esp + 0x28]
// 004a0a79  8b4608               mov eax, dword ptr [esi + 8]
// 004a0a7c  57                   push edi
// 004a0a7d  8d7801               lea edi, [eax + 1]
// 004a0a80  3b3e                 cmp edi, dword ptr [esi]
// 004a0a82  7f1d                 jg 0x4a0aa1
// 004a0a84  8bc8                 mov ecx, eax
// 004a0a86  83e107               and ecx, 7
// 004a0a89  ba80000000           mov edx, 0x80
// 004a0a8e  d3fa                 sar edx, cl
// 004a0a90  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004a0a93  c1f803               sar eax, 3
// 004a0a96  841408               test byte ptr [eax + ecx], dl
// 004a0a99  897e08               mov dword ptr [esi + 8], edi
// 004a0a9c  0f95c0               setne al
// 004a0a9f  eb04                 jmp 0x4a0aa5
// 004a0aa1  8a44242c             mov al, byte ptr [esp + 0x2c]
// 004a0aa5  33db                 xor ebx, ebx
// 004a0aa7  3ac3                 cmp al, bl
// 004a0aa9  6a01                 push 1
// 004a0aab  8bce                 mov ecx, esi
// 004a0aad  0f849e000000         je 0x4a0b51
// 004a0ab3  6a0b                 push 0xb
// 004a0ab5  8d542434             lea edx, [esp + 0x34]
// 004a0ab9  52                   push edx
// 004a0aba  895c2438             mov dword ptr [esp + 0x38], ebx
// 004a0abe  895c241c             mov dword ptr [esp + 0x1c], ebx
// 004a0ac2  895c2418             mov dword ptr [esp + 0x18], ebx
// 004a0ac6  e8d5eeffff           call 0x49f9a0
// 004a0acb  6a01                 push 1
// 004a0acd  6a0b                 push 0xb
// 004a0acf  8d442418             lea eax, [esp + 0x18]
// 004a0ad3  50                   push eax
// 004a0ad4  8bce                 mov ecx, esi
// 004a0ad6  e8c5eeffff           call 0x49f9a0
// 004a0adb  6a01                 push 1
// 004a0add  6a0b                 push 0xb
// 004a0adf  8d4c2414             lea ecx, [esp + 0x14]
// 004a0ae3  51                   push ecx
// 004a0ae4  8bce                 mov ecx, esi
// 004a0ae6  e8b5eeffff           call 0x49f9a0
// 004a0aeb  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004a0aef  a900040000           test eax, 0x400
// 004a0af4  7405                 je 0x4a0afb
// 004a0af6  0d00fcffff           or eax, 0xfffffc00
// 004a0afb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a0aff  f7c100040000         test ecx, 0x400
// 004a0b05  7406                 je 0x4a0b0d
// 004a0b07  81c900fcffff         or ecx, 0xfffffc00
// 004a0b0d  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004a0b11  0fbfd0               movsx edx, ax
// 004a0b14  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 004a0b19  8954242c             mov dword ptr [esp + 0x2c], edx
// 004a0b1d  0fbfc9               movsx ecx, cx
// 004a0b20  db44242c             fild dword ptr [esp + 0x2c]
// 004a0b24  dd05485b7900         fld qword ptr [0x795b48]
// 004a0b2a  8944242c             mov dword ptr [esp + 0x2c], eax
// 004a0b2e  dcc9                 fmul st(1), st(0)
// 004a0b30  d9c9                 fxch st(1)
// 004a0b32  d95f24               fstp dword ptr [edi + 0x24]
// 004a0b35  db44242c             fild dword ptr [esp + 0x2c]
// 004a0b39  894c242c             mov dword ptr [esp + 0x2c], ecx
// 004a0b3d  dc35685b7900         fdiv qword ptr [0x795b68]
// 004a0b43  d95f28               fstp dword ptr [edi + 0x28]
// 004a0b46  db44242c             fild dword ptr [esp + 0x2c]
// 004a0b4a  dec9                 fmulp st(1)
// 004a0b4c  d95f2c               fstp dword ptr [edi + 0x2c]
// 004a0b4f  eb2d                 jmp 0x4a0b7e
// 004a0b51  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 004a0b55  6a20                 push 0x20
// 004a0b57  8d5724               lea edx, [edi + 0x24]
// 004a0b5a  52                   push edx
// 004a0b5b  e840eeffff           call 0x49f9a0
// 004a0b60  6a01                 push 1
// 004a0b62  6a20                 push 0x20
// 004a0b64  8d4728               lea eax, [edi + 0x28]
// 004a0b67  50                   push eax
// 004a0b68  8bce                 mov ecx, esi
// 004a0b6a  e831eeffff           call 0x49f9a0
// 004a0b6f  6a01                 push 1
// 004a0b71  6a20                 push 0x20
// 004a0b73  8d4f2c               lea ecx, [edi + 0x2c]
// 004a0b76  51                   push ecx
// 004a0b77  8bce                 mov ecx, esi
// 004a0b79  e822eeffff           call 0x49f9a0
// 004a0b7e  8b4608               mov eax, dword ptr [esi + 8]
// 004a0b81  55                   push ebp
// 004a0b82  8d6801               lea ebp, [eax + 1]
// 004a0b85  3b2e                 cmp ebp, dword ptr [esi]
// 004a0b87  7f1d                 jg 0x4a0ba6
// 004a0b89  8bc8                 mov ecx, eax
// 004a0b8b  83e107               and ecx, 7
// 004a0b8e  ba80000000           mov edx, 0x80
// 004a0b93  d3fa                 sar edx, cl
// 004a0b95  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004a0b98  c1f803               sar eax, 3
// 004a0b9b  841408               test byte ptr [eax + ecx], dl
// 004a0b9e  896e08               mov dword ptr [esi + 8], ebp
// 004a0ba1  0f95c0               setne al
// 004a0ba4  eb04                 jmp 0x4a0baa
// 004a0ba6  8a442430             mov al, byte ptr [esp + 0x30]
// 004a0baa  3ac3                 cmp al, bl
// 004a0bac  5d                   pop ebp
// 004a0bad  6a01                 push 1
// 004a0baf  7429                 je 0x4a0bda
// 004a0bb1  6a06                 push 6
// 004a0bb3  8d542434             lea edx, [esp + 0x34]
// 004a0bb7  52                   push edx
// 004a0bb8  8bce                 mov ecx, esi
// 004a0bba  895c2438             mov dword ptr [esp + 0x38], ebx
// 004a0bbe  e8ddedffff           call 0x49f9a0
// 004a0bc3  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004a0bc7  57                   push edi
// 004a0bc8  50                   push eax
// 004a0bc9  e8a2a21000           call 0x5aae70
// 004a0bce  83c408               add esp, 8
// 004a0bd1  5f                   pop edi
// 004a0bd2  8bc6                 mov eax, esi
// 004a0bd4  5e                   pop esi
// 004a0bd5  5b                   pop ebx
// 004a0bd6  83c41c               add esp, 0x1c
// 004a0bd9  c3                   ret 
// 004a0bda  6a20                 push 0x20
// 004a0bdc  8d4c241c             lea ecx, [esp + 0x1c]
// 004a0be0  51                   push ecx
// 004a0be1  8bce                 mov ecx, esi
// 004a0be3  e8b8edffff           call 0x49f9a0
// 004a0be8  6a01                 push 1
// 004a0bea  6a20                 push 0x20
// 004a0bec  8d542434             lea edx, [esp + 0x34]
// 004a0bf0  52                   push edx
// 004a0bf1  8bce                 mov ecx, esi
// 004a0bf3  e8a8edffff           call 0x49f9a0
// 004a0bf8  6a01                 push 1
// 004a0bfa  6a20                 push 0x20
// 004a0bfc  8d442418             lea eax, [esp + 0x18]
// 004a0c00  50                   push eax
// 004a0c01  8bce                 mov ecx, esi
// 004a0c03  e898edffff           call 0x49f9a0
// 004a0c08  6a01                 push 1
// 004a0c0a  6a20                 push 0x20
// 004a0c0c  8d4c2414             lea ecx, [esp + 0x14]
// 004a0c10  51                   push ecx
// 004a0c11  8bce                 mov ecx, esi
// 004a0c13  e888edffff           call 0x49f9a0
// 004a0c18  d944242c             fld dword ptr [esp + 0x2c]
// 004a0c1c  d95c2418             fstp dword ptr [esp + 0x18]
// 004a0c20  57                   push edi
// 004a0c21  d9442414             fld dword ptr [esp + 0x14]
// 004a0c25  8d4c241c             lea ecx, [esp + 0x1c]
// 004a0c29  d95c2420             fstp dword ptr [esp + 0x20]
// 004a0c2d  d9442410             fld dword ptr [esp + 0x10]
// 004a0c31  d95c2424             fstp dword ptr [esp + 0x24]
// 004a0c35  d9442418             fld dword ptr [esp + 0x18]
// 004a0c39  d95c2428             fstp dword ptr [esp + 0x28]
// 004a0c3d  e89e9d1000           call 0x5aa9e0
// 004a0c42  57                   push edi
// 004a0c43  e8a8b51000           call 0x5ac1f0
// 004a0c48  83c404               add esp, 4
// 004a0c4b  5f                   pop edi
// 004a0c4c  8bc6                 mov eax, esi
// 004a0c4e  5e                   pop esi
// 004a0c4f  5b                   pop ebx
// 004a0c50  83c41c               add esp, 0x1c
// 004a0c53  c3                   ret 

namespace RakNet {
    class BitStream {
    public:
        bool ReadBits(unsigned char* output, int numberOfBitsToRead, const bool alignBitsToRight = true);

        bool Read(bool& var)
        {
            if (readOffset + 1 > numberOfBitsUsed)
                return false;
            if (data[readOffset >> 3] & (0x80 >> (readOffset & 7)))
                var = true;
            else
                var = false;
            readOffset++;
            return true;
        }
        bool Read(float& var)
        {
            return ReadBits((unsigned char*)&var, sizeof(float) * 8, true);
        }
        bool Read(int& var)
        {
            return ReadBits((unsigned char*)&var, sizeof(int) * 8, true);
        }
    private:
        int numberOfBitsUsed;
        int numberOfBitsAllocated;
        int readOffset;
        unsigned char* data;
    };
}

namespace G3D {
    class Vector3 {
    public:
        float x, y, z;
    };
    class Matrix3 {
    public:
        float elt[3][3];
    };
    class Quat {
    public:
        float x, y, z, w;
        Quat(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
        void toRotationMatrix(Matrix3& rot) const;
    };
    class CoordinateFrame {
    public:
        Matrix3 rotation;
        Vector3 translation;
    };
}

namespace RBX {
    namespace Math {
        void idToMatrix3(int orientId, G3D::Matrix3& matrix);
        void orthonormalizeIfNecessary(G3D::Matrix3& m);
    }

    namespace Network {
        RakNet::BitStream& operator>>(RakNet::BitStream& stream, G3D::CoordinateFrame& value)
        {

            bool isBrickLocation;
            stream.Read(isBrickLocation);

            if (isBrickLocation)
            {
                int x = 0;
                int y = 0;
                int z = 0;

                stream.ReadBits((unsigned char*)&x, 11);
                stream.ReadBits((unsigned char*)&y, 11);
                stream.ReadBits((unsigned char*)&z, 11);

                if (x & 0x400) // sign extend x and z
                    x |= 0xfffffc00;

                if (z & 0x400)
                    z |= 0xfffffc00;

                value.translation.x = (float)((short)x * 0.5);
                value.translation.y = (float)((unsigned short)y / 10.0);
                value.translation.z = (float)((short)z * 0.5);
            }
            else
            {
                stream.Read(value.translation.x);
                stream.Read(value.translation.y);
                stream.Read(value.translation.z);
            }

            bool isOrientId;
            stream.Read(isOrientId);

            if (isOrientId)
            {
                int orientId = 0;
                stream.ReadBits((unsigned char*)&orientId, 6);
                Math::idToMatrix3(orientId, value.rotation);
            }
            else
            {
                float w, x, y, z;
                stream.Read(w);
                stream.Read(x);
                stream.Read(y);
                stream.Read(z);
                G3D::Quat q(x, y, z, w);
                q.toRotationMatrix(value.rotation);
                Math::orthonormalizeIfNecessary(value.rotation);
            }
            return stream;
        }
    }
}

// from server: 100% by EspClaude
// roc 2009-06 00472c20  unit: RBX::LDraw2Lua::LDrawParser  size: 922 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00472c20
//
// 00472c20  55                   push ebp
// 00472c21  8bec                 mov ebp, esp
// 00472c23  83e4f8               and esp, 0xfffffff8
// 00472c26  6aff                 push -1
// 00472c28  681d3e8500           push 0x853e1d
// 00472c2d  64a100000000         mov eax, dword ptr fs:[0]
// 00472c33  50                   push eax
// 00472c34  64892500000000       mov dword ptr fs:[0], esp
// 00472c3b  81ec20090000         sub esp, 0x920
// 00472c41  53                   push ebx
// 00472c42  56                   push esi
// 00472c43  57                   push edi
// 00472c44  8b7d08               mov edi, dword ptr [ebp + 8]
// 00472c47  682cdb8b00           push 0x8bdb2c
// 00472c4c  680cdb8b00           push 0x8bdb0c
// 00472c51  6828db8b00           push 0x8bdb28
// 00472c56  57                   push edi
// 00472c57  8bf1                 mov esi, ecx
// 00472c59  e8b23afdff           call 0x446710
// 00472c5e  83c408               add esp, 8
// 00472c61  50                   push eax
// 00472c62  e8a93afdff           call 0x446710
// 00472c67  83c408               add esp, 8
// 00472c6a  50                   push eax
// 00472c6b  e8a03afdff           call 0x446710
// 00472c70  83c408               add esp, 8
// 00472c73  83c604               add esi, 4
// 00472c76  682cdb8b00           push 0x8bdb2c
// 00472c7b  8bce                 mov ecx, esi
// 00472c7d  ff15bce48900         call dword ptr [0x89e4bc]
// 00472c83  50                   push eax
// 00472c84  6800db8b00           push 0x8bdb00
// 00472c89  6828db8b00           push 0x8bdb28
// 00472c8e  57                   push edi
// 00472c8f  e87c3afdff           call 0x446710
// 00472c94  83c408               add esp, 8
// 00472c97  50                   push eax
// 00472c98  e8733afdff           call 0x446710
// 00472c9d  83c408               add esp, 8
// 00472ca0  50                   push eax
// 00472ca1  e86a3afdff           call 0x446710
// 00472ca6  83c408               add esp, 8
// 00472ca9  50                   push eax
// 00472caa  e8613afdff           call 0x446710
// 00472caf  682cdb8b00           push 0x8bdb2c
// 00472cb4  57                   push edi
// 00472cb5  e8563afdff           call 0x446710
// 00472cba  83c410               add esp, 0x10
// 00472cbd  68f4da8b00           push 0x8bdaf4
// 00472cc2  8d8c24f4000000       lea ecx, [esp + 0xf4]
// 00472cc9  e882030000           call 0x473050
// 00472cce  bb01000000           mov ebx, 1
// 00472cd3  53                   push ebx
// 00472cd4  6a40                 push 0x40
// 00472cd6  53                   push ebx
// 00472cd7  8bce                 mov ecx, esi
// 00472cd9  c784244009000000000000 mov dword ptr [esp + 0x940], 0
// 00472ce4  ff15bce48900         call dword ptr [0x89e4bc]
// 00472cea  50                   push eax
// 00472ceb  8d4c2450             lea ecx, [esp + 0x50]
// 00472cef  ff153ce48900         call dword ptr [0x89e43c]
// 00472cf5  8b442440             mov eax, dword ptr [esp + 0x40]
// 00472cf9  8b4804               mov ecx, dword ptr [eax + 4]
// 00472cfc  8d4c0c40             lea ecx, [esp + ecx + 0x40]
// 00472d00  889c2434090000       mov byte ptr [esp + 0x934], bl
// 00472d07  ff1508e58900         call dword ptr [0x89e508]
// 00472d0d  84c0                 test al, al
// 00472d0f  0f8558020000         jne 0x472f6d
// 00472d15  8d4c241c             lea ecx, [esp + 0x1c]
// 00472d19  51                   push ecx
// 00472d1a  8d4c2444             lea ecx, [esp + 0x44]
// 00472d1e  ff1504e58900         call dword ptr [0x89e504]
// 00472d24  395c241c             cmp dword ptr [esp + 0x1c], ebx
// 00472d28  0f850f020000         jne 0x472f3d
// 00472d2e  6890000000           push 0x90
// 00472d33  e8005d2a00           call 0x718a38
// 00472d38  83c404               add esp, 4
// 00472d3b  89442420             mov dword ptr [esp + 0x20], eax
// 00472d3f  c684243409000002     mov byte ptr [esp + 0x934], 2
// 00472d47  85c0                 test eax, eax
// 00472d49  7412                 je 0x472d5d
// 00472d4b  8b1538c5a300         mov edx, dword ptr [0xa3c538]
// 00472d51  52                   push edx
// 00472d52  8bc8                 mov ecx, eax
// 00472d54  e8f7f6ffff           call 0x472450
// 00472d59  8bf0                 mov esi, eax
// 00472d5b  eb02                 jmp 0x472d5f
// 00472d5d  33f6                 xor esi, esi
// 00472d5f  8d442418             lea eax, [esp + 0x18]
// 00472d63  895e08               mov dword ptr [esi + 8], ebx
// 00472d66  50                   push eax
// 00472d67  8d4c2444             lea ecx, [esp + 0x44]
// 00472d6b  889c2438090000       mov byte ptr [esp + 0x938], bl
// 00472d72  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00472d7a  ff1504e58900         call dword ptr [0x89e504]
// 00472d80  d9ee                 fldz 
// 00472d82  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00472d86  894e0c               mov dword ptr [esi + 0xc], ecx
// 00472d89  dd5c2410             fstp qword ptr [esp + 0x10]
// 00472d8d  8d542410             lea edx, [esp + 0x10]
// 00472d91  52                   push edx
// 00472d92  8d4c2444             lea ecx, [esp + 0x44]
// 00472d96  ff1500e58900         call dword ptr [0x89e500]
// 00472d9c  dd442410             fld qword ptr [esp + 0x10]
// 00472da0  8d442410             lea eax, [esp + 0x10]
// 00472da4  dd5e10               fstp qword ptr [esi + 0x10]
// 00472da7  50                   push eax
// 00472da8  8d4c2444             lea ecx, [esp + 0x44]
// 00472dac  ff1500e58900         call dword ptr [0x89e500]
// 00472db2  dd442410             fld qword ptr [esp + 0x10]
// 00472db6  8d4c2410             lea ecx, [esp + 0x10]
// 00472dba  dd5e18               fstp qword ptr [esi + 0x18]
// 00472dbd  51                   push ecx
// 00472dbe  8d4c2444             lea ecx, [esp + 0x44]
// 00472dc2  ff1500e58900         call dword ptr [0x89e500]
// 00472dc8  dd442410             fld qword ptr [esp + 0x10]
// 00472dcc  8d542410             lea edx, [esp + 0x10]
// 00472dd0  dd5e20               fstp qword ptr [esi + 0x20]
// 00472dd3  52                   push edx
// 00472dd4  8d4c2444             lea ecx, [esp + 0x44]
// 00472dd8  ff1500e58900         call dword ptr [0x89e500]
// 00472dde  dd442410             fld qword ptr [esp + 0x10]
// 00472de2  8d442410             lea eax, [esp + 0x10]
// 00472de6  dd5e28               fstp qword ptr [esi + 0x28]
// 00472de9  50                   push eax
// 00472dea  8d4c2444             lea ecx, [esp + 0x44]
// 00472dee  ff1500e58900         call dword ptr [0x89e500]
// 00472df4  dd442410             fld qword ptr [esp + 0x10]
// 00472df8  8d4c2410             lea ecx, [esp + 0x10]
// 00472dfc  dd5e30               fstp qword ptr [esi + 0x30]
// 00472dff  51                   push ecx
// 00472e00  8d4c2444             lea ecx, [esp + 0x44]
// 00472e04  ff1500e58900         call dword ptr [0x89e500]
// 00472e0a  dd442410             fld qword ptr [esp + 0x10]
// 00472e0e  8d542410             lea edx, [esp + 0x10]
// 00472e12  dd5e38               fstp qword ptr [esi + 0x38]
// 00472e15  52                   push edx
// 00472e16  8d4c2444             lea ecx, [esp + 0x44]
// 00472e1a  ff1500e58900         call dword ptr [0x89e500]
// 00472e20  dd442410             fld qword ptr [esp + 0x10]
// 00472e24  8d442410             lea eax, [esp + 0x10]
// 00472e28  dd5e40               fstp qword ptr [esi + 0x40]
// 00472e2b  50                   push eax
// 00472e2c  8d4c2444             lea ecx, [esp + 0x44]
// 00472e30  ff1500e58900         call dword ptr [0x89e500]
// 00472e36  dd442410             fld qword ptr [esp + 0x10]
// 00472e3a  8d4c2410             lea ecx, [esp + 0x10]
// 00472e3e  dd5e48               fstp qword ptr [esi + 0x48]
// 00472e41  51                   push ecx
// 00472e42  8d4c2444             lea ecx, [esp + 0x44]
// 00472e46  ff1500e58900         call dword ptr [0x89e500]
// 00472e4c  dd442410             fld qword ptr [esp + 0x10]
// 00472e50  8d542410             lea edx, [esp + 0x10]
// 00472e54  dd5e50               fstp qword ptr [esi + 0x50]
// 00472e57  52                   push edx
// 00472e58  8d4c2444             lea ecx, [esp + 0x44]
// 00472e5c  ff1500e58900         call dword ptr [0x89e500]
// 00472e62  dd442410             fld qword ptr [esp + 0x10]
// 00472e66  8d442410             lea eax, [esp + 0x10]
// 00472e6a  dd5e58               fstp qword ptr [esi + 0x58]
// 00472e6d  50                   push eax
// 00472e6e  8d4c2444             lea ecx, [esp + 0x44]
// 00472e72  ff1500e58900         call dword ptr [0x89e500]
// 00472e78  dd442410             fld qword ptr [esp + 0x10]
// 00472e7c  8d4c2410             lea ecx, [esp + 0x10]
// 00472e80  dd5e60               fstp qword ptr [esi + 0x60]
// 00472e83  51                   push ecx
// 00472e84  8d4c2444             lea ecx, [esp + 0x44]
// 00472e88  ff1500e58900         call dword ptr [0x89e500]
// 00472e8e  dd442410             fld qword ptr [esp + 0x10]
// 00472e92  68d0070000           push 0x7d0
// 00472e97  8d94242c010000       lea edx, [esp + 0x12c]
// 00472e9e  dd5e68               fstp qword ptr [esi + 0x68]
// 00472ea1  52                   push edx
// 00472ea2  8d4c2448             lea ecx, [esp + 0x48]
// 00472ea6  ff15fce48900         call dword ptr [0x89e4fc]
// 00472eac  8d842428010000       lea eax, [esp + 0x128]
// 00472eb3  50                   push eax
// 00472eb4  8d4c2428             lea ecx, [esp + 0x28]
// 00472eb8  ff15b4e48900         call dword ptr [0x89e4b4]
// 00472ebe  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00472ec2  51                   push ecx
// 00472ec3  6a00                 push 0
// 00472ec5  68f8338b00           push 0x8b33f8
// 00472eca  8d4c2430             lea ecx, [esp + 0x30]
// 00472ece  c684244009000003     mov byte ptr [esp + 0x940], 3
// 00472ed6  ff15f8e48900         call dword ptr [0x89e4f8]
// 00472edc  50                   push eax
// 00472edd  8d9424d8000000       lea edx, [esp + 0xd8]
// 00472ee4  52                   push edx
// 00472ee5  8d4c2430             lea ecx, [esp + 0x30]
// 00472ee9  ff1570e48900         call dword ptr [0x89e470]
// 00472eef  8d8424d0000000       lea eax, [esp + 0xd0]
// 00472ef6  50                   push eax
// 00472ef7  8d4e70               lea ecx, [esi + 0x70]
// 00472efa  c684243809000004     mov byte ptr [esp + 0x938], 4
// 00472f02  ff1564e48900         call dword ptr [0x89e464]
// 00472f08  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 00472f0f  c684243409000003     mov byte ptr [esp + 0x934], 3
// 00472f17  ff15c4e48900         call dword ptr [0x89e4c4]
// 00472f1d  56                   push esi
// 00472f1e  8d8c24f4000000       lea ecx, [esp + 0xf4]
// 00472f25  e816040000           call 0x473340
// 00472f2a  8d4c2424             lea ecx, [esp + 0x24]
// 00472f2e  889c2434090000       mov byte ptr [esp + 0x934], bl
// 00472f35  ff15c4e48900         call dword ptr [0x89e4c4]
// 00472f3b  eb17                 jmp 0x472f54
// 00472f3d  68d0070000           push 0x7d0
// 00472f42  8d8c242c010000       lea ecx, [esp + 0x12c]
// 00472f49  51                   push ecx
// 00472f4a  8d4c2448             lea ecx, [esp + 0x48]
// 00472f4e  ff15fce48900         call dword ptr [0x89e4fc]
// 00472f54  8b542440             mov edx, dword ptr [esp + 0x40]
// 00472f58  8b4a04               mov ecx, dword ptr [edx + 4]
// 00472f5b  8d4c0c40             lea ecx, [esp + ecx + 0x40]
// 00472f5f  ff1508e58900         call dword ptr [0x89e508]
// 00472f65  84c0                 test al, al
// 00472f67  0f84a8fdffff         je 0x472d15
// 00472f6d  8d4c2440             lea ecx, [esp + 0x40]
// 00472f71  c684243409000000     mov byte ptr [esp + 0x934], 0
// 00472f79  ff1540e48900         call dword ptr [0x89e440]
// 00472f7f  57                   push edi
// 00472f80  8d8c24f4000000       lea ecx, [esp + 0xf4]
// 00472f87  e844010000           call 0x4730d0
// 00472f8c  8d8c24f0000000       lea ecx, [esp + 0xf0]
// 00472f93  c7842434090000ffffffff mov dword ptr [esp + 0x934], 0xffffffff
// 00472f9e  e89d020000           call 0x473240
// 00472fa3  8b8c242c090000       mov ecx, dword ptr [esp + 0x92c]
// 00472faa  5f                   pop edi
// 00472fab  5e                   pop esi
// 00472fac  64890d00000000       mov dword ptr fs:[0], ecx
// 00472fb3  5b                   pop ebx
// 00472fb4  8be5                 mov esp, ebp
// 00472fb6  5d                   pop ebp
// 00472fb7  c20400               ret 4
// copied from an identical function in another client (function ?parse@LDrawParser@LDraw2Lua@RBX@@QAEXAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@@Z)

// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <vector>
#include <fstream>
#include <ostream>

template <class T> class bstr {
public:
    __declspec(noinline) bstr(const T* p) { _Mysize = 0; }
    __declspec(noinline) bstr(const bstr& r) { _Mysize = r._Mysize; }
    __declspec(noinline) ~bstr() { _Mysize = 0; }
    __declspec(noinline) const T* c_str() const { return _Buf; }
    __declspec(noinline) unsigned int find_first_not_of(const T*, unsigned int) const { return _Mysize; }
    __declspec(noinline) bstr substr(unsigned int, unsigned int) const { return *this; }
    __declspec(noinline) bstr& operator=(const bstr& r) { _Mysize = r._Mysize; return *this; }
    unsigned int size() const { return _Mysize; }
    void* _Myaux;
    T _Buf[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};
extern template class __declspec(dllimport) bstr<char>;
typedef bstr<char> Str;

template <class T> struct IosBaseT { __declspec(noinline) bool eof() const { return sizeof(T) == 1; } int x; };
extern template struct __declspec(dllimport) IosBaseT<char>;
inline bool isEof(std::ios_base& b) { return reinterpret_cast<IosBaseT<char>&>(b).eof(); }

namespace RBX {
namespace LDraw2Lua {

class LDrawItem {
public:
    virtual ~LDrawItem();
};

class LDrawPart : public LDrawItem {
public:
    void* output;
    int type;
    int color;
    double values[12];
    Str name;

    LDrawPart(void* output);
    void setName(Str n) { name = n; }
};

class LDrawModel {
public:
    std::string name;
    std::vector<LDrawItem*> items;

    LDrawModel(const char* name);
    virtual ~LDrawModel();
    void add(LDrawItem* item);
    void writeLua(std::ostream& out) const;
};

extern void* luaOutput;

class LDrawParser {
public:
    virtual ~LDrawParser();
    Str fileName;

    void parse(std::ostream& out);
};

void LDrawParser::parse(std::ostream& out)
{
    out << "-- " << "Roblox LDraw2Lua Conversion" << "\n";
    out << "-- " << "FileName: " << fileName.c_str() << "\n";
    out << "\n";

    LDrawModel model("LDrawModel");
    {
        std::ifstream file(fileName.c_str());
        char buffer[2048];
        if (!isEof(file)) do {
            int type;
            file >> type;
            if (type == 1) {
                LDrawPart* part = new LDrawPart(luaOutput);
                part->type = 1;
                int color = -1;
                file >> color;
                part->color = color;
                double value = 0.0;
                file >> value; part->values[0] = value;
                file >> value; part->values[1] = value;
                file >> value; part->values[2] = value;
                file >> value; part->values[3] = value;
                file >> value; part->values[4] = value;
                file >> value; part->values[5] = value;
                file >> value; part->values[6] = value;
                file >> value; part->values[7] = value;
                file >> value; part->values[8] = value;
                file >> value; part->values[9] = value;
                file >> value; part->values[10] = value;
                file >> value; part->values[11] = value;
                file.getline(buffer, 2000);
                Str line(buffer);
                part->setName(line.substr(line.find_first_not_of(" ", 0), line.size()));
                model.add(part);
            } else {
                file.getline(buffer, 2000);
            }
        } while (!isEof(file));
    }
    model.writeLua(out);
}

}
}
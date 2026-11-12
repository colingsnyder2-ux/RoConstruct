// from server: 63% by EspClaude
// roc 2007-08 004d5420  unit: RBX::View::Part  size: 395 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d5420
// 004d5420  64a100000000         mov eax, dword ptr fs:[0]
// 004d5426  6aff                 push -1
// 004d5428  682bc87400           push 0x74c82b
// 004d542d  50                   push eax
// 004d542e  64892500000000       mov dword ptr fs:[0], esp
// 004d5435  83ec14               sub esp, 0x14
// 004d5438  53                   push ebx
// 004d5439  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 004d543d  33d2                 xor edx, edx
// 004d543f  8bc3                 mov eax, ebx
// 004d5441  f735406c8900         div dword ptr [0x896c40]
// 004d5447  a13c6c8900           mov eax, dword ptr [0x896c3c]
// 004d544c  55                   push ebp
// 004d544d  56                   push esi
// 004d544e  57                   push edi
// 004d544f  33ff                 xor edi, edi
// 004d5451  8b0490               mov eax, dword ptr [eax + edx*4]
// 004d5454  3bc7                 cmp eax, edi
// 004d5456  7418                 je 0x4d5470
// 004d5458  3918                 cmp dword ptr [eax], ebx
// 004d545a  7505                 jne 0x4d5461
// 004d545c  395804               cmp dword ptr [eax + 4], ebx
// 004d545f  746a                 je 0x4d54cb
// 004d5461  8b4018               mov eax, dword ptr [eax + 0x18]
// 004d5464  3bc7                 cmp eax, edi
// 004d5466  75f0                 jne 0x4d5458
// 004d5468  eb06                 jmp 0x4d5470
// 004d546a  8d9b00000000         lea ebx, [ebx]
// 004d5470  6a10                 push 0x10
// 004d5472  be60f07900           mov esi, 0x79f060
// 004d5477  6a28                 push 0x28
// 004d5479  8974241c             mov dword ptr [esp + 0x1c], esi
// 004d547d  c74424280a000000     mov dword ptr [esp + 0x28], 0xa
// 004d5485  897c2420             mov dword ptr [esp + 0x20], edi
// 004d5489  e8d2ab0200           call 0x500060
// 004d548e  6a28                 push 0x28
// 004d5490  57                   push edi
// 004d5491  50                   push eax
// 004d5492  89442430             mov dword ptr [esp + 0x30], eax
// 004d5496  e8e5b00200           call 0x500580
// 004d549b  83c414               add esp, 0x14
// 004d549e  8d4c2414             lea ecx, [esp + 0x14]
// 004d54a2  51                   push ecx
// 004d54a3  8d54243c             lea edx, [esp + 0x3c]
// 004d54a7  52                   push edx
// 004d54a8  b9346c8900           mov ecx, 0x896c34
// 004d54ad  897c2434             mov dword ptr [esp + 0x34], edi
// 004d54b1  e8eaefffff           call 0x4d44a0
// 004d54b6  8d4c2414             lea ecx, [esp + 0x14]
// 004d54ba  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004d54c2  89742414             mov dword ptr [esp + 0x14], esi
// 004d54c6  e815ccffff           call 0x4d20e0
// 004d54cb  33d2                 xor edx, edx
// 004d54cd  8bc3                 mov eax, ebx
// 004d54cf  f735406c8900         div dword ptr [0x896c40]
// 004d54d5  a13c6c8900           mov eax, dword ptr [0x896c3c]
// 004d54da  8b0490               mov eax, dword ptr [eax + edx*4]
// 004d54dd  3bc7                 cmp eax, edi
// 004d54df  7410                 je 0x4d54f1
// 004d54e1  3918                 cmp dword ptr [eax], ebx
// 004d54e3  7505                 jne 0x4d54ea
// 004d54e5  395804               cmp dword ptr [eax + 4], ebx
// 004d54e8  7407                 je 0x4d54f1
// 004d54ea  8b4018               mov eax, dword ptr [eax + 0x18]
// 004d54ed  3bc7                 cmp eax, edi
// 004d54ef  75f0                 jne 0x4d54e1
// 004d54f1  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 004d54f5  8d7008               lea esi, [eax + 8]
// 004d54f8  57                   push edi
// 004d54f9  8bce                 mov ecx, esi
// 004d54fb  e830abffff           call 0x4d0030
// 004d5500  84c0                 test al, al
// 004d5502  7548                 jne 0x4d554c
// 004d5504  68f0374600           push 0x4637f0
// 004d5509  6840ff4c00           push 0x4cff40
// 004d550e  6a01                 push 1
// 004d5510  6a04                 push 4
// 004d5512  8d4c2448             lea ecx, [esp + 0x48]
// 004d5516  51                   push ecx
// 004d5517  e8c0b61500           call 0x630bdc
// 004d551c  8d542438             lea edx, [esp + 0x38]
// 004d5520  52                   push edx
// 004d5521  57                   push edi
// 004d5522  8bce                 mov ecx, esi
// 004d5524  c744243401000000     mov dword ptr [esp + 0x34], 1
// 004d552c  e8bfc9ffff           call 0x4d1ef0
// 004d5531  68f0374600           push 0x4637f0
// 004d5536  6a01                 push 1
// 004d5538  6a04                 push 4
// 004d553a  8d442444             lea eax, [esp + 0x44]
// 004d553e  50                   push eax
// 004d553f  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 004d5547  e8abb51500           call 0x630af7
// 004d554c  57                   push edi
// 004d554d  8bce                 mov ecx, esi
// 004d554f  e84cabffff           call 0x4d00a0
// 004d5554  8be8                 mov ebp, eax
// 004d5556  8b4500               mov eax, dword ptr [ebp]
// 004d5559  85c0                 test eax, eax
// 004d555b  753b                 jne 0x4d5598
// 004d555d  6a50                 push 0x50
// 004d555f  e892a91500           call 0x62fef6
// 004d5564  83c404               add esp, 4
// 004d5567  89442410             mov dword ptr [esp + 0x10], eax
// 004d556b  85c0                 test eax, eax
// 004d556d  c744242c02000000     mov dword ptr [esp + 0x2c], 2
// 004d5575  740d                 je 0x4d5584
// 004d5577  53                   push ebx
// 004d5578  57                   push edi
// 004d5579  8bc8                 mov ecx, eax
// 004d557b  e8205b0100           call 0x4eb0a0
// 004d5580  8bf0                 mov esi, eax
// 004d5582  eb02                 jmp 0x4d5586
// 004d5584  33f6                 xor esi, esi
// 004d5586  56                   push esi
// 004d5587  8bcd                 mov ecx, ebp
// 004d5589  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 004d5591  e8daf9f9ff           call 0x474f70
// 004d5596  8bc6                 mov eax, esi
// 004d5598  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004d559c  5f                   pop edi
// 004d559d  5e                   pop esi
// 004d559e  5d                   pop ebp
// 004d559f  5b                   pop ebx
// 004d55a0  64890d00000000       mov dword ptr fs:[0], ecx
// 004d55a7  83c420               add esp, 0x20
// 004d55aa  c3                   ret 
// RBX::View::MeshFactory<Mesh,1>::create(const Vector3& size, RenderSurfaceTypes)
// (rbxgs RbxView/MeshFactory.h: static G3D::Table<RenderSurfaceTypes,
// G3D::Table<Vector3, Variations> > cache1; Variations holds one
// ReferenceCountedPointer<Render::Mesh>). G3D::Table (G3D 6.x Table.h):
// vptr, _size +4, bucket +8, numBuckets +0xc; Node: hashCode, entry{key,value}, next.
// new Mesh is 0x50 bytes; Mesh(size, surfaceTypes) is out of line.
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

namespace G3D {
class Vector3 { public: float x, y, z; bool operator==(const Vector3& other) const; };
namespace System {
    void* alignedMalloc(unsigned int bytes, unsigned int alignment);
    void memset(void* dst, int value, unsigned int numBytes);
}
template<class T>
class ReferenceCountedPointer {
public:
    T* m_pointer;
    ReferenceCountedPointer();
    ~ReferenceCountedPointer();
    ReferenceCountedPointer& operator=(T* x);
    T* getPointer() const { return m_pointer; }
};
}

namespace RBX {
enum RenderSurfaceTypes {};
}

inline unsigned int hashCode(const RBX::RenderSurfaceTypes& x) { return (unsigned int)x; }
unsigned int hashCode(const G3D::Vector3& v);

namespace G3D {
template<class Key, class Value>
class Table {
public:
    class Entry {
    public:
        Key    key;
        Value  value;
    };
private:
    class Node {
    public:
        unsigned int      hashCode;
        Entry             entry;
        Node*             next;
    };

    int     _size;
    Node**  bucket;
    int     numBuckets;

    void freeMemory();

public:
    Table() {
        numBuckets = 10;
        _size      = 0;
        bucket     = (Node**)System::alignedMalloc(sizeof(Node*) * numBuckets, 16);
        System::memset(bucket, 0, sizeof(Node*) * numBuckets);
    }

    virtual ~Table() {
        freeMemory();
    }

    void set(const Key& key, const Value& value);

    Value& get(const Key& key) const {
        unsigned int code = ::hashCode(key);
        unsigned int b = code % numBuckets;

        Node* node = bucket[b];

        while (node != 0) {
            if ((node->hashCode == code) && (node->entry.key == key)) {
                return node->entry.value;
            }
            node = node->next;
        }

        return node->entry.value;
    }

    bool containsKey(const Key& key) const {
        unsigned int code = ::hashCode(key);
        unsigned int b = code % numBuckets;

        Node* node = bucket[b];

        while (node != 0) {
            if ((node->hashCode == code) && (node->entry.key == key)) {
                return true;
            }
            node = node->next;
        }

        return false;
    }
};
}

namespace RBX {
namespace Render { class Mesh { public: virtual ~Mesh(); }; }
namespace View {

class PartMesh : public Render::Mesh {
public:
    PartMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes);
    char data[0x4c];
};

template<class Mesh, unsigned int numMeshes>
class MeshFactory
{
    struct Variations
    {
        G3D::ReferenceCountedPointer<Render::Mesh> meshes[numMeshes];
    };

    static G3D::Table<RenderSurfaceTypes, G3D::Table<G3D::Vector3, Variations> > cache1;
public:
    static Mesh* create(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes);
};

template<class Mesh, unsigned int numMeshes>
Mesh* MeshFactory<Mesh, numMeshes>::create(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes)
{
    if (!cache1.containsKey(surfaceTypes))
        cache1.set(surfaceTypes, G3D::Table<G3D::Vector3, Variations>());

    G3D::Table<G3D::Vector3, Variations>& sizeCache = cache1.get(surfaceTypes);

    if (!sizeCache.containsKey(size))
        sizeCache.set(size, Variations());

    Variations& variation = sizeCache.get(size);

    if (!variation.meshes[0].getPointer())
    {
        Mesh* mesh = new Mesh(size, surfaceTypes);
        variation.meshes[0] = mesh;
        return mesh;
    }
    return static_cast<Mesh*>(variation.meshes[0].getPointer());
}

template PartMesh* MeshFactory<PartMesh, 1>::create(const G3D::Vector3&, RenderSurfaceTypes);
}
}

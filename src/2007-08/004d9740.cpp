// from server: 99% by EspClaude
// from server: 100% by Espeon
// roc 2008-06 004dc590  unit: RBX::ViewNew::ViewG3D  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dc590
//
// 004dc590  8b4118               mov eax, dword ptr [ecx + 0x18]
// 004dc593  8b4804               mov ecx, dword ptr [eax + 4]
// 004dc596  80793500             cmp byte ptr [ecx + 0x35], 0
// 004dc59a  57                   push edi
// 004dc59b  8bf8                 mov edi, eax
// 004dc59d  7577                 jne 0x4dc616
// 004dc59f  8b542408             mov edx, dword ptr [esp + 8]
// 004dc5a3  56                   push esi
// 004dc5a4  d902                 fld dword ptr [edx]
// 004dc5a6  d8590c               fcomp dword ptr [ecx + 0xc]
// 004dc5a9  dfe0                 fnstsw ax
// 004dc5ab  f6c441               test ah, 0x41
// 004dc5ae  7454                 je 0x4dc604
// 004dc5b0  d902                 fld dword ptr [edx]
// 004dc5b2  d8590c               fcomp dword ptr [ecx + 0xc]
// 004dc5b5  dfe0                 fnstsw ax
// 004dc5b7  f6c405               test ah, 5
// 004dc5ba  7b4d                 jnp 0x4dc609
// 004dc5bc  d94204               fld dword ptr [edx + 4]
// 004dc5bf  d85910               fcomp dword ptr [ecx + 0x10]
// 004dc5c2  dfe0                 fnstsw ax
// 004dc5c4  f6c441               test ah, 0x41
// 004dc5c7  743b                 je 0x4dc604
// 004dc5c9  d94204               fld dword ptr [edx + 4]
// 004dc5cc  d85910               fcomp dword ptr [ecx + 0x10]
// 004dc5cf  dfe0                 fnstsw ax
// 004dc5d1  f6c405               test ah, 5
// 004dc5d4  7b33                 jnp 0x4dc609
// 004dc5d6  d94208               fld dword ptr [edx + 8]
// 004dc5d9  d85914               fcomp dword ptr [ecx + 0x14]
// 004dc5dc  dfe0                 fnstsw ax
// 004dc5de  f6c441               test ah, 0x41
// 004dc5e1  7421                 je 0x4dc604
// 004dc5e3  d94208               fld dword ptr [edx + 8]
// 004dc5e6  d85914               fcomp dword ptr [ecx + 0x14]
// 004dc5e9  dfe0                 fnstsw ax
// 004dc5eb  f6c405               test ah, 5
// 004dc5ee  7b19                 jnp 0x4dc609
// 004dc5f0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 004dc5f3  8b720c               mov esi, dword ptr [edx + 0xc]
// 004dc5f6  3bc6                 cmp eax, esi
// 004dc5f8  720a                 jb 0x4dc604
// 004dc5fa  770d                 ja 0x4dc609
// 004dc5fc  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 004dc5ff  3b4210               cmp eax, dword ptr [edx + 0x10]
// 004dc602  7d05                 jge 0x4dc609
// 004dc604  8b4908               mov ecx, dword ptr [ecx + 8]
// 004dc607  eb04                 jmp 0x4dc60d
// 004dc609  8bf9                 mov edi, ecx
// 004dc60b  8b09                 mov ecx, dword ptr [ecx]
// 004dc60d  80793500             cmp byte ptr [ecx + 0x35], 0
// 004dc611  7491                 je 0x4dc5a4
// 004dc613  8bc7                 mov eax, edi
// 004dc615  5e                   pop esi
// 004dc616  5f                   pop edi
// 004dc617  c20400               ret 4

// from server: 89% by colin
// from server: 83% by colin
// roc-cl: 50727
// roc-cl: 50727
struct Key
{
    float x, y, z;
    unsigned int u;
    int i;
    __forceinline bool operator<(const Key& k) const { if(x<k.x)return true;if(x>k.x)return false;if(y<k.y)return true;if(y>k.y)return false;if(z<k.z)return true;if(z>k.z)return false;if(u<k.u)return true;if(u>k.u)return false;if(i<k.i)return true;return false;}
};

struct Node
{
    Node* left;
    Node* parent;
    Node* right;
    Key key;
    char padding[21];
    unsigned char nil;
};

struct S
{
    char padding[24];
    Node* head;
    Node* f(const Key& key);
};

Node* S::f(const Key& key)
{
    Node* node = head->parent;
    Node* result = head;

    while (!node->nil)
    {
        if (node->key < key)
        {
            node = node->right;
        }
        else
        {
            result = node;
            node = node->left;
        }
    }

    return result;
}

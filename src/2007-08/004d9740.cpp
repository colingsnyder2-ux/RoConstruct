// from server: 100% by Intel
// from server: 99% by EspClaude
// roc 2007-08 004d9740  unit: RBX::View::MegaTextureProxy  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d9740
//
// 004d9740  8b4104               mov eax, dword ptr [ecx + 4]
// 004d9743  8b4804               mov ecx, dword ptr [eax + 4]
// 004d9746  80793500             cmp byte ptr [ecx + 0x35], 0
// 004d974a  57                   push edi
// 004d974b  8bf8                 mov edi, eax
// 004d974d  0f8583000000         jne 0x4d97d6
// 004d9753  8b542408             mov edx, dword ptr [esp + 8]
// 004d9757  56                   push esi
// 004d9758  d9410c               fld dword ptr [ecx + 0xc]
// 004d975b  d902                 fld dword ptr [edx]
// 004d975d  ded9                 fcompp 
// 004d975f  dfe0                 fnstsw ax
// 004d9761  f6c441               test ah, 0x41
// 004d9764  745e                 je 0x4d97c4
// 004d9766  d9410c               fld dword ptr [ecx + 0xc]
// 004d9769  d902                 fld dword ptr [edx]
// 004d976b  ded9                 fcompp 
// 004d976d  dfe0                 fnstsw ax
// 004d976f  f6c405               test ah, 5
// 004d9772  7b55                 jnp 0x4d97c9
// 004d9774  d94110               fld dword ptr [ecx + 0x10]
// 004d9777  d94204               fld dword ptr [edx + 4]
// 004d977a  ded9                 fcompp 
// 004d977c  dfe0                 fnstsw ax
// 004d977e  f6c441               test ah, 0x41
// 004d9781  7441                 je 0x4d97c4
// 004d9783  d94110               fld dword ptr [ecx + 0x10]
// 004d9786  d94204               fld dword ptr [edx + 4]
// 004d9789  ded9                 fcompp 
// 004d978b  dfe0                 fnstsw ax
// 004d978d  f6c405               test ah, 5
// 004d9790  7b37                 jnp 0x4d97c9
// 004d9792  d94114               fld dword ptr [ecx + 0x14]
// 004d9795  d94208               fld dword ptr [edx + 8]
// 004d9798  ded9                 fcompp 
// 004d979a  dfe0                 fnstsw ax
// 004d979c  f6c441               test ah, 0x41
// 004d979f  7423                 je 0x4d97c4
// 004d97a1  d94114               fld dword ptr [ecx + 0x14]
// 004d97a4  d94208               fld dword ptr [edx + 8]
// 004d97a7  ded9                 fcompp 
// 004d97a9  dfe0                 fnstsw ax
// 004d97ab  f6c405               test ah, 5
// 004d97ae  7b19                 jnp 0x4d97c9
// 004d97b0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 004d97b3  8b720c               mov esi, dword ptr [edx + 0xc]
// 004d97b6  3bc6                 cmp eax, esi
// 004d97b8  720a                 jb 0x4d97c4
// 004d97ba  770d                 ja 0x4d97c9
// 004d97bc  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 004d97bf  3b4210               cmp eax, dword ptr [edx + 0x10]
// 004d97c2  7d05                 jge 0x4d97c9
// 004d97c4  8b4908               mov ecx, dword ptr [ecx + 8]
// 004d97c7  eb04                 jmp 0x4d97cd
// 004d97c9  8bf9                 mov edi, ecx
// 004d97cb  8b09                 mov ecx, dword ptr [ecx]
// 004d97cd  80793500             cmp byte ptr [ecx + 0x35], 0
// 004d97d1  7485                 je 0x4d9758
// 004d97d3  8bc7                 mov eax, edi
// 004d97d5  5e                   pop esi
// 004d97d6  5f                   pop edi
// 004d97d7  c20400               ret 4

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
    char padding[4];
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

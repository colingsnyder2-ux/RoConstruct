// from server: 36% by Intel
// roc 2012-06 006cb1e0  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cb1e0
//
// 006cb1e0  53                   push ebx
// 006cb1e1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 006cb1e5  8b4308               mov eax, dword ptr [ebx + 8]
// 006cb1e8  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006cb1eb  8d0481               lea eax, [ecx + eax*4]
// 006cb1ee  89442408             mov dword ptr [esp + 8], eax
// 006cb1f2  39430c               cmp dword ptr [ebx + 0xc], eax
// 006cb1f5  746b                 je 0x6cb262
// 006cb1f7  55                   push ebp
// 006cb1f8  8b2d4c29b200         mov ebp, dword ptr [0xb2294c]
// 006cb1fe  56                   push esi
// 006cb1ff  8b742414             mov esi, dword ptr [esp + 0x14]
// 006cb203  57                   push edi
// 006cb204  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 006cb207  833f00               cmp dword ptr [edi], 0
// 006cb20a  744a                 je 0x6cb256
// 006cb20c  8d642400             lea esp, [esp]
// 006cb210  8b07                 mov eax, dword ptr [edi]
// 006cb212  85c0                 test eax, eax
// 006cb214  7405                 je 0x6cb21b
// 006cb216  83c0f8               add eax, -8
// 006cb219  eb02                 jmp 0x6cb21d
// 006cb21b  33c0                 xor eax, eax
// 006cb21d  8b08                 mov ecx, dword ptr [eax]
// 006cb21f  ffd5                 call ebp
// 006cb221  8bc8                 mov ecx, eax
// 006cb223  c1e803               shr eax, 3
// 006cb226  03c1                 add eax, ecx
// 006cb228  33d2                 xor edx, edx
// 006cb22a  f77608               div dword ptr [esi + 8]
// 006cb22d  8b4604               mov eax, dword ptr [esi + 4]
// 006cb230  8b0f                 mov ecx, dword ptr [edi]
// 006cb232  8d0490               lea eax, [eax + edx*4]
// 006cb235  8b11                 mov edx, dword ptr [ecx]
// 006cb237  8917                 mov dword ptr [edi], edx
// 006cb239  ff4b10               dec dword ptr [ebx + 0x10]
// 006cb23c  8b10                 mov edx, dword ptr [eax]
// 006cb23e  8911                 mov dword ptr [ecx], edx
// 006cb240  8908                 mov dword ptr [eax], ecx
// 006cb242  ff4610               inc dword ptr [esi + 0x10]
// 006cb245  3b460c               cmp eax, dword ptr [esi + 0xc]
// 006cb248  7303                 jae 0x6cb24d
// 006cb24a  89460c               mov dword ptr [esi + 0xc], eax
// 006cb24d  833f00               cmp dword ptr [edi], 0
// 006cb250  75be                 jne 0x6cb210
// 006cb252  8b442414             mov eax, dword ptr [esp + 0x14]
// 006cb256  83430c04             add dword ptr [ebx + 0xc], 4
// 006cb25a  39430c               cmp dword ptr [ebx + 0xc], eax
// 006cb25d  75a5                 jne 0x6cb204
// 006cb25f  5f                   pop edi
// 006cb260  5e                   pop esi
// 006cb261  5d                   pop ebp
// 006cb262  5b                   pop ebx
// 006cb263  c3                   ret

struct HashTableNode {
    HashTableNode* next;
};

struct HashTable {
    HashTableNode** buckets;
    int bucketCount;
    int size;
    int minBucket;
    int count;
};

struct RehashContext {
    HashTableNode** start;
    HashTableNode** end;
    HashTableNode** current;
    int count;
    HashTable* table;

    void rehash();
};

extern "C" unsigned int __stdcall GetHash(void* object);

void RehashContext::rehash() {
    HashTableNode** endPtr = end;
    HashTableNode** currentPtr = current;
    HashTableNode** endAddress = currentPtr + (endPtr - currentPtr);
    current = endAddress;

    if (currentPtr == endAddress) {
        return;
    }

    unsigned int hashFunc = *reinterpret_cast<unsigned int*>(0xB2294C);

    HashTable* table = this->table;
    HashTableNode** bucketArray = table->buckets;
    int bucketCount = table->bucketCount;
    int minBucket = table->minBucket;

    HashTableNode* node = *currentPtr;

    while (node != 0) {
        HashTableNode* nextNode = node->next;
        unsigned int hash = 0;
        if (nextNode != 0) {
            hash = reinterpret_cast<unsigned int>(nextNode) - 8;
        }

        unsigned int hashValue = reinterpret_cast<unsigned int(__stdcall*)(void*)>(hashFunc)(reinterpret_cast<void*>(hash));
        unsigned int ecx = hashValue;
        hashValue >>= 3;
        hashValue += ecx;

        unsigned int bucketIndex = hashValue % bucketCount;
        HashTableNode* bucketHead = bucketArray[bucketIndex];

        *currentPtr = nextNode;
        table->count--;

        node->next = bucketHead;
        bucketArray[bucketIndex] = node;
        table->size++;

        if (bucketIndex < static_cast<unsigned int>(minBucket)) {
            table->minBucket = bucketIndex;
        }

        node = *currentPtr;
    }

    currentPtr = currentPtr + 1;
    current = currentPtr;

    if (currentPtr != endAddress) {
        goto loop_start;
    }

loop_start:
    ;
}

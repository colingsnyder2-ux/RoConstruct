// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: G3D Table<K,V>::clearAndDeallocate-style routine (hash table with chained buckets).
struct TableNode {
    int pad[4];        // INFERRED: hash/key area before the value
    int value;         // +0x10, one element destroyed via eh vector destructor
    TableNode* next;   // +0x14
};

struct Table {
    int unused0;           // +0
    int _size;             // +4
    TableNode** bucket;    // +8
    int numBuckets;        // +0xc
};

// ??_M@YGXPAXIHP6EX0@Z@Z : eh vector destructor iterator
extern "C" void __stdcall fn_006a165b(void* ptr, unsigned size, int count, void(__thiscall* dtor)(void*));
// element destructor at 0x502a70 (thiscall)
extern "C" void __fastcall fn_00502a70(void* self, int unusedEdx);
// G3D::System::free
extern "C" void fn_00507d00(void* p);
// G3D::System::alignedFree
extern "C" void fn_00507d20(void* p);

extern "C" void __fastcall fn_004d7e30(Table* self, int unusedEdx)
{
    for (int i = 0; i < self->numBuckets; ++i) {
        TableNode* node = self->bucket[i];
        while (node) {
            TableNode* next = node->next;
            fn_006a165b(&node->value, 4, 1,
                        reinterpret_cast<void(__thiscall*)(void*)>(&fn_00502a70));
            fn_00507d00(node);
            node = next;
        }
    }
    fn_00507d20(self->bucket);
    self->bucket = 0;
    self->numBuckets = 0;
    self->_size = 0;
}

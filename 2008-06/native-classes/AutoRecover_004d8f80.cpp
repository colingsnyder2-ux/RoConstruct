// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826c14[];   // INFERRED: unnamed global at 0x00826c14 in the original
#include "G3D/System.h"

// INFERRED: the callee takes only ecx (the disassembly sets up no edx and pushes no stack args).
// Declared with a single fastcall argument so the compiler does not zero edx before the call.
extern "C" int __fastcall fn_004d7e30(void* self);

// INFERRED: the node payload is a polymorphic object at offset 8 whose vtable is reset before destruction.
struct Local_004d8f80Node {
    unsigned char data[8];
    void* vtable;
    unsigned char payload[12];
    Local_004d8f80Node* next;
};

// INFERRED: hash table container with buckets at +8 and bucketCount at +0xc.
struct Local_004d8f80Table {
    unsigned int field0;
    int size;
    Local_004d8f80Node** buckets;
    int bucketCount;
};

extern "C" void __fastcall fn_004d8f80(Local_004d8f80Table* self, int unusedEdx)
{
    for (int i = 0; i < self->bucketCount; ++i) {
        Local_004d8f80Node* node = self->buckets[i];
        while (node) {
            Local_004d8f80Node* next = node->next;
            node->vtable = (void*)((int)&g_00826c14);
            fn_004d7e30(&node->vtable);
            G3D::System::free(node);
            node = next;
        }
    }
    G3D::System::alignedFree(self->buckets);
    self->buckets = 0;
    self->bucketCount = 0;
    self->size = 0;
}

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00826bfc[];   // INFERRED: unnamed global at 0x00826bfc in the original
#include "G3D/System.h"

// INFERRED: the disassembly pushes no stack args and does not set edx before this call, so only ecx is passed.
extern "C" int __fastcall fn_004d7e30(void* self);

// INFERRED: file-local layout types; offsets taken from the disassembly
struct Local_004d8e30_Node {
    unsigned char data[8];
    void* vtable;            // +8
    unsigned char payload[12];
    Local_004d8e30_Node* next; // +0x18
};

struct Local_004d8e30 {
    unsigned int field0;
    int size;                // +4
    Local_004d8e30_Node** buckets; // +8
    int bucketCount;         // +0xc
};

extern "C" void __fastcall fn_004d8e30(Local_004d8e30* self, int unusedEdx)
{
    for (int i = 0; i < self->bucketCount; ++i) {
        Local_004d8e30_Node* node = self->buckets[i];
        while (node) {
            Local_004d8e30_Node* next = node->next;
            node->vtable = (void*)((int)&g_00826bfc);
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

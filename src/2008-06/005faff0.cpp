// from server: 100% by EspClaude
// from server: 94% by colin
// roc 2008-06 005faff0  unit: UString_sink::?$stream_buffer  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005faff0
//
// 005faff0  55                   push ebp
// 005faff1  56                   push esi
// 005faff2  57                   push edi
// 005faff3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005faff7  8be9                 mov ebp, ecx
// 005faff9  33f6                 xor esi, esi
// 005faffb  eb03                 jmp 0x5fb000
// 005faffd  8d4900               lea ecx, [ecx]
// 005fb000  8b07                 mov eax, dword ptr [edi]
// 005fb002  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fb005  56                   push esi
// 005fb006  8bcf                 mov ecx, edi
// 005fb008  ffd2                 call edx
// 005fb00a  85c0                 test eax, eax
// 005fb00c  742c                 je 0x5fb03a
// 005fb00e  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005fb011  ff4008               inc dword ptr [eax + 8]
// 005fb014  8339ff               cmp dword ptr [ecx], -1
// 005fb017  7421                 je 0x5fb03a
// 005fb019  3bc1                 cmp eax, ecx
// 005fb01b  741d                 je 0x5fb03a
// 005fb01d  83780400             cmp dword ptr [eax + 4], 0
// 005fb021  7d17                 jge 0x5fb03a
// 005fb023  8b5510               mov edx, dword ptr [ebp + 0x10]
// 005fb026  8d4d0c               lea ecx, [ebp + 0xc]
// 005fb029  89442410             mov dword ptr [esp + 0x10], eax
// 005fb02d  895004               mov dword ptr [eax + 4], edx
// 005fb030  8d442410             lea eax, [esp + 0x10]
// 005fb034  50                   push eax
// 005fb035  e886fbffff           call 0x5fabc0
// 005fb03a  46                   inc esi
// 005fb03b  83fe02               cmp esi, 2
// 005fb03e  7cc0                 jl 0x5fb000
// 005fb040  5f                   pop edi
// 005fb041  5e                   pop esi
// 005fb042  5d                   pop ebp
// 005fb043  c20400               ret 4

// from server: 88% by colin
// from server: 86% by king_originala
// roc 2008-06 005faff0  unit: UString_sink::?$stream_buffer  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005faff0
//
// 005faff0  55                   push ebp
// 005faff1  56                   push esi
// 005faff2  57                   push edi
// 005faff3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005faff7  8be9                 mov ebp, ecx
// 005faff9  33f6                 xor esi, esi
// 005faffb  eb03                 jmp 0x5fb000
// 005faffd  8d4900               lea ecx, [ecx]
// 005fb000  8b07                 mov eax, dword ptr [edi]
// 005fb002  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fb005  56                   push esi
// 005fb006  8bcf                 mov ecx, edi
// 005fb008  ffd2                 call edx
// 005fb00a  85c0                 test eax, eax
// 005fb00c  742c                 je 0x5fb03a
// 005fb00e  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005fb011  ff4008               inc dword ptr [eax + 8]
// 005fb014  8339ff               cmp dword ptr [ecx], -1
// 005fb017  7421                 je 0x5fb03a
// 005fb019  3bc1                 cmp eax, ecx
// 005fb01b  741d                 je 0x5fb03a
// 005fb01d  83780400             cmp dword ptr [eax + 4], 0
// 005fb021  7d17                 jge 0x5fb03a
// 005fb023  8b5510               mov edx, dword ptr [ebp + 0x10]
// 005fb026  8d4d0c               lea ecx, [ebp + 0xc]
// 005fb029  89442410             mov dword ptr [esp + 0x10], eax
// 005fb02d  895004               mov dword ptr [eax + 4], edx
// 005fb030  8d442410             lea eax, [esp + 0x10]
// 005fb034  50                   push eax
// 005fb035  e886fbffff           call 0x5fabc0
// 005fb03a  46                   inc esi
// 005fb03b  83fe02               cmp esi, 2
// 005fb03e  7cc0                 jl 0x5fb000
// 005fb040  5f                   pop edi
// 005fb041  5e                   pop esi
// 005fb042  5d                   pop ebp
// 005fb043  c20400               ret 4
#include <intrin.h>

struct NodeBase { int tag; };
struct Node : NodeBase {
    int index;
    int references;
    int reserved;
    Node* parent;
    bool isRootish() const { return parent->tag != -1 && this != parent; }
};

struct Source {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Node* get(int index);
};

struct NodeList {
    NodeBase** data;
    int size;
    int capacity;

    void append(NodeBase* const& node);
};

struct Sink {
    unsigned char reserved[12];
    NodeList nodes;

    void collect(Source* source);
};

void Sink::collect(Source* source)
{
    for (int i = 0; i < 2; ++i) {
        Node* node = source->get(i);
        if (node) {
            ++node->references;
            bool ok = node->isRootish() && node->index < 0;
            if (ok) {
                NodeList* list = &nodes;
                NodeBase* base = node;
                node->index = list->size;
                list->append(base);
            }
        }
    }
}

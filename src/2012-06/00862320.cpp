// from server: 100% by Xemicl
// roc 2012-06 00862320  unit: boost::iostreams::DUinput::V?$basic_null_device::?$stream_buffer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00862320
//
// 00862320  8b442404             mov eax, dword ptr [esp + 4]
// 00862324  83f801               cmp eax, 1
// 00862327  751e                 jne 0x862347
// 00862329  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0086232c  c70000000000         mov dword ptr [eax], 0
// 00862332  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00862335  c70200000000         mov dword ptr [edx], 0
// 0086233b  8b4130               mov eax, dword ptr [ecx + 0x30]
// 0086233e  c70000000000         mov dword ptr [eax], 0
// 00862344  c20400               ret 4
// 00862347  83f803               cmp eax, 3
// 0086234a  750a                 jne 0x862356
// 0086234c  83c140               add ecx, 0x40
// 0086234f  51                   push ecx
// 00862350  e83b84d3ff           call 0x59a790
// 00862355  59                   pop ecx
// 00862356  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000018@@QAEXH@Z)

namespace ns_ROCX000018 {
// from server: 91% by atomic.potato
// roc 2009-06 006867b0  unit: boost::iostreams::DUinput::V?$basic_null_device::?$stream_buffer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006867b0
//
// 006867b0  8b442404             mov eax, dword ptr [esp + 4]
// 006867b4  83f801               cmp eax, 1
// 006867b7  751e                 jne 0x6867d7
// 006867b9  8b4110               mov eax, dword ptr [ecx + 0x10]
// 006867bc  c70000000000         mov dword ptr [eax], 0
// 006867c2  8b5120               mov edx, dword ptr [ecx + 0x20]
// 006867c5  c70200000000         mov dword ptr [edx], 0
// 006867cb  8b4130               mov eax, dword ptr [ecx + 0x30]
// 006867ce  c70000000000         mov dword ptr [eax], 0
// 006867d4  c20400               ret 4
// 006867d7  83f803               cmp eax, 3
// 006867da  750a                 jne 0x6867e6
// 006867dc  83c140               add ecx, 0x40
// 006867df  51                   push ecx
// 006867e0  e8fbe1feff           call 0x6749e0
// 006867e5  59                   pop ecx
// 006867e6  c20400               ret 4

struct C;
extern void fn_ROCX000018_006749e0(C*);

struct S {
    char pad0[0x10];
    int* p10;
    char pad1[0x0C];
    int* p20;
    char pad2[0x0C];
    int* p30;
    char pad3[0x0C];
    char c40[4];
    void f(int);
};

void S::f(int a)
{
    if (a == 1) {
        *p10 = 0;
        *p20 = 0;
        *p30 = 0;
        return;
    }
    if (a == 3) {
        fn_ROCX000018_006749e0((C*)c40);
    }
}
}

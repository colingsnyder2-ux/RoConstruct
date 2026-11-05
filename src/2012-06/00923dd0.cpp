// from server: 59% by atomic.potato
// roc 2012-06 00923dd0  unit: RBX::SleepStage  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00923dd0
//
// 00923dd0  56                   push esi
// 00923dd1  57                   push edi
// 00923dd2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00923dd6  8bf1                 mov esi, ecx
// 00923dd8  8bcf                 mov ecx, edi
// 00923dda  e851faebff           call 0x7e3830
// 00923ddf  85c0                 test eax, eax
// 00923de1  7419                 je 0x923dfc
// 00923de3  83f803               cmp eax, 3
// 00923de6  7414                 je 0x923dfc
// 00923de8  83f802               cmp eax, 2
// 00923deb  740f                 je 0x923dfc
// 00923ded  83f801               cmp eax, 1
// 00923df0  740a                 je 0x923dfc
// 00923df2  6a02                 push 2
// 00923df4  57                   push edi
// 00923df5  8bce                 mov ecx, esi
// 00923df7  e8e4f6ffff           call 0x9234e0
// 00923dfc  5f                   pop edi
// 00923dfd  5e                   pop esi
// 00923dfe  c20400               ret 4
// standard library set<ptr> (function ??Econst_iterator@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAEAAV012@XZ)

struct RBX_SleepStage {
    int f(int);
};

extern "C" int __stdcall _call_7e3830();
extern "C" int __stdcall _call_9234e0();

int RBX_SleepStage::f(int param) {
    int edi;
    int esi;
    edi = param;
    esi = reinterpret_cast<int>(this);
    int ecx = edi;
    int eax = _call_7e3830();
    if (eax == 0) {
        goto label_00923dfc;
    }
    if (eax == 3) {
        goto label_00923dfc;
    }
    if (eax == 2) {
        goto label_00923dfc;
    }
    if (eax == 1) {
        goto label_00923dfc;
    }
    int* esp = &param - 1;
    *esp = 2;
    *(esp - 1) = edi;
    ecx = esi;
    _call_9234e0();
label_00923dfc:
    return 0;
}

// from server: 100% by EspClaude
// from server: 91% by EspClaude
// roc 2007-08 0044d9f0  unit: ExitCommand  size: 1026 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044d9f0
//
// 0044d9f0  6aff                 push -1
// 0044d9f2  6879087400           push 0x740879
// 0044d9f7  64a100000000         mov eax, dword ptr fs:[0]
// 0044d9fd  50                   push eax
// 0044d9fe  51                   push ecx
// 0044d9ff  56                   push esi
// 0044da00  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044da05  33c4                 xor eax, esp
// 0044da07  50                   push eax
// 0044da08  8d44240c             lea eax, [esp + 0xc]
// 0044da0c  64a300000000         mov dword ptr fs:[0], eax
// 0044da12  8bf1                 mov esi, ecx
// 0044da14  89742408             mov dword ptr [esp + 8], esi
// 0044da18  8d8ef8060000         lea ecx, [esi + 0x6f8]
// 0044da1e  c74424143b000000     mov dword ptr [esp + 0x14], 0x3b
// 0044da26  e8d5141100           call 0x55ef00
// 0044da2b  8d8edc060000         lea ecx, [esi + 0x6dc]
// 0044da31  c64424143a           mov byte ptr [esp + 0x14], 0x3a
// 0044da36  e8c5141100           call 0x55ef00
// 0044da3b  8d8ec0060000         lea ecx, [esi + 0x6c0]
// 0044da41  c644241439           mov byte ptr [esp + 0x14], 0x39
// 0044da46  e8b5141100           call 0x55ef00
// 0044da4b  8d8ea4060000         lea ecx, [esi + 0x6a4]
// 0044da51  c644241438           mov byte ptr [esp + 0x14], 0x38
// 0044da56  e8a5141100           call 0x55ef00
// 0044da5b  8d8e88060000         lea ecx, [esi + 0x688]
// 0044da61  c644241437           mov byte ptr [esp + 0x14], 0x37
// 0044da66  e895141100           call 0x55ef00
// 0044da6b  8d8e6c060000         lea ecx, [esi + 0x66c]
// 0044da71  c644241436           mov byte ptr [esp + 0x14], 0x36
// 0044da76  e885141100           call 0x55ef00
// 0044da7b  8d8e50060000         lea ecx, [esi + 0x650]
// 0044da81  c644241435           mov byte ptr [esp + 0x14], 0x35
// 0044da86  e875141100           call 0x55ef00
// 0044da8b  8d8e34060000         lea ecx, [esi + 0x634]
// 0044da91  c644241434           mov byte ptr [esp + 0x14], 0x34
// 0044da96  e865141100           call 0x55ef00
// 0044da9b  8d8e18060000         lea ecx, [esi + 0x618]
// 0044daa1  c644241433           mov byte ptr [esp + 0x14], 0x33
// 0044daa6  e855141100           call 0x55ef00
// 0044daab  8d8efc050000         lea ecx, [esi + 0x5fc]
// 0044dab1  c644241432           mov byte ptr [esp + 0x14], 0x32
// 0044dab6  e845141100           call 0x55ef00
// 0044dabb  8d8ee0050000         lea ecx, [esi + 0x5e0]
// 0044dac1  c644241431           mov byte ptr [esp + 0x14], 0x31
// 0044dac6  e835141100           call 0x55ef00
// 0044dacb  8d8ec4050000         lea ecx, [esi + 0x5c4]
// 0044dad1  c644241430           mov byte ptr [esp + 0x14], 0x30
// 0044dad6  e825141100           call 0x55ef00
// 0044dadb  8d8ea8050000         lea ecx, [esi + 0x5a8]
// 0044dae1  c64424142f           mov byte ptr [esp + 0x14], 0x2f
// 0044dae6  e815141100           call 0x55ef00
// 0044daeb  8d8e8c050000         lea ecx, [esi + 0x58c]
// 0044daf1  c64424142e           mov byte ptr [esp + 0x14], 0x2e
// 0044daf6  e805141100           call 0x55ef00
// 0044dafb  8d8e70050000         lea ecx, [esi + 0x570]
// 0044db01  c64424142d           mov byte ptr [esp + 0x14], 0x2d
// 0044db06  e8f5131100           call 0x55ef00
// 0044db0b  8d8e54050000         lea ecx, [esi + 0x554]
// 0044db11  c64424142c           mov byte ptr [esp + 0x14], 0x2c
// 0044db16  e8e5131100           call 0x55ef00
// 0044db1b  8d8e38050000         lea ecx, [esi + 0x538]
// 0044db21  c64424142b           mov byte ptr [esp + 0x14], 0x2b
// 0044db26  e8d5131100           call 0x55ef00
// 0044db2b  8d8e1c050000         lea ecx, [esi + 0x51c]
// 0044db31  c64424142a           mov byte ptr [esp + 0x14], 0x2a
// 0044db36  e8c5131100           call 0x55ef00
// 0044db3b  8d8e00050000         lea ecx, [esi + 0x500]
// 0044db41  c644241429           mov byte ptr [esp + 0x14], 0x29
// 0044db46  e8b5131100           call 0x55ef00
// 0044db4b  8d8ee4040000         lea ecx, [esi + 0x4e4]
// 0044db51  c644241428           mov byte ptr [esp + 0x14], 0x28
// 0044db56  e8a5131100           call 0x55ef00
// 0044db5b  8d8ec8040000         lea ecx, [esi + 0x4c8]
// 0044db61  c644241427           mov byte ptr [esp + 0x14], 0x27
// 0044db66  e895131100           call 0x55ef00
// 0044db6b  8d8eac040000         lea ecx, [esi + 0x4ac]
// 0044db71  c644241426           mov byte ptr [esp + 0x14], 0x26
// 0044db76  e885131100           call 0x55ef00
// 0044db7b  8d8e90040000         lea ecx, [esi + 0x490]
// 0044db81  c644241425           mov byte ptr [esp + 0x14], 0x25
// 0044db86  e875131100           call 0x55ef00
// 0044db8b  8d8e74040000         lea ecx, [esi + 0x474]
// 0044db91  c644241424           mov byte ptr [esp + 0x14], 0x24
// 0044db96  e865131100           call 0x55ef00
// 0044db9b  8d8e58040000         lea ecx, [esi + 0x458]
// 0044dba1  c644241423           mov byte ptr [esp + 0x14], 0x23
// 0044dba6  e855131100           call 0x55ef00
// 0044dbab  8d8e3c040000         lea ecx, [esi + 0x43c]
// 0044dbb1  c644241422           mov byte ptr [esp + 0x14], 0x22
// 0044dbb6  e845131100           call 0x55ef00
// 0044dbbb  8d8e2c040000         lea ecx, [esi + 0x42c]
// 0044dbc1  c644241421           mov byte ptr [esp + 0x14], 0x21
// 0044dbc6  e8e56f1100           call 0x564bb0
// 0044dbcb  8d8e1c040000         lea ecx, [esi + 0x41c]
// 0044dbd1  c644241420           mov byte ptr [esp + 0x14], 0x20
// 0044dbd6  e8d56f1100           call 0x564bb0
// 0044dbdb  8d8e10040000         lea ecx, [esi + 0x410]
// 0044dbe1  c64424141f           mov byte ptr [esp + 0x14], 0x1f
// 0044dbe6  e8c56f1100           call 0x564bb0
// 0044dbeb  8d8e00040000         lea ecx, [esi + 0x400]
// 0044dbf1  c64424141e           mov byte ptr [esp + 0x14], 0x1e
// 0044dbf6  e8b56f1100           call 0x564bb0
// 0044dbfb  8d8ee4030000         lea ecx, [esi + 0x3e4]
// 0044dc01  c64424141d           mov byte ptr [esp + 0x14], 0x1d
// 0044dc06  e8f5121100           call 0x55ef00
// 0044dc0b  8d8ec8030000         lea ecx, [esi + 0x3c8]
// 0044dc11  c64424141c           mov byte ptr [esp + 0x14], 0x1c
// 0044dc16  e8e5121100           call 0x55ef00
// 0044dc1b  8d8eac030000         lea ecx, [esi + 0x3ac]
// 0044dc21  c64424141b           mov byte ptr [esp + 0x14], 0x1b
// 0044dc26  e8d5121100           call 0x55ef00
// 0044dc2b  8d8e9c030000         lea ecx, [esi + 0x39c]
// 0044dc31  c64424141a           mov byte ptr [esp + 0x14], 0x1a
// 0044dc36  e8756f1100           call 0x564bb0
// 0044dc3b  8d8e8c030000         lea ecx, [esi + 0x38c]
// 0044dc41  c644241419           mov byte ptr [esp + 0x14], 0x19
// 0044dc46  e8656f1100           call 0x564bb0
// 0044dc4b  8d8e68030000         lea ecx, [esi + 0x368]
// 0044dc51  c644241418           mov byte ptr [esp + 0x14], 0x18
// 0044dc56  e825131100           call 0x55ef80
// 0044dc5b  8d8e44030000         lea ecx, [esi + 0x344]
// 0044dc61  c644241417           mov byte ptr [esp + 0x14], 0x17
// 0044dc66  e815131100           call 0x55ef80
// 0044dc6b  8d8e20030000         lea ecx, [esi + 0x320]
// 0044dc71  c644241416           mov byte ptr [esp + 0x14], 0x16
// 0044dc76  e805131100           call 0x55ef80
// 0044dc7b  8d8efc020000         lea ecx, [esi + 0x2fc]
// 0044dc81  c644241415           mov byte ptr [esp + 0x14], 0x15
// 0044dc86  e8f5121100           call 0x55ef80
// 0044dc8b  8d8ed8020000         lea ecx, [esi + 0x2d8]
// 0044dc91  c644241414           mov byte ptr [esp + 0x14], 0x14
// 0044dc96  e8e5121100           call 0x55ef80
// 0044dc9b  8d8eb0020000         lea ecx, [esi + 0x2b0]
// 0044dca1  c644241413           mov byte ptr [esp + 0x14], 0x13
// 0044dca6  e8d5121100           call 0x55ef80
// 0044dcab  8d8e88020000         lea ecx, [esi + 0x288]
// 0044dcb1  c644241412           mov byte ptr [esp + 0x14], 0x12
// 0044dcb6  e8c5121100           call 0x55ef80
// 0044dcbb  8d8e6c020000         lea ecx, [esi + 0x26c]
// 0044dcc1  c644241411           mov byte ptr [esp + 0x14], 0x11
// 0044dcc6  e835121100           call 0x55ef00
// 0044dccb  8d8e48020000         lea ecx, [esi + 0x248]
// 0044dcd1  c644241410           mov byte ptr [esp + 0x14], 0x10
// 0044dcd6  e8a5121100           call 0x55ef80
// 0044dcdb  8d8e20020000         lea ecx, [esi + 0x220]
// 0044dce1  c64424140f           mov byte ptr [esp + 0x14], 0xf
// 0044dce6  e895121100           call 0x55ef80
// 0044dceb  8d8ef8010000         lea ecx, [esi + 0x1f8]
// 0044dcf1  c64424140e           mov byte ptr [esp + 0x14], 0xe
// 0044dcf6  e885121100           call 0x55ef80
// 0044dcfb  8d8ed0010000         lea ecx, [esi + 0x1d0]
// 0044dd01  c64424140d           mov byte ptr [esp + 0x14], 0xd
// 0044dd06  e875121100           call 0x55ef80
// 0044dd0b  8d8eac010000         lea ecx, [esi + 0x1ac]
// 0044dd11  c64424140c           mov byte ptr [esp + 0x14], 0xc
// 0044dd16  e865121100           call 0x55ef80
// 0044dd1b  8d8e88010000         lea ecx, [esi + 0x188]
// 0044dd21  c64424140b           mov byte ptr [esp + 0x14], 0xb
// 0044dd26  e855121100           call 0x55ef80
// 0044dd2b  8d8e64010000         lea ecx, [esi + 0x164]
// 0044dd31  c64424140a           mov byte ptr [esp + 0x14], 0xa
// 0044dd36  e845121100           call 0x55ef80
// 0044dd3b  8d8e40010000         lea ecx, [esi + 0x140]
// 0044dd41  c644241409           mov byte ptr [esp + 0x14], 9
// 0044dd46  e835121100           call 0x55ef80
// 0044dd4b  8d8e30010000         lea ecx, [esi + 0x130]
// 0044dd51  c644241408           mov byte ptr [esp + 0x14], 8
// 0044dd56  e8556e1100           call 0x564bb0
// 0044dd5b  8d8e20010000         lea ecx, [esi + 0x120]
// 0044dd61  c644241407           mov byte ptr [esp + 0x14], 7
// 0044dd66  e8456e1100           call 0x564bb0
// 0044dd6b  8d8efc000000         lea ecx, [esi + 0xfc]
// 0044dd71  c644241406           mov byte ptr [esp + 0x14], 6
// 0044dd76  e805121100           call 0x55ef80
// 0044dd7b  8d8ed8000000         lea ecx, [esi + 0xd8]
// 0044dd81  c644241405           mov byte ptr [esp + 0x14], 5
// 0044dd86  e8f5111100           call 0x55ef80
// 0044dd8b  8d8eb4000000         lea ecx, [esi + 0xb4]
// 0044dd91  c644241404           mov byte ptr [esp + 0x14], 4
// 0044dd96  e8e5111100           call 0x55ef80
// 0044dd9b  8d8e90000000         lea ecx, [esi + 0x90]
// 0044dda1  c644241403           mov byte ptr [esp + 0x14], 3
// 0044dda6  e8d5111100           call 0x55ef80
// 0044ddab  8d4e6c               lea ecx, [esi + 0x6c]
// 0044ddae  c644241402           mov byte ptr [esp + 0x14], 2
// 0044ddb3  e8c8111100           call 0x55ef80
// 0044ddb8  8d4e50               lea ecx, [esi + 0x50]
// 0044ddbb  c644241401           mov byte ptr [esp + 0x14], 1
// 0044ddc0  e83b111100           call 0x55ef00
// 0044ddc5  8d4e28               lea ecx, [esi + 0x28]
// 0044ddc8  c644241400           mov byte ptr [esp + 0x14], 0
// 0044ddcd  e8ae111100           call 0x55ef80
// 0044ddd2  8bce                 mov ecx, esi
// 0044ddd4  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0044dddc  e89f111100           call 0x55ef80
// 0044dde1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044dde5  64890d00000000       mov dword ptr fs:[0], ecx
// 0044ddec  59                   pop ecx
// 0044dded  5e                   pop esi
// 0044ddee  83c410               add esp, 0x10
// 0044ddf1  c3                   ret 

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727

template<int N, int I> struct Opaque { char data[N]; ~Opaque(); };
// 2007-08 member offsets read from the target's lea ecx,[esi+X] destructor calls (states 0..0x3b)
struct CRobloxDoc {
    ~CRobloxDoc();
    Opaque<0x28, 0> m0; // 0x0
    Opaque<0x28, 1> m1; // 0x28
    Opaque<0x1c, 2> m2; // 0x50
    Opaque<0x24, 3> m3; // 0x6c
    Opaque<0x24, 4> m4; // 0x90
    Opaque<0x24, 5> m5; // 0xb4
    Opaque<0x24, 6> m6; // 0xd8
    Opaque<0x24, 7> m7; // 0xfc
    Opaque<0x10, 8> m8; // 0x120
    Opaque<0x10, 9> m9; // 0x130
    Opaque<0x24, 10> m10; // 0x140
    Opaque<0x24, 11> m11; // 0x164
    Opaque<0x24, 12> m12; // 0x188
    Opaque<0x24, 13> m13; // 0x1ac
    Opaque<0x28, 14> m14; // 0x1d0
    Opaque<0x28, 15> m15; // 0x1f8
    Opaque<0x28, 16> m16; // 0x220
    Opaque<0x24, 17> m17; // 0x248
    Opaque<0x1c, 18> m18; // 0x26c
    Opaque<0x28, 19> m19; // 0x288
    Opaque<0x28, 20> m20; // 0x2b0
    Opaque<0x24, 21> m21; // 0x2d8
    Opaque<0x24, 22> m22; // 0x2fc
    Opaque<0x24, 23> m23; // 0x320
    Opaque<0x24, 24> m24; // 0x344
    Opaque<0x24, 25> m25; // 0x368
    Opaque<0x10, 26> m26; // 0x38c
    Opaque<0x10, 27> m27; // 0x39c
    Opaque<0x1c, 28> m28; // 0x3ac
    Opaque<0x1c, 29> m29; // 0x3c8
    Opaque<0x1c, 30> m30; // 0x3e4
    Opaque<0x10, 31> m31; // 0x400
    Opaque<0xc, 32> m32; // 0x410
    Opaque<0x10, 33> m33; // 0x41c
    Opaque<0x10, 34> m34; // 0x42c
    Opaque<0x1c, 35> m35; // 0x43c
    Opaque<0x1c, 36> m36; // 0x458
    Opaque<0x1c, 37> m37; // 0x474
    Opaque<0x1c, 38> m38; // 0x490
    Opaque<0x1c, 39> m39; // 0x4ac
    Opaque<0x1c, 40> m40; // 0x4c8
    Opaque<0x1c, 41> m41; // 0x4e4
    Opaque<0x1c, 42> m42; // 0x500
    Opaque<0x1c, 43> m43; // 0x51c
    Opaque<0x1c, 44> m44; // 0x538
    Opaque<0x1c, 45> m45; // 0x554
    Opaque<0x1c, 46> m46; // 0x570
    Opaque<0x1c, 47> m47; // 0x58c
    Opaque<0x1c, 48> m48; // 0x5a8
    Opaque<0x1c, 49> m49; // 0x5c4
    Opaque<0x1c, 50> m50; // 0x5e0
    Opaque<0x1c, 51> m51; // 0x5fc
    Opaque<0x1c, 52> m52; // 0x618
    Opaque<0x1c, 53> m53; // 0x634
    Opaque<0x1c, 54> m54; // 0x650
    Opaque<0x1c, 55> m55; // 0x66c
    Opaque<0x1c, 56> m56; // 0x688
    Opaque<0x1c, 57> m57; // 0x6a4
    Opaque<0x1c, 58> m58; // 0x6c0
    Opaque<0x1c, 59> m59; // 0x6dc
    Opaque<0x1c, 60> m60; // 0x6f8
};
CRobloxDoc::~CRobloxDoc() {}

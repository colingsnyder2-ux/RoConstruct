// from server: 100% by colin
// roc 2007-08 00465ce0  unit: DxUserInput  size: 665 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00465ce0
//
// 00465ce0  803dfcce8b0000       cmp byte ptr [0x8bcefc], 0
// 00465ce7  0f8580020000         jne 0x465f6d
// 00465ced  57                   push edi
// 00465cee  33c0                 xor eax, eax
// 00465cf0  b943010000           mov ecx, 0x143
// 00465cf5  bff0c98b00           mov edi, 0x8bc9f0
// 00465cfa  f3ab                 rep stosd dword ptr es:[edi], eax
// 00465cfc  b80d000000           mov eax, 0xd
// 00465d01  a324ca8b00           mov dword ptr [0x8bca24], eax
// 00465d06  a32cce8b00           mov dword ptr [0x8bce2c], eax
// 00465d0b  8b442408             mov eax, dword ptr [esp + 8]
// 00465d0f  c705e0ce8b002a000000 mov dword ptr [0x8bcee0], 0x2a
// 00465d19  c705e4ce8b002c000000 mov dword ptr [0x8bcee4], 0x2c
// 00465d23  c7055cca8b001b000000 mov dword ptr [0x8bca5c], 0x1b
// 00465d2d  c70510ca8b0008000000 mov dword ptr [0x8bca10], 8
// 00465d37  c70514ca8b0009000000 mov dword ptr [0x8bca14], 9
// 00465d41  c705b8ce8b00a2000000 mov dword ptr [0x8bceb8], 0xa2
// 00465d4b  c705b0ce8b00a0000000 mov dword ptr [0x8bceb0], 0xa0
// 00465d55  c70560cb8b00e2000000 mov dword ptr [0x8bcb60], 0xe2
// 00465d5f  c705acce8b00a1000000 mov dword ptr [0x8bceac], 0xa1
// 00465d69  c70520ce8b006a000000 mov dword ptr [0x8bce20], 0x6a
// 00465d73  c705c0ce8b00a4000000 mov dword ptr [0x8bcec0], 0xa4
// 00465d7d  c70570ca8b0020000000 mov dword ptr [0x8bca70], 0x20
// 00465d87  c705a4ce8b0014000000 mov dword ptr [0x8bcea4], 0x14
// 00465d91  c70558ce8b0070000000 mov dword ptr [0x8bce58], 0x70
// 00465d9b  c7055cce8b0071000000 mov dword ptr [0x8bce5c], 0x71
// 00465da5  c70560ce8b0072000000 mov dword ptr [0x8bce60], 0x72
// 00465daf  c70564ce8b0073000000 mov dword ptr [0x8bce64], 0x73
// 00465db9  c70568ce8b0074000000 mov dword ptr [0x8bce68], 0x74
// 00465dc3  c7056cce8b0075000000 mov dword ptr [0x8bce6c], 0x75
// 00465dcd  c70570ce8b0076000000 mov dword ptr [0x8bce70], 0x76
// 00465dd7  c70574ce8b0077000000 mov dword ptr [0x8bce74], 0x77
// 00465de1  c70578ce8b0078000000 mov dword ptr [0x8bce78], 0x78
// 00465deb  c7057cce8b0079000000 mov dword ptr [0x8bce7c], 0x79
// 00465df5  c705a0ce8b0090000000 mov dword ptr [0x8bcea0], 0x90
// 00465dff  c705a8ce8b0091000000 mov dword ptr [0x8bcea8], 0x91
// 00465e09  c7050cce8b0067000000 mov dword ptr [0x8bce0c], 0x67
// 00465e13  c70510ce8b0068000000 mov dword ptr [0x8bce10], 0x68
// 00465e1d  c70514ce8b0069000000 mov dword ptr [0x8bce14], 0x69
// 00465e27  c70524ce8b006d000000 mov dword ptr [0x8bce24], 0x6d
// 00465e31  c70500ce8b0064000000 mov dword ptr [0x8bce00], 0x64
// 00465e3b  c70504ce8b0065000000 mov dword ptr [0x8bce04], 0x65
// 00465e45  c70508ce8b0066000000 mov dword ptr [0x8bce08], 0x66
// 00465e4f  c70528ce8b006b000000 mov dword ptr [0x8bce28], 0x6b
// 00465e59  c705f4cd8b0061000000 mov dword ptr [0x8bcdf4], 0x61
// 00465e63  c705f8cd8b0062000000 mov dword ptr [0x8bcdf8], 0x62
// 00465e6d  c705fccd8b0063000000 mov dword ptr [0x8bcdfc], 0x63
// 00465e77  c705f0cd8b0060000000 mov dword ptr [0x8bcdf0], 0x60
// 00465e81  c70518ce8b006e000000 mov dword ptr [0x8bce18], 0x6e
// 00465e8b  c70580ce8b007a000000 mov dword ptr [0x8bce80], 0x7a
// 00465e95  c70584ce8b007b000000 mov dword ptr [0x8bce84], 0x7b
// 00465e9f  c70588ce8b007c000000 mov dword ptr [0x8bce88], 0x7c
// 00465ea9  c7058cce8b007d000000 mov dword ptr [0x8bce8c], 0x7d
// 00465eb3  c70590ce8b007e000000 mov dword ptr [0x8bce90], 0x7e
// 00465ebd  c705b4ce8b00a3000000 mov dword ptr [0x8bceb4], 0xa3
// 00465ec7  c7051cce8b006f000000 mov dword ptr [0x8bce1c], 0x6f
// 00465ed1  c705bcce8b00a5000000 mov dword ptr [0x8bcebc], 0xa5
// 00465edb  c70548ce8b0024000000 mov dword ptr [0x8bce48], 0x24
// 00465ee5  c70534ce8b0026000000 mov dword ptr [0x8bce34], 0x26
// 00465eef  c70550ce8b0021000000 mov dword ptr [0x8bce50], 0x21
// 00465ef9  c70540ce8b0025000000 mov dword ptr [0x8bce40], 0x25
// 00465f03  c7053cce8b0027000000 mov dword ptr [0x8bce3c], 0x27
// 00465f0d  c7054cce8b0023000000 mov dword ptr [0x8bce4c], 0x23
// 00465f17  c70538ce8b0028000000 mov dword ptr [0x8bce38], 0x28
// 00465f21  c70554ce8b0022000000 mov dword ptr [0x8bce54], 0x22
// 00465f2b  c70544ce8b002d000000 mov dword ptr [0x8bce44], 0x2d
// 00465f35  c705eccb8b002e000000 mov dword ptr [0x8bcbec], 0x2e
// 00465f3f  c705c8ce8b005b000000 mov dword ptr [0x8bcec8], 0x5b
// 00465f49  c705c4ce8b005c000000 mov dword ptr [0x8bcec4], 0x5c
// 00465f53  c705ecce8b005d000000 mov dword ptr [0x8bceec], 0x5d
// 00465f5d  8b0485f0c98b00       mov eax, dword ptr [eax*4 + 0x8bc9f0]
// 00465f64  c605fcce8b0001       mov byte ptr [0x8bcefc], 1
// 00465f6b  5f                   pop edi
// 00465f6c  c3                   ret 
// 00465f6d  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00465f71  8b048df0c98b00       mov eax, dword ptr [ecx*4 + 0x8bc9f0]
// 00465f78  c3                   ret 
// copied from an identical function in another client (function ?getKeyCode@@YAHH@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
static unsigned char g_initialized;
static int g_keyMap[0x143];

int __cdecl getKeyCode(int index)
{
    if (!g_initialized)
    {
        int i;
        for (i = 0; i < 0x143; ++i)
            g_keyMap[i] = 0;
        g_keyMap[0xd] = 0xd;
        g_keyMap[0x10f] = 0xd;
        g_keyMap[0x13c] = 0x2a;
        g_keyMap[0x13d] = 0x2c;
        g_keyMap[0x1b] = 0x1b;
        g_keyMap[0x8] = 0x8;
        g_keyMap[0x9] = 0x9;
        g_keyMap[0x132] = 0xa2;
        g_keyMap[0x130] = 0xa0;
        g_keyMap[0x5c] = 0xe2;
        g_keyMap[0x12f] = 0xa1;
        g_keyMap[0x10c] = 0x6a;
        g_keyMap[0x134] = 0xa4;
        g_keyMap[0x20] = 0x20;
        g_keyMap[0x12d] = 0x14;
        g_keyMap[0x11a] = 0x70;
        g_keyMap[0x11b] = 0x71;
        g_keyMap[0x11c] = 0x72;
        g_keyMap[0x11d] = 0x73;
        g_keyMap[0x11e] = 0x74;
        g_keyMap[0x11f] = 0x75;
        g_keyMap[0x120] = 0x76;
        g_keyMap[0x121] = 0x77;
        g_keyMap[0x122] = 0x78;
        g_keyMap[0x123] = 0x79;
        g_keyMap[0x12c] = 0x90;
        g_keyMap[0x12e] = 0x91;
        g_keyMap[0x107] = 0x67;
        g_keyMap[0x108] = 0x68;
        g_keyMap[0x109] = 0x69;
        g_keyMap[0x10d] = 0x6d;
        g_keyMap[0x104] = 0x64;
        g_keyMap[0x105] = 0x65;
        g_keyMap[0x106] = 0x66;
        g_keyMap[0x10e] = 0x6b;
        g_keyMap[0x101] = 0x61;
        g_keyMap[0x102] = 0x62;
        g_keyMap[0x103] = 0x63;
        g_keyMap[0x100] = 0x60;
        g_keyMap[0x10a] = 0x6e;
        g_keyMap[0x124] = 0x7a;
        g_keyMap[0x125] = 0x7b;
        g_keyMap[0x126] = 0x7c;
        g_keyMap[0x127] = 0x7d;
        g_keyMap[0x128] = 0x7e;
        g_keyMap[0x131] = 0xa3;
        g_keyMap[0x10b] = 0x6f;
        g_keyMap[0x133] = 0xa5;
        g_keyMap[0x116] = 0x24;
        g_keyMap[0x111] = 0x26;
        g_keyMap[0x118] = 0x21;
        g_keyMap[0x114] = 0x25;
        g_keyMap[0x113] = 0x27;
        g_keyMap[0x117] = 0x23;
        g_keyMap[0x112] = 0x28;
        g_keyMap[0x119] = 0x22;
        g_keyMap[0x115] = 0x2d;
        g_keyMap[0x7f] = 0x2e;
        g_keyMap[0x136] = 0x5b;
        g_keyMap[0x135] = 0x5c;
        g_keyMap[0x13f] = 0x5d;
        g_initialized = 1;
    }
    return g_keyMap[index];
}
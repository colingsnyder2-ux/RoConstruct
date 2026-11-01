// from server: 100% by colin
// roc 2007-08 004806c0  unit: G3D::Win32Window  size: 5268 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004806c0
//
// 004806c0  8b442404             mov eax, dword ptr [esp + 4]
// 004806c4  3d00010000           cmp eax, 0x100
// 004806c9  7775                 ja 0x480740
// 004806cb  746d                 je 0x48073a
// 004806cd  3d80000000           cmp eax, 0x80
// 004806d2  0f87010d0000         ja 0x4813d9
// 004806d8  0fb68830144800       movzx ecx, byte ptr [eax + 0x481430]
// 004806df  ff248df4134800       jmp dword ptr [ecx*4 + 0x4813f4]
// 004806e6  b8aca47900           mov eax, 0x79a4ac
// 004806eb  c3                   ret 
// 004806ec  b89ca47900           mov eax, 0x79a49c
// 004806f1  c3                   ret 
// 004806f2  b884a47900           mov eax, 0x79a484
// 004806f7  c3                   ret 
// 004806f8  b870a47900           mov eax, 0x79a470
// 004806fd  c3                   ret 
// 004806fe  b860a47900           mov eax, 0x79a460
// 00480703  c3                   ret 
// 00480704  b854a47900           mov eax, 0x79a454
// 00480709  c3                   ret 
// 0048070a  b844a47900           mov eax, 0x79a444
// 0048070f  c3                   ret 
// 00480710  b834a47900           mov eax, 0x79a434
// 00480715  c3                   ret 
// 00480716  b820a47900           mov eax, 0x79a420
// 0048071b  c3                   ret 
// 0048071c  b810a47900           mov eax, 0x79a410
// 00480721  c3                   ret 
// 00480722  b804a47900           mov eax, 0x79a404
// 00480727  c3                   ret 
// 00480728  b8f8a37900           mov eax, 0x79a3f8
// 0048072d  c3                   ret 
// 0048072e  b8f0a37900           mov eax, 0x79a3f0
// 00480733  c3                   ret 
// 00480734  b8e8a37900           mov eax, 0x79a3e8
// 00480739  c3                   ret 
// 0048073a  b8dca37900           mov eax, 0x79a3dc
// 0048073f  c3                   ret 
// 00480740  3d00020000           cmp eax, 0x200
// 00480745  7736                 ja 0x48077d
// 00480747  742e                 je 0x480777
// 00480749  8d88fffeffff         lea ecx, [eax - 0x101]
// 0048074f  83f903               cmp ecx, 3
// 00480752  0f87810c0000         ja 0x4813d9
// 00480758  ff248db4144800       jmp dword ptr [ecx*4 + 0x4814b4]
// 0048075f  b8d4a37900           mov eax, 0x79a3d4
// 00480764  c3                   ret 
// 00480765  b8c8a37900           mov eax, 0x79a3c8
// 0048076a  c3                   ret 
// 0048076b  b8c0a37900           mov eax, 0x79a3c0
// 00480770  c3                   ret 
// 00480771  b8b8a37900           mov eax, 0x79a3b8
// 00480776  c3                   ret 
// 00480777  b8aca37900           mov eax, 0x79a3ac
// 0048077c  c3                   ret 
// 0048077d  3d00030000           cmp eax, 0x300
// 00480782  7748                 ja 0x4807cc
// 00480784  7440                 je 0x4807c6
// 00480786  8d88fffdffff         lea ecx, [eax - 0x201]
// 0048078c  83f906               cmp ecx, 6
// 0048078f  0f87440c0000         ja 0x4813d9
// 00480795  ff248dc4144800       jmp dword ptr [ecx*4 + 0x4814c4]
// 0048079c  b8a4a37900           mov eax, 0x79a3a4
// 004807a1  c3                   ret 
// 004807a2  b898a37900           mov eax, 0x79a398
// 004807a7  c3                   ret 
// 004807a8  b88ca37900           mov eax, 0x79a38c
// 004807ad  c3                   ret 
// 004807ae  b880a37900           mov eax, 0x79a380
// 004807b3  c3                   ret 
// 004807b4  b874a37900           mov eax, 0x79a374
// 004807b9  c3                   ret 
// 004807ba  b868a37900           mov eax, 0x79a368
// 004807bf  c3                   ret 
// 004807c0  b85ca37900           mov eax, 0x79a35c
// 004807c5  c3                   ret 
// 004807c6  b84ca37900           mov eax, 0x79a34c
// 004807cb  c3                   ret 
// 004807cc  3d00160000           cmp eax, 0x1600
// 004807d1  0f8778050000         ja 0x480d4f
// 004807d7  0f846c050000         je 0x480d49
// 004807dd  3d600c0000           cmp eax, 0xc60
// 004807e2  0f8759020000         ja 0x480a41
// 004807e8  0f844d020000         je 0x480a3b
// 004807ee  3d000b0000           cmp eax, 0xb00
// 004807f3  0f874b010000         ja 0x480944
// 004807f9  0f843f010000         je 0x48093e
// 004807ff  3d00050000           cmp eax, 0x500
// 00480804  0f8787000000         ja 0x480891
// 0048080a  747f                 je 0x48088b
// 0048080c  3d00040000           cmp eax, 0x400
// 00480811  7732                 ja 0x480845
// 00480813  742a                 je 0x48083f
// 00480815  8bc8                 mov ecx, eax
// 00480817  81e901030000         sub ecx, 0x301
// 0048081d  741a                 je 0x480839
// 0048081f  83e901               sub ecx, 1
// 00480822  740f                 je 0x480833
// 00480824  83e901               sub ecx, 1
// 00480827  0f85ac0b0000         jne 0x4813d9
// 0048082d  b834a37900           mov eax, 0x79a334
// 00480832  c3                   ret 
// 00480833  b824a37900           mov eax, 0x79a324
// 00480838  c3                   ret 
// 00480839  b80ca37900           mov eax, 0x79a30c
// 0048083e  c3                   ret 
// 0048083f  b8f4a27900           mov eax, 0x79a2f4
// 00480844  c3                   ret 
// 00480845  8d88fffbffff         lea ecx, [eax - 0x401]
// 0048084b  83f907               cmp ecx, 7
// 0048084e  0f87850b0000         ja 0x4813d9
// 00480854  ff248de0144800       jmp dword ptr [ecx*4 + 0x4814e0]
// 0048085b  b8e4a27900           mov eax, 0x79a2e4
// 00480860  c3                   ret 
// 00480861  b8d4a27900           mov eax, 0x79a2d4
// 00480866  c3                   ret 
// 00480867  b8c4a27900           mov eax, 0x79a2c4
// 0048086c  c3                   ret 
// 0048086d  b8b8a27900           mov eax, 0x79a2b8
// 00480872  c3                   ret 
// 00480873  b8b0a27900           mov eax, 0x79a2b0
// 00480878  c3                   ret 
// 00480879  b8a8a27900           mov eax, 0x79a2a8
// 0048087e  c3                   ret 
// 0048087f  b89ca27900           mov eax, 0x79a29c
// 00480884  c3                   ret 
// 00480885  b888a27900           mov eax, 0x79a288
// 0048088a  c3                   ret 
// 0048088b  b878a27900           mov eax, 0x79a278
// 00480890  c3                   ret 
// 00480891  3d00060000           cmp eax, 0x600
// 00480896  773c                 ja 0x4808d4
// 00480898  7434                 je 0x4808ce
// 0048089a  8d88fffaffff         lea ecx, [eax - 0x501]
// 004808a0  83f904               cmp ecx, 4
// 004808a3  0f87300b0000         ja 0x4813d9
// 004808a9  ff248d00154800       jmp dword ptr [ecx*4 + 0x481500]
// 004808b0  b864a27900           mov eax, 0x79a264
// 004808b5  c3                   ret 
// 004808b6  b84ca27900           mov eax, 0x79a24c
// 004808bb  c3                   ret 
// 004808bc  b838a27900           mov eax, 0x79a238
// 004808c1  c3                   ret 
// 004808c2  b824a27900           mov eax, 0x79a224
// 004808c7  c3                   ret 
// 004808c8  b810a27900           mov eax, 0x79a210
// 004808cd  c3                   ret 
// 004808ce  b808a27900           mov eax, 0x79a208
// 004808d3  c3                   ret 
// 004808d4  3d00080000           cmp eax, 0x800
// 004808d9  7736                 ja 0x480911
// 004808db  742e                 je 0x48090b
// 004808dd  8d88fff9ffff         lea ecx, [eax - 0x601]
// 004808e3  83f903               cmp ecx, 3
// 004808e6  0f87ed0a0000         ja 0x4813d9
// 004808ec  ff248d14154800       jmp dword ptr [ecx*4 + 0x481514]
// 004808f3  b800a27900           mov eax, 0x79a200
// 004808f8  c3                   ret 
// 004808f9  b8f4a17900           mov eax, 0x79a1f4
// 004808fe  c3                   ret 
// 004808ff  b8e0a17900           mov eax, 0x79a1e0
// 00480904  c3                   ret 
// 00480905  b8cca17900           mov eax, 0x79a1cc
// 0048090a  c3                   ret 
// 0048090b  b8bca17900           mov eax, 0x79a1bc
// 00480910  c3                   ret 
// 00480911  8bc8                 mov ecx, eax
// 00480913  81e901080000         sub ecx, 0x801
// 00480919  741d                 je 0x480938
// 0048091b  81e9ff000000         sub ecx, 0xff
// 00480921  740f                 je 0x480932
// 00480923  83e901               sub ecx, 1
// 00480926  0f85ad0a0000         jne 0x4813d9
// 0048092c  b8b4a17900           mov eax, 0x79a1b4
// 00480931  c3                   ret 
// 00480932  b8aca17900           mov eax, 0x79a1ac
// 00480937  c3                   ret 
// 00480938  b8a4a17900           mov eax, 0x79a1a4
// 0048093d  c3                   ret 
// 0048093e  b890a17900           mov eax, 0x79a190
// 00480943  c3                   ret 
// 00480944  3d110c0000           cmp eax, 0xc11
// 00480949  0f878a0a0000         ja 0x4813d9
// 0048094f  0f84e0000000         je 0x480a35
// 00480955  8d88fff4ffff         lea ecx, [eax - 0xb01]
// 0048095b  81f9f1000000         cmp ecx, 0xf1
// 00480961  0f87720a0000         ja 0x4813d9
// 00480967  0fb691a8154800       movzx edx, byte ptr [ecx + 0x4815a8]
// 0048096e  ff249524154800       jmp dword ptr [edx*4 + 0x481524]
// 00480975  b884a17900           mov eax, 0x79a184
// 0048097a  c3                   ret 
// 0048097b  b870a17900           mov eax, 0x79a170
// 00480980  c3                   ret 
// 00480981  b85ca17900           mov eax, 0x79a15c
// 00480986  c3                   ret 
// 00480987  b840a17900           mov eax, 0x79a140
// 0048098c  c3                   ret 
// 0048098d  b828a17900           mov eax, 0x79a128
// 00480992  c3                   ret 
// 00480993  b810a17900           mov eax, 0x79a110
// 00480998  c3                   ret 
// 00480999  b8eca07900           mov eax, 0x79a0ec
// 0048099e  c3                   ret 
// 0048099f  b8d0a07900           mov eax, 0x79a0d0
// 004809a4  c3                   ret 
// 004809a5  b8aca07900           mov eax, 0x79a0ac
// 004809aa  c3                   ret 
// 004809ab  b890a07900           mov eax, 0x79a090
// 004809b0  c3                   ret 
// 004809b1  b880a07900           mov eax, 0x79a080
// 004809b6  c3                   ret 
// 004809b7  b870a07900           mov eax, 0x79a070
// 004809bc  c3                   ret 
// 004809bd  b85ca07900           mov eax, 0x79a05c
// 004809c2  c3                   ret 
// 004809c3  b840a07900           mov eax, 0x79a040
// 004809c8  c3                   ret 
// 004809c9  b830a07900           mov eax, 0x79a030
// 004809ce  c3                   ret 
// 004809cf  b820a07900           mov eax, 0x79a020
// 004809d4  c3                   ret 
// 004809d5  b80ca07900           mov eax, 0x79a00c
// 004809da  c3                   ret 
// 004809db  b8f89f7900           mov eax, 0x799ff8
// 004809e0  c3                   ret 
// 004809e1  b8ec9f7900           mov eax, 0x799fec
// 004809e6  c3                   ret 
// 004809e7  b8dc9f7900           mov eax, 0x799fdc
// 004809ec  c3                   ret 
// 004809ed  b8cc9f7900           mov eax, 0x799fcc
// 004809f2  c3                   ret 
// 004809f3  b8bc9f7900           mov eax, 0x799fbc
// 004809f8  c3                   ret 
// 004809f9  b8ac9f7900           mov eax, 0x799fac
// 004809fe  c3                   ret 
// 004809ff  b89c9f7900           mov eax, 0x799f9c
// 00480a04  c3                   ret 
// 00480a05  b88c9f7900           mov eax, 0x799f8c
// 00480a0a  c3                   ret 
// 00480a0b  b8789f7900           mov eax, 0x799f78
// 00480a10  c3                   ret 
// 00480a11  b8649f7900           mov eax, 0x799f64
// 00480a16  c3                   ret 
// 00480a17  b8549f7900           mov eax, 0x799f54
// 00480a1c  c3                   ret 
// 00480a1d  b8449f7900           mov eax, 0x799f44
// 00480a22  c3                   ret 
// 00480a23  b8389f7900           mov eax, 0x799f38
// 00480a28  c3                   ret 
// 00480a29  b8309f7900           mov eax, 0x799f30
// 00480a2e  c3                   ret 
// 00480a2f  b81c9f7900           mov eax, 0x799f1c
// 00480a34  c3                   ret 
// 00480a35  b80c9f7900           mov eax, 0x799f0c
// 00480a3a  c3                   ret 
// 00480a3b  b8f89e7900           mov eax, 0x799ef8
// 00480a40  c3                   ret 
// 00480a41  3d800d0000           cmp eax, 0xd80
// 00480a46  0f879e000000         ja 0x480aea
// 00480a4c  0f8492000000         je 0x480ae4
// 00480a52  8d889ff3ffff         lea ecx, [eax - 0xc61]
// 00480a58  81f9d3000000         cmp ecx, 0xd3
// 00480a5e  0f8775090000         ja 0x4813d9
// 00480a64  0fb689ec164800       movzx ecx, byte ptr [ecx + 0x4816ec]
// 00480a6b  ff248d9c164800       jmp dword ptr [ecx*4 + 0x48169c]
// 00480a72  b8ec9e7900           mov eax, 0x799eec
// 00480a77  c3                   ret 
// 00480a78  b8e09e7900           mov eax, 0x799ee0
// 00480a7d  c3                   ret 
// 00480a7e  b8d49e7900           mov eax, 0x799ed4
// 00480a83  c3                   ret 
// 00480a84  b8c49e7900           mov eax, 0x799ec4
// 00480a89  c3                   ret 
// 00480a8a  b8b49e7900           mov eax, 0x799eb4
// 00480a8f  c3                   ret 
// 00480a90  b8a49e7900           mov eax, 0x799ea4
// 00480a95  c3                   ret 
// 00480a96  b8949e7900           mov eax, 0x799e94
// 00480a9b  c3                   ret 
// 00480a9c  b8849e7900           mov eax, 0x799e84
// 00480aa1  c3                   ret 
// 00480aa2  b8749e7900           mov eax, 0x799e74
// 00480aa7  c3                   ret 
// 00480aa8  b8649e7900           mov eax, 0x799e64
// 00480aad  c3                   ret 
// 00480aae  b8549e7900           mov eax, 0x799e54
// 00480ab3  c3                   ret 
// 00480ab4  b8409e7900           mov eax, 0x799e40
// 00480ab9  c3                   ret 
// 00480aba  b8309e7900           mov eax, 0x799e30
// 00480abf  c3                   ret 
// 00480ac0  b81c9e7900           mov eax, 0x799e1c
// 00480ac5  c3                   ret 
// 00480ac6  b8089e7900           mov eax, 0x799e08
// 00480acb  c3                   ret 
// 00480acc  b8f09d7900           mov eax, 0x799df0
// 00480ad1  c3                   ret 
// 00480ad2  b8dc9d7900           mov eax, 0x799ddc
// 00480ad7  c3                   ret 
// 00480ad8  b8c89d7900           mov eax, 0x799dc8
// 00480add  c3                   ret 
// 00480ade  b8b49d7900           mov eax, 0x799db4
// 00480ae3  c3                   ret 
// 00480ae4  b8a49d7900           mov eax, 0x799da4
// 00480ae9  c3                   ret 
// 00480aea  3d00100000           cmp eax, 0x1000
// 00480aef  0f87a1000000         ja 0x480b96
// 00480af5  0f8495000000         je 0x480b90
// 00480afb  8d8870f2ffff         lea ecx, [eax - 0xd90]
// 00480b01  83f951               cmp ecx, 0x51
// 00480b04  0f87cf080000         ja 0x4813d9
// 00480b0a  0fb69114184800       movzx edx, byte ptr [ecx + 0x481814]
// 00480b11  ff2495c0174800       jmp dword ptr [edx*4 + 0x4817c0]
// 00480b18  b8949d7900           mov eax, 0x799d94
// 00480b1d  c3                   ret 
// 00480b1e  b8849d7900           mov eax, 0x799d84
// 00480b23  c3                   ret 
// 00480b24  b8749d7900           mov eax, 0x799d74
// 00480b29  c3                   ret 
// 00480b2a  b85c9d7900           mov eax, 0x799d5c
// 00480b2f  c3                   ret 
// 00480b30  b8449d7900           mov eax, 0x799d44
// 00480b35  c3                   ret 
// 00480b36  b82c9d7900           mov eax, 0x799d2c
// 00480b3b  c3                   ret 
// 00480b3c  b8149d7900           mov eax, 0x799d14
// 00480b41  c3                   ret 
// 00480b42  b8009d7900           mov eax, 0x799d00
// 00480b47  c3                   ret 
// 00480b48  b8ec9c7900           mov eax, 0x799cec
// 00480b4d  c3                   ret 
// 00480b4e  b8dc9c7900           mov eax, 0x799cdc
// 00480b53  c3                   ret 
// 00480b54  b8cc9c7900           mov eax, 0x799ccc
// 00480b59  c3                   ret 
// 00480b5a  b8bc9c7900           mov eax, 0x799cbc
// 00480b5f  c3                   ret 
// 00480b60  b8a49c7900           mov eax, 0x799ca4
// 00480b65  c3                   ret 
// 00480b66  b88c9c7900           mov eax, 0x799c8c
// 00480b6b  c3                   ret 
// 00480b6c  b8749c7900           mov eax, 0x799c74
// 00480b71  c3                   ret 
// 00480b72  b85c9c7900           mov eax, 0x799c5c
// 00480b77  c3                   ret 
// 00480b78  b8489c7900           mov eax, 0x799c48
// 00480b7d  c3                   ret 
// 00480b7e  b8349c7900           mov eax, 0x799c34
// 00480b83  c3                   ret 
// 00480b84  b8249c7900           mov eax, 0x799c24
// 00480b89  c3                   ret 
// 00480b8a  b8149c7900           mov eax, 0x799c14
// 00480b8f  c3                   ret 
// 00480b90  b8009c7900           mov eax, 0x799c00
// 00480b95  c3                   ret 
// 00480b96  3d00110000           cmp eax, 0x1100
// 00480b9b  7736                 ja 0x480bd3
// 00480b9d  742e                 je 0x480bcd
// 00480b9f  8d88ffefffff         lea ecx, [eax - 0x1001]
// 00480ba5  83f904               cmp ecx, 4
// 00480ba8  0f872b080000         ja 0x4813d9
// 00480bae  ff248d68184800       jmp dword ptr [ecx*4 + 0x481868]
// 00480bb5  b8ec9b7900           mov eax, 0x799bec
// 00480bba  c3                   ret 
// 00480bbb  b8d09b7900           mov eax, 0x799bd0
// 00480bc0  c3                   ret 
// 00480bc1  b8b89b7900           mov eax, 0x799bb8
// 00480bc6  c3                   ret 
// 00480bc7  b8a49b7900           mov eax, 0x799ba4
// 00480bcc  c3                   ret 
// 00480bcd  b8949b7900           mov eax, 0x799b94
// 00480bd2  c3                   ret 
// 00480bd3  3d00140000           cmp eax, 0x1400
// 00480bd8  0f879a000000         ja 0x480c78
// 00480bde  0f848e000000         je 0x480c72
// 00480be4  3d00120000           cmp eax, 0x1200
// 00480be9  7727                 ja 0x480c12
// 00480beb  741f                 je 0x480c0c
// 00480bed  8bc8                 mov ecx, eax
// 00480bef  81e901110000         sub ecx, 0x1101
// 00480bf5  740f                 je 0x480c06
// 00480bf7  83e901               sub ecx, 1
// 00480bfa  0f85d9070000         jne 0x4813d9
// 00480c00  b8889b7900           mov eax, 0x799b88
// 00480c05  c3                   ret 
// 00480c06  b87c9b7900           mov eax, 0x799b7c
// 00480c0b  c3                   ret 
// 00480c0c  b8709b7900           mov eax, 0x799b70
// 00480c11  c3                   ret 
// 00480c12  3d00130000           cmp eax, 0x1300
// 00480c17  7748                 ja 0x480c61
// 00480c19  7440                 je 0x480c5b
// 00480c1b  8d88ffedffff         lea ecx, [eax - 0x1201]
// 00480c21  83f906               cmp ecx, 6
// 00480c24  0f87af070000         ja 0x4813d9
// 00480c2a  ff248d7c184800       jmp dword ptr [ecx*4 + 0x48187c]
// 00480c31  b8649b7900           mov eax, 0x799b64
// 00480c36  c3                   ret 
// 00480c37  b8589b7900           mov eax, 0x799b58
// 00480c3c  c3                   ret 
// 00480c3d  b84c9b7900           mov eax, 0x799b4c
// 00480c42  c3                   ret 
// 00480c43  b8389b7900           mov eax, 0x799b38
// 00480c48  c3                   ret 
// 00480c49  b8249b7900           mov eax, 0x799b24
// 00480c4e  c3                   ret 
// 00480c4f  b8149b7900           mov eax, 0x799b14
// 00480c54  c3                   ret 
// 00480c55  b8fc9a7900           mov eax, 0x799afc
// 00480c5a  c3                   ret 
// 00480c5b  b8f09a7900           mov eax, 0x799af0
// 00480c60  c3                   ret 
// 00480c61  3d01130000           cmp eax, 0x1301
// 00480c66  0f856d070000         jne 0x4813d9
// 00480c6c  b8d89a7900           mov eax, 0x799ad8
// 00480c71  c3                   ret 
// 00480c72  b8d09a7900           mov eax, 0x799ad0
// 00480c77  c3                   ret 
// 00480c78  3d00150000           cmp eax, 0x1500
// 00480c7d  775a                 ja 0x480cd9
// 00480c7f  7452                 je 0x480cd3
// 00480c81  8d88ffebffff         lea ecx, [eax - 0x1401]
// 00480c87  83f909               cmp ecx, 9
// 00480c8a  0f8749070000         ja 0x4813d9
// 00480c90  ff248d98184800       jmp dword ptr [ecx*4 + 0x481898]
// 00480c97  b8bc9a7900           mov eax, 0x799abc
// 00480c9c  c3                   ret 
// 00480c9d  b8b09a7900           mov eax, 0x799ab0
// 00480ca2  c3                   ret 
// 00480ca3  b89c9a7900           mov eax, 0x799a9c
// 00480ca8  c3                   ret 
// 00480ca9  b8949a7900           mov eax, 0x799a94
// 00480cae  c3                   ret 
// 00480caf  b8849a7900           mov eax, 0x799a84
// 00480cb4  c3                   ret 
// 00480cb5  b8789a7900           mov eax, 0x799a78
// 00480cba  c3                   ret 
// 00480cbb  b86c9a7900           mov eax, 0x799a6c
// 00480cc0  c3                   ret 
// 00480cc1  b8609a7900           mov eax, 0x799a60
// 00480cc6  c3                   ret 
// 00480cc7  b8549a7900           mov eax, 0x799a54
// 00480ccc  c3                   ret 
// 00480ccd  b8489a7900           mov eax, 0x799a48
// 00480cd2  c3                   ret 
// 00480cd3  b83c9a7900           mov eax, 0x799a3c
// 00480cd8  c3                   ret 
// 00480cd9  8d88ffeaffff         lea ecx, [eax - 0x1501]
// 00480cdf  83f90e               cmp ecx, 0xe
// 00480ce2  0f87f1060000         ja 0x4813d9
// 00480ce8  ff248dc0184800       jmp dword ptr [ecx*4 + 0x4818c0]
// 00480cef  b8349a7900           mov eax, 0x799a34
// 00480cf4  c3                   ret 
// 00480cf5  b8249a7900           mov eax, 0x799a24
// 00480cfa  c3                   ret 
// 00480cfb  b81c9a7900           mov eax, 0x799a1c
// 00480d00  c3                   ret 
// 00480d01  b80c9a7900           mov eax, 0x799a0c
// 00480d06  c3                   ret 
// 00480d07  b8049a7900           mov eax, 0x799a04
// 00480d0c  c3                   ret 
// 00480d0d  b8fc997900           mov eax, 0x7999fc
// 00480d12  c3                   ret 
// 00480d13  b8f4997900           mov eax, 0x7999f4
// 00480d18  c3                   ret 
// 00480d19  b8ec997900           mov eax, 0x7999ec
// 00480d1e  c3                   ret 
// 00480d1f  b8e0997900           mov eax, 0x7999e0
// 00480d24  c3                   ret 
// 00480d25  b8d4997900           mov eax, 0x7999d4
// 00480d2a  c3                   ret 
// 00480d2b  b8c4997900           mov eax, 0x7999c4
// 00480d30  c3                   ret 
// 00480d31  b8b0997900           mov eax, 0x7999b0
// 00480d36  c3                   ret 
// 00480d37  b8a0997900           mov eax, 0x7999a0
// 00480d3c  c3                   ret 
// 00480d3d  b898997900           mov eax, 0x799998
// 00480d42  c3                   ret 
// 00480d43  b890997900           mov eax, 0x799990
// 00480d48  c3                   ret 
// 00480d49  b884997900           mov eax, 0x799984
// 00480d4e  c3                   ret 
// 00480d4f  3d00400000           cmp eax, 0x4000
// 00480d54  0f871e040000         ja 0x481178
// 00480d5a  0f8412040000         je 0x481172
// 00480d60  3d001f0000           cmp eax, 0x1f00
// 00480d65  0f87c1010000         ja 0x480f2c
// 00480d6b  0f84b5010000         je 0x480f26
// 00480d71  3d00190000           cmp eax, 0x1900
// 00480d76  0f8798000000         ja 0x480e14
// 00480d7c  0f848c000000         je 0x480e0e
// 00480d82  3d01170000           cmp eax, 0x1701
// 00480d87  7747                 ja 0x480dd0
// 00480d89  743f                 je 0x480dca
// 00480d8b  3d03160000           cmp eax, 0x1603
// 00480d90  7727                 ja 0x480db9
// 00480d92  741f                 je 0x480db3
// 00480d94  8bc8                 mov ecx, eax
// 00480d96  81e901160000         sub ecx, 0x1601
// 00480d9c  740f                 je 0x480dad
// 00480d9e  83e901               sub ecx, 1
// 00480da1  0f8532060000         jne 0x4813d9
// 00480da7  b86c997900           mov eax, 0x79996c
// 00480dac  c3                   ret 
// 00480dad  b85c997900           mov eax, 0x79995c
// 00480db2  c3                   ret 
// 00480db3  b848997900           mov eax, 0x799948
// 00480db8  c3                   ret 
// 00480db9  3d00170000           cmp eax, 0x1700
// 00480dbe  0f8515060000         jne 0x4813d9
// 00480dc4  b838997900           mov eax, 0x799938
// 00480dc9  c3                   ret 
// 00480dca  b828997900           mov eax, 0x799928
// 00480dcf  c3                   ret 
// 00480dd0  3d01180000           cmp eax, 0x1801
// 00480dd5  7726                 ja 0x480dfd
// 00480dd7  741e                 je 0x480df7
// 00480dd9  3d02170000           cmp eax, 0x1702
// 00480dde  7411                 je 0x480df1
// 00480de0  3d00180000           cmp eax, 0x1800
// 00480de5  0f85ee050000         jne 0x4813d9
// 00480deb  b81c997900           mov eax, 0x79991c
// 00480df0  c3                   ret 
// 00480df1  b810997900           mov eax, 0x799910
// 00480df6  c3                   ret 
// 00480df7  b804997900           mov eax, 0x799904
// 00480dfc  c3                   ret 
// 00480dfd  3d02180000           cmp eax, 0x1802
// 00480e02  0f85d1050000         jne 0x4813d9
// 00480e08  b8f8987900           mov eax, 0x7998f8
// 00480e0d  c3                   ret 
// 00480e0e  b8e8987900           mov eax, 0x7998e8
// 00480e13  c3                   ret 
// 00480e14  3d001a0000           cmp eax, 0x1a00
// 00480e19  775a                 ja 0x480e75
// 00480e1b  7452                 je 0x480e6f
// 00480e1d  8d88ffe6ffff         lea ecx, [eax - 0x1901]
// 00480e23  83f909               cmp ecx, 9
// 00480e26  0f87ad050000         ja 0x4813d9
// 00480e2c  ff248dfc184800       jmp dword ptr [ecx*4 + 0x4818fc]
// 00480e33  b8d4987900           mov eax, 0x7998d4
// 00480e38  c3                   ret 
// 00480e39  b8c0987900           mov eax, 0x7998c0
// 00480e3e  c3                   ret 
// 00480e3f  b8b8987900           mov eax, 0x7998b8
// 00480e44  c3                   ret 
// 00480e45  b8ac987900           mov eax, 0x7998ac
// 00480e4a  c3                   ret 
// 00480e4b  b8a4987900           mov eax, 0x7998a4
// 00480e50  c3                   ret 
// 00480e51  b898987900           mov eax, 0x799898
// 00480e56  c3                   ret 
// 00480e57  b890987900           mov eax, 0x799890
// 00480e5c  c3                   ret 
// 00480e5d  b888987900           mov eax, 0x799888
// 00480e62  c3                   ret 
// 00480e63  b878987900           mov eax, 0x799878
// 00480e68  c3                   ret 
// 00480e69  b864987900           mov eax, 0x799864
// 00480e6e  c3                   ret 
// 00480e6f  b858987900           mov eax, 0x799858
// 00480e74  c3                   ret 
// 00480e75  3d001d0000           cmp eax, 0x1d00
// 00480e7a  7760                 ja 0x480edc
// 00480e7c  7458                 je 0x480ed6
// 00480e7e  3d001c0000           cmp eax, 0x1c00
// 00480e83  7732                 ja 0x480eb7
// 00480e85  742a                 je 0x480eb1
// 00480e87  8bc8                 mov ecx, eax
// 00480e89  81e9001b0000         sub ecx, 0x1b00
// 00480e8f  741a                 je 0x480eab
// 00480e91  83e901               sub ecx, 1
// 00480e94  740f                 je 0x480ea5
// 00480e96  83e901               sub ecx, 1
// 00480e99  0f853a050000         jne 0x4813d9
// 00480e9f  b850987900           mov eax, 0x799850
// 00480ea4  c3                   ret 
// 00480ea5  b848987900           mov eax, 0x799848
// 00480eaa  c3                   ret 
// 00480eab  b83c987900           mov eax, 0x79983c
// 00480eb0  c3                   ret 
// 00480eb1  b830987900           mov eax, 0x799830
// 00480eb6  c3                   ret 
// 00480eb7  8bc8                 mov ecx, eax
// 00480eb9  81e9011c0000         sub ecx, 0x1c01
// 00480ebf  740f                 je 0x480ed0
// 00480ec1  83e901               sub ecx, 1
// 00480ec4  0f850f050000         jne 0x4813d9
// 00480eca  b824987900           mov eax, 0x799824
// 00480ecf  c3                   ret 
// 00480ed0  b818987900           mov eax, 0x799818
// 00480ed5  c3                   ret 
// 00480ed6  b810987900           mov eax, 0x799810
// 00480edb  c3                   ret 
// 00480edc  3d001e0000           cmp eax, 0x1e00
// 00480ee1  7719                 ja 0x480efc
// 00480ee3  7411                 je 0x480ef6
// 00480ee5  3d011d0000           cmp eax, 0x1d01
// 00480eea  0f85e9040000         jne 0x4813d9
// 00480ef0  b804987900           mov eax, 0x799804
// 00480ef5  c3                   ret 
// 00480ef6  b8fc977900           mov eax, 0x7997fc
// 00480efb  c3                   ret 
// 00480efc  8bc8                 mov ecx, eax
// 00480efe  81e9011e0000         sub ecx, 0x1e01
// 00480f04  741a                 je 0x480f20
// 00480f06  83e901               sub ecx, 1
// 00480f09  740f                 je 0x480f1a
// 00480f0b  83e901               sub ecx, 1
// 00480f0e  0f85c5040000         jne 0x4813d9
// 00480f14  b8f4977900           mov eax, 0x7997f4
// 00480f19  c3                   ret 
// 00480f1a  b8ec977900           mov eax, 0x7997ec
// 00480f1f  c3                   ret 
// 00480f20  b8e0977900           mov eax, 0x7997e0
// 00480f25  c3                   ret 
// 00480f26  b8d4977900           mov eax, 0x7997d4
// 00480f2b  c3                   ret 
// 00480f2c  3d00260000           cmp eax, 0x2600
// 00480f31  0f8720010000         ja 0x481057
// 00480f37  0f8414010000         je 0x481051
// 00480f3d  3d00220000           cmp eax, 0x2200
// 00480f42  0f8792000000         ja 0x480fda
// 00480f48  0f8486000000         je 0x480fd4
// 00480f4e  3d00200000           cmp eax, 0x2000
// 00480f53  7732                 ja 0x480f87
// 00480f55  742a                 je 0x480f81
// 00480f57  8bc8                 mov ecx, eax
// 00480f59  81e9011f0000         sub ecx, 0x1f01
// 00480f5f  741a                 je 0x480f7b
// 00480f61  83e901               sub ecx, 1
// 00480f64  740f                 je 0x480f75
// 00480f66  83e901               sub ecx, 1
// 00480f69  0f856a040000         jne 0x4813d9
// 00480f6f  b8c4977900           mov eax, 0x7997c4
// 00480f74  c3                   ret 
// 00480f75  b8b8977900           mov eax, 0x7997b8
// 00480f7a  c3                   ret 
// 00480f7b  b8ac977900           mov eax, 0x7997ac
// 00480f80  c3                   ret 
// 00480f81  b89c977900           mov eax, 0x79979c
// 00480f86  c3                   ret 
// 00480f87  3d03200000           cmp eax, 0x2003
// 00480f8c  7727                 ja 0x480fb5
// 00480f8e  741f                 je 0x480faf
// 00480f90  8bc8                 mov ecx, eax
// 00480f92  81e901200000         sub ecx, 0x2001
// 00480f98  740f                 je 0x480fa9
// 00480f9a  83e901               sub ecx, 1
// 00480f9d  0f8536040000         jne 0x4813d9
// 00480fa3  b894977900           mov eax, 0x799794
// 00480fa8  c3                   ret 
// 00480fa9  b88c977900           mov eax, 0x79978c
// 00480fae  c3                   ret 
// 00480faf  b884977900           mov eax, 0x799784
// 00480fb4  c3                   ret 
// 00480fb5  8bc8                 mov ecx, eax
// 00480fb7  81e900210000         sub ecx, 0x2100
// 00480fbd  740f                 je 0x480fce
// 00480fbf  83e901               sub ecx, 1
// 00480fc2  0f8511040000         jne 0x4813d9
// 00480fc8  b878977900           mov eax, 0x799778
// 00480fcd  c3                   ret 
// 00480fce  b86c977900           mov eax, 0x79976c
// 00480fd3  c3                   ret 
// 00480fd4  b858977900           mov eax, 0x799758
// 00480fd9  c3                   ret 
// 00480fda  3d02240000           cmp eax, 0x2402
// 00480fdf  7746                 ja 0x481027
// 00480fe1  743e                 je 0x481021
// 00480fe3  3d00240000           cmp eax, 0x2400
// 00480fe8  7726                 ja 0x481010
// 00480fea  741e                 je 0x48100a
// 00480fec  3d01220000           cmp eax, 0x2201
// 00480ff1  7411                 je 0x481004
// 00480ff3  3d00230000           cmp eax, 0x2300
// 00480ff8  0f85db030000         jne 0x4813d9
// 00480ffe  b848977900           mov eax, 0x799748
// 00481003  c3                   ret 
// 00481004  b830977900           mov eax, 0x799730
// 00481009  c3                   ret 
// 0048100a  b820977900           mov eax, 0x799720
// 0048100f  c3                   ret 
// 00481010  3d01240000           cmp eax, 0x2401
// 00481015  0f85be030000         jne 0x4813d9
// 0048101b  b80c977900           mov eax, 0x79970c
// 00481020  c3                   ret 
// 00481021  b8fc967900           mov eax, 0x7996fc
// 00481026  c3                   ret 
// 00481027  8bc8                 mov ecx, eax
// 00481029  81e900250000         sub ecx, 0x2500
// 0048102f  741a                 je 0x48104b
// 00481031  83e901               sub ecx, 1
// 00481034  740f                 je 0x481045
// 00481036  83e901               sub ecx, 1
// 00481039  0f859a030000         jne 0x4813d9
// 0048103f  b8ec967900           mov eax, 0x7996ec
// 00481044  c3                   ret 
// 00481045  b8dc967900           mov eax, 0x7996dc
// 0048104a  c3                   ret 
// 0048104b  b8c8967900           mov eax, 0x7996c8
// 00481050  c3                   ret 
// 00481051  b8bc967900           mov eax, 0x7996bc
// 00481056  c3                   ret 
// 00481057  3d00290000           cmp eax, 0x2900
// 0048105c  0f878f000000         ja 0x4810f1
// 00481062  0f8483000000         je 0x4810eb
// 00481068  3d00270000           cmp eax, 0x2700
// 0048106d  7719                 ja 0x481088
// 0048106f  7411                 je 0x481082
// 00481071  3d01260000           cmp eax, 0x2601
// 00481076  0f855d030000         jne 0x4813d9
// 0048107c  b8b0967900           mov eax, 0x7996b0
// 00481081  c3                   ret 
// 00481082  b894967900           mov eax, 0x799694
// 00481087  c3                   ret 
// 00481088  3d00280000           cmp eax, 0x2800
// 0048108d  7732                 ja 0x4810c1
// 0048108f  742a                 je 0x4810bb
// 00481091  8bc8                 mov ecx, eax
// 00481093  81e901270000         sub ecx, 0x2701
// 00481099  741a                 je 0x4810b5
// 0048109b  83e901               sub ecx, 1
// 0048109e  740f                 je 0x4810af
// 004810a0  83e901               sub ecx, 1
// 004810a3  0f8530030000         jne 0x4813d9
// 004810a9  b87c967900           mov eax, 0x79967c
// 004810ae  c3                   ret 
// 004810af  b860967900           mov eax, 0x799660
// 004810b4  c3                   ret 
// 004810b5  b844967900           mov eax, 0x799644
// 004810ba  c3                   ret 
// 004810bb  b82c967900           mov eax, 0x79962c
// 004810c0  c3                   ret 
// 004810c1  8bc8                 mov ecx, eax
// 004810c3  81e901280000         sub ecx, 0x2801
// 004810c9  741a                 je 0x4810e5
// 004810cb  83e901               sub ecx, 1
// 004810ce  740f                 je 0x4810df
// 004810d0  83e901               sub ecx, 1
// 004810d3  0f8500030000         jne 0x4813d9
// 004810d9  b818967900           mov eax, 0x799618
// 004810de  c3                   ret 
// 004810df  b804967900           mov eax, 0x799604
// 004810e4  c3                   ret 
// 004810e5  b8ec957900           mov eax, 0x7995ec
// 004810ea  c3                   ret 
// 004810eb  b8e0957900           mov eax, 0x7995e0
// 004810f0  c3                   ret 
// 004810f1  3d00300000           cmp eax, 0x3000
// 004810f6  7746                 ja 0x48113e
// 004810f8  743e                 je 0x481138
// 004810fa  3d012a0000           cmp eax, 0x2a01
// 004810ff  7726                 ja 0x481127
// 00481101  741e                 je 0x481121
// 00481103  3d01290000           cmp eax, 0x2901
// 00481108  7411                 je 0x48111b
// 0048110a  3d002a0000           cmp eax, 0x2a00
// 0048110f  0f85c4020000         jne 0x4813d9
// 00481115  b8c8957900           mov eax, 0x7995c8
// 0048111a  c3                   ret 
// 0048111b  b8bc957900           mov eax, 0x7995bc
// 00481120  c3                   ret 
// 00481121  b8a4957900           mov eax, 0x7995a4
// 00481126  c3                   ret 
// 00481127  3d022a0000           cmp eax, 0x2a02
// 0048112c  0f85a7020000         jne 0x4813d9
// 00481132  b88c957900           mov eax, 0x79958c
// 00481137  c3                   ret 
// 00481138  b87c957900           mov eax, 0x79957c
// 0048113d  c3                   ret 
// 0048113e  8d88ffcfffff         lea ecx, [eax - 0x3001]
// 00481144  83f904               cmp ecx, 4
// 00481147  0f878c020000         ja 0x4813d9
// 0048114d  ff248d24194800       jmp dword ptr [ecx*4 + 0x481924]
// 00481154  b86c957900           mov eax, 0x79956c
// 00481159  c3                   ret 
// 0048115a  b85c957900           mov eax, 0x79955c
// 0048115f  c3                   ret 
// 00481160  b84c957900           mov eax, 0x79954c
// 00481165  c3                   ret 
// 00481166  b83c957900           mov eax, 0x79953c
// 0048116b  c3                   ret 
// 0048116c  b82c957900           mov eax, 0x79952c
// 00481171  c3                   ret 
// 00481172  b820957900           mov eax, 0x799520
// 00481177  c3                   ret 
// 00481178  3d00800000           cmp eax, 0x8000
// 0048117d  7748                 ja 0x4811c7
// 0048117f  7440                 je 0x4811c1
// 00481181  8d88ffbfffff         lea ecx, [eax - 0x4001]
// 00481187  83f906               cmp ecx, 6
// 0048118a  0f8749020000         ja 0x4813d9
// 00481190  ff248d38194800       jmp dword ptr [ecx*4 + 0x481938]
// 00481197  b814957900           mov eax, 0x799514
// 0048119c  c3                   ret 
// 0048119d  b808957900           mov eax, 0x799508
// 004811a2  c3                   ret 
// 004811a3  b8fc947900           mov eax, 0x7994fc
// 004811a8  c3                   ret 
// 004811a9  b8f0947900           mov eax, 0x7994f0
// 004811ae  c3                   ret 
// 004811af  b8e4947900           mov eax, 0x7994e4
// 004811b4  c3                   ret 
// 004811b5  b8d8947900           mov eax, 0x7994d8
// 004811ba  c3                   ret 
// 004811bb  b8cc947900           mov eax, 0x7994cc
// 004811c0  c3                   ret 
// 004811c1  b8c0947900           mov eax, 0x7994c0
// 004811c6  c3                   ret 
// 004811c7  3df5840000           cmp eax, 0x84f5
// 004811cc  0f872e010000         ja 0x481300
// 004811d2  0f8422010000         je 0x4812fa
// 004811d8  8d88c97fffff         lea ecx, [eax - 0x8037]
// 004811de  81f9f8000000         cmp ecx, 0xf8
// 004811e4  0f87ef010000         ja 0x4813d9
// 004811ea  0fb689041a4800       movzx ecx, byte ptr [ecx + 0x481a04]
// 004811f1  ff248d54194800       jmp dword ptr [ecx*4 + 0x481954]
// 004811f8  b8ac947900           mov eax, 0x7994ac
// 004811fd  c3                   ret 
// 004811fe  b898947900           mov eax, 0x799498
// 00481203  c3                   ret 
// 00481204  b87c947900           mov eax, 0x79947c
// 00481209  c3                   ret 
// 0048120a  b864947900           mov eax, 0x799464
// 0048120f  c3                   ret 
// 00481210  b854947900           mov eax, 0x799454
// 00481215  c3                   ret 
// 00481216  b844947900           mov eax, 0x799444
// 0048121b  c3                   ret 
// 0048121c  b834947900           mov eax, 0x799434
// 00481221  c3                   ret 
// 00481222  b824947900           mov eax, 0x799424
// 00481227  c3                   ret 
// 00481228  b80c947900           mov eax, 0x79940c
// 0048122d  c3                   ret 
// 0048122e  b8f8937900           mov eax, 0x7993f8
// 00481233  c3                   ret 
// 00481234  b8e0937900           mov eax, 0x7993e0
// 00481239  c3                   ret 
// 0048123a  b8c8937900           mov eax, 0x7993c8
// 0048123f  c3                   ret 
// 00481240  b8b0937900           mov eax, 0x7993b0
// 00481245  c3                   ret 
// 00481246  b898937900           mov eax, 0x799398
// 0048124b  c3                   ret 
// 0048124c  b880937900           mov eax, 0x799380
// 00481251  c3                   ret 
// 00481252  b86c937900           mov eax, 0x79936c
// 00481257  c3                   ret 
// 00481258  b858937900           mov eax, 0x799358
// 0048125d  c3                   ret 
// 0048125e  b840937900           mov eax, 0x799340
// 00481263  c3                   ret 
// 00481264  b82c937900           mov eax, 0x79932c
// 00481269  c3                   ret 
// 0048126a  b814937900           mov eax, 0x799314
// 0048126f  c3                   ret 
// 00481270  b8f8927900           mov eax, 0x7992f8
// 00481275  c3                   ret 
// 00481276  b8dc927900           mov eax, 0x7992dc
// 0048127b  c3                   ret 
// 0048127c  b8c0927900           mov eax, 0x7992c0
// 00481281  c3                   ret 
// 00481282  b8a4927900           mov eax, 0x7992a4
// 00481287  c3                   ret 
// 00481288  b884927900           mov eax, 0x799284
// 0048128d  c3                   ret 
// 0048128e  b864927900           mov eax, 0x799264
// 00481293  c3                   ret 
// 00481294  b840927900           mov eax, 0x799240
// 00481299  c3                   ret 
// 0048129a  b81c927900           mov eax, 0x79921c
// 0048129f  c3                   ret 
// 004812a0  b8fc917900           mov eax, 0x7991fc
// 004812a5  c3                   ret 
// 004812a6  b8dc917900           mov eax, 0x7991dc
// 004812ab  c3                   ret 
// 004812ac  b8c0917900           mov eax, 0x7991c0
// 004812b1  c3                   ret 
// 004812b2  b8a4917900           mov eax, 0x7991a4
// 004812b7  c3                   ret 
// 004812b8  b888917900           mov eax, 0x799188
// 004812bd  c3                   ret 
// 004812be  b86c917900           mov eax, 0x79916c
// 004812c3  c3                   ret 
// 004812c4  b848917900           mov eax, 0x799148
// 004812c9  c3                   ret 
// 004812ca  b828917900           mov eax, 0x799128
// 004812cf  c3                   ret 
// 004812d0  b818917900           mov eax, 0x799118
// 004812d5  c3                   ret 
// 004812d6  b804917900           mov eax, 0x799104
// 004812db  c3                   ret 
// 004812dc  b8e8907900           mov eax, 0x7990e8
// 004812e1  c3                   ret 
// 004812e2  b8d8907900           mov eax, 0x7990d8
// 004812e7  c3                   ret 
// 004812e8  b8c0907900           mov eax, 0x7990c0
// 004812ed  c3                   ret 
// 004812ee  b8a8907900           mov eax, 0x7990a8
// 004812f3  c3                   ret 
// 004812f4  b890907900           mov eax, 0x799090
// 004812f9  c3                   ret 
// 004812fa  b874907900           mov eax, 0x799074
// 004812ff  c3                   ret 
// 00481300  3d488b0000           cmp eax, 0x8b48
// 00481305  7727                 ja 0x48132e
// 00481307  741f                 je 0x481328
// 00481309  8bc8                 mov ecx, eax
// 0048130b  81e907850000         sub ecx, 0x8507
// 00481311  740f                 je 0x481322
// 00481313  83e901               sub ecx, 1
// 00481316  0f85bd000000         jne 0x4813d9
// 0048131c  b860907900           mov eax, 0x799060
// 00481321  c3                   ret 
// 00481322  b84c907900           mov eax, 0x79904c
// 00481327  c3                   ret 
// 00481328  b834907900           mov eax, 0x799034
// 0048132d  c3                   ret 
// 0048132e  3d00000100           cmp eax, 0x10000
// 00481333  0f87a0000000         ja 0x4813d9
// 00481339  0f8494000000         je 0x4813d3
// 0048133f  8d88b074ffff         lea ecx, [eax - 0x8b50]
// 00481345  83f914               cmp ecx, 0x14
// 00481348  0f878b000000         ja 0x4813d9
// 0048134e  ff248d001b4800       jmp dword ptr [ecx*4 + 0x481b00]
// 00481355  b820907900           mov eax, 0x799020
// 0048135a  c3                   ret 
// 0048135b  b80c907900           mov eax, 0x79900c
// 00481360  c3                   ret 
// 00481361  b8f88f7900           mov eax, 0x798ff8
// 00481366  c3                   ret 
// 00481367  b8e88f7900           mov eax, 0x798fe8
// 0048136c  c3                   ret 
// 0048136d  b8d88f7900           mov eax, 0x798fd8
// 00481372  c3                   ret 
// 00481373  b8c88f7900           mov eax, 0x798fc8
// 00481378  c3                   ret 
// 00481379  b8bc8f7900           mov eax, 0x798fbc
// 0048137e  c3                   ret 
// 0048137f  b8a88f7900           mov eax, 0x798fa8
// 00481384  c3                   ret 
// 00481385  b8948f7900           mov eax, 0x798f94
// 0048138a  c3                   ret 
// 0048138b  b8808f7900           mov eax, 0x798f80
// 00481390  c3                   ret 
// 00481391  b86c8f7900           mov eax, 0x798f6c
// 00481396  c3                   ret 
// 00481397  b8588f7900           mov eax, 0x798f58
// 0048139c  c3                   ret 
// 0048139d  b8448f7900           mov eax, 0x798f44
// 004813a2  c3                   ret 
// 004813a3  b8308f7900           mov eax, 0x798f30
// 004813a8  c3                   ret 
// 004813a9  b81c8f7900           mov eax, 0x798f1c
// 004813ae  c3                   ret 
// 004813af  b8088f7900           mov eax, 0x798f08
// 004813b4  c3                   ret 
// 004813b5  b8f48e7900           mov eax, 0x798ef4
// 004813ba  c3                   ret 
// 004813bb  b8d88e7900           mov eax, 0x798ed8
// 004813c0  c3                   ret 
// 004813c1  b8bc8e7900           mov eax, 0x798ebc
// 004813c6  c3                   ret 
// 004813c7  b8a48e7900           mov eax, 0x798ea4
// 004813cc  c3                   ret 
// 004813cd  b8848e7900           mov eax, 0x798e84
// 004813d2  c3                   ret 
// 004813d3  b8788e7900           mov eax, 0x798e78
// 004813d8  c3                   ret 
// 004813d9  50                   push eax
// 004813da  68708e7900           push 0x798e70
// 004813df  68b4db8b00           push 0x8bdbb4
// 004813e4  ff1568e97700         call dword ptr [0x77e968]
// 004813ea  83c40c               add esp, 0xc
// 004813ed  b8b4db8b00           mov eax, 0x8bdbb4
// 004813f2  c3                   ret 
// 004813f3  90                   nop 
// 004813f4  2e07                 pop es
// 004813f6  48                   dec eax
// 004813f7  003407               add byte ptr [edi + eax], dh
// 004813fa  48                   dec eax
// 004813fb  00e6                 add dh, ah
// 004813fd  06                   push es
// 004813fe  48                   dec eax
// 004813ff  000a                 add byte ptr [edx], cl
// 00481401  07                   pop es
// 00481402  48                   dec eax
// 00481403  0010                 add byte ptr [eax], dl
// 00481405  07                   pop es
// 00481406  48                   dec eax
// 00481407  0016                 add byte ptr [esi], dl
// 00481409  07                   pop es
// 0048140a  48                   dec eax
// 0048140b  001c07               add byte ptr [edi + eax], bl
// 0048140e  48                   dec eax
// 0048140f  0022                 add byte ptr [edx], ah
// 00481411  07                   pop es
// 00481412  48                   dec eax
// 00481413  00ec                 add ah, ch
// 00481415  06                   push es
// 00481416  48                   dec eax
// 00481417  0028                 add byte ptr [eax], ch
// 00481419  07                   pop es
// 0048141a  48                   dec eax
// 0048141b  00f2                 add dl, dh
// 0048141d  06                   push es
// 0048141e  48                   dec eax
// 0048141f  00f8                 add al, bh
// 00481421  06                   push es
// 00481422  48                   dec eax
// 00481423  00fe                 add dh, bh
// 00481425  06                   push es
// 00481426  48                   dec eax
// 00481427  000407               add byte ptr [edi + eax], al
// 0048142a  48                   dec eax
// 0048142b  00d9                 add cl, bl
// 0048142d  134800               adc ecx, dword ptr [eax]
// 00481430  0001                 add byte ptr [ecx], al
// 00481432  0203                 add al, byte ptr [ebx]
// 00481434  0405                 add al, 5
// 00481436  06                   push es
// 00481437  07                   pop es
// 00481438  0809                 or byte ptr [ecx], cl
// 0048143a  0e                   push cs
// 0048143b  0e                   push cs
// 0048143c  0e                   push cs
// 0048143d  0e                   push cs
// 0048143e  0e                   push cs
// 0048143f  0e                   push cs
// 00481440  0a0e                 or cl, byte ptr [esi]
// 00481442  0e                   push cs
// 00481443  0e                   push cs
// 00481444  0e                   push cs
// 00481445  0e                   push cs
// 00481446  0e                   push cs
// 00481447  0e                   push cs
// 00481448  0e                   push cs
// 00481449  0e                   push cs
// 0048144a  0e                   push cs
// 0048144b  0e                   push cs
// 0048144c  0e                   push cs
// 0048144d  0e                   push cs
// 0048144e  0e                   push cs
// 0048144f  0e                   push cs
// 00481450  0b0e                 or ecx, dword ptr [esi]
// 00481452  0e                   push cs
// 00481453  0e                   push cs
// 00481454  0e                   push cs
// 00481455  0e                   push cs
// 00481456  0e                   push cs
// 00481457  0e                   push cs
// 00481458  0e                   push cs
// 00481459  0e                   push cs
// 0048145a  0e                   push cs
// 0048145b  0e                   push cs
// 0048145c  0e                   push cs
// 0048145d  0e                   push cs
// 0048145e  0e                   push cs
// 0048145f  0e                   push cs
// 00481460  0e                   push cs
// 00481461  0e                   push cs
// 00481462  0e                   push cs
// 00481463  0e                   push cs
// 00481464  0e                   push cs
// 00481465  0e                   push cs
// 00481466  0e                   push cs
// 00481467  0e                   push cs
// 00481468  0e                   push cs
// 00481469  0e                   push cs
// 0048146a  0e                   push cs
// 0048146b  0e                   push cs
// 0048146c  0e                   push cs
// 0048146d  0e                   push cs
// 0048146e  0e                   push cs
// 0048146f  0e                   push cs
// 00481470  0c0e                 or al, 0xe
// 00481472  0e                   push cs
// 00481473  0e                   push cs
// 00481474  0e                   push cs
// 00481475  0e                   push cs
// 00481476  0e                   push cs
// 00481477  0e                   push cs
// 00481478  0e                   push cs
// 00481479  0e                   push cs
// 0048147a  0e                   push cs
// 0048147b  0e                   push cs
// 0048147c  0e                   push cs
// 0048147d  0e                   push cs
// 0048147e  0e                   push cs
// 0048147f  0e                   push cs
// 00481480  0e                   push cs
// 00481481  0e                   push cs
// 00481482  0e                   push cs
// 00481483  0e                   push cs
// 00481484  0e                   push cs
// 00481485  0e                   push cs
// 00481486  0e                   push cs
// 00481487  0e                   push cs
// 00481488  0e                   push cs
// 00481489  0e                   push cs
// 0048148a  0e                   push cs
// 0048148b  0e                   push cs
// 0048148c  0e                   push cs
// 0048148d  0e                   push cs
// 0048148e  0e                   push cs
// 0048148f  0e                   push cs
// 00481490  0e                   push cs
// 00481491  0e                   push cs
// 00481492  0e                   push cs
// 00481493  0e                   push cs
// 00481494  0e                   push cs
// 00481495  0e                   push cs
// 00481496  0e                   push cs
// 00481497  0e                   push cs
// 00481498  0e                   push cs
// 00481499  0e                   push cs
// 0048149a  0e                   push cs
// 0048149b  0e                   push cs
// 0048149c  0e                   push cs
// 0048149d  0e                   push cs
// 0048149e  0e                   push cs
// 0048149f  0e                   push cs
// 004814a0  0e                   push cs
// 004814a1  0e                   push cs
// 004814a2  0e                   push cs
// 004814a3  0e                   push cs
// 004814a4  0e                   push cs
// 004814a5  0e                   push cs
// 004814a6  0e                   push cs
// 004814a7  0e                   push cs
// 004814a8  0e                   push cs
// 004814a9  0e                   push cs
// 004814aa  0e                   push cs
// 004814ab  0e                   push cs
// 004814ac  0e                   push cs
// 004814ad  0e                   push cs
// 004814ae  0e                   push cs
// 004814af  0e                   push cs
// 004814b0  0d8d49005f           or eax, 0x5f00498d
// 004814b5  07                   pop es
// 004814b6  48                   dec eax
// 004814b7  006507               add byte ptr [ebp + 7], ah
// 004814ba  48                   dec eax
// 004814bb  006b07               add byte ptr [ebx + 7], ch
// 004814be  48                   dec eax
// 004814bf  007107               add byte ptr [ecx + 7], dh
// 004814c2  48                   dec eax
// 004814c3  009c074800a207       add byte ptr [edi + eax + 0x7a20048], bl
// 004814ca  48                   dec eax
// 004814cb  00a8074800ae         add byte ptr [eax - 0x51ffb7f9], ch
// 004814d1  07                   pop es
// 004814d2  48                   dec eax
// 004814d3  00b4074800ba07       add byte ptr [edi + eax + 0x7ba0048], dh
// 004814da  48                   dec eax
// 004814db  00c0                 add al, al
// 004814dd  07                   pop es
// 004814de  48                   dec eax
// 004814df  005b08               add byte ptr [ebx + 8], bl
// 004814e2  48                   dec eax
// 004814e3  006108               add byte ptr [ecx + 8], ah
// 004814e6  48                   dec eax
// 004814e7  006708               add byte ptr [edi + 8], ah
// 004814ea  48                   dec eax
// 004814eb  006d08               add byte ptr [ebp + 8], ch
// 004814ee  48                   dec eax
// 004814ef  007308               add byte ptr [ebx + 8], dh
// 004814f2  48                   dec eax
// 004814f3  007908               add byte ptr [ecx + 8], bh
// 004814f6  48                   dec eax
// 004814f7  007f08               add byte ptr [edi + 8], bh
// 004814fa  48                   dec eax
// 004814fb  0085084800b0         add byte ptr [ebp - 0x4fffb7f8], al
// 00481501  084800               or byte ptr [eax], cl
// 00481504  b608                 mov dh, 8
// 00481506  48                   dec eax
// 00481507  00bc084800c208       add byte ptr [eax + ecx + 0x8c20048], bh
// 0048150e  48                   dec eax
// 0048150f  00c8                 add al, cl
// 00481511  084800               or byte ptr [eax], cl
// 00481514  f3084800             or byte ptr [eax], cl
// 00481518  f9                   stc 
// 00481519  084800               or byte ptr [eax], cl
// 0048151c  ff08                 dec dword ptr [eax]
// 0048151e  48                   dec eax
// 0048151f  00050948007b         add byte ptr [0x7b004809], al
// 00481525  094800               or dword ptr [eax], ecx
// 00481528  810948008709         or dword ptr [ecx], 0x9870048
// 0048152e  48                   dec eax
// 0048152f  008d09480093         add byte ptr [ebp - 0x6cffb7f7], cl
// 00481535  094800               or dword ptr [eax], ecx
// 00481538  99                   cdq 
// 00481539  094800               or dword ptr [eax], ecx
// 0048153c  9f                   lahf 
// 0048153d  094800               or dword ptr [eax], ecx
// 00481540  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 00481541  094800               or dword ptr [eax], ecx
// 00481544  ab                   stosd dword ptr es:[edi], eax
// 00481545  094800               or dword ptr [eax], ecx
// 00481548  b109                 mov cl, 9
// 0048154a  48                   dec eax
// 0048154b  00b7094800bd         add byte ptr [edi - 0x42ffb7f7], dh
// 00481551  094800               or dword ptr [eax], ecx
// 00481554  c3                   ret 
// 00481555  094800               or dword ptr [eax], ecx
// 00481558  c9                   leave 
// 00481559  094800               or dword ptr [eax], ecx
// 0048155c  cf                   iretd 
// 0048155d  094800               or dword ptr [eax], ecx
// 00481560  17                   pop ss
// 00481561  0a4800               or cl, byte ptr [eax]
// 00481564  110a                 adc dword ptr [edx], ecx
// 00481566  48                   dec eax
// 00481567  000b                 add byte ptr [ebx], cl
// 00481569  0a4800               or cl, byte ptr [eax]
// 0048156c  1d0a480075           sbb eax, 0x7500480a
// 00481571  094800               or dword ptr [eax], ecx
// 00481574  db09                 fisttp dword ptr [ecx]
// 00481576  48                   dec eax
// 00481577  0029                 add byte ptr [ecx], ch
// 00481579  0a4800               or cl, byte ptr [eax]
// 0048157c  f9                   stc 
// 0048157d  094800               or dword ptr [eax], ecx
// 00481580  050a4800ff           add eax, 0xff00480a
// 00481585  094800               or dword ptr [eax], ecx
// 00481588  f3094800             or dword ptr [eax], ecx
// 0048158c  230a                 and ecx, dword ptr [edx]
// 0048158e  48                   dec eax
// 0048158f  00e7                 add bh, ah
// 00481591  094800               or dword ptr [eax], ecx
// 00481594  ed                   in eax, dx
// 00481595  094800               or dword ptr [eax], ecx
// 00481598  e109                 loope 0x4815a3
// 0048159a  48                   dec eax
// 0048159b  002f                 add byte ptr [edi], ch
// 0048159d  0a4800               or cl, byte ptr [eax]
// 004815a0  d509                 aad 9
// 004815a2  48                   dec eax
// 004815a3  00d9                 add cl, bl
// 004815a5  134800               adc ecx, dword ptr [eax]
// 004815a8  0001                 add byte ptr [ecx], al
// 004815aa  0203                 add al, byte ptr [ebx]
// 004815ac  0405                 add al, 5
// 004815ae  06                   push es
// 004815af  07                   pop es
// 004815b0  0820                 or byte ptr [eax], ah
// 004815b2  2020                 and byte ptr [eax], ah
// 004815b4  2020                 and byte ptr [eax], ah
// 004815b6  2009                 and byte ptr [ecx], cl
// 004815b8  0a0b                 or cl, byte ptr [ebx]
// 004815ba  0c20                 or al, 0x20
// 004815bc  2020                 and byte ptr [eax], ah
// 004815be  2020                 and byte ptr [eax], ah
// 004815c0  2020                 and byte ptr [eax], ah
// 004815c2  2020                 and byte ptr [eax], ah
// 004815c4  2020                 and byte ptr [eax], ah
// 004815c6  200d0e20200f         and byte ptr [0xf20200e], cl
// 004815cc  2020                 and byte ptr [eax], ah
// 004815ce  2020                 and byte ptr [eax], ah
// 004815d0  2020                 and byte ptr [eax], ah
// 004815d2  2020                 and byte ptr [eax], ah
// 004815d4  2020                 and byte ptr [eax], ah
// 004815d6  2020                 and byte ptr [eax], ah
// 004815d8  2020                 and byte ptr [eax], ah
// 004815da  2020                 and byte ptr [eax], ah
// 004815dc  2020                 and byte ptr [eax], ah
// 004815de  2020                 and byte ptr [eax], ah
// 004815e0  2020                 and byte ptr [eax], ah
// 004815e2  2020                 and byte ptr [eax], ah
// 004815e4  2020                 and byte ptr [eax], ah
// 004815e6  2020                 and byte ptr [eax], ah
// 004815e8  1011                 adc byte ptr [ecx], dl
// 004815ea  2012                 and byte ptr [edx], dl
// 004815ec  2020                 and byte ptr [eax], ah
// 004815ee  2020                 and byte ptr [eax], ah
// 004815f0  2020                 and byte ptr [eax], ah
// 004815f2  2020                 and byte ptr [eax], ah
// 004815f4  2020                 and byte ptr [eax], ah
// 004815f6  2013                 and byte ptr [ebx], dl
// 004815f8  2020                 and byte ptr [eax], ah
// 004815fa  2020                 and byte ptr [eax], ah
// 004815fc  2020                 and byte ptr [eax], ah
// 004815fe  1420                 adc al, 0x20
// 00481600  2020                 and byte ptr [eax], ah
// 00481602  2020                 and byte ptr [eax], ah
// 00481604  2020                 and byte ptr [eax], ah
// 00481606  201520202020         and byte ptr [0x20202020], dl
// 0048160c  2020                 and byte ptr [eax], ah
// 0048160e  2020                 and byte ptr [eax], ah
// 00481610  2020                 and byte ptr [eax], ah
// 00481612  2020                 and byte ptr [eax], ah
// 00481614  2020                 and byte ptr [eax], ah
// 00481616  2020                 and byte ptr [eax], ah
// 00481618  16                   push ss
// 00481619  2020                 and byte ptr [eax], ah
// 0048161b  2020                 and byte ptr [eax], ah
// 0048161d  2020                 and byte ptr [eax], ah
// 0048161f  2020                 and byte ptr [eax], ah
// 00481621  2020                 and byte ptr [eax], ah
// 00481623  2020                 and byte ptr [eax], ah
// 00481625  2020                 and byte ptr [eax], ah
// 00481627  2020                 and byte ptr [eax], ah
// 00481629  2020                 and byte ptr [eax], ah
// 0048162b  2020                 and byte ptr [eax], ah
// 0048162d  2020                 and byte ptr [eax], ah
// 0048162f  2020                 and byte ptr [eax], ah
// 00481631  2020                 and byte ptr [eax], ah
// 00481633  2020                 and byte ptr [eax], ah
// 00481635  2020                 and byte ptr [eax], ah
// 00481637  17                   pop ss
// 00481638  2020                 and byte ptr [eax], ah
// 0048163a  2020                 and byte ptr [eax], ah
// 0048163c  2020                 and byte ptr [eax], ah
// 0048163e  2020                 and byte ptr [eax], ah
// 00481640  2020                 and byte ptr [eax], ah
// 00481642  2020                 and byte ptr [eax], ah
// 00481644  2020                 and byte ptr [eax], ah
// 00481646  2020                 and byte ptr [eax], ah
// 00481648  1820                 sbb byte ptr [eax], ah
// 0048164a  2020                 and byte ptr [eax], ah
// 0048164c  2020                 and byte ptr [eax], ah
// 0048164e  2020                 and byte ptr [eax], ah
// 00481650  2020                 and byte ptr [eax], ah
// 00481652  2020                 and byte ptr [eax], ah
// 00481654  2020                 and byte ptr [eax], ah
// 00481656  2020                 and byte ptr [eax], ah
// 00481658  2020                 and byte ptr [eax], ah
// 0048165a  2020                 and byte ptr [eax], ah
// 0048165c  2020                 and byte ptr [eax], ah
// 0048165e  2020                 and byte ptr [eax], ah
// 00481660  2020                 and byte ptr [eax], ah
// 00481662  2020                 and byte ptr [eax], ah
// 00481664  2020                 and byte ptr [eax], ah
// 00481666  2019                 and byte ptr [ecx], bl
// 00481668  2020                 and byte ptr [eax], ah
// 0048166a  2020                 and byte ptr [eax], ah
// 0048166c  2020                 and byte ptr [eax], ah
// 0048166e  2020                 and byte ptr [eax], ah
// 00481670  2020                 and byte ptr [eax], ah
// 00481672  2020                 and byte ptr [eax], ah
// 00481674  2020                 and byte ptr [eax], ah
// 00481676  201a                 and byte ptr [edx], bl
// 00481678  2020                 and byte ptr [eax], ah
// 0048167a  2020                 and byte ptr [eax], ah
// 0048167c  2020                 and byte ptr [eax], ah
// 0048167e  2020                 and byte ptr [eax], ah
// 00481680  2020                 and byte ptr [eax], ah
// 00481682  2020                 and byte ptr [eax], ah
// 00481684  2020                 and byte ptr [eax], ah
// 00481686  201b                 and byte ptr [ebx], bl
// 00481688  1c1d                 sbb al, 0x1d
// 0048168a  2020                 and byte ptr [eax], ah
// 0048168c  2020                 and byte ptr [eax], ah
// 0048168e  2020                 and byte ptr [eax], ah
// 00481690  2020                 and byte ptr [eax], ah
// 00481692  2020                 and byte ptr [eax], ah
// 00481694  2020                 and byte ptr [eax], ah
// 00481696  2020                 and byte ptr [eax], ah
// 00481698  1e                   push ds
// 00481699  1f                   pop ds
// 0048169a  8bff                 mov edi, edi
// 0048169c  de0a                 fimul word ptr [edx]
// 0048169e  48                   dec eax
// 0048169f  00d8                 add al, bl
// 004816a1  0a4800               or cl, byte ptr [eax]
// 004816a4  d20a                 ror byte ptr [edx], cl
// 004816a6  48                   dec eax
// 004816a7  00720a               add byte ptr [edx + 0xa], dh
// 004816aa  48                   dec eax
// 004816ab  00780a               add byte ptr [eax + 0xa], bh
// 004816ae  48                   dec eax
// 004816af  007e0a               add byte ptr [esi + 0xa], bh
// 004816b2  48                   dec eax
// 004816b3  00840a48008a0a       add byte ptr [edx + ecx + 0xa8a0048], al
// 004816ba  48                   dec eax
// 004816bb  00900a480096         add byte ptr [eax - 0x69ffb7f6], dl
// 004816c1  0a4800               or cl, byte ptr [eax]
// 004816c4  9c                   pushfd 
// 004816c5  0a4800               or cl, byte ptr [eax]
// 004816c8  a20a4800a8           mov byte ptr [0xa800480a], al
// 004816cd  0a4800               or cl, byte ptr [eax]
// 004816d0  ae                   scasb al, byte ptr es:[edi]
// 004816d1  0a4800               or cl, byte ptr [eax]
// 004816d4  b40a                 mov ah, 0xa
// 004816d6  48                   dec eax
// 004816d7  00ba0a4800c0         add byte ptr [edx - 0x3fffb7f6], bh
// 004816dd  0a4800               or cl, byte ptr [eax]
// copied from an identical function in another client (function ?GLenumToString@G3D@@YAPBDI@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09 GLG3Dcpp/glenumtostring.cpp
// roc 2008-06 00483a00  unit: G3D::Win32Window  size: 5268 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00483a00
//
// 00483a00  8b442404             mov eax, dword ptr [esp + 4]
// 00483a04  3d00010000           cmp eax, 0x100
// 00483a09  7775                 ja 0x483a80
// 00483a0b  746d                 je 0x483a7a
// 00483a0d  3d80000000           cmp eax, 0x80
// 00483a12  0f87010d0000         ja 0x484719
// 00483a18  0fb68870474800       movzx ecx, byte ptr [eax + 0x484770]
// 00483a1f  ff248d34474800       jmp dword ptr [ecx*4 + 0x484734]
// 00483a26  b84c0c8200           mov eax, 0x820c4c
// 00483a2b  c3                   ret 
// 00483a2c  b83c0c8200           mov eax, 0x820c3c
// 00483a31  c3                   ret 
// 00483a32  b8240c8200           mov eax, 0x820c24
// 00483a37  c3                   ret 
// 00483a38  b8100c8200           mov eax, 0x820c10
// 00483a3d  c3                   ret 
// 00483a3e  b8000c8200           mov eax, 0x820c00
// 00483a43  c3                   ret 
// 00483a44  b8f40b8200           mov eax, 0x820bf4
// 00483a49  c3                   ret 
// 00483a4a  b8e40b8200           mov eax, 0x820be4
// 00483a4f  c3                   ret 
// 00483a50  b8d40b8200           mov eax, 0x820bd4
// 00483a55  c3                   ret 
// 00483a56  b8c00b8200           mov eax, 0x820bc0
// 00483a5b  c3                   ret 
// 00483a5c  b8b00b8200           mov eax, 0x820bb0
// 00483a61  c3                   ret 
// 00483a62  b8a40b8200           mov eax, 0x820ba4
// 00483a67  c3                   ret 
// 00483a68  b8980b8200           mov eax, 0x820b98
// 00483a6d  c3                   ret 
// 00483a6e  b8900b8200           mov eax, 0x820b90
// 00483a73  c3                   ret 
// 00483a74  b8880b8200           mov eax, 0x820b88
// 00483a79  c3                   ret 
// 00483a7a  b87c0b8200           mov eax, 0x820b7c
// 00483a7f  c3                   ret 
// 00483a80  3d00020000           cmp eax, 0x200
// 00483a85  7736                 ja 0x483abd
// 00483a87  742e                 je 0x483ab7
// 00483a89  8d88fffeffff         lea ecx, [eax - 0x101]
// 00483a8f  83f903               cmp ecx, 3
// 00483a92  0f87810c0000         ja 0x484719
// 00483a98  ff248df4474800       jmp dword ptr [ecx*4 + 0x4847f4]
// 00483a9f  b8740b8200           mov eax, 0x820b74
// 00483aa4  c3                   ret 
// 00483aa5  b8680b8200           mov eax, 0x820b68
// 00483aaa  c3                   ret 
// 00483aab  b8600b8200           mov eax, 0x820b60
// 00483ab0  c3                   ret 
// 00483ab1  b8580b8200           mov eax, 0x820b58
// 00483ab6  c3                   ret 
// 00483ab7  b84c0b8200           mov eax, 0x820b4c
// 00483abc  c3                   ret 
// 00483abd  3d00030000           cmp eax, 0x300
// 00483ac2  7748                 ja 0x483b0c
// 00483ac4  7440                 je 0x483b06
// 00483ac6  8d88fffdffff         lea ecx, [eax - 0x201]
// 00483acc  83f906               cmp ecx, 6
// 00483acf  0f87440c0000         ja 0x484719
// 00483ad5  ff248d04484800       jmp dword ptr [ecx*4 + 0x484804]
// 00483adc  b8440b8200           mov eax, 0x820b44
// 00483ae1  c3                   ret 
// 00483ae2  b8380b8200           mov eax, 0x820b38
// 00483ae7  c3                   ret 
// 00483ae8  b82c0b8200           mov eax, 0x820b2c
// 00483aed  c3                   ret 
// 00483aee  b8200b8200           mov eax, 0x820b20
// 00483af3  c3                   ret 
// 00483af4  b8140b8200           mov eax, 0x820b14
// 00483af9  c3                   ret 
// 00483afa  b8080b8200           mov eax, 0x820b08
// 00483aff  c3                   ret 
// 00483b00  b8fc0a8200           mov eax, 0x820afc
// 00483b05  c3                   ret 
// 00483b06  b8ec0a8200           mov eax, 0x820aec
// 00483b0b  c3                   ret 
// 00483b0c  3d00160000           cmp eax, 0x1600
// 00483b11  0f8778050000         ja 0x48408f
// 00483b17  0f846c050000         je 0x484089
// 00483b1d  3d600c0000           cmp eax, 0xc60
// 00483b22  0f8759020000         ja 0x483d81
// 00483b28  0f844d020000         je 0x483d7b
// 00483b2e  3d000b0000           cmp eax, 0xb00
// 00483b33  0f874b010000         ja 0x483c84
// 00483b39  0f843f010000         je 0x483c7e
// 00483b3f  3d00050000           cmp eax, 0x500
// 00483b44  0f8787000000         ja 0x483bd1
// 00483b4a  747f                 je 0x483bcb
// 00483b4c  3d00040000           cmp eax, 0x400
// 00483b51  7732                 ja 0x483b85
// 00483b53  742a                 je 0x483b7f
// 00483b55  8bc8                 mov ecx, eax
// 00483b57  81e901030000         sub ecx, 0x301
// 00483b5d  741a                 je 0x483b79
// 00483b5f  83e901               sub ecx, 1
// 00483b62  740f                 je 0x483b73
// 00483b64  83e901               sub ecx, 1
// 00483b67  0f85ac0b0000         jne 0x484719
// 00483b6d  b8d40a8200           mov eax, 0x820ad4
// 00483b72  c3                   ret 
// 00483b73  b8c40a8200           mov eax, 0x820ac4
// 00483b78  c3                   ret 
// 00483b79  b8ac0a8200           mov eax, 0x820aac
// 00483b7e  c3                   ret 
// 00483b7f  b8940a8200           mov eax, 0x820a94
// 00483b84  c3                   ret 
// 00483b85  8d88fffbffff         lea ecx, [eax - 0x401]
// 00483b8b  83f907               cmp ecx, 7
// 00483b8e  0f87850b0000         ja 0x484719
// 00483b94  ff248d20484800       jmp dword ptr [ecx*4 + 0x484820]
// 00483b9b  b8840a8200           mov eax, 0x820a84
// 00483ba0  c3                   ret 
// 00483ba1  b8740a8200           mov eax, 0x820a74
// 00483ba6  c3                   ret 
// 00483ba7  b8640a8200           mov eax, 0x820a64
// 00483bac  c3                   ret 
// 00483bad  b8580a8200           mov eax, 0x820a58
// 00483bb2  c3                   ret 
// 00483bb3  b8500a8200           mov eax, 0x820a50
// 00483bb8  c3                   ret 
// 00483bb9  b8480a8200           mov eax, 0x820a48
// 00483bbe  c3                   ret 
// 00483bbf  b83c0a8200           mov eax, 0x820a3c
// 00483bc4  c3                   ret 
// 00483bc5  b8280a8200           mov eax, 0x820a28
// 00483bca  c3                   ret 
// 00483bcb  b8180a8200           mov eax, 0x820a18
// 00483bd0  c3                   ret 
// 00483bd1  3d00060000           cmp eax, 0x600
// 00483bd6  773c                 ja 0x483c14
// 00483bd8  7434                 je 0x483c0e
// 00483bda  8d88fffaffff         lea ecx, [eax - 0x501]
// 00483be0  83f904               cmp ecx, 4
// 00483be3  0f87300b0000         ja 0x484719
// 00483be9  ff248d40484800       jmp dword ptr [ecx*4 + 0x484840]
// 00483bf0  b8040a8200           mov eax, 0x820a04
// 00483bf5  c3                   ret 
// 00483bf6  b8ec098200           mov eax, 0x8209ec
// 00483bfb  c3                   ret 
// 00483bfc  b8d8098200           mov eax, 0x8209d8
// 00483c01  c3                   ret 
// 00483c02  b8c4098200           mov eax, 0x8209c4
// 00483c07  c3                   ret 
// 00483c08  b8b0098200           mov eax, 0x8209b0
// 00483c0d  c3                   ret 
// 00483c0e  b8a8098200           mov eax, 0x8209a8
// 00483c13  c3                   ret 
// 00483c14  3d00080000           cmp eax, 0x800
// 00483c19  7736                 ja 0x483c51
// 00483c1b  742e                 je 0x483c4b
// 00483c1d  8d88fff9ffff         lea ecx, [eax - 0x601]
// 00483c23  83f903               cmp ecx, 3
// 00483c26  0f87ed0a0000         ja 0x484719
// 00483c2c  ff248d54484800       jmp dword ptr [ecx*4 + 0x484854]
// 00483c33  b8a0098200           mov eax, 0x8209a0
// 00483c38  c3                   ret 
// 00483c39  b894098200           mov eax, 0x820994
// 00483c3e  c3                   ret 
// 00483c3f  b880098200           mov eax, 0x820980
// 00483c44  c3                   ret 
// 00483c45  b86c098200           mov eax, 0x82096c
// 00483c4a  c3                   ret 
// 00483c4b  b85c098200           mov eax, 0x82095c
// 00483c50  c3                   ret 
// 00483c51  8bc8                 mov ecx, eax
// 00483c53  81e901080000         sub ecx, 0x801
// 00483c59  741d                 je 0x483c78
// 00483c5b  81e9ff000000         sub ecx, 0xff
// 00483c61  740f                 je 0x483c72
// 00483c63  83e901               sub ecx, 1
// 00483c66  0f85ad0a0000         jne 0x484719
// 00483c6c  b854098200           mov eax, 0x820954
// 00483c71  c3                   ret 
// 00483c72  b84c098200           mov eax, 0x82094c
// 00483c77  c3                   ret 
// 00483c78  b844098200           mov eax, 0x820944
// 00483c7d  c3                   ret 
// 00483c7e  b830098200           mov eax, 0x820930
// 00483c83  c3                   ret 
// 00483c84  3d110c0000           cmp eax, 0xc11
// 00483c89  0f878a0a0000         ja 0x484719
// 00483c8f  0f84e0000000         je 0x483d75
// 00483c95  8d88fff4ffff         lea ecx, [eax - 0xb01]
// 00483c9b  81f9f1000000         cmp ecx, 0xf1
// 00483ca1  0f87720a0000         ja 0x484719
// 00483ca7  0fb691e8484800       movzx edx, byte ptr [ecx + 0x4848e8]
// 00483cae  ff249564484800       jmp dword ptr [edx*4 + 0x484864]
// 00483cb5  b824098200           mov eax, 0x820924
// 00483cba  c3                   ret 
// 00483cbb  b810098200           mov eax, 0x820910
// 00483cc0  c3                   ret 
// 00483cc1  b8fc088200           mov eax, 0x8208fc
// 00483cc6  c3                   ret 
// 00483cc7  b8e0088200           mov eax, 0x8208e0
// 00483ccc  c3                   ret 
// 00483ccd  b8c8088200           mov eax, 0x8208c8
// 00483cd2  c3                   ret 
// 00483cd3  b8b0088200           mov eax, 0x8208b0
// 00483cd8  c3                   ret 
// 00483cd9  b88c088200           mov eax, 0x82088c
// 00483cde  c3                   ret 
// 00483cdf  b870088200           mov eax, 0x820870
// 00483ce4  c3                   ret 
// 00483ce5  b84c088200           mov eax, 0x82084c
// 00483cea  c3                   ret 
// 00483ceb  b830088200           mov eax, 0x820830
// 00483cf0  c3                   ret 
// 00483cf1  b820088200           mov eax, 0x820820
// 00483cf6  c3                   ret 
// 00483cf7  b810088200           mov eax, 0x820810
// 00483cfc  c3                   ret 
// 00483cfd  b8fc078200           mov eax, 0x8207fc
// 00483d02  c3                   ret 
// 00483d03  b8e0078200           mov eax, 0x8207e0
// 00483d08  c3                   ret 
// 00483d09  b8d0078200           mov eax, 0x8207d0
// 00483d0e  c3                   ret 
// 00483d0f  b8c0078200           mov eax, 0x8207c0
// 00483d14  c3                   ret 
// 00483d15  b8ac078200           mov eax, 0x8207ac
// 00483d1a  c3                   ret 
// 00483d1b  b898078200           mov eax, 0x820798
// 00483d20  c3                   ret 
// 00483d21  b88c078200           mov eax, 0x82078c
// 00483d26  c3                   ret 
// 00483d27  b87c078200           mov eax, 0x82077c
// 00483d2c  c3                   ret 
// 00483d2d  b86c078200           mov eax, 0x82076c
// 00483d32  c3                   ret 
// 00483d33  b85c078200           mov eax, 0x82075c
// 00483d38  c3                   ret 
// 00483d39  b84c078200           mov eax, 0x82074c
// 00483d3e  c3                   ret 
// 00483d3f  b83c078200           mov eax, 0x82073c
// 00483d44  c3                   ret 
// 00483d45  b82c078200           mov eax, 0x82072c
// 00483d4a  c3                   ret 
// 00483d4b  b818078200           mov eax, 0x820718
// 00483d50  c3                   ret 
// 00483d51  b804078200           mov eax, 0x820704
// 00483d56  c3                   ret 
// 00483d57  b8f4068200           mov eax, 0x8206f4
// 00483d5c  c3                   ret 
// 00483d5d  b8e4068200           mov eax, 0x8206e4
// 00483d62  c3                   ret 
// 00483d63  b8d8068200           mov eax, 0x8206d8
// 00483d68  c3                   ret 
// 00483d69  b8d0068200           mov eax, 0x8206d0
// 00483d6e  c3                   ret 
// 00483d6f  b8bc068200           mov eax, 0x8206bc
// 00483d74  c3                   ret 
// 00483d75  b8ac068200           mov eax, 0x8206ac
// 00483d7a  c3                   ret 
// 00483d7b  b898068200           mov eax, 0x820698
// 00483d80  c3                   ret 
// 00483d81  3d800d0000           cmp eax, 0xd80
// 00483d86  0f879e000000         ja 0x483e2a
// 00483d8c  0f8492000000         je 0x483e24
// 00483d92  8d889ff3ffff         lea ecx, [eax - 0xc61]
// 00483d98  81f9d3000000         cmp ecx, 0xd3
// 00483d9e  0f8775090000         ja 0x484719
// 00483da4  0fb6892c4a4800       movzx ecx, byte ptr [ecx + 0x484a2c]
// 00483dab  ff248ddc494800       jmp dword ptr [ecx*4 + 0x4849dc]
// 00483db2  b88c068200           mov eax, 0x82068c
// 00483db7  c3                   ret 
// 00483db8  b880068200           mov eax, 0x820680
// 00483dbd  c3                   ret 
// 00483dbe  b874068200           mov eax, 0x820674
// 00483dc3  c3                   ret 
// 00483dc4  b864068200           mov eax, 0x820664
// 00483dc9  c3                   ret 
// 00483dca  b854068200           mov eax, 0x820654
// 00483dcf  c3                   ret 
// 00483dd0  b844068200           mov eax, 0x820644
// 00483dd5  c3                   ret 
// 00483dd6  b834068200           mov eax, 0x820634
// 00483ddb  c3                   ret 
// 00483ddc  b824068200           mov eax, 0x820624
// 00483de1  c3                   ret 
// 00483de2  b814068200           mov eax, 0x820614
// 00483de7  c3                   ret 
// 00483de8  b804068200           mov eax, 0x820604
// 00483ded  c3                   ret 
// 00483dee  b8f4058200           mov eax, 0x8205f4
// 00483df3  c3                   ret 
// 00483df4  b8e0058200           mov eax, 0x8205e0
// 00483df9  c3                   ret 
// 00483dfa  b8d0058200           mov eax, 0x8205d0
// 00483dff  c3                   ret 
// 00483e00  b8bc058200           mov eax, 0x8205bc
// 00483e05  c3                   ret 
// 00483e06  b8a8058200           mov eax, 0x8205a8
// 00483e0b  c3                   ret 
// 00483e0c  b890058200           mov eax, 0x820590
// 00483e11  c3                   ret 
// 00483e12  b87c058200           mov eax, 0x82057c
// 00483e17  c3                   ret 
// 00483e18  b868058200           mov eax, 0x820568
// 00483e1d  c3                   ret 
// 00483e1e  b854058200           mov eax, 0x820554
// 00483e23  c3                   ret 
// 00483e24  b844058200           mov eax, 0x820544
// 00483e29  c3                   ret 
// 00483e2a  3d00100000           cmp eax, 0x1000
// 00483e2f  0f87a1000000         ja 0x483ed6
// 00483e35  0f8495000000         je 0x483ed0
// 00483e3b  8d8870f2ffff         lea ecx, [eax - 0xd90]
// 00483e41  83f951               cmp ecx, 0x51
// 00483e44  0f87cf080000         ja 0x484719
// 00483e4a  0fb691544b4800       movzx edx, byte ptr [ecx + 0x484b54]
// 00483e51  ff2495004b4800       jmp dword ptr [edx*4 + 0x484b00]
// 00483e58  b834058200           mov eax, 0x820534
// 00483e5d  c3                   ret 
// 00483e5e  b824058200           mov eax, 0x820524
// 00483e63  c3                   ret 
// 00483e64  b814058200           mov eax, 0x820514
// 00483e69  c3                   ret 
// 00483e6a  b8fc048200           mov eax, 0x8204fc
// 00483e6f  c3                   ret 
// 00483e70  b8e4048200           mov eax, 0x8204e4
// 00483e75  c3                   ret 
// 00483e76  b8cc048200           mov eax, 0x8204cc
// 00483e7b  c3                   ret 
// 00483e7c  b8b4048200           mov eax, 0x8204b4
// 00483e81  c3                   ret 
// 00483e82  b8a0048200           mov eax, 0x8204a0
// 00483e87  c3                   ret 
// 00483e88  b88c048200           mov eax, 0x82048c
// 00483e8d  c3                   ret 
// 00483e8e  b87c048200           mov eax, 0x82047c
// 00483e93  c3                   ret 
// 00483e94  b86c048200           mov eax, 0x82046c
// 00483e99  c3                   ret 
// 00483e9a  b85c048200           mov eax, 0x82045c
// 00483e9f  c3                   ret 
// 00483ea0  b844048200           mov eax, 0x820444
// 00483ea5  c3                   ret 
// 00483ea6  b82c048200           mov eax, 0x82042c
// 00483eab  c3                   ret 
// 00483eac  b814048200           mov eax, 0x820414
// 00483eb1  c3                   ret 
// 00483eb2  b8fc038200           mov eax, 0x8203fc
// 00483eb7  c3                   ret 
// 00483eb8  b8e8038200           mov eax, 0x8203e8
// 00483ebd  c3                   ret 
// 00483ebe  b8d4038200           mov eax, 0x8203d4
// 00483ec3  c3                   ret 
// 00483ec4  b8c4038200           mov eax, 0x8203c4
// 00483ec9  c3                   ret 
// 00483eca  b8b4038200           mov eax, 0x8203b4
// 00483ecf  c3                   ret 
// 00483ed0  b8a0038200           mov eax, 0x8203a0
// 00483ed5  c3                   ret 
// 00483ed6  3d00110000           cmp eax, 0x1100
// 00483edb  7736                 ja 0x483f13
// 00483edd  742e                 je 0x483f0d
// 00483edf  8d88ffefffff         lea ecx, [eax - 0x1001]
// 00483ee5  83f904               cmp ecx, 4
// 00483ee8  0f872b080000         ja 0x484719
// 00483eee  ff248da84b4800       jmp dword ptr [ecx*4 + 0x484ba8]
// 00483ef5  b88c038200           mov eax, 0x82038c
// 00483efa  c3                   ret 
// 00483efb  b870038200           mov eax, 0x820370
// 00483f00  c3                   ret 
// 00483f01  b858038200           mov eax, 0x820358
// 00483f06  c3                   ret 
// 00483f07  b844038200           mov eax, 0x820344
// 00483f0c  c3                   ret 
// 00483f0d  b834038200           mov eax, 0x820334
// 00483f12  c3                   ret 
// 00483f13  3d00140000           cmp eax, 0x1400
// 00483f18  0f879a000000         ja 0x483fb8
// 00483f1e  0f848e000000         je 0x483fb2
// 00483f24  3d00120000           cmp eax, 0x1200
// 00483f29  7727                 ja 0x483f52
// 00483f2b  741f                 je 0x483f4c
// 00483f2d  8bc8                 mov ecx, eax
// 00483f2f  81e901110000         sub ecx, 0x1101
// 00483f35  740f                 je 0x483f46
// 00483f37  83e901               sub ecx, 1
// 00483f3a  0f85d9070000         jne 0x484719
// 00483f40  b828038200           mov eax, 0x820328
// 00483f45  c3                   ret 
// 00483f46  b81c038200           mov eax, 0x82031c
// 00483f4b  c3                   ret 
// 00483f4c  b810038200           mov eax, 0x820310
// 00483f51  c3                   ret 
// 00483f52  3d00130000           cmp eax, 0x1300
// 00483f57  7748                 ja 0x483fa1
// 00483f59  7440                 je 0x483f9b
// 00483f5b  8d88ffedffff         lea ecx, [eax - 0x1201]
// 00483f61  83f906               cmp ecx, 6
// 00483f64  0f87af070000         ja 0x484719
// 00483f6a  ff248dbc4b4800       jmp dword ptr [ecx*4 + 0x484bbc]
// 00483f71  b804038200           mov eax, 0x820304
// 00483f76  c3                   ret 
// 00483f77  b8f8028200           mov eax, 0x8202f8
// 00483f7c  c3                   ret 
// 00483f7d  b8ec028200           mov eax, 0x8202ec
// 00483f82  c3                   ret 
// 00483f83  b8d8028200           mov eax, 0x8202d8
// 00483f88  c3                   ret 
// 00483f89  b8c4028200           mov eax, 0x8202c4
// 00483f8e  c3                   ret 
// 00483f8f  b8b4028200           mov eax, 0x8202b4
// 00483f94  c3                   ret 
// 00483f95  b89c028200           mov eax, 0x82029c
// 00483f9a  c3                   ret 
// 00483f9b  b890028200           mov eax, 0x820290
// 00483fa0  c3                   ret 
// 00483fa1  3d01130000           cmp eax, 0x1301
// 00483fa6  0f856d070000         jne 0x484719
// 00483fac  b878028200           mov eax, 0x820278
// 00483fb1  c3                   ret 
// 00483fb2  b870028200           mov eax, 0x820270
// 00483fb7  c3                   ret 
// 00483fb8  3d00150000           cmp eax, 0x1500
// 00483fbd  775a                 ja 0x484019
// 00483fbf  7452                 je 0x484013
// 00483fc1  8d88ffebffff         lea ecx, [eax - 0x1401]
// 00483fc7  83f909               cmp ecx, 9
// 00483fca  0f8749070000         ja 0x484719
// 00483fd0  ff248dd84b4800       jmp dword ptr [ecx*4 + 0x484bd8]
// 00483fd7  b85c028200           mov eax, 0x82025c
// 00483fdc  c3                   ret 
// 00483fdd  b850028200           mov eax, 0x820250
// 00483fe2  c3                   ret 
// 00483fe3  b83c028200           mov eax, 0x82023c
// 00483fe8  c3                   ret 
// 00483fe9  b834028200           mov eax, 0x820234
// 00483fee  c3                   ret 
// 00483fef  b824028200           mov eax, 0x820224
// 00483ff4  c3                   ret 
// 00483ff5  b818028200           mov eax, 0x820218
// 00483ffa  c3                   ret 
// 00483ffb  b80c028200           mov eax, 0x82020c
// 00484000  c3                   ret 
// 00484001  b800028200           mov eax, 0x820200
// 00484006  c3                   ret 
// 00484007  b8f4018200           mov eax, 0x8201f4
// 0048400c  c3                   ret 
// 0048400d  b8e8018200           mov eax, 0x8201e8
// 00484012  c3                   ret 
// 00484013  b8dc018200           mov eax, 0x8201dc
// 00484018  c3                   ret 
// 00484019  8d88ffeaffff         lea ecx, [eax - 0x1501]
// 0048401f  83f90e               cmp ecx, 0xe
// 00484022  0f87f1060000         ja 0x484719
// 00484028  ff248d004c4800       jmp dword ptr [ecx*4 + 0x484c00]
// 0048402f  b8d4018200           mov eax, 0x8201d4
// 00484034  c3                   ret 
// 00484035  b8c4018200           mov eax, 0x8201c4
// 0048403a  c3                   ret 
// 0048403b  b8bc018200           mov eax, 0x8201bc
// 00484040  c3                   ret 
// 00484041  b8ac018200           mov eax, 0x8201ac
// 00484046  c3                   ret 
// 00484047  b8a4018200           mov eax, 0x8201a4
// 0048404c  c3                   ret 
// 0048404d  b89c018200           mov eax, 0x82019c
// 00484052  c3                   ret 
// 00484053  b894018200           mov eax, 0x820194
// 00484058  c3                   ret 
// 00484059  b88c018200           mov eax, 0x82018c
// 0048405e  c3                   ret 
// 0048405f  b880018200           mov eax, 0x820180
// 00484064  c3                   ret 
// 00484065  b874018200           mov eax, 0x820174
// 0048406a  c3                   ret 
// 0048406b  b864018200           mov eax, 0x820164
// 00484070  c3                   ret 
// 00484071  b850018200           mov eax, 0x820150
// 00484076  c3                   ret 
// 00484077  b840018200           mov eax, 0x820140
// 0048407c  c3                   ret 
// 0048407d  b838018200           mov eax, 0x820138
// 00484082  c3                   ret 
// 00484083  b830018200           mov eax, 0x820130
// 00484088  c3                   ret 
// 00484089  b824018200           mov eax, 0x820124
// 0048408e  c3                   ret 
// 0048408f  3d00400000           cmp eax, 0x4000
// 00484094  0f871e040000         ja 0x4844b8
// 0048409a  0f8412040000         je 0x4844b2
// 004840a0  3d001f0000           cmp eax, 0x1f00
// 004840a5  0f87c1010000         ja 0x48426c
// 004840ab  0f84b5010000         je 0x484266
// 004840b1  3d00190000           cmp eax, 0x1900
// 004840b6  0f8798000000         ja 0x484154
// 004840bc  0f848c000000         je 0x48414e
// 004840c2  3d01170000           cmp eax, 0x1701
// 004840c7  7747                 ja 0x484110
// 004840c9  743f                 je 0x48410a
// 004840cb  3d03160000           cmp eax, 0x1603
// 004840d0  7727                 ja 0x4840f9
// 004840d2  741f                 je 0x4840f3
// 004840d4  8bc8                 mov ecx, eax
// 004840d6  81e901160000         sub ecx, 0x1601
// 004840dc  740f                 je 0x4840ed
// 004840de  83e901               sub ecx, 1
// 004840e1  0f8532060000         jne 0x484719
// 004840e7  b80c018200           mov eax, 0x82010c
// 004840ec  c3                   ret 
// 004840ed  b8fc008200           mov eax, 0x8200fc
// 004840f2  c3                   ret 
// 004840f3  b8e8008200           mov eax, 0x8200e8
// 004840f8  c3                   ret 
// 004840f9  3d00170000           cmp eax, 0x1700
// 004840fe  0f8515060000         jne 0x484719
// 00484104  b8d8008200           mov eax, 0x8200d8
// 00484109  c3                   ret 
// 0048410a  b8c8008200           mov eax, 0x8200c8
// 0048410f  c3                   ret 
// 00484110  3d01180000           cmp eax, 0x1801
// 00484115  7726                 ja 0x48413d
// 00484117  741e                 je 0x484137
// 00484119  3d02170000           cmp eax, 0x1702
// 0048411e  7411                 je 0x484131
// 00484120  3d00180000           cmp eax, 0x1800
// 00484125  0f85ee050000         jne 0x484719
// 0048412b  b8bc008200           mov eax, 0x8200bc
// 00484130  c3                   ret 
// 00484131  b8b0008200           mov eax, 0x8200b0
// 00484136  c3                   ret 
// 00484137  b8a4008200           mov eax, 0x8200a4
// 0048413c  c3                   ret 
// 0048413d  3d02180000           cmp eax, 0x1802
// 00484142  0f85d1050000         jne 0x484719
// 00484148  b898008200           mov eax, 0x820098
// 0048414d  c3                   ret 
// 0048414e  b888008200           mov eax, 0x820088
// 00484153  c3                   ret 
// 00484154  3d001a0000           cmp eax, 0x1a00
// 00484159  775a                 ja 0x4841b5
// 0048415b  7452                 je 0x4841af
// 0048415d  8d88ffe6ffff         lea ecx, [eax - 0x1901]
// 00484163  83f909               cmp ecx, 9
// 00484166  0f87ad050000         ja 0x484719
// 0048416c  ff248d3c4c4800       jmp dword ptr [ecx*4 + 0x484c3c]
// 00484173  b874008200           mov eax, 0x820074
// 00484178  c3                   ret 
// 00484179  b860008200           mov eax, 0x820060
// 0048417e  c3                   ret 
// 0048417f  b858008200           mov eax, 0x820058
// 00484184  c3                   ret 
// 00484185  b84c008200           mov eax, 0x82004c
// 0048418a  c3                   ret 
// 0048418b  b844008200           mov eax, 0x820044
// 00484190  c3                   ret 
// 00484191  b838008200           mov eax, 0x820038
// 00484196  c3                   ret 
// 00484197  b830008200           mov eax, 0x820030
// 0048419c  c3                   ret 
// 0048419d  b828008200           mov eax, 0x820028
// 004841a2  c3                   ret 
// 004841a3  b818008200           mov eax, 0x820018
// 004841a8  c3                   ret 
// 004841a9  b804008200           mov eax, 0x820004
// 004841ae  c3                   ret 
// 004841af  b8f8ff8100           mov eax, 0x81fff8
// 004841b4  c3                   ret 
// 004841b5  3d001d0000           cmp eax, 0x1d00
// 004841ba  7760                 ja 0x48421c
// 004841bc  7458                 je 0x484216
// 004841be  3d001c0000           cmp eax, 0x1c00
// 004841c3  7732                 ja 0x4841f7
// 004841c5  742a                 je 0x4841f1
// 004841c7  8bc8                 mov ecx, eax
// 004841c9  81e9001b0000         sub ecx, 0x1b00
// 004841cf  741a                 je 0x4841eb
// 004841d1  83e901               sub ecx, 1
// 004841d4  740f                 je 0x4841e5
// 004841d6  83e901               sub ecx, 1
// 004841d9  0f853a050000         jne 0x484719
// 004841df  b8f0ff8100           mov eax, 0x81fff0
// 004841e4  c3                   ret 
// 004841e5  b8e8ff8100           mov eax, 0x81ffe8
// 004841ea  c3                   ret 
// 004841eb  b8dcff8100           mov eax, 0x81ffdc
// 004841f0  c3                   ret 
// 004841f1  b8d0ff8100           mov eax, 0x81ffd0
// 004841f6  c3                   ret 
// 004841f7  8bc8                 mov ecx, eax
// 004841f9  81e9011c0000         sub ecx, 0x1c01
// 004841ff  740f                 je 0x484210
// 00484201  83e901               sub ecx, 1
// 00484204  0f850f050000         jne 0x484719
// 0048420a  b8c4ff8100           mov eax, 0x81ffc4
// 0048420f  c3                   ret 
// 00484210  b8b8ff8100           mov eax, 0x81ffb8
// 00484215  c3                   ret 
// 00484216  b8b0ff8100           mov eax, 0x81ffb0
// 0048421b  c3                   ret 
// 0048421c  3d001e0000           cmp eax, 0x1e00
// 00484221  7719                 ja 0x48423c
// 00484223  7411                 je 0x484236
// 00484225  3d011d0000           cmp eax, 0x1d01
// 0048422a  0f85e9040000         jne 0x484719
// 00484230  b8a4ff8100           mov eax, 0x81ffa4
// 00484235  c3                   ret 
// 00484236  b89cff8100           mov eax, 0x81ff9c
// 0048423b  c3                   ret 
// 0048423c  8bc8                 mov ecx, eax
// 0048423e  81e9011e0000         sub ecx, 0x1e01
// 00484244  741a                 je 0x484260
// 00484246  83e901               sub ecx, 1
// 00484249  740f                 je 0x48425a
// 0048424b  83e901               sub ecx, 1
// 0048424e  0f85c5040000         jne 0x484719
// 00484254  b894ff8100           mov eax, 0x81ff94
// 00484259  c3                   ret 
// 0048425a  b88cff8100           mov eax, 0x81ff8c
// 0048425f  c3                   ret 
// 00484260  b880ff8100           mov eax, 0x81ff80
// 00484265  c3                   ret 
// 00484266  b874ff8100           mov eax, 0x81ff74
// 0048426b  c3                   ret 
// 0048426c  3d00260000           cmp eax, 0x2600
// 00484271  0f8720010000         ja 0x484397
// 00484277  0f8414010000         je 0x484391
// 0048427d  3d00220000           cmp eax, 0x2200
// 00484282  0f8792000000         ja 0x48431a
// 00484288  0f8486000000         je 0x484314
// 0048428e  3d00200000           cmp eax, 0x2000
// 00484293  7732                 ja 0x4842c7
// 00484295  742a                 je 0x4842c1
// 00484297  8bc8                 mov ecx, eax
// 00484299  81e9011f0000         sub ecx, 0x1f01
// 0048429f  741a                 je 0x4842bb
// 004842a1  83e901               sub ecx, 1
// 004842a4  740f                 je 0x4842b5
// 004842a6  83e901               sub ecx, 1
// 004842a9  0f856a040000         jne 0x484719
// 004842af  b864ff8100           mov eax, 0x81ff64
// 004842b4  c3                   ret 
// 004842b5  b858ff8100           mov eax, 0x81ff58
// 004842ba  c3                   ret 
// 004842bb  b84cff8100           mov eax, 0x81ff4c
// 004842c0  c3                   ret 
// 004842c1  b83cff8100           mov eax, 0x81ff3c
// 004842c6  c3                   ret 
// 004842c7  3d03200000           cmp eax, 0x2003
// 004842cc  7727                 ja 0x4842f5
// 004842ce  741f                 je 0x4842ef
// 004842d0  8bc8                 mov ecx, eax
// 004842d2  81e901200000         sub ecx, 0x2001
// 004842d8  740f                 je 0x4842e9
// 004842da  83e901               sub ecx, 1
// 004842dd  0f8536040000         jne 0x484719
// 004842e3  b834ff8100           mov eax, 0x81ff34
// 004842e8  c3                   ret 
// 004842e9  b82cff8100           mov eax, 0x81ff2c
// 004842ee  c3                   ret 
// 004842ef  b824ff8100           mov eax, 0x81ff24
// 004842f4  c3                   ret 
// 004842f5  8bc8                 mov ecx, eax
// 004842f7  81e900210000         sub ecx, 0x2100
// 004842fd  740f                 je 0x48430e
// 004842ff  83e901               sub ecx, 1
// 00484302  0f8511040000         jne 0x484719
// 00484308  b818ff8100           mov eax, 0x81ff18
// 0048430d  c3                   ret 
// 0048430e  b80cff8100           mov eax, 0x81ff0c
// 00484313  c3                   ret 
// 00484314  b8f8fe8100           mov eax, 0x81fef8
// 00484319  c3                   ret 
// 0048431a  3d02240000           cmp eax, 0x2402
// 0048431f  7746                 ja 0x484367
// 00484321  743e                 je 0x484361
// 00484323  3d00240000           cmp eax, 0x2400
// 00484328  7726                 ja 0x484350
// 0048432a  741e                 je 0x48434a
// 0048432c  3d01220000           cmp eax, 0x2201
// 00484331  7411                 je 0x484344
// 00484333  3d00230000           cmp eax, 0x2300
// 00484338  0f85db030000         jne 0x484719
// 0048433e  b8e8fe8100           mov eax, 0x81fee8
// 00484343  c3                   ret 
// 00484344  b8d0fe8100           mov eax, 0x81fed0
// 00484349  c3                   ret 
// 0048434a  b8c0fe8100           mov eax, 0x81fec0
// 0048434f  c3                   ret 
// 00484350  3d01240000           cmp eax, 0x2401
// 00484355  0f85be030000         jne 0x484719
// 0048435b  b8acfe8100           mov eax, 0x81feac
// 00484360  c3                   ret 
// 00484361  b89cfe8100           mov eax, 0x81fe9c
// 00484366  c3                   ret 
// 00484367  8bc8                 mov ecx, eax
// 00484369  81e900250000         sub ecx, 0x2500
// 0048436f  741a                 je 0x48438b
// 00484371  83e901               sub ecx, 1
// 00484374  740f                 je 0x484385
// 00484376  83e901               sub ecx, 1
// 00484379  0f859a030000         jne 0x484719
// 0048437f  b88cfe8100           mov eax, 0x81fe8c
// 00484384  c3                   ret 
// 00484385  b87cfe8100           mov eax, 0x81fe7c
// 0048438a  c3                   ret 
// 0048438b  b868fe8100           mov eax, 0x81fe68
// 00484390  c3                   ret 
// 00484391  b85cfe8100           mov eax, 0x81fe5c
// 00484396  c3                   ret 
// 00484397  3d00290000           cmp eax, 0x2900
// 0048439c  0f878f000000         ja 0x484431
// 004843a2  0f8483000000         je 0x48442b
// 004843a8  3d00270000           cmp eax, 0x2700
// 004843ad  7719                 ja 0x4843c8
// 004843af  7411                 je 0x4843c2
// 004843b1  3d01260000           cmp eax, 0x2601
// 004843b6  0f855d030000         jne 0x484719
// 004843bc  b850fe8100           mov eax, 0x81fe50
// 004843c1  c3                   ret 
// 004843c2  b834fe8100           mov eax, 0x81fe34
// 004843c7  c3                   ret 
// 004843c8  3d00280000           cmp eax, 0x2800
// 004843cd  7732                 ja 0x484401
// 004843cf  742a                 je 0x4843fb
// 004843d1  8bc8                 mov ecx, eax
// 004843d3  81e901270000         sub ecx, 0x2701
// 004843d9  741a                 je 0x4843f5
// 004843db  83e901               sub ecx, 1
// 004843de  740f                 je 0x4843ef
// 004843e0  83e901               sub ecx, 1
// 004843e3  0f8530030000         jne 0x484719
// 004843e9  b81cfe8100           mov eax, 0x81fe1c
// 004843ee  c3                   ret 
// 004843ef  b800fe8100           mov eax, 0x81fe00
// 004843f4  c3                   ret 
// 004843f5  b8e4fd8100           mov eax, 0x81fde4
// 004843fa  c3                   ret 
// 004843fb  b8ccfd8100           mov eax, 0x81fdcc
// 00484400  c3                   ret 
// 00484401  8bc8                 mov ecx, eax
// 00484403  81e901280000         sub ecx, 0x2801
// 00484409  741a                 je 0x484425
// 0048440b  83e901               sub ecx, 1
// 0048440e  740f                 je 0x48441f
// 00484410  83e901               sub ecx, 1
// 00484413  0f8500030000         jne 0x484719
// 00484419  b8b8fd8100           mov eax, 0x81fdb8
// 0048441e  c3                   ret 
// 0048441f  b8a4fd8100           mov eax, 0x81fda4
// 00484424  c3                   ret 
// 00484425  b88cfd8100           mov eax, 0x81fd8c
// 0048442a  c3                   ret 
// 0048442b  b880fd8100           mov eax, 0x81fd80
// 00484430  c3                   ret 
// 00484431  3d00300000           cmp eax, 0x3000
// 00484436  7746                 ja 0x48447e
// 00484438  743e                 je 0x484478
// 0048443a  3d012a0000           cmp eax, 0x2a01
// 0048443f  7726                 ja 0x484467
// 00484441  741e                 je 0x484461
// 00484443  3d01290000           cmp eax, 0x2901
// 00484448  7411                 je 0x48445b
// 0048444a  3d002a0000           cmp eax, 0x2a00
// 0048444f  0f85c4020000         jne 0x484719
// 00484455  b868fd8100           mov eax, 0x81fd68
// 0048445a  c3                   ret 
// 0048445b  b85cfd8100           mov eax, 0x81fd5c
// 00484460  c3                   ret 
// 00484461  b844fd8100           mov eax, 0x81fd44
// 00484466  c3                   ret 
// 00484467  3d022a0000           cmp eax, 0x2a02
// 0048446c  0f85a7020000         jne 0x484719
// 00484472  b82cfd8100           mov eax, 0x81fd2c
// 00484477  c3                   ret 
// 00484478  b81cfd8100           mov eax, 0x81fd1c
// 0048447d  c3                   ret 
// 0048447e  8d88ffcfffff         lea ecx, [eax - 0x3001]
// 00484484  83f904               cmp ecx, 4
// 00484487  0f878c020000         ja 0x484719
// 0048448d  ff248d644c4800       jmp dword ptr [ecx*4 + 0x484c64]
// 00484494  b80cfd8100           mov eax, 0x81fd0c
// 00484499  c3                   ret 
// 0048449a  b8fcfc8100           mov eax, 0x81fcfc
// 0048449f  c3                   ret 
// 004844a0  b8ecfc8100           mov eax, 0x81fcec
// 004844a5  c3                   ret 
// 004844a6  b8dcfc8100           mov eax, 0x81fcdc
// 004844ab  c3                   ret 
// 004844ac  b8ccfc8100           mov eax, 0x81fccc
// 004844b1  c3                   ret 
// 004844b2  b8c0fc8100           mov eax, 0x81fcc0
// 004844b7  c3                   ret 
// 004844b8  3d00800000           cmp eax, 0x8000
// 004844bd  7748                 ja 0x484507
// 004844bf  7440                 je 0x484501
// 004844c1  8d88ffbfffff         lea ecx, [eax - 0x4001]
// 004844c7  83f906               cmp ecx, 6
// 004844ca  0f8749020000         ja 0x484719
// 004844d0  ff248d784c4800       jmp dword ptr [ecx*4 + 0x484c78]
// 004844d7  b8b4fc8100           mov eax, 0x81fcb4
// 004844dc  c3                   ret 
// 004844dd  b8a8fc8100           mov eax, 0x81fca8
// 004844e2  c3                   ret 
// 004844e3  b89cfc8100           mov eax, 0x81fc9c
// 004844e8  c3                   ret 
// 004844e9  b890fc8100           mov eax, 0x81fc90
// 004844ee  c3                   ret 
// 004844ef  b884fc8100           mov eax, 0x81fc84
// 004844f4  c3                   ret 
// 004844f5  b878fc8100           mov eax, 0x81fc78
// 004844fa  c3                   ret 
// 004844fb  b86cfc8100           mov eax, 0x81fc6c
// 00484500  c3                   ret 
// 00484501  b860fc8100           mov eax, 0x81fc60
// 00484506  c3                   ret 
// 00484507  3df5840000           cmp eax, 0x84f5
// 0048450c  0f872e010000         ja 0x484640
// 00484512  0f8422010000         je 0x48463a
// 00484518  8d88c97fffff         lea ecx, [eax - 0x8037]
// 0048451e  81f9f8000000         cmp ecx, 0xf8
// 00484524  0f87ef010000         ja 0x484719
// 0048452a  0fb689444d4800       movzx ecx, byte ptr [ecx + 0x484d44]
// 00484531  ff248d944c4800       jmp dword ptr [ecx*4 + 0x484c94]
// 00484538  b84cfc8100           mov eax, 0x81fc4c
// 0048453d  c3                   ret 
// 0048453e  b838fc8100           mov eax, 0x81fc38
// 00484543  c3                   ret 
// 00484544  b81cfc8100           mov eax, 0x81fc1c
// 00484549  c3                   ret 
// 0048454a  b804fc8100           mov eax, 0x81fc04
// 0048454f  c3                   ret 
// 00484550  b8f4fb8100           mov eax, 0x81fbf4
// 00484555  c3                   ret 
// 00484556  b8e4fb8100           mov eax, 0x81fbe4
// 0048455b  c3                   ret 
// 0048455c  b8d4fb8100           mov eax, 0x81fbd4
// 00484561  c3                   ret 
// 00484562  b8c4fb8100           mov eax, 0x81fbc4
// 00484567  c3                   ret 
// 00484568  b8acfb8100           mov eax, 0x81fbac
// 0048456d  c3                   ret 
// 0048456e  b898fb8100           mov eax, 0x81fb98
// 00484573  c3                   ret 
// 00484574  b880fb8100           mov eax, 0x81fb80
// 00484579  c3                   ret 
// 0048457a  b868fb8100           mov eax, 0x81fb68
// 0048457f  c3                   ret 
// 00484580  b850fb8100           mov eax, 0x81fb50
// 00484585  c3                   ret 
// 00484586  b838fb8100           mov eax, 0x81fb38
// 0048458b  c3                   ret 
// 0048458c  b820fb8100           mov eax, 0x81fb20
// 00484591  c3                   ret 
// 00484592  b80cfb8100           mov eax, 0x81fb0c
// 00484597  c3                   ret 
// 00484598  b8f8fa8100           mov eax, 0x81faf8
// 0048459d  c3                   ret 
// 0048459e  b8e0fa8100           mov eax, 0x81fae0
// 004845a3  c3                   ret 
// 004845a4  b8ccfa8100           mov eax, 0x81facc
// 004845a9  c3                   ret 
// 004845aa  b8b4fa8100           mov eax, 0x81fab4
// 004845af  c3                   ret 
// 004845b0  b898fa8100           mov eax, 0x81fa98
// 004845b5  c3                   ret 
// 004845b6  b87cfa8100           mov eax, 0x81fa7c
// 004845bb  c3                   ret 
// 004845bc  b860fa8100           mov eax, 0x81fa60
// 004845c1  c3                   ret 
// 004845c2  b844fa8100           mov eax, 0x81fa44
// 004845c7  c3                   ret 
// 004845c8  b824fa8100           mov eax, 0x81fa24
// 004845cd  c3                   ret 
// 004845ce  b804fa8100           mov eax, 0x81fa04
// 004845d3  c3                   ret 
// 004845d4  b8e0f98100           mov eax, 0x81f9e0
// 004845d9  c3                   ret 
// 004845da  b8bcf98100           mov eax, 0x81f9bc
// 004845df  c3                   ret 
// 004845e0  b89cf98100           mov eax, 0x81f99c
// 004845e5  c3                   ret 
// 004845e6  b87cf98100           mov eax, 0x81f97c
// 004845eb  c3                   ret 
// 004845ec  b860f98100           mov eax, 0x81f960
// 004845f1  c3                   ret 
// 004845f2  b844f98100           mov eax, 0x81f944
// 004845f7  c3                   ret 
// 004845f8  b828f98100           mov eax, 0x81f928
// 004845fd  c3                   ret 
// 004845fe  b80cf98100           mov eax, 0x81f90c
// 00484603  c3                   ret 
// 00484604  b8e8f88100           mov eax, 0x81f8e8
// 00484609  c3                   ret 
// 0048460a  b8c8f88100           mov eax, 0x81f8c8
// 0048460f  c3                   ret 
// 00484610  b8b8f88100           mov eax, 0x81f8b8
// 00484615  c3                   ret 
// 00484616  b8a4f88100           mov eax, 0x81f8a4
// 0048461b  c3                   ret 
// 0048461c  b888f88100           mov eax, 0x81f888
// 00484621  c3                   ret 
// 00484622  b878f88100           mov eax, 0x81f878
// 00484627  c3                   ret 
// 00484628  b860f88100           mov eax, 0x81f860
// 0048462d  c3                   ret 
// 0048462e  b848f88100           mov eax, 0x81f848
// 00484633  c3                   ret 
// 00484634  b830f88100           mov eax, 0x81f830
// 00484639  c3                   ret 
// 0048463a  b814f88100           mov eax, 0x81f814
// 0048463f  c3                   ret 
// 00484640  3d488b0000           cmp eax, 0x8b48
// 00484645  7727                 ja 0x48466e
// 00484647  741f                 je 0x484668
// 00484649  8bc8                 mov ecx, eax
// 0048464b  81e907850000         sub ecx, 0x8507
// 00484651  740f                 je 0x484662
// 00484653  83e901               sub ecx, 1
// 00484656  0f85bd000000         jne 0x484719
// 0048465c  b800f88100           mov eax, 0x81f800
// 00484661  c3                   ret 
// 00484662  b8ecf78100           mov eax, 0x81f7ec
// 00484667  c3                   ret 
// 00484668  b8d4f78100           mov eax, 0x81f7d4
// 0048466d  c3                   ret 
// 0048466e  3d00000100           cmp eax, 0x10000
// 00484673  0f87a0000000         ja 0x484719
// 00484679  0f8494000000         je 0x484713
// 0048467f  8d88b074ffff         lea ecx, [eax - 0x8b50]
// 00484685  83f914               cmp ecx, 0x14
// 00484688  0f878b000000         ja 0x484719
// 0048468e  ff248d404e4800       jmp dword ptr [ecx*4 + 0x484e40]
// 00484695  b8c0f78100           mov eax, 0x81f7c0
// 0048469a  c3                   ret 
// 0048469b  b8acf78100           mov eax, 0x81f7ac
// 004846a0  c3                   ret 
// 004846a1  b898f78100           mov eax, 0x81f798
// 004846a6  c3                   ret 
// 004846a7  b888f78100           mov eax, 0x81f788
// 004846ac  c3                   ret 
// 004846ad  b878f78100           mov eax, 0x81f778
// 004846b2  c3                   ret 
// 004846b3  b868f78100           mov eax, 0x81f768
// 004846b8  c3                   ret 
// 004846b9  b85cf78100           mov eax, 0x81f75c
// 004846be  c3                   ret 
// 004846bf  b848f78100           mov eax, 0x81f748
// 004846c4  c3                   ret 
// 004846c5  b834f78100           mov eax, 0x81f734
// 004846ca  c3                   ret 
// 004846cb  b820f78100           mov eax, 0x81f720
// 004846d0  c3                   ret 
// 004846d1  b80cf78100           mov eax, 0x81f70c
// 004846d6  c3                   ret 
// 004846d7  b8f8f68100           mov eax, 0x81f6f8
// 004846dc  c3                   ret 
// 004846dd  b8e4f68100           mov eax, 0x81f6e4
// 004846e2  c3                   ret 
// 004846e3  b8d0f68100           mov eax, 0x81f6d0
// 004846e8  c3                   ret 
// 004846e9  b8bcf68100           mov eax, 0x81f6bc
// 004846ee  c3                   ret 
// 004846ef  b8a8f68100           mov eax, 0x81f6a8
// 004846f4  c3                   ret 
// 004846f5  b894f68100           mov eax, 0x81f694
// 004846fa  c3                   ret 
// 004846fb  b878f68100           mov eax, 0x81f678
// 00484700  c3                   ret 
// 00484701  b85cf68100           mov eax, 0x81f65c
// 00484706  c3                   ret 
// 00484707  b844f68100           mov eax, 0x81f644
// 0048470c  c3                   ret 
// 0048470d  b824f68100           mov eax, 0x81f624
// 00484712  c3                   ret 
// 00484713  b818f68100           mov eax, 0x81f618
// 00484718  c3                   ret 
// 00484719  50                   push eax
// 0048471a  6810f68100           push 0x81f610
// 0048471f  68c8fa9600           push 0x96fac8
// 00484724  ff1530288000         call dword ptr [0x802830]
// 0048472a  83c40c               add esp, 0xc
// 0048472d  b8c8fa9600           mov eax, 0x96fac8
// 00484732  c3                   ret 
// 00484733  90                   nop 
// 00484734  6e                   outsb dx, byte ptr [esi]
// 00484735  3a4800               cmp cl, byte ptr [eax]
// 00484738  743a                 je 0x484774
// 0048473a  48                   dec eax
// 0048473b  0026                 add byte ptr [esi], ah
// 0048473d  3a4800               cmp cl, byte ptr [eax]
// 00484740  4a                   dec edx
// 00484741  3a4800               cmp cl, byte ptr [eax]
// 00484744  50                   push eax
// 00484745  3a4800               cmp cl, byte ptr [eax]
// 00484748  56                   push esi
// 00484749  3a4800               cmp cl, byte ptr [eax]
// 0048474c  5c                   pop esp
// 0048474d  3a4800               cmp cl, byte ptr [eax]
// 00484750  623a                 bound edi, qword ptr [edx]
// 00484752  48                   dec eax
// 00484753  002c3a               add byte ptr [edx + edi], ch
// 00484756  48                   dec eax
// 00484757  00683a               add byte ptr [eax + 0x3a], ch
// 0048475a  48                   dec eax
// 0048475b  0032                 add byte ptr [edx], dh
// 0048475d  3a4800               cmp cl, byte ptr [eax]
// 00484760  383a                 cmp byte ptr [edx], bh
// 00484762  48                   dec eax
// 00484763  003e                 add byte ptr [esi], bh
// 00484765  3a4800               cmp cl, byte ptr [eax]
// 00484768  44                   inc esp
// 00484769  3a4800               cmp cl, byte ptr [eax]
// 0048476c  194748               sbb dword ptr [edi + 0x48], eax
// 0048476f  0000                 add byte ptr [eax], al
// 00484771  0102                 add dword ptr [edx], eax
// 00484773  03040506070809       add eax, dword ptr [eax + 0x9080706]
// 0048477a  0e                   push cs
// 0048477b  0e                   push cs
// 0048477c  0e                   push cs
// 0048477d  0e                   push cs
// 0048477e  0e                   push cs
// 0048477f  0e                   push cs
// 00484780  0a0e                 or cl, byte ptr [esi]
// 00484782  0e                   push cs
// 00484783  0e                   push cs
// 00484784  0e                   push cs
// 00484785  0e                   push cs
// 00484786  0e                   push cs
// 00484787  0e                   push cs
// 00484788  0e                   push cs
// 00484789  0e                   push cs
// 0048478a  0e                   push cs
// 0048478b  0e                   push cs
// 0048478c  0e                   push cs
// 0048478d  0e                   push cs
// 0048478e  0e                   push cs
// 0048478f  0e                   push cs
// 00484790  0b0e                 or ecx, dword ptr [esi]
// 00484792  0e                   push cs
// 00484793  0e                   push cs
// 00484794  0e                   push cs
// 00484795  0e                   push cs
// 00484796  0e                   push cs
// 00484797  0e                   push cs
// 00484798  0e                   push cs
// 00484799  0e                   push cs
// 0048479a  0e                   push cs
// 0048479b  0e                   push cs
// 0048479c  0e                   push cs
// 0048479d  0e                   push cs
// 0048479e  0e                   push cs
// 0048479f  0e                   push cs
// 004847a0  0e                   push cs
// 004847a1  0e                   push cs
// 004847a2  0e                   push cs
// 004847a3  0e                   push cs
// 004847a4  0e                   push cs
// 004847a5  0e                   push cs
// 004847a6  0e                   push cs
// 004847a7  0e                   push cs
// 004847a8  0e                   push cs
// 004847a9  0e                   push cs
// 004847aa  0e                   push cs
// 004847ab  0e                   push cs
// 004847ac  0e                   push cs
// 004847ad  0e                   push cs
// 004847ae  0e                   push cs
// 004847af  0e                   push cs
// 004847b0  0c0e                 or al, 0xe
// 004847b2  0e                   push cs
// 004847b3  0e                   push cs
// 004847b4  0e                   push cs
// 004847b5  0e                   push cs
// 004847b6  0e                   push cs
// 004847b7  0e                   push cs
// 004847b8  0e                   push cs
// 004847b9  0e                   push cs
// 004847ba  0e                   push cs
// 004847bb  0e                   push cs
// 004847bc  0e                   push cs
// 004847bd  0e                   push cs
// 004847be  0e                   push cs
// 004847bf  0e                   push cs
// 004847c0  0e                   push cs
// 004847c1  0e                   push cs
// 004847c2  0e                   push cs
// 004847c3  0e                   push cs
// 004847c4  0e                   push cs
// 004847c5  0e                   push cs
// 004847c6  0e                   push cs
// 004847c7  0e                   push cs
// 004847c8  0e                   push cs
// 004847c9  0e                   push cs
// 004847ca  0e                   push cs
// 004847cb  0e                   push cs
// 004847cc  0e                   push cs
// 004847cd  0e                   push cs
// 004847ce  0e                   push cs
// 004847cf  0e                   push cs
// 004847d0  0e                   push cs
// 004847d1  0e                   push cs
// 004847d2  0e                   push cs
// 004847d3  0e                   push cs
// 004847d4  0e                   push cs
// 004847d5  0e                   push cs
// 004847d6  0e                   push cs
// 004847d7  0e                   push cs
// 004847d8  0e                   push cs
// 004847d9  0e                   push cs
// 004847da  0e                   push cs
// 004847db  0e                   push cs
// 004847dc  0e                   push cs
// 004847dd  0e                   push cs
// 004847de  0e                   push cs
// 004847df  0e                   push cs
// 004847e0  0e                   push cs
// 004847e1  0e                   push cs
// 004847e2  0e                   push cs
// 004847e3  0e                   push cs
// 004847e4  0e                   push cs
// 004847e5  0e                   push cs
// 004847e6  0e                   push cs
// 004847e7  0e                   push cs
// 004847e8  0e                   push cs
// 004847e9  0e                   push cs
// 004847ea  0e                   push cs
// 004847eb  0e                   push cs
// 004847ec  0e                   push cs
// 004847ed  0e                   push cs
// 004847ee  0e                   push cs
// 004847ef  0e                   push cs
// 004847f0  0d8d49009f           or eax, 0x9f00498d
// 004847f5  3a4800               cmp cl, byte ptr [eax]
// 004847f8  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 004847f9  3a4800               cmp cl, byte ptr [eax]
// 004847fc  ab                   stosd dword ptr es:[edi], eax
// 004847fd  3a4800               cmp cl, byte ptr [eax]
// 00484800  b13a                 mov cl, 0x3a
// 00484802  48                   dec eax
// 00484803  00dc                 add ah, bl
// 00484805  3a4800               cmp cl, byte ptr [eax]
// 00484808  e23a                 loop 0x484844
// 0048480a  48                   dec eax
// 0048480b  00e8                 add al, ch
// 0048480d  3a4800               cmp cl, byte ptr [eax]
// 00484810  ee                   out dx, al
// 00484811  3a4800               cmp cl, byte ptr [eax]
// 00484814  f4                   hlt 
// 00484815  3a4800               cmp cl, byte ptr [eax]
// 00484818  fa                   cli 
// 00484819  3a4800               cmp cl, byte ptr [eax]
// 0048481c  003b                 add byte ptr [ebx], bh
// 0048481e  48                   dec eax
// 0048481f  009b3b4800a1         add byte ptr [ebx - 0x5effb7c5], bl
// 00484825  3b4800               cmp ecx, dword ptr [eax]
// 00484828  a7                   cmpsd dword ptr [esi], dword ptr es:[edi]
// 00484829  3b4800               cmp ecx, dword ptr [eax]
// 0048482c  ad                   lodsd eax, dword ptr [esi]
// 0048482d  3b4800               cmp ecx, dword ptr [eax]
// 00484830  b33b                 mov bl, 0x3b
// 00484832  48                   dec eax
// 00484833  00b93b4800bf         add byte ptr [ecx - 0x40ffb7c5], bh
// 00484839  3b4800               cmp ecx, dword ptr [eax]
// 0048483c  c53b                 lds edi, ptr [ebx]
// 0048483e  48                   dec eax
// 0048483f  00f0                 add al, dh
// 00484841  3b4800               cmp ecx, dword ptr [eax]
// 00484844  f63b                 idiv byte ptr [ebx]
// 00484846  48                   dec eax
// 00484847  00fc                 add ah, bh
// 00484849  3b4800               cmp ecx, dword ptr [eax]
// 0048484c  023c48               add bh, byte ptr [eax + ecx*2]
// 0048484f  0008                 add byte ptr [eax], cl
// 00484851  3c48                 cmp al, 0x48
// 00484853  0033                 add byte ptr [ebx], dh
// 00484855  3c48                 cmp al, 0x48
// 00484857  0039                 add byte ptr [ecx], bh
// 00484859  3c48                 cmp al, 0x48
// 0048485b  003f                 add byte ptr [edi], bh
// 0048485d  3c48                 cmp al, 0x48
// 0048485f  00453c               add byte ptr [ebp + 0x3c], al
// 00484862  48                   dec eax
// 00484863  00bb3c4800c1         add byte ptr [ebx - 0x3effb7c4], bh
// 00484869  3c48                 cmp al, 0x48
// 0048486b  00c7                 add bh, al
// 0048486d  3c48                 cmp al, 0x48
// 0048486f  00cd                 add ch, cl
// 00484871  3c48                 cmp al, 0x48
// 00484873  00d3                 add bl, dl
// 00484875  3c48                 cmp al, 0x48
// 00484877  00d9                 add cl, bl
// 00484879  3c48                 cmp al, 0x48
// 0048487b  00df                 add bh, bl
// 0048487d  3c48                 cmp al, 0x48
// 0048487f  00e5                 add ch, ah
// 00484881  3c48                 cmp al, 0x48
// 00484883  00eb                 add bl, ch
// 00484885  3c48                 cmp al, 0x48
// 00484887  00f1                 add cl, dh
// 00484889  3c48                 cmp al, 0x48
// 0048488b  00f7                 add bh, dh
// 0048488d  3c48                 cmp al, 0x48
// 0048488f  00fd                 add ch, bh
// 00484891  3c48                 cmp al, 0x48
// 00484893  0003                 add byte ptr [ebx], al
// 00484895  3d4800093d           cmp eax, 0x3d090048
// 0048489a  48                   dec eax
// 0048489b  000f                 add byte ptr [edi], cl
// 0048489d  3d4800573d           cmp eax, 0x3d570048
// 004848a2  48                   dec eax
// 004848a3  00513d               add byte ptr [ecx + 0x3d], dl
// 004848a6  48                   dec eax
// 004848a7  004b3d               add byte ptr [ebx + 0x3d], cl
// 004848aa  48                   dec eax
// 004848ab  005d3d               add byte ptr [ebp + 0x3d], bl
// 004848ae  48                   dec eax
// 004848af  00b53c48001b         add byte ptr [ebp + 0x1b00483c], dh
// 004848b5  3d4800693d           cmp eax, 0x3d690048
// 004848ba  48                   dec eax
// 004848bb  0039                 add byte ptr [ecx], bh
// 004848bd  3d4800453d           cmp eax, 0x3d450048
// 004848c2  48                   dec eax
// 004848c3  003f                 add byte ptr [edi], bh
// 004848c5  3d4800333d           cmp eax, 0x3d330048
// 004848ca  48                   dec eax
// 004848cb  00633d               add byte ptr [ebx + 0x3d], ah
// 004848ce  48                   dec eax
// 004848cf  0027                 add byte ptr [edi], ah
// 004848d1  3d48002d3d           cmp eax, 0x3d2d0048
// 004848d6  48                   dec eax
// 004848d7  0021                 add byte ptr [ecx], ah
// 004848d9  3d48006f3d           cmp eax, 0x3d6f0048
// 004848de  48                   dec eax
// 004848df  00153d480019         add byte ptr [0x1900483d], dl
// 004848e5  47                   inc edi
// 004848e6  48                   dec eax
// 004848e7  0000                 add byte ptr [eax], al
// 004848e9  0102                 add dword ptr [edx], eax
// 004848eb  03040506070820       add eax, dword ptr [eax + 0x20080706]
// 004848f2  2020                 and byte ptr [eax], ah
// 004848f4  2020                 and byte ptr [eax], ah
// 004848f6  2009                 and byte ptr [ecx], cl
// 004848f8  0a0b                 or cl, byte ptr [ebx]
// 004848fa  0c20                 or al, 0x20
// 004848fc  2020                 and byte ptr [eax], ah
// 004848fe  2020                 and byte ptr [eax], ah
// 00484900  2020                 and byte ptr [eax], ah
// 00484902  2020                 and byte ptr [eax], ah
// 00484904  2020                 and byte ptr [eax], ah
// 00484906  200d0e20200f         and byte ptr [0xf20200e], cl
// 0048490c  2020                 and byte ptr [eax], ah
// 0048490e  2020                 and byte ptr [eax], ah
// 00484910  2020                 and byte ptr [eax], ah
// 00484912  2020                 and byte ptr [eax], ah
// 00484914  2020                 and byte ptr [eax], ah
// 00484916  2020                 and byte ptr [eax], ah
// 00484918  2020                 and byte ptr [eax], ah
// 0048491a  2020                 and byte ptr [eax], ah
// 0048491c  2020                 and byte ptr [eax], ah
// 0048491e  2020                 and byte ptr [eax], ah
// 00484920  2020                 and byte ptr [eax], ah
// 00484922  2020                 and byte ptr [eax], ah
// 00484924  2020                 and byte ptr [eax], ah
// 00484926  2020                 and byte ptr [eax], ah
// 00484928  1011                 adc byte ptr [ecx], dl
// 0048492a  2012                 and byte ptr [edx], dl
// 0048492c  2020                 and byte ptr [eax], ah
// 0048492e  2020                 and byte ptr [eax], ah
// 00484930  2020                 and byte ptr [eax], ah
// 00484932  2020                 and byte ptr [eax], ah
// 00484934  2020                 and byte ptr [eax], ah
// 00484936  2013                 and byte ptr [ebx], dl
// 00484938  2020                 and byte ptr [eax], ah
// 0048493a  2020                 and byte ptr [eax], ah
// 0048493c  2020                 and byte ptr [eax], ah
// 0048493e  1420                 adc al, 0x20
// 00484940  2020                 and byte ptr [eax], ah
// 00484942  2020                 and byte ptr [eax], ah
// 00484944  2020                 and byte ptr [eax], ah
// 00484946  201520202020         and byte ptr [0x20202020], dl
// 0048494c  2020                 and byte ptr [eax], ah
// 0048494e  2020                 and byte ptr [eax], ah
// 00484950  2020                 and byte ptr [eax], ah
// 00484952  2020                 and byte ptr [eax], ah
// 00484954  2020                 and byte ptr [eax], ah
// 00484956  2020                 and byte ptr [eax], ah
// 00484958  16                   push ss
// 00484959  2020                 and byte ptr [eax], ah
// 0048495b  2020                 and byte ptr [eax], ah
// 0048495d  2020                 and byte ptr [eax], ah
// 0048495f  2020                 and byte ptr [eax], ah
// 00484961  2020                 and byte ptr [eax], ah
// 00484963  2020                 and byte ptr [eax], ah
// 00484965  2020                 and byte ptr [eax], ah
// 00484967  2020                 and byte ptr [eax], ah
// 00484969  2020                 and byte ptr [eax], ah
// 0048496b  2020                 and byte ptr [eax], ah
// 0048496d  2020                 and byte ptr [eax], ah
// 0048496f  2020                 and byte ptr [eax], ah
// 00484971  2020                 and byte ptr [eax], ah
// 00484973  2020                 and byte ptr [eax], ah
// 00484975  2020                 and byte ptr [eax], ah
// 00484977  17                   pop ss
// 00484978  2020                 and byte ptr [eax], ah
// 0048497a  2020                 and byte ptr [eax], ah
// 0048497c  2020                 and byte ptr [eax], ah
// 0048497e  2020                 and byte ptr [eax], ah
// 00484980  2020                 and byte ptr [eax], ah
// 00484982  2020                 and byte ptr [eax], ah
// 00484984  2020                 and byte ptr [eax], ah
// 00484986  2020                 and byte ptr [eax], ah
// 00484988  1820                 sbb byte ptr [eax], ah
// 0048498a  2020                 and byte ptr [eax], ah
// 0048498c  2020                 and byte ptr [eax], ah
// 0048498e  2020                 and byte ptr [eax], ah
// 00484990  2020                 and byte ptr [eax], ah
// 00484992  2020                 and byte ptr [eax], ah
// 00484994  2020                 and byte ptr [eax], ah
// 00484996  2020                 and byte ptr [eax], ah
// 00484998  2020                 and byte ptr [eax], ah
// 0048499a  2020                 and byte ptr [eax], ah
// 0048499c  2020                 and byte ptr [eax], ah
// 0048499e  2020                 and byte ptr [eax], ah
// 004849a0  2020                 and byte ptr [eax], ah
// 004849a2  2020                 and byte ptr [eax], ah
// 004849a4  2020                 and byte ptr [eax], ah
// 004849a6  2019                 and byte ptr [ecx], bl
// 004849a8  2020                 and byte ptr [eax], ah
// 004849aa  2020                 and byte ptr [eax], ah
// 004849ac  2020                 and byte ptr [eax], ah
// 004849ae  2020                 and byte ptr [eax], ah
// 004849b0  2020                 and byte ptr [eax], ah
// 004849b2  2020                 and byte ptr [eax], ah
// 004849b4  2020                 and byte ptr [eax], ah
// 004849b6  201a                 and byte ptr [edx], bl
// 004849b8  2020                 and byte ptr [eax], ah
// 004849ba  2020                 and byte ptr [eax], ah
// 004849bc  2020                 and byte ptr [eax], ah
// 004849be  2020                 and byte ptr [eax], ah
// 004849c0  2020                 and byte ptr [eax], ah
// 004849c2  2020                 and byte ptr [eax], ah
// 004849c4  2020                 and byte ptr [eax], ah
// 004849c6  201b                 and byte ptr [ebx], bl
// 004849c8  1c1d                 sbb al, 0x1d
// 004849ca  2020                 and byte ptr [eax], ah
// 004849cc  2020                 and byte ptr [eax], ah
// 004849ce  2020                 and byte ptr [eax], ah
// 004849d0  2020                 and byte ptr [eax], ah
// 004849d2  2020                 and byte ptr [eax], ah
// 004849d4  2020                 and byte ptr [eax], ah
// 004849d6  2020                 and byte ptr [eax], ah
// 004849d8  1e                   push ds
// 004849d9  1f                   pop ds
// 004849da  8bff                 mov edi, edi
// 004849dc  1e                   push ds
// 004849dd  3e48                 dec eax
// 004849df  0018                 add byte ptr [eax], bl
// 004849e1  3e48                 dec eax
// 004849e3  0012                 add byte ptr [edx], dl
// 004849e5  3e48                 dec eax
// 004849e7  00b23d4800b8         add byte ptr [edx - 0x47ffb7c3], dh
// 004849ed  3d4800be3d           cmp eax, 0x3dbe0048
// 004849f2  48                   dec eax
// 004849f3  00c4                 add ah, al
// 004849f5  3d4800ca3d           cmp eax, 0x3dca0048
// 004849fa  48                   dec eax
// 004849fb  00d0                 add al, dl
// 004849fd  3d4800d63d           cmp eax, 0x3dd60048
// 00484a02  48                   dec eax
// 00484a03  00dc                 add ah, bl
// 00484a05  3d4800e23d           cmp eax, 0x3de20048
// 00484a0a  48                   dec eax
// 00484a0b  00e8                 add al, ch
// 00484a0d  3d4800ee3d           cmp eax, 0x3dee0048
// 00484a12  48                   dec eax
// 00484a13  00f4                 add ah, dh
// 00484a15  3d4800fa3d           cmp eax, 0x3dfa0048
// 00484a1a  48                   dec eax
// 00484a1b  0000                 add byte ptr [eax], al
// 00484a1d  3e48                 dec eax
// 00484a1f  0006                 add byte ptr [esi], al
// 00484a21  3e48                 dec eax
// 00484a23  000c3e               add byte ptr [esi + edi], cl
// 00484a26  48                   dec eax
// 00484a27  0019                 add byte ptr [ecx], bl
// 00484a29  47                   inc edi
// 00484a2a  48                   dec eax
// 00484a2b  0000                 add byte ptr [eax], al
// 00484a2d  0102                 add dword ptr [edx], eax
// 00484a2f  1313                 adc edx, dword ptr [ebx]
// 00484a31  1313                 adc edx, dword ptr [ebx]
// 00484a33  1313                 adc edx, dword ptr [ebx]
// 00484a35  1313                 adc edx, dword ptr [ebx]
// 00484a37  1313                 adc edx, dword ptr [ebx]
// 00484a39  1313                 adc edx, dword ptr [ebx]
// 00484a3b  1313                 adc edx, dword ptr [ebx]
// 00484a3d  1313                 adc edx, dword ptr [ebx]
// 00484a3f  1313                 adc edx, dword ptr [ebx]
// 00484a41  1313                 adc edx, dword ptr [ebx]
// 00484a43  1313                 adc edx, dword ptr [ebx]
// 00484a45  1313                 adc edx, dword ptr [ebx]
// 00484a47  1313                 adc edx, dword ptr [ebx]
// 00484a49  1313                 adc edx, dword ptr [ebx]
// 00484a4b  1313                 adc edx, dword ptr [ebx]
// 00484a4d  1313                 adc edx, dword ptr [ebx]
// 00484a4f  1313                 adc edx, dword ptr [ebx]
// 00484a51  1313                 adc edx, dword ptr [ebx]
// 00484a53  1313                 adc edx, dword ptr [ebx]
// 00484a55  1313                 adc edx, dword ptr [ebx]
// 00484a57  1313                 adc edx, dword ptr [ebx]
// 00484a59  1313                 adc edx, dword ptr [ebx]
// 00484a5b  1313                 adc edx, dword ptr [ebx]
// 00484a5d  1313                 adc edx, dword ptr [ebx]
// 00484a5f  1313                 adc edx, dword ptr [ebx]
// 00484a61  1313                 adc edx, dword ptr [ebx]
// 00484a63  1313                 adc edx, dword ptr [ebx]
// 00484a65  1313                 adc edx, dword ptr [ebx]
// 00484a67  1313                 adc edx, dword ptr [ebx]
// 00484a69  1313                 adc edx, dword ptr [ebx]
// 00484a6b  1313                 adc edx, dword ptr [ebx]
// 00484a6d  1313                 adc edx, dword ptr [ebx]
// 00484a6f  1313                 adc edx, dword ptr [ebx]
// 00484a71  1313                 adc edx, dword ptr [ebx]
// 00484a73  1313                 adc edx, dword ptr [ebx]
// 00484a75  1313                 adc edx, dword ptr [ebx]
// 00484a77  1313                 adc edx, dword ptr [ebx]
// 00484a79  1313                 adc edx, dword ptr [ebx]
// 00484a7b  1313                 adc edx, dword ptr [ebx]
// 00484a7d  1313                 adc edx, dword ptr [ebx]
// 00484a7f  1313                 adc edx, dword ptr [ebx]
// 00484a81  1313                 adc edx, dword ptr [ebx]
// 00484a83  1313                 adc edx, dword ptr [ebx]
// 00484a85  1313                 adc edx, dword ptr [ebx]
// 00484a87  1313                 adc edx, dword ptr [ebx]
// 00484a89  1313                 adc edx, dword ptr [ebx]
// 00484a8b  1313                 adc edx, dword ptr [ebx]
// 00484a8d  1313                 adc edx, dword ptr [ebx]
// 00484a8f  1313                 adc edx, dword ptr [ebx]
// 00484a91  1313                 adc edx, dword ptr [ebx]
// 00484a93  1313                 adc edx, dword ptr [ebx]
// 00484a95  1313                 adc edx, dword ptr [ebx]
// 00484a97  1313                 adc edx, dword ptr [ebx]
// 00484a99  1313                 adc edx, dword ptr [ebx]
// 00484a9b  1313                 adc edx, dword ptr [ebx]
// 00484a9d  1313                 adc edx, dword ptr [ebx]
// 00484a9f  1313                 adc edx, dword ptr [ebx]
// 00484aa1  1313                 adc edx, dword ptr [ebx]
// 00484aa3  1313                 adc edx, dword ptr [ebx]
// 00484aa5  1313                 adc edx, dword ptr [ebx]
// 00484aa7  1313                 adc edx, dword ptr [ebx]
// 00484aa9  1313                 adc edx, dword ptr [ebx]
// 00484aab  1313                 adc edx, dword ptr [ebx]
// 00484aad  1313                 adc edx, dword ptr [ebx]
// 00484aaf  1313                 adc edx, dword ptr [ebx]
// 00484ab1  1313                 adc edx, dword ptr [ebx]
// 00484ab3  1313                 adc edx, dword ptr [ebx]
// 00484ab5  1313                 adc edx, dword ptr [ebx]
// 00484ab7  1313                 adc edx, dword ptr [ebx]
// 00484ab9  1313                 adc edx, dword ptr [ebx]
// 00484abb  1313                 adc edx, dword ptr [ebx]
// 00484abd  1313                 adc edx, dword ptr [ebx]
// 00484abf  1313                 adc edx, dword ptr [ebx]
// 00484ac1  1313                 adc edx, dword ptr [ebx]
// 00484ac3  1313                 adc edx, dword ptr [ebx]
// 00484ac5  1313                 adc edx, dword ptr [ebx]
// 00484ac7  1313                 adc edx, dword ptr [ebx]
// 00484ac9  1313                 adc edx, dword ptr [ebx]
// 00484acb  1313                 adc edx, dword ptr [ebx]
// 00484acd  1313                 adc edx, dword ptr [ebx]
// 00484acf  1313                 adc edx, dword ptr [ebx]
// 00484ad1  1313                 adc edx, dword ptr [ebx]
// 00484ad3  1313                 adc edx, dword ptr [ebx]
// 00484ad5  1313                 adc edx, dword ptr [ebx]
// 00484ad7  1313                 adc edx, dword ptr [ebx]
// 00484ad9  1313                 adc edx, dword ptr [ebx]
// 00484adb  1313                 adc edx, dword ptr [ebx]
// 00484add  1313                 adc edx, dword ptr [ebx]
// 00484adf  1303                 adc eax, dword ptr [ebx]
// 00484ae1  0405                 add al, 5
// 00484ae3  06                   push es
// 00484ae4  07                   pop es
// 00484ae5  0809                 or byte ptr [ecx], cl
// 00484ae7  0a0b                 or cl, byte ptr [ebx]
// 00484ae9  0c0d                 or al, 0xd
// 00484aeb  1313                 adc edx, dword ptr [ebx]
// 00484aed  1313                 adc edx, dword ptr [ebx]
// 00484aef  1313                 adc edx, dword ptr [ebx]
// 00484af1  1313                 adc edx, dword ptr [ebx]
// 00484af3  1313                 adc edx, dword ptr [ebx]
// 00484af5  1313                 adc edx, dword ptr [ebx]
// 00484af7  1313                 adc edx, dword ptr [ebx]
// 00484af9  1313                 adc edx, dword ptr [ebx]
// 00484afb  0e                   push cs
// 00484afc  0f1011               movups xmm2, xmmword ptr [ecx]
// 00484aff  12583e               adc bl, byte ptr [eax + 0x3e]
// 00484b02  48                   dec eax
// 00484b03  005e3e               add byte ptr [esi + 0x3e], bl
// 00484b06  48                   dec eax
// 00484b07  00643e48             add byte ptr [esi + edi + 0x48], ah
// 00484b0b  006a3e               add byte ptr [edx + 0x3e], ch
// 00484b0e  48                   dec eax
// 00484b0f  00703e               add byte ptr [eax + 0x3e], dh
// 00484b12  48                   dec eax
// 00484b13  00763e               add byte ptr [esi + 0x3e], dh
// 00484b16  48                   dec eax
// 00484b17  007c3e48             add byte ptr [esi + edi + 0x48], bh
// 00484b1b  00823e480088         add byte ptr [edx - 0x77ffb7c2], al
// 00484b21  3e48                 dec eax
// 00484b23  008e3e480094         add byte ptr [esi - 0x6bffb7c2], cl
// 00484b29  3e48                 dec eax
// 00484b2b  009a3e4800a0         add byte ptr [edx - 0x5fffb7c2], bl
// 00484b31  3e48                 dec eax
// 00484b33  00a63e4800ac         add byte ptr [esi - 0x53ffb7c2], ah
// 00484b39  3e48                 dec eax
// 00484b3b  00b23e4800b8         add byte ptr [edx - 0x47ffb7c2], dh
// 00484b41  3e48                 dec eax
// 00484b43  00be3e4800c4         add byte ptr [esi - 0x3bffb7c2], bh
// 00484b49  3e48                 dec eax
// 00484b4b  00ca                 add dl, cl
// 00484b4d  3e48                 dec eax
// 00484b4f  0019                 add byte ptr [ecx], bl
// 00484b51  47                   inc edi
// 00484b52  48                   dec eax
// 00484b53  0000                 add byte ptr [eax], al
// 00484b55  0102                 add dword ptr [edx], eax
// 00484b57  03040506070814       add eax, dword ptr [eax + 0x14080706]
// 00484b5e  1414                 adc al, 0x14
// 00484b60  1414                 adc al, 0x14
// 00484b62  1414                 adc al, 0x14
// 00484b64  1414                 adc al, 0x14
// 00484b66  1414                 adc al, 0x14
// 00484b68  1414                 adc al, 0x14
// 00484b6a  1414                 adc al, 0x14
// 00484b6c  1414                 adc al, 0x14
// 00484b6e  1414                 adc al, 0x14
// 00484b70  1414                 adc al, 0x14
// 00484b72  1414                 adc al, 0x14
// 00484b74  090a                 or dword ptr [edx], ecx
// 00484b76  0b0c0d0e0f1011       or ecx, dword ptr [ecx + 0x11100f0e]
// 00484b7d  1414                 adc al, 0x14
// 00484b7f  1414                 adc al, 0x14
// 00484b81  1414                 adc al, 0x14
// 00484b83  1414                 adc al, 0x14
// 00484b85  1414                 adc al, 0x14
// 00484b87  1414                 adc al, 0x14
// 00484b89  1414                 adc al, 0x14
// 00484b8b  1414                 adc al, 0x14
// 00484b8d  1414                 adc al, 0x14
// 00484b8f  1414                 adc al, 0x14
// 00484b91  1414                 adc al, 0x14
// 00484b93  1414                 adc al, 0x14
// 00484b95  1414                 adc al, 0x14
// 00484b97  1414                 adc al, 0x14
// 00484b99  1414                 adc al, 0x14
// 00484b9b  1414                 adc al, 0x14
// 00484b9d  1414                 adc al, 0x14
// 00484b9f  1414                 adc al, 0x14
// 00484ba1  1414                 adc al, 0x14
// 00484ba3  1412                 adc al, 0x12
// 00484ba5  138bfff53e48         adc ecx, dword ptr [ebx + 0x483ef5ff]
// 00484bab  0019                 add byte ptr [ecx], bl
// 00484bad  47                   inc edi
// 00484bae  48                   dec eax
// 00484baf  00fb                 add bl, bh
// 00484bb1  3e48                 dec eax
// 00484bb3  0001                 add byte ptr [ecx], al
// 00484bb5  3f                   aas 
// 00484bb6  48                   dec eax
// 00484bb7  0007                 add byte ptr [edi], al
// 00484bb9  3f                   aas 
// 00484bba  48                   dec eax
// 00484bbb  00713f               add byte ptr [ecx + 0x3f], dh
// 00484bbe  48                   dec eax
// 00484bbf  00773f               add byte ptr [edi + 0x3f], dh
// 00484bc2  48                   dec eax
// 00484bc3  007d3f               add byte ptr [ebp + 0x3f], bh
// 00484bc6  48                   dec eax
// 00484bc7  00833f480089         add byte ptr [ebx - 0x76ffb7c1], al
// 00484bcd  3f                   aas 
// 00484bce  48                   dec eax
// 00484bcf  008f3f480095         add byte ptr [edi - 0x6affb7c1], cl
// 00484bd5  3f                   aas 
// 00484bd6  48                   dec eax
// 00484bd7  00d7                 add bh, dl
// 00484bd9  3f                   aas 
// 00484bda  48                   dec eax
// 00484bdb  00dd                 add ch, bl
// 00484bdd  3f                   aas 
// 00484bde  48                   dec eax
// 00484bdf  00e3                 add bl, ah
// 00484be1  3f                   aas 
// 00484be2  48                   dec eax
// 00484be3  00e9                 add cl, ch
// 00484be5  3f                   aas 
// 00484be6  48                   dec eax
// 00484be7  00ef                 add bh, ch
// 00484be9  3f                   aas 
// 00484bea  48                   dec eax
// 00484beb  00f5                 add ch, dh
// 00484bed  3f                   aas 
// 00484bee  48                   dec eax
// 00484bef  00fb                 add bl, bh
// 00484bf1  3f                   aas 
// 00484bf2  48                   dec eax
// 00484bf3  0001                 add byte ptr [ecx], al
// 00484bf5  40                   inc eax
// 00484bf6  48                   dec eax
// 00484bf7  0007                 add byte ptr [edi], al
// 00484bf9  40                   inc eax
// 00484bfa  48                   dec eax
// 00484bfb  000d4048002f         add byte ptr [0x2f004840], cl
// 00484c01  40                   inc eax
// 00484c02  48                   dec eax
// 00484c03  00354048003b         add byte ptr [0x3b004840], dh
// 00484c09  40                   inc eax
// 00484c0a  48                   dec eax
// 00484c0b  004140               add byte ptr [ecx + 0x40], al
// 00484c0e  48                   dec eax
// 00484c0f  004740               add byte ptr [edi + 0x40], al
// 00484c12  48                   dec eax
// 00484c13  004d40               add byte ptr [ebp + 0x40], cl
// 00484c16  48                   dec eax
// 00484c17  005340               add byte ptr [ebx + 0x40], dl
// 00484c1a  48                   dec eax
// 00484c1b  005940               add byte ptr [ecx + 0x40], bl
// 00484c1e  48                   dec eax
// 00484c1f  005f40               add byte ptr [edi + 0x40], bl
// 00484c22  48                   dec eax
// 00484c23  006540               add byte ptr [ebp + 0x40], ah
// 00484c26  48                   dec eax
// 00484c27  006b40               add byte ptr [ebx + 0x40], ch
// 00484c2a  48                   dec eax
// 00484c2b  007140               add byte ptr [ecx + 0x40], dh
// 00484c2e  48                   dec eax
// 00484c2f  007740               add byte ptr [edi + 0x40], dh
// 00484c32  48                   dec eax
// 00484c33  007d40               add byte ptr [ebp + 0x40], bh
// 00484c36  48                   dec eax
// 00484c37  008340480073         add byte ptr [ebx + 0x73004840], al
// 00484c3d  41                   inc ecx
// 00484c3e  48                   dec eax
// 00484c3f  007941               add byte ptr [ecx + 0x41], bh
// 00484c42  48                   dec eax
// 00484c43  007f41               add byte ptr [edi + 0x41], bh
// 00484c46  48                   dec eax
// 00484c47  00854148008b         add byte ptr [ebp - 0x74ffb7bf], al
// 00484c4d  41                   inc ecx
// 00484c4e  48                   dec eax
// 00484c4f  009141480097         add byte ptr [ecx - 0x68ffb7bf], dl
// 00484c55  41                   inc ecx
// 00484c56  48                   dec eax
// 00484c57  009d414800a3         add byte ptr [ebp - 0x5cffb7bf], bl
// 00484c5d  41                   inc ecx
// 00484c5e  48                   dec eax
// 00484c5f  00a941480094         add byte ptr [ecx - 0x6bffb7bf], ch
// 00484c65  44                   inc esp
// 00484c66  48                   dec eax
// 00484c67  009a444800a0         add byte ptr [edx - 0x5fffb7bc], bl
// 00484c6d  44                   inc esp
// 00484c6e  48                   dec eax
// 00484c6f  00a6444800ac         add byte ptr [esi - 0x53ffb7bc], ah
// 00484c75  44                   inc esp
// 00484c76  48                   dec eax
// 00484c77  00d7                 add bh, dl
// 00484c79  44                   inc esp
// 00484c7a  48                   dec eax
// 00484c7b  00dd                 add ch, bl
// 00484c7d  44                   inc esp
// 00484c7e  48                   dec eax
// 00484c7f  00e3                 add bl, ah
// 00484c81  44                   inc esp
// 00484c82  48                   dec eax
// 00484c83  00e9                 add cl, ch
// 00484c85  44                   inc esp
// 00484c86  48                   dec eax
// 00484c87  00ef                 add bh, ch
// 00484c89  44                   inc esp
// 00484c8a  48                   dec eax
// 00484c8b  00f5                 add ch, dh
// 00484c8d  44                   inc esp
// 00484c8e  48                   dec eax
// 00484c8f  00fb                 add bl, bh
// 00484c91  44                   inc esp
// 00484c92  48                   dec eax
// 00484c93  004a45               add byte ptr [edx + 0x45], cl
// 00484c96  48                   dec eax
// 00484c97  00444548             add byte ptr [ebp + eax*2 + 0x48], al
// 00484c9b  0028                 add byte ptr [eax], ch
// 00484c9d  46                   inc esi
// 00484c9e  48                   dec eax
// 00484c9f  002e                 add byte ptr [esi], ch
// 00484ca1  46                   inc esi
// 00484ca2  48                   dec eax
// 00484ca3  003446               add byte ptr [esi + eax*2], dh
// 00484ca6  48                   dec eax
// 00484ca7  0022                 add byte ptr [edx], ah
// 00484ca9  46                   inc esi
// 00484caa  48                   dec eax
// 00484cab  0038                 add byte ptr [eax], bh
// 00484cad  45                   inc ebp
// 00484cae  48                   dec eax
// 00484caf  005045               add byte ptr [eax + 0x45], dl
// 00484cb2  48                   dec eax
// 00484cb3  005645               add byte ptr [esi + 0x45], dl
// 00484cb6  48                   dec eax
// 00484cb7  005c4548             add byte ptr [ebp + eax*2 + 0x48], bl
// 00484cbb  006245               add byte ptr [edx + 0x45], ah
// 00484cbe  48                   dec eax
// 00484cbf  006845               add byte ptr [eax + 0x45], ch
// 00484cc2  48                   dec eax
// 00484cc3  006e45               add byte ptr [esi + 0x45], ch
// 00484cc6  48                   dec eax
// 00484cc7  00744548             add byte ptr [ebp + eax*2 + 0x48], dh
// 00484ccb  007a45               add byte ptr [edx + 0x45], bh
// 00484cce  48                   dec eax
// 00484ccf  0080454800b0         add byte ptr [eax - 0x4fffb7bb], al
// 00484cd5  45                   inc ebp
// 00484cd6  48                   dec eax
// 00484cd7  00864548008c         add byte ptr [esi - 0x73ffb7bb], al
// 00484cdd  45                   inc ebp
// 00484cde  48                   dec eax
// 00484cdf  00b645480092         add byte ptr [esi - 0x6dffb7bb], dh
// 00484ce5  45                   inc ebp
// 00484ce6  48                   dec eax
// 00484ce7  00984548009e         add byte ptr [eax - 0x61ffb7bb], bl
// 00484ced  45                   inc ebp
// 00484cee  48                   dec eax
// 00484cef  00bc454800a445       add byte ptr [ebp + eax*2 + 0x45a40048], bh
// 00484cf6  48                   dec eax
// 00484cf7  00aa454800c2         add byte ptr [edx - 0x3dffb7bb], ch
// 00484cfd  45                   inc ebp
// 00484cfe  48                   dec eax
// 00484cff  00c8                 add al, cl
// 00484d01  45                   inc ebp
// 00484d02  48                   dec eax
// 00484d03  00ce                 add dh, cl
// 00484d05  45                   inc ebp
// 00484d06  48                   dec eax
// 00484d07  00d4                 add ah, dl
// 00484d09  45                   inc ebp
// 00484d0a  48                   dec eax
// 00484d0b  00da                 add dl, bl
// 00484d0d  45                   inc ebp
// 00484d0e  48                   dec eax
// 00484d0f  00e0                 add al, ah
// 00484d11  45                   inc ebp
// 00484d12  48                   dec eax
// 00484d13  00e6                 add dh, ah
// 00484d15  45                   inc ebp
// 00484d16  48                   dec eax
// 00484d17  00ec                 add ah, ch
// 00484d19  45                   inc ebp
// 00484d1a  48                   dec eax
// 00484d1b  00f2                 add dl, dh
// 00484d1d  45                   inc ebp
// 00484d1e  48                   dec eax
// 00484d1f  00f8                 add al, bh
// 00484d21  45                   inc ebp
// 00484d22  48                   dec eax
// 00484d23  00fe                 add dh, bh
// 00484d25  45                   inc ebp
// 00484d26  48                   dec eax
// 00484d27  000446               add byte ptr [esi + eax*2], al
// 00484d2a  48                   dec eax
// 00484d2b  000a                 add byte ptr [edx], cl
// 00484d2d  46                   inc esi
// 00484d2e  48                   dec eax
// 00484d2f  0010                 add byte ptr [eax], dl
// 00484d31  46                   inc esi
// 00484d32  48                   dec eax
// 00484d33  0016                 add byte ptr [esi], dl
// 00484d35  46                   inc esi
// 00484d36  48                   dec eax
// 00484d37  001c46               add byte ptr [esi + eax*2], bl
// 00484d3a  48                   dec eax
// 00484d3b  003e                 add byte ptr [esi], bh
// 00484d3d  45                   inc ebp
// 00484d3e  48                   dec eax
// 00484d3f  0019                 add byte ptr [ecx], bl
// 00484d41  47                   inc edi
// 00484d42  48                   dec eax
// 00484d43  0000                 add byte ptr [eax], al
// 00484d45  012b                 add dword ptr [ebx], ebp
// 00484d47  2b2b                 sub ebp, dword ptr [ebx]
// 00484d49  2b2b                 sub ebp, dword ptr [ebx]
// 00484d4b  2b2b                 sub ebp, dword ptr [ebx]
// 00484d4d  2b2b                 sub ebp, dword ptr [ebx]
// 00484d4f  2b2b                 sub ebp, dword ptr [ebx]
// 00484d51  2b2b                 sub ebp, dword ptr [ebx]
// 00484d53  2b2b                 sub ebp, dword ptr [ebx]
// 00484d55  2b2b                 sub ebp, dword ptr [ebx]
// 00484d57  2b2b                 sub ebp, dword ptr [ebx]
// 00484d59  2b2b                 sub ebp, dword ptr [ebx]
// 00484d5b  2b2b                 sub ebp, dword ptr [ebx]
// 00484d5d  2b2b                 sub ebp, dword ptr [ebx]
// 00484d5f  2b2b                 sub ebp, dword ptr [ebx]
// 00484d61  2b2b                 sub ebp, dword ptr [ebx]
// 00484d63  2b2b                 sub ebp, dword ptr [ebx]
// 00484d65  2b2b                 sub ebp, dword ptr [ebx]
// 00484d67  2b2b                 sub ebp, dword ptr [ebx]
// 00484d69  2b2b                 sub ebp, dword ptr [ebx]
// 00484d6b  2b2b                 sub ebp, dword ptr [ebx]
// 00484d6d  2b2b                 sub ebp, dword ptr [ebx]
// 00484d6f  2b2b                 sub ebp, dword ptr [ebx]
// 00484d71  2b2b                 sub ebp, dword ptr [ebx]
// 00484d73  2b2b                 sub ebp, dword ptr [ebx]
// 00484d75  0203                 add al, byte ptr [ebx]
// 00484d77  042b                 add al, 0x2b
// 00484d79  2b2b                 sub ebp, dword ptr [ebx]
// 00484d7b  2b052b2b062b         sub eax, dword ptr [0x2b062b2b]
// 00484d81  07                   pop es
// 00484d82  0809                 or byte ptr [ecx], cl
// 00484d84  0a0b                 or cl, byte ptr [ebx]
// 00484d86  0c0d                 or al, 0xd
// 00484d88  0e                   push cs
// 00484d89  0f1011               movups xmm2, xmmword ptr [ecx]
// 00484d8c  1213                 adc dl, byte ptr [ebx]
// 00484d8e  1415                 adc al, 0x15
// 00484d90  16                   push ss
// 00484d91  17                   pop ss
// 00484d92  1819                 sbb byte ptr [ecx], bl
// 00484d94  1a1b                 sbb bl, byte ptr [ebx]
// 00484d96  1c1d                 sbb al, 0x1d
// 00484d98  1e                   push ds
// 00484d99  1f                   pop ds
// 00484d9a  2021                 and byte ptr [ecx], ah
// 00484d9c  2223                 and ah, byte ptr [ebx]
// 00484d9e  2425                 and al, 0x25
// 00484da0  262b2b               sub ebp, dword ptr es:[ebx]
// 00484da3  2b2b                 sub ebp, dword ptr [ebx]
// 00484da5  2b2b                 sub ebp, dword ptr [ebx]
// 00484da7  2b2b                 sub ebp, dword ptr [ebx]
// 00484da9  2b2b                 sub ebp, dword ptr [ebx]
// 00484dab  2b2b                 sub ebp, dword ptr [ebx]
// 00484dad  2b2b                 sub ebp, dword ptr [ebx]
// 00484daf  2b2b                 sub ebp, dword ptr [ebx]
// 00484db1  2b2b                 sub ebp, dword ptr [ebx]
// 00484db3  2b2b                 sub ebp, dword ptr [ebx]
// 00484db5  2b2b                 sub ebp, dword ptr [ebx]
// 00484db7  2b2b                 sub ebp, dword ptr [ebx]
// 00484db9  2b2b                 sub ebp, dword ptr [ebx]
// 00484dbb  2b2b                 sub ebp, dword ptr [ebx]
// 00484dbd  2b2b                 sub ebp, dword ptr [ebx]
// 00484dbf  2b2b                 sub ebp, dword ptr [ebx]
// 00484dc1  2b2b                 sub ebp, dword ptr [ebx]
// 00484dc3  2b2b                 sub ebp, dword ptr [ebx]
// 00484dc5  2b2b                 sub ebp, dword ptr [ebx]
// 00484dc7  2b2b                 sub ebp, dword ptr [ebx]
// 00484dc9  2b2b                 sub ebp, dword ptr [ebx]
// 00484dcb  2b2b                 sub ebp, dword ptr [ebx]
// 00484dcd  2b2b                 sub ebp, dword ptr [ebx]
// 00484dcf  2b2b                 sub ebp, dword ptr [ebx]
// 00484dd1  2b2b                 sub ebp, dword ptr [ebx]
// 00484dd3  2b2b                 sub ebp, dword ptr [ebx]
// 00484dd5  2b2b                 sub ebp, dword ptr [ebx]
// 00484dd7  2b2b                 sub ebp, dword ptr [ebx]
// 00484dd9  2b2b                 sub ebp, dword ptr [ebx]
// 00484ddb  2b2b                 sub ebp, dword ptr [ebx]
// 00484ddd  2b2b                 sub ebp, dword ptr [ebx]
// 00484ddf  2b2b                 sub ebp, dword ptr [ebx]
// 00484de1  2b2b                 sub ebp, dword ptr [ebx]
// 00484de3  2b2b                 sub ebp, dword ptr [ebx]
// 00484de5  2b2b                 sub ebp, dword ptr [ebx]
// 00484de7  2b2b                 sub ebp, dword ptr [ebx]
// 00484de9  2b2b                 sub ebp, dword ptr [ebx]
// 00484deb  2b2b                 sub ebp, dword ptr [ebx]
// 00484ded  2b2b                 sub ebp, dword ptr [ebx]
// 00484def  2b2b                 sub ebp, dword ptr [ebx]
// 00484df1  2b2b                 sub ebp, dword ptr [ebx]
// 00484df3  2b2b                 sub ebp, dword ptr [ebx]
// 00484df5  2b2b                 sub ebp, dword ptr [ebx]
// 00484df7  27                   daa 
// 00484df8  2829                 sub byte ptr [ecx], ch
// 00484dfa  2b2b                 sub ebp, dword ptr [ebx]
// 00484dfc  2b2b                 sub ebp, dword ptr [ebx]
// 00484dfe  2b2b                 sub ebp, dword ptr [ebx]
// 00484e00  2b2b                 sub ebp, dword ptr [ebx]
// 00484e02  2b2b                 sub ebp, dword ptr [ebx]
// 00484e04  2b2b                 sub ebp, dword ptr [ebx]
// 00484e06  2b2b                 sub ebp, dword ptr [ebx]
// 00484e08  2b2b                 sub ebp, dword ptr [ebx]
// 00484e0a  2b2b                 sub ebp, dword ptr [ebx]
// 00484e0c  2b2b                 sub ebp, dword ptr [ebx]
// 00484e0e  2b2b                 sub ebp, dword ptr [ebx]
// 00484e10  2b2b                 sub ebp, dword ptr [ebx]
// 00484e12  2b2b                 sub ebp, dword ptr [ebx]
// 00484e14  2b2b                 sub ebp, dword ptr [ebx]
// 00484e16  2b2b                 sub ebp, dword ptr [ebx]
// 00484e18  2b2b                 sub ebp, dword ptr [ebx]
// 00484e1a  2b2b                 sub ebp, dword ptr [ebx]
// 00484e1c  2b2b                 sub ebp, dword ptr [ebx]
// 00484e1e  2b2b                 sub ebp, dword ptr [ebx]
// 00484e20  2b2b                 sub ebp, dword ptr [ebx]
// 00484e22  2b2b                 sub ebp, dword ptr [ebx]
// 00484e24  2b2b                 sub ebp, dword ptr [ebx]
// 00484e26  2b2b                 sub ebp, dword ptr [ebx]
// 00484e28  2b2b                 sub ebp, dword ptr [ebx]
// 00484e2a  2b2b                 sub ebp, dword ptr [ebx]
// 00484e2c  2b2b                 sub ebp, dword ptr [ebx]
// 00484e2e  2b2b                 sub ebp, dword ptr [ebx]
// 00484e30  2b2b                 sub ebp, dword ptr [ebx]
// 00484e32  2b2b                 sub ebp, dword ptr [ebx]
// 00484e34  2b2b                 sub ebp, dword ptr [ebx]
// 00484e36  2b2b                 sub ebp, dword ptr [ebx]
// 00484e38  2b2b                 sub ebp, dword ptr [ebx]
// 00484e3a  2b2b                 sub ebp, dword ptr [ebx]
// 00484e3c  2a8d49009546         sub cl, byte ptr [ebp + 0x46950049]
// 00484e42  48                   dec eax
// 00484e43  009b464800a1         add byte ptr [ebx - 0x5effb7ba], bl
// 00484e49  46                   inc esi
// 00484e4a  48                   dec eax
// 00484e4b  00a7464800ad         add byte ptr [edi - 0x52ffb7ba], ah
// 00484e51  46                   inc esi
// 00484e52  48                   dec eax
// 00484e53  00b3464800b9         add byte ptr [ebx - 0x46ffb7ba], dh
// 00484e59  46                   inc esi
// 00484e5a  48                   dec eax
// 00484e5b  00bf464800c5         add byte ptr [edi - 0x3affb7ba], bh
// 00484e61  46                   inc esi
// 00484e62  48                   dec eax
// 00484e63  00cb                 add bl, cl
// 00484e65  46                   inc esi
// 00484e66  48                   dec eax
// 00484e67  00d1                 add cl, dl
// 00484e69  46                   inc esi
// 00484e6a  48                   dec eax
// 00484e6b  00d7                 add bh, dl
// 00484e6d  46                   inc esi
// 00484e6e  48                   dec eax
// 00484e6f  00dd                 add ch, bl
// 00484e71  46                   inc esi
// 00484e72  48                   dec eax
// 00484e73  00e3                 add bl, ah
// 00484e75  46                   inc esi
// 00484e76  48                   dec eax
// 00484e77  00e9                 add cl, ch
// 00484e79  46                   inc esi
// 00484e7a  48                   dec eax
// 00484e7b  00ef                 add bh, ch
// 00484e7d  46                   inc esi
// 00484e7e  48                   dec eax
// 00484e7f  00f5                 add ch, dh
// 00484e81  46                   inc esi
// 00484e82  48                   dec eax
// 00484e83  00fb                 add bl, bh
// 00484e85  46                   inc esi
// 00484e86  48                   dec eax
// 00484e87  0001                 add byte ptr [ecx], al
// 00484e89  47                   inc edi
// 00484e8a  48                   dec eax
// 00484e8b  0007                 add byte ptr [edi], al
// 00484e8d  47                   inc edi
// 00484e8e  48                   dec eax

void func_00483a00()
{
}
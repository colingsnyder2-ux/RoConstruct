// from server: 100% by auto
// roc 2011-06 00a2eee0  unit: seg_00a20000  size: 1252 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a2eee0
//
// 00a2eee0  b97088d100           mov ecx, 0xd18870
// 00a2eee5  ff15b42da400         call dword ptr [0xa42db4]
// 00a2eeeb  b97c88d100           mov ecx, 0xd1887c
// 00a2eef0  c7056888d10000000000 mov dword ptr [0xd18868], 0
// 00a2eefa  c7056c88d100ac260000 mov dword ptr [0xd1886c], 0x26ac
// 00a2ef04  ff15b42da400         call dword ptr [0xa42db4]
// 00a2ef0a  b98888d100           mov ecx, 0xd18888
// 00a2ef0f  c7057488d10099330000 mov dword ptr [0xd18874], 0x3399
// 00a2ef19  c7057888d100ad260000 mov dword ptr [0xd18878], 0x26ad
// 00a2ef23  ff15b42da400         call dword ptr [0xa42db4]
// 00a2ef29  b99488d100           mov ecx, 0xd18894
// 00a2ef2e  c7058088d10033330000 mov dword ptr [0xd18880], 0x3333
// 00a2ef38  c7058488d100ae260000 mov dword ptr [0xd18884], 0x26ae
// 00a2ef42  ff15b42da400         call dword ptr [0xa42db4]
// 00a2ef48  b9a088d100           mov ecx, 0xd188a0
// 00a2ef4d  c7058c88d10000330000 mov dword ptr [0xd1888c], 0x3300
// 00a2ef57  c7059088d100af260000 mov dword ptr [0xd18890], 0x26af
// 00a2ef61  ff15b42da400         call dword ptr [0xa42db4]
// 00a2ef67  b9ac88d100           mov ecx, 0xd188ac
// 00a2ef6c  c7059888d10000336600 mov dword ptr [0xd18898], 0x663300
// 00a2ef76  c7059c88d100b0260000 mov dword ptr [0xd1889c], 0x26b0
// 00a2ef80  ff15b42da400         call dword ptr [0xa42db4]
// 00a2ef86  b9b888d100           mov ecx, 0xd188b8
// 00a2ef8b  c705a488d10000008000 mov dword ptr [0xd188a4], 0x800000
// 00a2ef95  c705a888d100b1260000 mov dword ptr [0xd188a8], 0x26b1
// 00a2ef9f  ff15b42da400         call dword ptr [0xa42db4]
// 00a2efa5  b9c488d100           mov ecx, 0xd188c4
// 00a2efaa  c705b088d10033339900 mov dword ptr [0xd188b0], 0x993333
// 00a2efb4  c705b488d100b2260000 mov dword ptr [0xd188b4], 0x26b2
// 00a2efbe  ff15b42da400         call dword ptr [0xa42db4]
// 00a2efc4  b9d088d100           mov ecx, 0xd188d0
// 00a2efc9  c705bc88d10033333300 mov dword ptr [0xd188bc], 0x333333
// 00a2efd3  c705c088d100b3260000 mov dword ptr [0xd188c0], 0x26b3
// 00a2efdd  ff15b42da400         call dword ptr [0xa42db4]
// 00a2efe3  b9dc88d100           mov ecx, 0xd188dc
// 00a2efe8  c705c888d10080000000 mov dword ptr [0xd188c8], 0x80
// 00a2eff2  c705cc88d100b4260000 mov dword ptr [0xd188cc], 0x26b4
// 00a2effc  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f002  b9e888d100           mov ecx, 0xd188e8
// 00a2f007  c705d488d100ff660000 mov dword ptr [0xd188d4], 0x66ff
// 00a2f011  c705d888d100b5260000 mov dword ptr [0xd188d8], 0x26b5
// 00a2f01b  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f021  b9f488d100           mov ecx, 0xd188f4
// 00a2f026  c705e088d10080800000 mov dword ptr [0xd188e0], 0x8080
// 00a2f030  c705e488d100b6260000 mov dword ptr [0xd188e4], 0x26b6
// 00a2f03a  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f040  b90089d100           mov ecx, 0xd18900
// 00a2f045  c705ec88d10000800000 mov dword ptr [0xd188ec], 0x8000
// 00a2f04f  c705f088d100b7260000 mov dword ptr [0xd188f0], 0x26b7
// 00a2f059  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f05f  b90c89d100           mov ecx, 0xd1890c
// 00a2f064  c705f888d10000808000 mov dword ptr [0xd188f8], 0x808000
// 00a2f06e  c705fc88d100b8260000 mov dword ptr [0xd188fc], 0x26b8
// 00a2f078  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f07e  b91889d100           mov ecx, 0xd18918
// 00a2f083  c7050489d1000000ff00 mov dword ptr [0xd18904], 0xff0000
// 00a2f08d  c7050889d100b9260000 mov dword ptr [0xd18908], 0x26b9
// 00a2f097  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f09d  b92489d100           mov ecx, 0xd18924
// 00a2f0a2  c7051089d10066669900 mov dword ptr [0xd18910], 0x996666
// 00a2f0ac  c7051489d100ba260000 mov dword ptr [0xd18914], 0x26ba
// 00a2f0b6  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f0bc  b93089d100           mov ecx, 0xd18930
// 00a2f0c1  c7051c89d10080808000 mov dword ptr [0xd1891c], 0x808080
// 00a2f0cb  c7052089d100bb260000 mov dword ptr [0xd18920], 0x26bb
// 00a2f0d5  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f0db  b93c89d100           mov ecx, 0xd1893c
// 00a2f0e0  c7052889d100ff000000 mov dword ptr [0xd18928], 0xff
// 00a2f0ea  c7052c89d100bc260000 mov dword ptr [0xd1892c], 0x26bc
// 00a2f0f4  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f0fa  b94889d100           mov ecx, 0xd18948
// 00a2f0ff  c7053489d100ff990000 mov dword ptr [0xd18934], 0x99ff
// 00a2f109  c7053889d100bd260000 mov dword ptr [0xd18938], 0x26bd
// 00a2f113  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f119  b95489d100           mov ecx, 0xd18954
// 00a2f11e  c7054089d10099cc0000 mov dword ptr [0xd18940], 0xcc99
// 00a2f128  c7054489d100be260000 mov dword ptr [0xd18944], 0x26be
// 00a2f132  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f138  c7054c89d10033996600 mov dword ptr [0xd1894c], 0x669933
// 00a2f142  c7055089d100bf260000 mov dword ptr [0xd18950], 0x26bf
// 00a2f14c  b96089d100           mov ecx, 0xd18960
// 00a2f151  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f157  b96c89d100           mov ecx, 0xd1896c
// 00a2f15c  c7055889d10033cccc00 mov dword ptr [0xd18958], 0xcccc33
// 00a2f166  c7055c89d100c0260000 mov dword ptr [0xd1895c], 0x26c0
// 00a2f170  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f176  b97889d100           mov ecx, 0xd18978
// 00a2f17b  c7056489d1003366ff00 mov dword ptr [0xd18964], 0xff6633
// 00a2f185  c7056889d100c1260000 mov dword ptr [0xd18968], 0x26c1
// 00a2f18f  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f195  b98489d100           mov ecx, 0xd18984
// 00a2f19a  c7057089d10080008000 mov dword ptr [0xd18970], 0x800080
// 00a2f1a4  c7057489d100c2260000 mov dword ptr [0xd18974], 0x26c2
// 00a2f1ae  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f1b4  b99089d100           mov ecx, 0xd18990
// 00a2f1b9  c7057c89d10099999900 mov dword ptr [0xd1897c], 0x999999
// 00a2f1c3  c7058089d100c3260000 mov dword ptr [0xd18980], 0x26c3
// 00a2f1cd  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f1d3  b99c89d100           mov ecx, 0xd1899c
// 00a2f1d8  c7058889d100ff00ff00 mov dword ptr [0xd18988], 0xff00ff
// 00a2f1e2  c7058c89d100c4260000 mov dword ptr [0xd1898c], 0x26c4
// 00a2f1ec  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f1f2  b9a889d100           mov ecx, 0xd189a8
// 00a2f1f7  c7059489d100ffcc0000 mov dword ptr [0xd18994], 0xccff
// 00a2f201  c7059889d100c5260000 mov dword ptr [0xd18998], 0x26c5
// 00a2f20b  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f211  b9b489d100           mov ecx, 0xd189b4
// 00a2f216  c705a089d100ffff0000 mov dword ptr [0xd189a0], 0xffff
// 00a2f220  c705a489d100c6260000 mov dword ptr [0xd189a4], 0x26c6
// 00a2f22a  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f230  b9c089d100           mov ecx, 0xd189c0
// 00a2f235  c705ac89d10000ff0000 mov dword ptr [0xd189ac], 0xff00
// 00a2f23f  c705b089d100c7260000 mov dword ptr [0xd189b0], 0x26c7
// 00a2f249  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f24f  b9cc89d100           mov ecx, 0xd189cc
// 00a2f254  c705b889d10000ffff00 mov dword ptr [0xd189b8], 0xffff00
// 00a2f25e  c705bc89d100c8260000 mov dword ptr [0xd189bc], 0x26c8
// 00a2f268  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f26e  b9d889d100           mov ecx, 0xd189d8
// 00a2f273  c705c489d10000ccff00 mov dword ptr [0xd189c4], 0xffcc00
// 00a2f27d  c705c889d100c9260000 mov dword ptr [0xd189c8], 0x26c9
// 00a2f287  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f28d  b9e489d100           mov ecx, 0xd189e4
// 00a2f292  c705d089d10099336600 mov dword ptr [0xd189d0], 0x663399
// 00a2f29c  c705d489d100ca260000 mov dword ptr [0xd189d4], 0x26ca
// 00a2f2a6  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f2ac  b9f089d100           mov ecx, 0xd189f0
// 00a2f2b1  c705dc89d100c0c0c000 mov dword ptr [0xd189dc], 0xc0c0c0
// 00a2f2bb  c705e089d100cb260000 mov dword ptr [0xd189e0], 0x26cb
// 00a2f2c5  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f2cb  b9fc89d100           mov ecx, 0xd189fc
// 00a2f2d0  c705e889d100ff99cc00 mov dword ptr [0xd189e8], 0xcc99ff
// 00a2f2da  c705ec89d100cc260000 mov dword ptr [0xd189ec], 0x26cc
// 00a2f2e4  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f2ea  b9088ad100           mov ecx, 0xd18a08
// 00a2f2ef  c705f489d100ffcc9900 mov dword ptr [0xd189f4], 0x99ccff
// 00a2f2f9  c705f889d100cd260000 mov dword ptr [0xd189f8], 0x26cd
// 00a2f303  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f309  b9148ad100           mov ecx, 0xd18a14
// 00a2f30e  c705008ad100ffff9900 mov dword ptr [0xd18a00], 0x99ffff
// 00a2f318  c705048ad100ce260000 mov dword ptr [0xd18a04], 0x26ce
// 00a2f322  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f328  b9208ad100           mov ecx, 0xd18a20
// 00a2f32d  c7050c8ad100ccffcc00 mov dword ptr [0xd18a0c], 0xccffcc
// 00a2f337  c705108ad100cf260000 mov dword ptr [0xd18a10], 0x26cf
// 00a2f341  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f347  b92c8ad100           mov ecx, 0xd18a2c
// 00a2f34c  c705188ad100ccffff00 mov dword ptr [0xd18a18], 0xffffcc
// 00a2f356  c7051c8ad100d0260000 mov dword ptr [0xd18a1c], 0x26d0
// 00a2f360  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f366  b9388ad100           mov ecx, 0xd18a38
// 00a2f36b  c705248ad10099ccff00 mov dword ptr [0xd18a24], 0xffcc99
// 00a2f375  c705288ad100d1260000 mov dword ptr [0xd18a28], 0x26d1
// 00a2f37f  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f385  b9448ad100           mov ecx, 0xd18a44
// 00a2f38a  c705308ad100cc99ff00 mov dword ptr [0xd18a30], 0xff99cc
// 00a2f394  c705348ad100d2260000 mov dword ptr [0xd18a34], 0x26d2
// 00a2f39e  ff15b42da400         call dword ptr [0xa42db4]
// 00a2f3a4  6840fca300           push 0xa3fc40
// 00a2f3a9  c7053c8ad100ffffff00 mov dword ptr [0xd18a3c], 0xffffff
// 00a2f3b3  c705408ad100d3260000 mov dword ptr [0xd18a40], 0x26d3
// 00a2f3bd  e89bbdddff           call 0x80b15d
// 00a2f3c2  59                   pop ecx
// 00a2f3c3  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPControlPopupColor.cpp (function ??__EextendedColors@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPControlPopupColor.cpp

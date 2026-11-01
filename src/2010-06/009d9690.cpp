// from server: 100% by auto
// roc 2010-06 009d9690  unit: seg_009d0000  size: 1252 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009d9690
//
// 009d9690  b9885bc200           mov ecx, 0xc25b88
// 009d9695  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d969b  b9945bc200           mov ecx, 0xc25b94
// 009d96a0  c705805bc20000000000 mov dword ptr [0xc25b80], 0
// 009d96aa  c705845bc200ac260000 mov dword ptr [0xc25b84], 0x26ac
// 009d96b4  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d96ba  b9a05bc200           mov ecx, 0xc25ba0
// 009d96bf  c7058c5bc20099330000 mov dword ptr [0xc25b8c], 0x3399
// 009d96c9  c705905bc200ad260000 mov dword ptr [0xc25b90], 0x26ad
// 009d96d3  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d96d9  b9ac5bc200           mov ecx, 0xc25bac
// 009d96de  c705985bc20033330000 mov dword ptr [0xc25b98], 0x3333
// 009d96e8  c7059c5bc200ae260000 mov dword ptr [0xc25b9c], 0x26ae
// 009d96f2  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d96f8  b9b85bc200           mov ecx, 0xc25bb8
// 009d96fd  c705a45bc20000330000 mov dword ptr [0xc25ba4], 0x3300
// 009d9707  c705a85bc200af260000 mov dword ptr [0xc25ba8], 0x26af
// 009d9711  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9717  b9c45bc200           mov ecx, 0xc25bc4
// 009d971c  c705b05bc20000336600 mov dword ptr [0xc25bb0], 0x663300
// 009d9726  c705b45bc200b0260000 mov dword ptr [0xc25bb4], 0x26b0
// 009d9730  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9736  b9d05bc200           mov ecx, 0xc25bd0
// 009d973b  c705bc5bc20000008000 mov dword ptr [0xc25bbc], 0x800000
// 009d9745  c705c05bc200b1260000 mov dword ptr [0xc25bc0], 0x26b1
// 009d974f  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9755  b9dc5bc200           mov ecx, 0xc25bdc
// 009d975a  c705c85bc20033339900 mov dword ptr [0xc25bc8], 0x993333
// 009d9764  c705cc5bc200b2260000 mov dword ptr [0xc25bcc], 0x26b2
// 009d976e  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9774  b9e85bc200           mov ecx, 0xc25be8
// 009d9779  c705d45bc20033333300 mov dword ptr [0xc25bd4], 0x333333
// 009d9783  c705d85bc200b3260000 mov dword ptr [0xc25bd8], 0x26b3
// 009d978d  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9793  b9f45bc200           mov ecx, 0xc25bf4
// 009d9798  c705e05bc20080000000 mov dword ptr [0xc25be0], 0x80
// 009d97a2  c705e45bc200b4260000 mov dword ptr [0xc25be4], 0x26b4
// 009d97ac  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d97b2  b9005cc200           mov ecx, 0xc25c00
// 009d97b7  c705ec5bc200ff660000 mov dword ptr [0xc25bec], 0x66ff
// 009d97c1  c705f05bc200b5260000 mov dword ptr [0xc25bf0], 0x26b5
// 009d97cb  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d97d1  b90c5cc200           mov ecx, 0xc25c0c
// 009d97d6  c705f85bc20080800000 mov dword ptr [0xc25bf8], 0x8080
// 009d97e0  c705fc5bc200b6260000 mov dword ptr [0xc25bfc], 0x26b6
// 009d97ea  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d97f0  b9185cc200           mov ecx, 0xc25c18
// 009d97f5  c705045cc20000800000 mov dword ptr [0xc25c04], 0x8000
// 009d97ff  c705085cc200b7260000 mov dword ptr [0xc25c08], 0x26b7
// 009d9809  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d980f  b9245cc200           mov ecx, 0xc25c24
// 009d9814  c705105cc20000808000 mov dword ptr [0xc25c10], 0x808000
// 009d981e  c705145cc200b8260000 mov dword ptr [0xc25c14], 0x26b8
// 009d9828  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d982e  b9305cc200           mov ecx, 0xc25c30
// 009d9833  c7051c5cc2000000ff00 mov dword ptr [0xc25c1c], 0xff0000
// 009d983d  c705205cc200b9260000 mov dword ptr [0xc25c20], 0x26b9
// 009d9847  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d984d  b93c5cc200           mov ecx, 0xc25c3c
// 009d9852  c705285cc20066669900 mov dword ptr [0xc25c28], 0x996666
// 009d985c  c7052c5cc200ba260000 mov dword ptr [0xc25c2c], 0x26ba
// 009d9866  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d986c  b9485cc200           mov ecx, 0xc25c48
// 009d9871  c705345cc20080808000 mov dword ptr [0xc25c34], 0x808080
// 009d987b  c705385cc200bb260000 mov dword ptr [0xc25c38], 0x26bb
// 009d9885  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d988b  b9545cc200           mov ecx, 0xc25c54
// 009d9890  c705405cc200ff000000 mov dword ptr [0xc25c40], 0xff
// 009d989a  c705445cc200bc260000 mov dword ptr [0xc25c44], 0x26bc
// 009d98a4  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d98aa  b9605cc200           mov ecx, 0xc25c60
// 009d98af  c7054c5cc200ff990000 mov dword ptr [0xc25c4c], 0x99ff
// 009d98b9  c705505cc200bd260000 mov dword ptr [0xc25c50], 0x26bd
// 009d98c3  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d98c9  b96c5cc200           mov ecx, 0xc25c6c
// 009d98ce  c705585cc20099cc0000 mov dword ptr [0xc25c58], 0xcc99
// 009d98d8  c7055c5cc200be260000 mov dword ptr [0xc25c5c], 0x26be
// 009d98e2  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d98e8  c705645cc20033996600 mov dword ptr [0xc25c64], 0x669933
// 009d98f2  c705685cc200bf260000 mov dword ptr [0xc25c68], 0x26bf
// 009d98fc  b9785cc200           mov ecx, 0xc25c78
// 009d9901  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9907  b9845cc200           mov ecx, 0xc25c84
// 009d990c  c705705cc20033cccc00 mov dword ptr [0xc25c70], 0xcccc33
// 009d9916  c705745cc200c0260000 mov dword ptr [0xc25c74], 0x26c0
// 009d9920  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9926  b9905cc200           mov ecx, 0xc25c90
// 009d992b  c7057c5cc2003366ff00 mov dword ptr [0xc25c7c], 0xff6633
// 009d9935  c705805cc200c1260000 mov dword ptr [0xc25c80], 0x26c1
// 009d993f  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9945  b99c5cc200           mov ecx, 0xc25c9c
// 009d994a  c705885cc20080008000 mov dword ptr [0xc25c88], 0x800080
// 009d9954  c7058c5cc200c2260000 mov dword ptr [0xc25c8c], 0x26c2
// 009d995e  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9964  b9a85cc200           mov ecx, 0xc25ca8
// 009d9969  c705945cc20099999900 mov dword ptr [0xc25c94], 0x999999
// 009d9973  c705985cc200c3260000 mov dword ptr [0xc25c98], 0x26c3
// 009d997d  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9983  b9b45cc200           mov ecx, 0xc25cb4
// 009d9988  c705a05cc200ff00ff00 mov dword ptr [0xc25ca0], 0xff00ff
// 009d9992  c705a45cc200c4260000 mov dword ptr [0xc25ca4], 0x26c4
// 009d999c  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d99a2  b9c05cc200           mov ecx, 0xc25cc0
// 009d99a7  c705ac5cc200ffcc0000 mov dword ptr [0xc25cac], 0xccff
// 009d99b1  c705b05cc200c5260000 mov dword ptr [0xc25cb0], 0x26c5
// 009d99bb  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d99c1  b9cc5cc200           mov ecx, 0xc25ccc
// 009d99c6  c705b85cc200ffff0000 mov dword ptr [0xc25cb8], 0xffff
// 009d99d0  c705bc5cc200c6260000 mov dword ptr [0xc25cbc], 0x26c6
// 009d99da  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d99e0  b9d85cc200           mov ecx, 0xc25cd8
// 009d99e5  c705c45cc20000ff0000 mov dword ptr [0xc25cc4], 0xff00
// 009d99ef  c705c85cc200c7260000 mov dword ptr [0xc25cc8], 0x26c7
// 009d99f9  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d99ff  b9e45cc200           mov ecx, 0xc25ce4
// 009d9a04  c705d05cc20000ffff00 mov dword ptr [0xc25cd0], 0xffff00
// 009d9a0e  c705d45cc200c8260000 mov dword ptr [0xc25cd4], 0x26c8
// 009d9a18  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9a1e  b9f05cc200           mov ecx, 0xc25cf0
// 009d9a23  c705dc5cc20000ccff00 mov dword ptr [0xc25cdc], 0xffcc00
// 009d9a2d  c705e05cc200c9260000 mov dword ptr [0xc25ce0], 0x26c9
// 009d9a37  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9a3d  b9fc5cc200           mov ecx, 0xc25cfc
// 009d9a42  c705e85cc20099336600 mov dword ptr [0xc25ce8], 0x663399
// 009d9a4c  c705ec5cc200ca260000 mov dword ptr [0xc25cec], 0x26ca
// 009d9a56  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9a5c  b9085dc200           mov ecx, 0xc25d08
// 009d9a61  c705f45cc200c0c0c000 mov dword ptr [0xc25cf4], 0xc0c0c0
// 009d9a6b  c705f85cc200cb260000 mov dword ptr [0xc25cf8], 0x26cb
// 009d9a75  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9a7b  b9145dc200           mov ecx, 0xc25d14
// 009d9a80  c705005dc200ff99cc00 mov dword ptr [0xc25d00], 0xcc99ff
// 009d9a8a  c705045dc200cc260000 mov dword ptr [0xc25d04], 0x26cc
// 009d9a94  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9a9a  b9205dc200           mov ecx, 0xc25d20
// 009d9a9f  c7050c5dc200ffcc9900 mov dword ptr [0xc25d0c], 0x99ccff
// 009d9aa9  c705105dc200cd260000 mov dword ptr [0xc25d10], 0x26cd
// 009d9ab3  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9ab9  b92c5dc200           mov ecx, 0xc25d2c
// 009d9abe  c705185dc200ffff9900 mov dword ptr [0xc25d18], 0x99ffff
// 009d9ac8  c7051c5dc200ce260000 mov dword ptr [0xc25d1c], 0x26ce
// 009d9ad2  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9ad8  b9385dc200           mov ecx, 0xc25d38
// 009d9add  c705245dc200ccffcc00 mov dword ptr [0xc25d24], 0xccffcc
// 009d9ae7  c705285dc200cf260000 mov dword ptr [0xc25d28], 0x26cf
// 009d9af1  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9af7  b9445dc200           mov ecx, 0xc25d44
// 009d9afc  c705305dc200ccffff00 mov dword ptr [0xc25d30], 0xffffcc
// 009d9b06  c705345dc200d0260000 mov dword ptr [0xc25d34], 0x26d0
// 009d9b10  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9b16  b9505dc200           mov ecx, 0xc25d50
// 009d9b1b  c7053c5dc20099ccff00 mov dword ptr [0xc25d3c], 0xffcc99
// 009d9b25  c705405dc200d1260000 mov dword ptr [0xc25d40], 0x26d1
// 009d9b2f  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9b35  b95c5dc200           mov ecx, 0xc25d5c
// 009d9b3a  c705485dc200cc99ff00 mov dword ptr [0xc25d48], 0xff99cc
// 009d9b44  c7054c5dc200d2260000 mov dword ptr [0xc25d4c], 0x26d2
// 009d9b4e  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 009d9b54  6890909e00           push 0x9e9090
// 009d9b59  c705545dc200ffffff00 mov dword ptr [0xc25d54], 0xffffff
// 009d9b63  c705585dc200d3260000 mov dword ptr [0xc25d58], 0x26d3
// 009d9b6d  e8f1eedcff           call 0x7a8a63
// 009d9b72  59                   pop ecx
// 009d9b73  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPControlPopupColor.cpp (function ??__EextendedColors@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPControlPopupColor.cpp

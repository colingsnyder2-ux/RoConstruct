// from server: 100% by user
// from server: 99% by king_originala
// roc 2008-06 004639a0  unit: CScriptEditor  size: 1324 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004639a0
//
// 004639a0  56                   push esi
// 004639a1  8bf1                 mov esi, ecx
// 004639a3  e81ad32300           call 0x6a0cc2
// 004639a8  8bce                 mov ecx, esi
// 004639aa  e8c5cf2300           call 0x6a0974
// 004639af  85c0                 test eax, eax
// 004639b1  7505                 jne 0x4639b8
// 004639b3  e88ccf2300           call 0x6a0944
// 004639b8  53                   push ebx
// 004639b9  57                   push edi
// 004639ba  8bce                 mov ecx, esi
// 004639bc  898640010000         mov dword ptr [esi + 0x140], eax
// 004639c2  e809daffff           call 0x4613d0
// 004639c7  8bf8                 mov edi, eax
// 004639c9  6a01                 push 1
// 004639cb  6a0f                 push 0xf
// 004639cd  8bcf                 mov ecx, edi
// 004639cf  e82cd8ffff           call 0x461200
// 004639d4  6a01                 push 1
// 004639d6  6880b18100           push 0x81b180
// 004639db  6a00                 push 0
// 004639dd  8bcf                 mov ecx, edi
// 004639df  e8acd8ffff           call 0x461290
// 004639e4  8bce                 mov ecx, esi
// 004639e6  e8e5d9ffff           call 0x4613d0
// 004639eb  6a01                 push 1
// 004639ed  8bd8                 mov ebx, eax
// 004639ef  6a00                 push 0
// 004639f1  6a20                 push 0x20
// 004639f3  8bcb                 mov ecx, ebx
// 004639f5  e836cdffff           call 0x460730
// 004639fa  6a01                 push 1
// 004639fc  68ffffff00           push 0xffffff
// 00463a01  6a20                 push 0x20
// 00463a03  8bcb                 mov ecx, ebx
// 00463a05  e876cdffff           call 0x460780
// 00463a0a  6a01                 push 1
// 00463a0c  6a09                 push 9
// 00463a0e  6a20                 push 0x20
// 00463a10  8bcb                 mov ecx, ebx
// 00463a12  e809ceffff           call 0x460820
// 00463a17  6a01                 push 1
// 00463a19  6858b28100           push 0x81b258
// 00463a1e  6a20                 push 0x20
// 00463a20  8bcb                 mov ecx, ebx
// 00463a22  e849ceffff           call 0x460870
// 00463a27  6a01                 push 1
// 00463a29  8bcf                 mov ecx, edi
// 00463a2b  e8d0ccffff           call 0x460700
// 00463a30  8bce                 mov ecx, esi
// 00463a32  e899d9ffff           call 0x4613d0
// 00463a37  6a01                 push 1
// 00463a39  8bd8                 mov ebx, eax
// 00463a3b  6a00                 push 0
// 00463a3d  6a00                 push 0
// 00463a3f  8bcb                 mov ecx, ebx
// 00463a41  e8eaccffff           call 0x460730
// 00463a46  6a01                 push 1
// 00463a48  68ffffff00           push 0xffffff
// 00463a4d  6a00                 push 0
// 00463a4f  8bcb                 mov ecx, ebx
// 00463a51  e82acdffff           call 0x460780
// 00463a56  8bce                 mov ecx, esi
// 00463a58  e873d9ffff           call 0x4613d0
// 00463a5d  6a01                 push 1
// 00463a5f  8bd8                 mov ebx, eax
// 00463a61  6800800000           push 0x8000
// 00463a66  6a01                 push 1
// 00463a68  8bcb                 mov ecx, ebx
// 00463a6a  e8c1ccffff           call 0x460730
// 00463a6f  6a01                 push 1
// 00463a71  68ffffff00           push 0xffffff
// 00463a76  6a01                 push 1
// 00463a78  8bcb                 mov ecx, ebx
// 00463a7a  e801cdffff           call 0x460780
// 00463a7f  8bce                 mov ecx, esi
// 00463a81  e84ad9ffff           call 0x4613d0
// 00463a86  6a01                 push 1
// 00463a88  8bd8                 mov ebx, eax
// 00463a8a  6800800000           push 0x8000
// 00463a8f  6a02                 push 2
// 00463a91  8bcb                 mov ecx, ebx
// 00463a93  e898ccffff           call 0x460730
// 00463a98  6a01                 push 1
// 00463a9a  68ffffff00           push 0xffffff
// 00463a9f  6a02                 push 2
// 00463aa1  8bcb                 mov ecx, ebx
// 00463aa3  e8d8ccffff           call 0x460780
// 00463aa8  8bce                 mov ecx, esi
// 00463aaa  e821d9ffff           call 0x4613d0
// 00463aaf  6a01                 push 1
// 00463ab1  8bd8                 mov ebx, eax
// 00463ab3  6800800000           push 0x8000
// 00463ab8  6a03                 push 3
// 00463aba  8bcb                 mov ecx, ebx
// 00463abc  e86fccffff           call 0x460730
// 00463ac1  6a01                 push 1
// 00463ac3  68ffffff00           push 0xffffff
// 00463ac8  6a03                 push 3
// 00463aca  8bcb                 mov ecx, ebx
// 00463acc  e8afccffff           call 0x460780
// 00463ad1  8bce                 mov ecx, esi
// 00463ad3  e8f8d8ffff           call 0x4613d0
// 00463ad8  6a01                 push 1
// 00463ada  8bd8                 mov ebx, eax
// 00463adc  6800808000           push 0x808000
// 00463ae1  6a04                 push 4
// 00463ae3  8bcb                 mov ecx, ebx
// 00463ae5  e846ccffff           call 0x460730
// 00463aea  6a01                 push 1
// 00463aec  68ffffff00           push 0xffffff
// 00463af1  6a04                 push 4
// 00463af3  8bcb                 mov ecx, ebx
// 00463af5  e886ccffff           call 0x460780
// 00463afa  8bce                 mov ecx, esi
// 00463afc  e8cfd8ffff           call 0x4613d0
// 00463b01  6a01                 push 1
// 00463b03  8bd8                 mov ebx, eax
// 00463b05  6800008000           push 0x800000
// 00463b0a  6a05                 push 5
// 00463b0c  8bcb                 mov ecx, ebx
// 00463b0e  e81dccffff           call 0x460730
// 00463b13  6a01                 push 1
// 00463b15  68ffffff00           push 0xffffff
// 00463b1a  6a05                 push 5
// 00463b1c  8bcb                 mov ecx, ebx
// 00463b1e  e85dccffff           call 0x460780
// 00463b23  8bce                 mov ecx, esi
// 00463b25  e8a6d8ffff           call 0x4613d0
// 00463b2a  6a01                 push 1
// 00463b2c  8bd8                 mov ebx, eax
// 00463b2e  6800008000           push 0x800000
// 00463b33  6a0d                 push 0xd
// 00463b35  8bcb                 mov ecx, ebx
// 00463b37  e8f4cbffff           call 0x460730
// 00463b3c  6a01                 push 1
// 00463b3e  68ffffff00           push 0xffffff
// 00463b43  6a0d                 push 0xd
// 00463b45  8bcb                 mov ecx, ebx
// 00463b47  e834ccffff           call 0x460780
// 00463b4c  8bce                 mov ecx, esi
// 00463b4e  e87dd8ffff           call 0x4613d0
// 00463b53  6a01                 push 1
// 00463b55  8bd8                 mov ebx, eax
// 00463b57  6800008000           push 0x800000
// 00463b5c  6a0e                 push 0xe
// 00463b5e  8bcb                 mov ecx, ebx
// 00463b60  e8cbcbffff           call 0x460730
// 00463b65  6a01                 push 1
// 00463b67  68ffffff00           push 0xffffff
// 00463b6c  6a0e                 push 0xe
// 00463b6e  8bcb                 mov ecx, ebx
// 00463b70  e80bccffff           call 0x460780
// 00463b75  8bce                 mov ecx, esi
// 00463b77  e854d8ffff           call 0x4613d0
// 00463b7c  6a01                 push 1
// 00463b7e  8bd8                 mov ebx, eax
// 00463b80  6800008000           push 0x800000
// 00463b85  6a0f                 push 0xf
// 00463b87  8bcb                 mov ecx, ebx
// 00463b89  e8a2cbffff           call 0x460730
// 00463b8e  6a01                 push 1
// 00463b90  68ffffff00           push 0xffffff
// 00463b95  6a0f                 push 0xf
// 00463b97  8bcb                 mov ecx, ebx
// 00463b99  e8e2cbffff           call 0x460780
// 00463b9e  8bce                 mov ecx, esi
// 00463ba0  e82bd8ffff           call 0x4613d0
// 00463ba5  8bd8                 mov ebx, eax
// 00463ba7  6a01                 push 1
// 00463ba9  6800008000           push 0x800000
// 00463bae  6a10                 push 0x10
// 00463bb0  8bcb                 mov ecx, ebx
// 00463bb2  e879cbffff           call 0x460730
// 00463bb7  6a01                 push 1
// 00463bb9  68ffffff00           push 0xffffff
// 00463bbe  6a10                 push 0x10
// 00463bc0  8bcb                 mov ecx, ebx
// 00463bc2  e8b9cbffff           call 0x460780
// 00463bc7  8bce                 mov ecx, esi
// 00463bc9  e802d8ffff           call 0x4613d0
// 00463bce  6a01                 push 1
// 00463bd0  8bd8                 mov ebx, eax
// 00463bd2  6800008000           push 0x800000
// 00463bd7  6a11                 push 0x11
// 00463bd9  8bcb                 mov ecx, ebx
// 00463bdb  e850cbffff           call 0x460730
// 00463be0  6a01                 push 1
// 00463be2  68ffffff00           push 0xffffff
// 00463be7  6a11                 push 0x11
// 00463be9  8bcb                 mov ecx, ebx
// 00463beb  e890cbffff           call 0x460780
// 00463bf0  8bce                 mov ecx, esi
// 00463bf2  e8d9d7ffff           call 0x4613d0
// 00463bf7  6a01                 push 1
// 00463bf9  8bd8                 mov ebx, eax
// 00463bfb  6800008000           push 0x800000
// 00463c00  6a12                 push 0x12
// 00463c02  8bcb                 mov ecx, ebx
// 00463c04  e827cbffff           call 0x460730
// 00463c09  6a01                 push 1
// 00463c0b  68ffffff00           push 0xffffff
// 00463c10  6a12                 push 0x12
// 00463c12  8bcb                 mov ecx, ebx
// 00463c14  e867cbffff           call 0x460780
// 00463c19  8bce                 mov ecx, esi
// 00463c1b  e8b0d7ffff           call 0x4613d0
// 00463c20  6a01                 push 1
// 00463c22  8bd8                 mov ebx, eax
// 00463c24  6800008000           push 0x800000
// 00463c29  6a13                 push 0x13
// 00463c2b  8bcb                 mov ecx, ebx
// 00463c2d  e8fecaffff           call 0x460730
// 00463c32  6a01                 push 1
// 00463c34  68ffffff00           push 0xffffff
// 00463c39  6a13                 push 0x13
// 00463c3b  8bcb                 mov ecx, ebx
// 00463c3d  e83ecbffff           call 0x460780
// 00463c42  6a01                 push 1
// 00463c44  6a01                 push 1
// 00463c46  6a05                 push 5
// 00463c48  8bcf                 mov ecx, edi
// 00463c4a  e881cbffff           call 0x4607d0
// 00463c4f  8bce                 mov ecx, esi
// 00463c51  e87ad7ffff           call 0x4613d0
// 00463c56  6a01                 push 1
// 00463c58  8bd8                 mov ebx, eax
// 00463c5a  6880008000           push 0x800080
// 00463c5f  6a06                 push 6
// 00463c61  8bcb                 mov ecx, ebx
// 00463c63  e8c8caffff           call 0x460730
// 00463c68  6a01                 push 1
// 00463c6a  68ffffff00           push 0xffffff
// 00463c6f  6a06                 push 6
// 00463c71  8bcb                 mov ecx, ebx
// 00463c73  e808cbffff           call 0x460780
// 00463c78  8bce                 mov ecx, esi
// 00463c7a  e851d7ffff           call 0x4613d0
// 00463c7f  6a01                 push 1
// 00463c81  8bd8                 mov ebx, eax
// 00463c83  6a00                 push 0
// 00463c85  6a0b                 push 0xb
// 00463c87  8bcb                 mov ecx, ebx
// 00463c89  e8a2caffff           call 0x460730
// 00463c8e  6a01                 push 1
// 00463c90  68ffffff00           push 0xffffff
// 00463c95  6a0b                 push 0xb
// 00463c97  8bcb                 mov ecx, ebx
// 00463c99  e8e2caffff           call 0x460780
// 00463c9e  8bce                 mov ecx, esi
// 00463ca0  e82bd7ffff           call 0x4613d0
// 00463ca5  6a01                 push 1
// 00463ca7  8bd8                 mov ebx, eax
// 00463ca9  6880000000           push 0x80
// 00463cae  6a09                 push 9
// 00463cb0  8bcb                 mov ecx, ebx
// 00463cb2  e879caffff           call 0x460730
// 00463cb7  6a01                 push 1
// 00463cb9  68ffffff00           push 0xffffff
// 00463cbe  6a09                 push 9
// 00463cc0  8bcb                 mov ecx, ebx
// 00463cc2  e8b9caffff           call 0x460780
// 00463cc7  8bce                 mov ecx, esi
// 00463cc9  e802d7ffff           call 0x4613d0
// 00463cce  6a01                 push 1
// 00463cd0  8bd8                 mov ebx, eax
// 00463cd2  6880800000           push 0x8080
// 00463cd7  6a0a                 push 0xa
// 00463cd9  8bcb                 mov ecx, ebx
// 00463cdb  e850caffff           call 0x460730
// 00463ce0  6a01                 push 1
// 00463ce2  68ffffff00           push 0xffffff
// 00463ce7  6a0a                 push 0xa
// 00463ce9  8bcb                 mov ecx, ebx
// 00463ceb  e890caffff           call 0x460780
// 00463cf0  6a01                 push 1
// 00463cf2  6a10                 push 0x10
// 00463cf4  6a02                 push 2
// 00463cf6  8bcf                 mov ecx, edi
// 00463cf8  e8d3c8ffff           call 0x4605d0
// 00463cfd  6a01                 push 1
// 00463cff  6a01                 push 1
// 00463d01  6a02                 push 2
// 00463d03  8bcf                 mov ecx, edi
// 00463d05  e8a6c9ffff           call 0x4606b0
// 00463d0a  6a01                 push 1
// 00463d0c  6a00                 push 0
// 00463d0e  6a02                 push 2
// 00463d10  8bcf                 mov ecx, edi
// 00463d12  e869c8ffff           call 0x460580
// 00463d17  6a01                 push 1
// 00463d19  68000000fe           push 0xfe000000
// 00463d1e  6a02                 push 2
// 00463d20  8bcf                 mov ecx, edi
// 00463d22  e839c9ffff           call 0x460660
// 00463d27  6a01                 push 1
// 00463d29  6854b28100           push 0x81b254
// 00463d2e  684cb28100           push 0x81b24c
// 00463d33  8bcf                 mov ecx, edi
// 00463d35  e806d5ffff           call 0x461240
// 00463d3a  8bce                 mov ecx, esi
// 00463d3c  e88fd6ffff           call 0x4613d0
// 00463d41  6a01                 push 1
// 00463d43  8bd8                 mov ebx, eax
// 00463d45  6a07                 push 7
// 00463d47  6a1f                 push 0x1f
// 00463d49  8bcb                 mov ecx, ebx
// 00463d4b  e8c0c5ffff           call 0x460310
// 00463d50  6a01                 push 1
// 00463d52  68ffffff00           push 0xffffff
// 00463d57  6a1f                 push 0x1f
// 00463d59  8bcb                 mov ecx, ebx
// 00463d5b  e800c6ffff           call 0x460360
// 00463d60  6a01                 push 1
// 00463d62  680000ff00           push 0xff0000
// 00463d67  6a1f                 push 0x1f
// 00463d69  8bcb                 mov ecx, ebx
// 00463d6b  e840c6ffff           call 0x4603b0
// 00463d70  8bce                 mov ecx, esi
// 00463d72  e859d6ffff           call 0x4613d0
// 00463d77  6a01                 push 1
// 00463d79  8bd8                 mov ebx, eax
// 00463d7b  6a08                 push 8
// 00463d7d  6a1e                 push 0x1e
// 00463d7f  8bcb                 mov ecx, ebx
// 00463d81  e88ac5ffff           call 0x460310
// 00463d86  6a01                 push 1
// 00463d88  68ffffff00           push 0xffffff
// 00463d8d  6a1e                 push 0x1e
// 00463d8f  8bcb                 mov ecx, ebx
// 00463d91  e8cac5ffff           call 0x460360
// 00463d96  6a01                 push 1
// 00463d98  6a00                 push 0
// 00463d9a  6a1e                 push 0x1e
// 00463d9c  8bcb                 mov ecx, ebx
// 00463d9e  e80dc6ffff           call 0x4603b0
// 00463da3  8bce                 mov ecx, esi
// 00463da5  e826d6ffff           call 0x4613d0
// 00463daa  6a01                 push 1
// 00463dac  8bd8                 mov ebx, eax
// 00463dae  6a05                 push 5
// 00463db0  6a1d                 push 0x1d
// 00463db2  8bcb                 mov ecx, ebx
// 00463db4  e857c5ffff           call 0x460310
// 00463db9  6a01                 push 1
// 00463dbb  68ffffff00           push 0xffffff
// 00463dc0  6a1d                 push 0x1d
// 00463dc2  8bcb                 mov ecx, ebx
// 00463dc4  e897c5ffff           call 0x460360
// 00463dc9  6a01                 push 1
// 00463dcb  6a00                 push 0
// 00463dcd  6a1d                 push 0x1d
// 00463dcf  8bcb                 mov ecx, ebx
// 00463dd1  e8dac5ffff           call 0x4603b0
// 00463dd6  8bce                 mov ecx, esi
// 00463dd8  e8f3d5ffff           call 0x4613d0
// 00463ddd  6a01                 push 1
// 00463ddf  8bd8                 mov ebx, eax
// 00463de1  6a05                 push 5
// 00463de3  6a1c                 push 0x1c
// 00463de5  8bcb                 mov ecx, ebx
// 00463de7  e824c5ffff           call 0x460310
// 00463dec  6a01                 push 1
// 00463dee  68ffffff00           push 0xffffff
// 00463df3  6a1c                 push 0x1c
// 00463df5  8bcb                 mov ecx, ebx
// 00463df7  e864c5ffff           call 0x460360
// 00463dfc  6a01                 push 1
// 00463dfe  6a00                 push 0
// 00463e00  6a1c                 push 0x1c
// 00463e02  8bcb                 mov ecx, ebx
// 00463e04  e8a7c5ffff           call 0x4603b0
// 00463e09  8bce                 mov ecx, esi
// 00463e0b  e8c0d5ffff           call 0x4613d0
// 00463e10  6a01                 push 1
// 00463e12  8bd8                 mov ebx, eax
// 00463e14  6a05                 push 5
// 00463e16  6a19                 push 0x19
// 00463e18  8bcb                 mov ecx, ebx
// 00463e1a  e8f1c4ffff           call 0x460310
// 00463e1f  6a01                 push 1
// 00463e21  68ffffff00           push 0xffffff
// 00463e26  6a19                 push 0x19
// 00463e28  8bcb                 mov ecx, ebx
// 00463e2a  e831c5ffff           call 0x460360
// 00463e2f  6a01                 push 1
// 00463e31  6a00                 push 0
// 00463e33  6a19                 push 0x19
// 00463e35  8bcb                 mov ecx, ebx
// 00463e37  e874c5ffff           call 0x4603b0
// 00463e3c  8bce                 mov ecx, esi
// 00463e3e  e88dd5ffff           call 0x4613d0
// 00463e43  6a01                 push 1
// 00463e45  8bd8                 mov ebx, eax
// 00463e47  6a05                 push 5
// 00463e49  6a1a                 push 0x1a
// 00463e4b  8bcb                 mov ecx, ebx
// 00463e4d  e8bec4ffff           call 0x460310
// 00463e52  6a01                 push 1
// 00463e54  68ffffff00           push 0xffffff
// 00463e59  6a1a                 push 0x1a
// 00463e5b  8bcb                 mov ecx, ebx
// 00463e5d  e8fec4ffff           call 0x460360
// 00463e62  6a01                 push 1
// 00463e64  6a00                 push 0
// 00463e66  6a1a                 push 0x1a
// 00463e68  8bcb                 mov ecx, ebx
// 00463e6a  e841c5ffff           call 0x4603b0
// 00463e6f  8bce                 mov ecx, esi
// 00463e71  e85ad5ffff           call 0x4613d0
// 00463e76  6a01                 push 1
// 00463e78  8bf0                 mov esi, eax
// 00463e7a  6a05                 push 5
// 00463e7c  6a1b                 push 0x1b
// 00463e7e  8bce                 mov ecx, esi
// 00463e80  e88bc4ffff           call 0x460310
// 00463e85  6a01                 push 1
// 00463e87  68ffffff00           push 0xffffff
// 00463e8c  6a1b                 push 0x1b
// 00463e8e  8bce                 mov ecx, esi
// 00463e90  e8cbc4ffff           call 0x460360
// 00463e95  6a01                 push 1
// 00463e97  6a00                 push 0
// 00463e99  6a1b                 push 0x1b
// 00463e9b  8bce                 mov ecx, esi
// 00463e9d  e80ec5ffff           call 0x4603b0
// 00463ea2  6a01                 push 1
// 00463ea4  6a0a                 push 0xa
// 00463ea6  8bcf                 mov ecx, edi
// 00463ea8  e863caffff           call 0x460910
// 00463ead  6a01                 push 1
// 00463eaf  68e8030000           push 0x3e8
// 00463eb4  8bcf                 mov ecx, edi
// 00463eb6  e8a5d2ffff           call 0x461160
// 00463ebb  6a01                 push 1
// 00463ebd  6a20                 push 0x20
// 00463ebf  6a00                 push 0
// 00463ec1  8bcf                 mov ecx, edi
// 00463ec3  e808c7ffff           call 0x4605d0
// 00463ec8  5f                   pop edi
// 00463ec9  5b                   pop ebx
// 00463eca  5e                   pop esi
// 00463ecb  c3                   ret 

struct Control {
    void lexer(int, int);
    void keywords(int, const char*, int);
    void foreground(int, int, int);
    void background(int, int, int);
    void size(int, int, int);
    void font(int, const char*, int);
    void clearStyles(int);
    void bold(int, int, int);
    void marginWidth(int, int, int);
    void marginSensitive(int, int, int);
    void marginType(int, int, int);
    void marginMask(int, unsigned int, int);
    void property(const char*, const char*, int);
    void markerDefine(int, int, int);
    void markerForeground(int, int, int);
    void markerBackground(int, int, int);
    void tabWidth(int, int);
    void dwellTime(int, int);
};

struct CScriptEditor {
    char padding[0x140];
    void* parent;

    void initialize();
    void* getParent();
    static __declspec(noreturn) void defaultParent();
    Control* control();
    void func_004639a0();
};

void CScriptEditor::func_004639a0()
{
    initialize();
    void* p = getParent();
    if (!p)
        defaultParent();
    parent = p;

    Control* c = control();
    c->lexer(15, 1);
    c->keywords(0, reinterpret_cast<const char*>(0x81b180), 1);

    Control* s = control();
    s->foreground(32, 0, 1);
    s->background(32, 0xffffff, 1);
    s->size(32, 9, 1);
    s->font(32, reinterpret_cast<const char*>(0x81b258), 1);
    c->clearStyles(1);

    s = control();
    s->foreground(0, 0, 1);
    s->background(0, 0xffffff, 1);

    s = control();
    s->foreground(1, 0x8000, 1);
    s->background(1, 0xffffff, 1);

    s = control();
    s->foreground(2, 0x8000, 1);
    s->background(2, 0xffffff, 1);

    s = control();
    s->foreground(3, 0x8000, 1);
    s->background(3, 0xffffff, 1);

    s = control();
    s->foreground(4, 0x808000, 1);
    s->background(4, 0xffffff, 1);

    s = control();
    s->foreground(5, 0x800000, 1);
    s->background(5, 0xffffff, 1);

    s = control();
    s->foreground(13, 0x800000, 1);
    s->background(13, 0xffffff, 1);

    s = control();
    s->foreground(14, 0x800000, 1);
    s->background(14, 0xffffff, 1);

    s = control();
    s->foreground(15, 0x800000, 1);
    s->background(15, 0xffffff, 1);

    s = control();
    s->foreground(16, 0x800000, 1);
    s->background(16, 0xffffff, 1);

    s = control();
    s->foreground(17, 0x800000, 1);
    s->background(17, 0xffffff, 1);

    s = control();
    s->foreground(18, 0x800000, 1);
    s->background(18, 0xffffff, 1);

    s = control();
    s->foreground(19, 0x800000, 1);
    s->background(19, 0xffffff, 1);

    c->bold(5, 1, 1);

    s = control();
    s->foreground(6, 0x800080, 1);
    s->background(6, 0xffffff, 1);

    s = control();
    s->foreground(11, 0, 1);
    s->background(11, 0xffffff, 1);

    s = control();
    s->foreground(9, 0x80, 1);
    s->background(9, 0xffffff, 1);

    s = control();
    s->foreground(10, 0x8080, 1);
    s->background(10, 0xffffff, 1);

    c->marginWidth(2, 16, 1);
    c->marginSensitive(2, 1, 1);
    c->marginType(2, 0, 1);
    c->marginMask(2, 0xfe000000U, 1);
    c->property(reinterpret_cast<const char*>(0x81b24c),
                reinterpret_cast<const char*>(0x81b254), 1);

    s = control();
    s->markerDefine(31, 7, 1);
    s->markerForeground(31, 0xffffff, 1);
    s->markerBackground(31, 0xff0000, 1);

    s = control();
    s->markerDefine(30, 8, 1);
    s->markerForeground(30, 0xffffff, 1);
    s->markerBackground(30, 0, 1);

    s = control();
    s->markerDefine(29, 5, 1);
    s->markerForeground(29, 0xffffff, 1);
    s->markerBackground(29, 0, 1);

    s = control();
    s->markerDefine(28, 5, 1);
    s->markerForeground(28, 0xffffff, 1);
    s->markerBackground(28, 0, 1);

    s = control();
    s->markerDefine(25, 5, 1);
    s->markerForeground(25, 0xffffff, 1);
    s->markerBackground(25, 0, 1);

    s = control();
    s->markerDefine(26, 5, 1);
    s->markerForeground(26, 0xffffff, 1);
    s->markerBackground(26, 0, 1);

    s = control();
    s->markerDefine(27, 5, 1);
    s->markerForeground(27, 0xffffff, 1);
    s->markerBackground(27, 0, 1);

    c->tabWidth(10, 1);
    c->dwellTime(1000, 1);
    c->marginWidth(0, 32, 1);
}

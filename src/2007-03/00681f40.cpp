// from server: 100% by auto
// roc 2007-03 00681f40  unit: seg_00680000  size: 717 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00681f40
//
// 00681f40  56                   push esi
// 00681f41  8bf1                 mov esi, ecx
// 00681f43  e8884bfdff           call 0x656ad0
// 00681f48  e85330fdff           call 0x654fa0
// 00681f4d  6a0f                 push 0xf
// 00681f4f  8bc8                 mov ecx, eax
// 00681f51  e85a28fdff           call 0x6547b0
// 00681f56  894604               mov dword ptr [esi + 4], eax
// 00681f59  e84230fdff           call 0x654fa0
// 00681f5e  6a10                 push 0x10
// 00681f60  8bc8                 mov ecx, eax
// 00681f62  e84928fdff           call 0x6547b0
// 00681f67  894608               mov dword ptr [esi + 8], eax
// 00681f6a  e83130fdff           call 0x654fa0
// 00681f6f  6a15                 push 0x15
// 00681f71  8bc8                 mov ecx, eax
// 00681f73  e83828fdff           call 0x6547b0
// 00681f78  89460c               mov dword ptr [esi + 0xc], eax
// 00681f7b  e82030fdff           call 0x654fa0
// 00681f80  6a14                 push 0x14
// 00681f82  8bc8                 mov ecx, eax
// 00681f84  e82728fdff           call 0x6547b0
// 00681f89  894610               mov dword ptr [esi + 0x10], eax
// 00681f8c  e80f30fdff           call 0x654fa0
// 00681f91  6a16                 push 0x16
// 00681f93  8bc8                 mov ecx, eax
// 00681f95  e81628fdff           call 0x6547b0
// 00681f9a  894614               mov dword ptr [esi + 0x14], eax
// 00681f9d  e8fe2ffdff           call 0x654fa0
// 00681fa2  6a12                 push 0x12
// 00681fa4  8bc8                 mov ecx, eax
// 00681fa6  e80528fdff           call 0x6547b0
// 00681fab  894618               mov dword ptr [esi + 0x18], eax
// 00681fae  e8ed2ffdff           call 0x654fa0
// 00681fb3  6a11                 push 0x11
// 00681fb5  8bc8                 mov ecx, eax
// 00681fb7  e8f427fdff           call 0x6547b0
// 00681fbc  89461c               mov dword ptr [esi + 0x1c], eax
// 00681fbf  e8dc2ffdff           call 0x654fa0
// 00681fc4  6a0d                 push 0xd
// 00681fc6  8bc8                 mov ecx, eax
// 00681fc8  e8e327fdff           call 0x6547b0
// 00681fcd  894620               mov dword ptr [esi + 0x20], eax
// 00681fd0  e8cb2ffdff           call 0x654fa0
// 00681fd5  6a0e                 push 0xe
// 00681fd7  8bc8                 mov ecx, eax
// 00681fd9  e8d227fdff           call 0x6547b0
// 00681fde  894624               mov dword ptr [esi + 0x24], eax
// 00681fe1  e8ba2ffdff           call 0x654fa0
// 00681fe6  6a04                 push 4
// 00681fe8  8bc8                 mov ecx, eax
// 00681fea  e8c127fdff           call 0x6547b0
// 00681fef  894628               mov dword ptr [esi + 0x28], eax
// 00681ff2  e8a92ffdff           call 0x654fa0
// 00681ff7  6a07                 push 7
// 00681ff9  8bc8                 mov ecx, eax
// 00681ffb  e8b027fdff           call 0x6547b0
// 00682000  89462c               mov dword ptr [esi + 0x2c], eax
// 00682003  e8982ffdff           call 0x654fa0
// 00682008  6a05                 push 5
// 0068200a  8bc8                 mov ecx, eax
// 0068200c  e89f27fdff           call 0x6547b0
// 00682011  894630               mov dword ptr [esi + 0x30], eax
// 00682014  e8872ffdff           call 0x654fa0
// 00682019  6a06                 push 6
// 0068201b  8bc8                 mov ecx, eax
// 0068201d  e88e27fdff           call 0x6547b0
// 00682022  894634               mov dword ptr [esi + 0x34], eax
// 00682025  e8762ffdff           call 0x654fa0
// 0068202a  6a08                 push 8
// 0068202c  8bc8                 mov ecx, eax
// 0068202e  e87d27fdff           call 0x6547b0
// 00682033  894638               mov dword ptr [esi + 0x38], eax
// 00682036  e8652ffdff           call 0x654fa0
// 0068203b  6a02                 push 2
// 0068203d  8bc8                 mov ecx, eax
// 0068203f  e86c27fdff           call 0x6547b0
// 00682044  89463c               mov dword ptr [esi + 0x3c], eax
// 00682047  e8542ffdff           call 0x654fa0
// 0068204c  6a03                 push 3
// 0068204e  8bc8                 mov ecx, eax
// 00682050  e85b27fdff           call 0x6547b0
// 00682055  894640               mov dword ptr [esi + 0x40], eax
// 00682058  e8432ffdff           call 0x654fa0
// 0068205d  6a1b                 push 0x1b
// 0068205f  8bc8                 mov ecx, eax
// 00682061  e84a27fdff           call 0x6547b0
// 00682066  894644               mov dword ptr [esi + 0x44], eax
// 00682069  e8322ffdff           call 0x654fa0
// 0068206e  6a1c                 push 0x1c
// 00682070  8bc8                 mov ecx, eax
// 00682072  e83927fdff           call 0x6547b0
// 00682077  894648               mov dword ptr [esi + 0x48], eax
// 0068207a  e8212ffdff           call 0x654fa0
// 0068207f  6a09                 push 9
// 00682081  8bc8                 mov ecx, eax
// 00682083  e82827fdff           call 0x6547b0
// 00682088  89464c               mov dword ptr [esi + 0x4c], eax
// 0068208b  e8102ffdff           call 0x654fa0
// 00682090  6a13                 push 0x13
// 00682092  8bc8                 mov ecx, eax
// 00682094  e81727fdff           call 0x6547b0
// 00682099  894650               mov dword ptr [esi + 0x50], eax
// 0068209c  e8ff2efdff           call 0x654fa0
// 006820a1  6a1e                 push 0x1e
// 006820a3  8bc8                 mov ecx, eax
// 006820a5  e80627fdff           call 0x6547b0
// 006820aa  894654               mov dword ptr [esi + 0x54], eax
// 006820ad  e8ee2efdff           call 0x654fa0
// 006820b2  6a1f                 push 0x1f
// 006820b4  8bc8                 mov ecx, eax
// 006820b6  e8f526fdff           call 0x6547b0
// 006820bb  894658               mov dword ptr [esi + 0x58], eax
// 006820be  e8dd2efdff           call 0x654fa0
// 006820c3  6a20                 push 0x20
// 006820c5  8bc8                 mov ecx, eax
// 006820c7  e8e426fdff           call 0x6547b0
// 006820cc  89465c               mov dword ptr [esi + 0x5c], eax
// 006820cf  e8cc2efdff           call 0x654fa0
// 006820d4  6a21                 push 0x21
// 006820d6  8bc8                 mov ecx, eax
// 006820d8  e8d326fdff           call 0x6547b0
// 006820dd  894660               mov dword ptr [esi + 0x60], eax
// 006820e0  e8bb2efdff           call 0x654fa0
// 006820e5  6a22                 push 0x22
// 006820e7  8bc8                 mov ecx, eax
// 006820e9  e8c226fdff           call 0x6547b0
// 006820ee  894664               mov dword ptr [esi + 0x64], eax
// 006820f1  e8aa2efdff           call 0x654fa0
// 006820f6  6a23                 push 0x23
// 006820f8  8bc8                 mov ecx, eax
// 006820fa  e8b126fdff           call 0x6547b0
// 006820ff  894668               mov dword ptr [esi + 0x68], eax
// 00682102  e8992efdff           call 0x654fa0
// 00682107  6a24                 push 0x24
// 00682109  8bc8                 mov ecx, eax
// 0068210b  e8a026fdff           call 0x6547b0
// 00682110  89466c               mov dword ptr [esi + 0x6c], eax
// 00682113  e8882efdff           call 0x654fa0
// 00682118  6a25                 push 0x25
// 0068211a  8bc8                 mov ecx, eax
// 0068211c  e88f26fdff           call 0x6547b0
// 00682121  894670               mov dword ptr [esi + 0x70], eax
// 00682124  e8772efdff           call 0x654fa0
// 00682129  6a26                 push 0x26
// 0068212b  8bc8                 mov ecx, eax
// 0068212d  e87e26fdff           call 0x6547b0
// 00682132  894674               mov dword ptr [esi + 0x74], eax
// 00682135  e8662efdff           call 0x654fa0
// 0068213a  6a27                 push 0x27
// 0068213c  8bc8                 mov ecx, eax
// 0068213e  e86d26fdff           call 0x6547b0
// 00682143  894678               mov dword ptr [esi + 0x78], eax
// 00682146  e8552efdff           call 0x654fa0
// 0068214b  6a28                 push 0x28
// 0068214d  8bc8                 mov ecx, eax
// 0068214f  e85c26fdff           call 0x6547b0
// 00682154  89467c               mov dword ptr [esi + 0x7c], eax
// 00682157  e8442efdff           call 0x654fa0
// 0068215c  6a29                 push 0x29
// 0068215e  8bc8                 mov ecx, eax
// 00682160  e84b26fdff           call 0x6547b0
// 00682165  898680000000         mov dword ptr [esi + 0x80], eax
// 0068216b  e8302efdff           call 0x654fa0
// 00682170  6a2a                 push 0x2a
// 00682172  8bc8                 mov ecx, eax
// 00682174  e83726fdff           call 0x6547b0
// 00682179  898684000000         mov dword ptr [esi + 0x84], eax
// 0068217f  e81c2efdff           call 0x654fa0
// 00682184  6a2b                 push 0x2b
// 00682186  8bc8                 mov ecx, eax
// 00682188  e82326fdff           call 0x6547b0
// 0068218d  898688000000         mov dword ptr [esi + 0x88], eax
// 00682193  e8082efdff           call 0x654fa0
// 00682198  6a2c                 push 0x2c
// 0068219a  8bc8                 mov ecx, eax
// 0068219c  e80f26fdff           call 0x6547b0
// 006821a1  89868c000000         mov dword ptr [esi + 0x8c], eax
// 006821a7  e8f42dfdff           call 0x654fa0
// 006821ac  6a2d                 push 0x2d
// 006821ae  8bc8                 mov ecx, eax
// 006821b0  e8fb25fdff           call 0x6547b0
// 006821b5  898690000000         mov dword ptr [esi + 0x90], eax
// 006821bb  e8e02dfdff           call 0x654fa0
// 006821c0  6a2e                 push 0x2e
// 006821c2  8bc8                 mov ecx, eax
// 006821c4  e8e725fdff           call 0x6547b0
// 006821c9  898694000000         mov dword ptr [esi + 0x94], eax
// 006821cf  e8cc2dfdff           call 0x654fa0
// 006821d4  6a2f                 push 0x2f
// 006821d6  8bc8                 mov ecx, eax
// 006821d8  e8d325fdff           call 0x6547b0
// 006821dd  898698000000         mov dword ptr [esi + 0x98], eax
// 006821e3  e8b82dfdff           call 0x654fa0
// 006821e8  6a30                 push 0x30
// 006821ea  8bc8                 mov ecx, eax
// 006821ec  e8bf25fdff           call 0x6547b0
// 006821f1  89869c000000         mov dword ptr [esi + 0x9c], eax
// 006821f7  e8a42dfdff           call 0x654fa0
// 006821fc  6a31                 push 0x31
// 006821fe  8bc8                 mov ecx, eax
// 00682200  e8ab25fdff           call 0x6547b0
// 00682205  8986a0000000         mov dword ptr [esi + 0xa0], eax
// 0068220b  5e                   pop esi
// 0068220c  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPGlobal.cpp (function ?UpdateSysColors@CXTPAuxData@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPGlobal.cpp

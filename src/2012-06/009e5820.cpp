// roc 2012-06 009e5820  unit: CXTSplitterWnd  size: 264 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e5820
//
// 009e5820  8b442404             mov eax, dword ptr [esp + 4]
// 009e5824  83ec30               sub esp, 0x30
// 009e5827  56                   push esi
// 009e5828  57                   push edi
// 009e5829  50                   push eax
// 009e582a  8bf1                 mov esi, ecx
// 009e582c  e8413d0b00           call 0xa99572
// 009e5831  8bf8                 mov edi, eax
// 009e5833  85ff                 test edi, edi
// 009e5835  0f84e0000000         je 0x9e591b
// 009e583b  8b5620               mov edx, dword ptr [esi + 0x20]
// 009e583e  8d4c2408             lea ecx, [esp + 8]
// 009e5842  51                   push ecx
// 009e5843  52                   push edx
// 009e5844  ff15d83ab200         call dword ptr [0xb23ad8]
// 009e584a  8b467c               mov eax, dword ptr [esi + 0x7c]
// 009e584d  8b4e78               mov ecx, dword ptr [esi + 0x78]
// 009e5850  f7d8                 neg eax
// 009e5852  50                   push eax
// 009e5853  f7d9                 neg ecx
// 009e5855  51                   push ecx
// 009e5856  8d542410             lea edx, [esp + 0x10]
// 009e585a  52                   push edx
// 009e585b  ff154c3bb200         call dword ptr [0xb23b4c]
// 009e5861  8b06                 mov eax, dword ptr [esi]
// 009e5863  8b9094010000         mov edx, dword ptr [eax + 0x194]
// 009e5869  8d4c2428             lea ecx, [esp + 0x28]
// 009e586d  51                   push ecx
// 009e586e  8bce                 mov ecx, esi
// 009e5870  ffd2                 call edx
// 009e5872  83be8c00000000       cmp dword ptr [esi + 0x8c], 0
// 009e5879  7440                 je 0x9e58bb
// 009e587b  8b8680000000         mov eax, dword ptr [esi + 0x80]
// 009e5881  3b4658               cmp eax, dword ptr [esi + 0x58]
// 009e5884  7d35                 jge 0x9e58bb
// 009e5886  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 009e588a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009e588e  8b542410             mov edx, dword ptr [esp + 0x10]
// 009e5892  894c2418             mov dword ptr [esp + 0x18], ecx
// 009e5896  8b4e64               mov ecx, dword ptr [esi + 0x64]
// 009e5899  03c8                 add ecx, eax
// 009e589b  8944241c             mov dword ptr [esp + 0x1c], eax
// 009e589f  8d442418             lea eax, [esp + 0x18]
// 009e58a3  50                   push eax
// 009e58a4  89542424             mov dword ptr [esp + 0x24], edx
// 009e58a8  8b16                 mov edx, dword ptr [esi]
// 009e58aa  8b9254010000         mov edx, dword ptr [edx + 0x154]
// 009e58b0  6a00                 push 0
// 009e58b2  894c242c             mov dword ptr [esp + 0x2c], ecx
// 009e58b6  57                   push edi
// 009e58b7  8bce                 mov ecx, esi
// 009e58b9  ffd2                 call edx
// 009e58bb  83be8800000000       cmp dword ptr [esi + 0x88], 0
// 009e58c2  7440                 je 0x9e5904
// 009e58c4  8b8684000000         mov eax, dword ptr [esi + 0x84]
// 009e58ca  3b465c               cmp eax, dword ptr [esi + 0x5c]
// 009e58cd  7d35                 jge 0x9e5904
// 009e58cf  8b442408             mov eax, dword ptr [esp + 8]
// 009e58d3  8b5660               mov edx, dword ptr [esi + 0x60]
// 009e58d6  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 009e58da  03d0                 add edx, eax
// 009e58dc  89442418             mov dword ptr [esp + 0x18], eax
// 009e58e0  8b442414             mov eax, dword ptr [esp + 0x14]
// 009e58e4  89442424             mov dword ptr [esp + 0x24], eax
// 009e58e8  8d442418             lea eax, [esp + 0x18]
// 009e58ec  50                   push eax
// 009e58ed  89542424             mov dword ptr [esp + 0x24], edx
// 009e58f1  8b16                 mov edx, dword ptr [esi]
// 009e58f3  8b9254010000         mov edx, dword ptr [edx + 0x154]
// 009e58f9  6a00                 push 0
// 009e58fb  894c2424             mov dword ptr [esp + 0x24], ecx
// 009e58ff  57                   push edi
// 009e5900  8bce                 mov ecx, esi
// 009e5902  ffd2                 call edx
// 009e5904  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 009e5908  8b542430             mov edx, dword ptr [esp + 0x30]
// 009e590c  8b06                 mov eax, dword ptr [esi]
// 009e590e  8b80a4010000         mov eax, dword ptr [eax + 0x1a4]
// 009e5914  51                   push ecx
// 009e5915  52                   push edx
// 009e5916  57                   push edi
// 009e5917  8bce                 mov ecx, esi
// 009e5919  ffd0                 call eax
// 009e591b  5f                   pop edi
// 009e591c  b801000000           mov eax, 1
// 009e5921  5e                   pop esi
// 009e5922  83c430               add esp, 0x30
// 009e5925  c20800               ret 8
// copied from an identical function in another client (function ?OnPrintClient@CXTSplitterWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1
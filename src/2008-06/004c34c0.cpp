// from server: 100% by auto
// roc 2008-06 004c34c0  unit: ProfiledRakPeer  size: 726 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c34c0
//
// 004c34c0  55                   push ebp
// 004c34c1  8d6c24b0             lea ebp, [esp - 0x50]
// 004c34c5  81ec20010000         sub esp, 0x120
// 004c34cb  56                   push esi
// 004c34cc  8b7564               mov esi, dword ptr [ebp + 0x64]
// 004c34cf  8b06                 mov eax, dword ptr [esi]
// 004c34d1  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c34d4  8b5608               mov edx, dword ptr [esi + 8]
// 004c34d7  894500               mov dword ptr [ebp], eax
// 004c34da  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c34dd  89450c               mov dword ptr [ebp + 0xc], eax
// 004c34e0  33c0                 xor eax, eax
// 004c34e2  894d04               mov dword ptr [ebp + 4], ecx
// 004c34e5  57                   push edi
// 004c34e6  895508               mov dword ptr [ebp + 8], edx
// 004c34e9  894510               mov dword ptr [ebp + 0x10], eax
// 004c34ec  894514               mov dword ptr [ebp + 0x14], eax
// 004c34ef  894518               mov dword ptr [ebp + 0x18], eax
// 004c34f2  89451c               mov dword ptr [ebp + 0x1c], eax
// 004c34f5  33c9                 xor ecx, ecx
// 004c34f7  eb07                 jmp 0x4c3500
// 004c34f9  8da42400000000       lea esp, [esp]
// 004c3500  8b448d00             mov eax, dword ptr [ebp + ecx*4]
// 004c3504  8d50ff               lea edx, [eax - 1]
// 004c3507  89548d00             mov dword ptr [ebp + ecx*4], edx
// 004c350b  85c0                 test eax, eax
// 004c350d  7506                 jne 0x4c3515
// 004c350f  41                   inc ecx
// 004c3510  83f908               cmp ecx, 8
// 004c3513  72eb                 jb 0x4c3500
// 004c3515  8b7d60               mov edi, dword ptr [ebp + 0x60]
// 004c3518  53                   push ebx
// 004c3519  8d4500               lea eax, [ebp]
// 004c351c  50                   push eax
// 004c351d  8bc8                 mov ecx, eax
// 004c351f  51                   push ecx
// 004c3520  57                   push edi
// 004c3521  e87aacffff           call 0x4be1a0
// 004c3526  8b5500               mov edx, dword ptr [ebp]
// 004c3529  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004c352c  8b4504               mov eax, dword ptr [ebp + 4]
// 004c352f  8b5d5c               mov ebx, dword ptr [ebp + 0x5c]
// 004c3532  895540               mov dword ptr [ebp + 0x40], edx
// 004c3535  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004c3538  894d48               mov dword ptr [ebp + 0x48], ecx
// 004c353b  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c353e  894544               mov dword ptr [ebp + 0x44], eax
// 004c3541  8b06                 mov eax, dword ptr [esi]
// 004c3543  89554c               mov dword ptr [ebp + 0x4c], edx
// 004c3546  8b5608               mov edx, dword ptr [esi + 8]
// 004c3549  898d74ffffff         mov dword ptr [ebp - 0x8c], ecx
// 004c354f  898570ffffff         mov dword ptr [ebp - 0x90], eax
// 004c3555  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c3558  8d8d30ffffff         lea ecx, [ebp - 0xd0]
// 004c355e  899578ffffff         mov dword ptr [ebp - 0x88], edx
// 004c3564  51                   push ecx
// 004c3565  8d9570ffffff         lea edx, [ebp - 0x90]
// 004c356b  89857cffffff         mov dword ptr [ebp - 0x84], eax
// 004c3571  33c0                 xor eax, eax
// 004c3573  52                   push edx
// 004c3574  53                   push ebx
// 004c3575  894580               mov dword ptr [ebp - 0x80], eax
// 004c3578  894584               mov dword ptr [ebp - 0x7c], eax
// 004c357b  894588               mov dword ptr [ebp - 0x78], eax
// 004c357e  89458c               mov dword ptr [ebp - 0x74], eax
// 004c3581  e81aacffff           call 0x4be1a0
// 004c3586  8b8d34ffffff         mov ecx, dword ptr [ebp - 0xcc]
// 004c358c  8b8530ffffff         mov eax, dword ptr [ebp - 0xd0]
// 004c3592  8b9538ffffff         mov edx, dword ptr [ebp - 0xc8]
// 004c3598  894d24               mov dword ptr [ebp + 0x24], ecx
// 004c359b  8d4d30               lea ecx, [ebp + 0x30]
// 004c359e  51                   push ecx
// 004c359f  894520               mov dword ptr [ebp + 0x20], eax
// 004c35a2  8b853cffffff         mov eax, dword ptr [ebp - 0xc4]
// 004c35a8  895528               mov dword ptr [ebp + 0x28], edx
// 004c35ab  56                   push esi
// 004c35ac  8d5540               lea edx, [ebp + 0x40]
// 004c35af  89452c               mov dword ptr [ebp + 0x2c], eax
// 004c35b2  52                   push edx
// 004c35b3  8d4520               lea eax, [ebp + 0x20]
// 004c35b6  50                   push eax
// 004c35b7  e824dcffff           call 0x4c11e0
// 004c35bc  8b7568               mov esi, dword ptr [ebp + 0x68]
// 004c35bf  8b0e                 mov ecx, dword ptr [esi]
// 004c35c1  8b4608               mov eax, dword ptr [esi + 8]
// 004c35c4  8b5604               mov edx, dword ptr [esi + 4]
// 004c35c7  83c428               add esp, 0x28
// 004c35ca  894de0               mov dword ptr [ebp - 0x20], ecx
// 004c35cd  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c35d0  8945e8               mov dword ptr [ebp - 0x18], eax
// 004c35d3  33c0                 xor eax, eax
// 004c35d5  8955e4               mov dword ptr [ebp - 0x1c], edx
// 004c35d8  894dec               mov dword ptr [ebp - 0x14], ecx
// 004c35db  8945f0               mov dword ptr [ebp - 0x10], eax
// 004c35de  8945f4               mov dword ptr [ebp - 0xc], eax
// 004c35e1  8945f8               mov dword ptr [ebp - 8], eax
// 004c35e4  8945fc               mov dword ptr [ebp - 4], eax
// 004c35e7  eb07                 jmp 0x4c35f0
// 004c35e9  8da42400000000       lea esp, [esp]
// 004c35f0  8b4c85e0             mov ecx, dword ptr [ebp + eax*4 - 0x20]
// 004c35f4  8d51ff               lea edx, [ecx - 1]
// 004c35f7  895485e0             mov dword ptr [ebp + eax*4 - 0x20], edx
// 004c35fb  85c9                 test ecx, ecx
// 004c35fd  7506                 jne 0x4c3605
// 004c35ff  40                   inc eax
// 004c3600  83f808               cmp eax, 8
// 004c3603  72eb                 jb 0x4c35f0
// 004c3605  8d45e0               lea eax, [ebp - 0x20]
// 004c3608  50                   push eax
// 004c3609  8bc8                 mov ecx, eax
// 004c360b  51                   push ecx
// 004c360c  57                   push edi
// 004c360d  e88eabffff           call 0x4be1a0
// 004c3612  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 004c3615  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 004c3618  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 004c361b  895520               mov dword ptr [ebp + 0x20], edx
// 004c361e  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004c3621  894d28               mov dword ptr [ebp + 0x28], ecx
// 004c3624  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c3627  894524               mov dword ptr [ebp + 0x24], eax
// 004c362a  8b06                 mov eax, dword ptr [esi]
// 004c362c  89552c               mov dword ptr [ebp + 0x2c], edx
// 004c362f  8b5608               mov edx, dword ptr [esi + 8]
// 004c3632  894d94               mov dword ptr [ebp - 0x6c], ecx
// 004c3635  894590               mov dword ptr [ebp - 0x70], eax
// 004c3638  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c363b  8d8d50ffffff         lea ecx, [ebp - 0xb0]
// 004c3641  895598               mov dword ptr [ebp - 0x68], edx
// 004c3644  51                   push ecx
// 004c3645  8d5590               lea edx, [ebp - 0x70]
// 004c3648  89459c               mov dword ptr [ebp - 0x64], eax
// 004c364b  33c0                 xor eax, eax
// 004c364d  52                   push edx
// 004c364e  53                   push ebx
// 004c364f  8945a0               mov dword ptr [ebp - 0x60], eax
// 004c3652  8945a4               mov dword ptr [ebp - 0x5c], eax
// 004c3655  8945a8               mov dword ptr [ebp - 0x58], eax
// 004c3658  8945ac               mov dword ptr [ebp - 0x54], eax
// 004c365b  e840abffff           call 0x4be1a0
// 004c3660  8b8d54ffffff         mov ecx, dword ptr [ebp - 0xac]
// 004c3666  8b8550ffffff         mov eax, dword ptr [ebp - 0xb0]
// 004c366c  8b9558ffffff         mov edx, dword ptr [ebp - 0xa8]
// 004c3672  894d44               mov dword ptr [ebp + 0x44], ecx
// 004c3675  8d4dd0               lea ecx, [ebp - 0x30]
// 004c3678  51                   push ecx
// 004c3679  894540               mov dword ptr [ebp + 0x40], eax
// 004c367c  8b855cffffff         mov eax, dword ptr [ebp - 0xa4]
// 004c3682  895548               mov dword ptr [ebp + 0x48], edx
// 004c3685  56                   push esi
// 004c3686  8d5520               lea edx, [ebp + 0x20]
// 004c3689  89454c               mov dword ptr [ebp + 0x4c], eax
// 004c368c  52                   push edx
// 004c368d  8d4540               lea eax, [ebp + 0x40]
// 004c3690  50                   push eax
// 004c3691  e84adbffff           call 0x4c11e0
// 004c3696  83c428               add esp, 0x28
// 004c3699  33c0                 xor eax, eax
// 004c369b  5b                   pop ebx
// 004c369c  8d642400             lea esp, [esp]
// 004c36a0  8b4c05dc             mov ecx, dword ptr [ebp + eax - 0x24]
// 004c36a4  8b54053c             mov edx, dword ptr [ebp + eax + 0x3c]
// 004c36a8  3bca                 cmp ecx, edx
// 004c36aa  0f87d1000000         ja 0x4c3781
// 004c36b0  7208                 jb 0x4c36ba
// 004c36b2  83e804               sub eax, 4
// 004c36b5  83f8f4               cmp eax, -0xc
// 004c36b8  7de6                 jge 0x4c36a0
// 004c36ba  8d4530               lea eax, [ebp + 0x30]
// 004c36bd  50                   push eax
// 004c36be  8d4dd0               lea ecx, [ebp - 0x30]
// 004c36c1  51                   push ecx
// 004c36c2  e8f98fffff           call 0x4bc6c0
// 004c36c7  8d55d0               lea edx, [ebp - 0x30]
// 004c36ca  56                   push esi
// 004c36cb  52                   push edx
// 004c36cc  e84f90ffff           call 0x4bc720
// 004c36d1  83c410               add esp, 0x10
// 004c36d4  8b7558               mov esi, dword ptr [ebp + 0x58]
// 004c36d7  8b456c               mov eax, dword ptr [ebp + 0x6c]
// 004c36da  56                   push esi
// 004c36db  50                   push eax
// 004c36dc  8d4dd0               lea ecx, [ebp - 0x30]
// 004c36df  51                   push ecx
// 004c36e0  e82ba5ffff           call 0x4bdc10
// 004c36e5  56                   push esi
// 004c36e6  8d5590               lea edx, [ebp - 0x70]
// 004c36e9  52                   push edx
// 004c36ea  56                   push esi
// 004c36eb  e8b0aaffff           call 0x4be1a0
// 004c36f0  8d8570ffffff         lea eax, [ebp - 0x90]
// 004c36f6  50                   push eax
// 004c36f7  56                   push esi
// 004c36f8  e8e3adffff           call 0x4be4e0
// 004c36fd  8b4d30               mov ecx, dword ptr [ebp + 0x30]
// 004c3700  8b5534               mov edx, dword ptr [ebp + 0x34]
// 004c3703  8b4538               mov eax, dword ptr [ebp + 0x38]
// 004c3706  83c420               add esp, 0x20
// 004c3709  894db0               mov dword ptr [ebp - 0x50], ecx
// 004c370c  8b4d3c               mov ecx, dword ptr [ebp + 0x3c]
// 004c370f  8955b4               mov dword ptr [ebp - 0x4c], edx
// 004c3712  8945b8               mov dword ptr [ebp - 0x48], eax
// 004c3715  33c0                 xor eax, eax
// 004c3717  8d55b0               lea edx, [ebp - 0x50]
// 004c371a  894dbc               mov dword ptr [ebp - 0x44], ecx
// 004c371d  8945c0               mov dword ptr [ebp - 0x40], eax
// 004c3720  8945c4               mov dword ptr [ebp - 0x3c], eax
// 004c3723  8945c8               mov dword ptr [ebp - 0x38], eax
// 004c3726  8945cc               mov dword ptr [ebp - 0x34], eax
// 004c3729  895568               mov dword ptr [ebp + 0x68], edx
// 004c372c  c7456401000000       mov dword ptr [ebp + 0x64], 1
// 004c3733  8b7568               mov esi, dword ptr [ebp + 0x68]
// 004c3736  8b7d58               mov edi, dword ptr [ebp + 0x58]
// 004c3739  8b4d64               mov ecx, dword ptr [ebp + 0x64]
// 004c373c  8b06                 mov eax, dword ptr [esi]
// 004c373e  33d2                 xor edx, edx
// 004c3740  0107                 add dword ptr [edi], eax
// 004c3742  8b4604               mov eax, dword ptr [esi + 4]
// 004c3745  114704               adc dword ptr [edi + 4], eax
// 004c3748  8b4608               mov eax, dword ptr [esi + 8]
// 004c374b  114708               adc dword ptr [edi + 8], eax
// 004c374e  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c3751  11470c               adc dword ptr [edi + 0xc], eax
// 004c3754  e322                 jecxz 0x4c3778
// 004c3756  42                   inc edx
// 004c3757  42                   inc edx
// 004c3758  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004c375b  1104d7               adc dword ptr [edi + edx*8], eax
// 004c375e  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004c3762  1144d704             adc dword ptr [edi + edx*8 + 4], eax
// 004c3766  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004c376a  1144d708             adc dword ptr [edi + edx*8 + 8], eax
// 004c376e  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004c3772  1144d70c             adc dword ptr [edi + edx*8 + 0xc], eax
// 004c3776  e2de                 loop 0x4c3756
// 004c3778  5f                   pop edi
// 004c3779  5e                   pop esi
// 004c377a  83c550               add ebp, 0x50
// 004c377d  8be5                 mov esp, ebp
// 004c377f  5d                   pop ebp
// 004c3780  c3                   ret 
// 004c3781  8d4d30               lea ecx, [ebp + 0x30]
// 004c3784  51                   push ecx
// 004c3785  8d55d0               lea edx, [ebp - 0x30]
// 004c3788  52                   push edx
// 004c3789  e8328fffff           call 0x4bc6c0
// 004c378e  83c408               add esp, 8
// 004c3791  e93effffff           jmp 0x4c36d4
// library openrbx-raknet/RakPeer.cpp (function ??$CRTModExp@$$BY03I$$BY07I@big@@YAXAAY07I00AAY03I111111@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp

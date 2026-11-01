// from server: 100% by auto
// roc 2009-12 0056ed20  unit: RakPeer  size: 4394 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0056ed20
//
// 0056ed20  83ec10               sub esp, 0x10
// 0056ed23  53                   push ebx
// 0056ed24  55                   push ebp
// 0056ed25  56                   push esi
// 0056ed26  8b742424             mov esi, dword ptr [esp + 0x24]
// 0056ed2a  8d4174               lea eax, [ecx + 0x74]
// 0056ed2d  57                   push edi
// 0056ed2e  b910000000           mov ecx, 0x10
// 0056ed33  8bf8                 mov edi, eax
// 0056ed35  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0056ed37  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0056ed3b  8b7108               mov esi, dword ptr [ecx + 8]
// 0056ed3e  8b590c               mov ebx, dword ptr [ecx + 0xc]
// 0056ed41  8b11                 mov edx, dword ptr [ecx]
// 0056ed43  8b7904               mov edi, dword ptr [ecx + 4]
// 0056ed46  33de                 xor ebx, esi
// 0056ed48  23df                 and ebx, edi
// 0056ed4a  33590c               xor ebx, dword ptr [ecx + 0xc]
// 0056ed4d  8b30                 mov esi, dword ptr [eax]
// 0056ed4f  8bea                 mov ebp, edx
// 0056ed51  c1c505               rol ebp, 5
// 0056ed54  03eb                 add ebp, ebx
// 0056ed56  036910               add ebp, dword ptr [ecx + 0x10]
// 0056ed59  c1cf02               ror edi, 2
// 0056ed5c  8db42e9979825a       lea esi, [esi + ebp + 0x5a827999]
// 0056ed63  8b6908               mov ebp, dword ptr [ecx + 8]
// 0056ed66  33ef                 xor ebp, edi
// 0056ed68  23ea                 and ebp, edx
// 0056ed6a  336908               xor ebp, dword ptr [ecx + 8]
// 0056ed6d  8bde                 mov ebx, esi
// 0056ed6f  c1c305               rol ebx, 5
// 0056ed72  03dd                 add ebx, ebp
// 0056ed74  035804               add ebx, dword ptr [eax + 4]
// 0056ed77  c1ca02               ror edx, 2
// 0056ed7a  897c2410             mov dword ptr [esp + 0x10], edi
// 0056ed7e  8b790c               mov edi, dword ptr [ecx + 0xc]
// 0056ed81  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0056ed85  33ea                 xor ebp, edx
// 0056ed87  23ee                 and ebp, esi
// 0056ed89  336c2410             xor ebp, dword ptr [esp + 0x10]
// 0056ed8d  8dbc1f9979825a       lea edi, [edi + ebx + 0x5a827999]
// 0056ed94  8bdf                 mov ebx, edi
// 0056ed96  c1c305               rol ebx, 5
// 0056ed99  035808               add ebx, dword ptr [eax + 8]
// 0056ed9c  89542428             mov dword ptr [esp + 0x28], edx
// 0056eda0  8b5108               mov edx, dword ptr [ecx + 8]
// 0056eda3  03eb                 add ebp, ebx
// 0056eda5  8d942a9979825a       lea edx, [edx + ebp + 0x5a827999]
// 0056edac  c1ce02               ror esi, 2
// 0056edaf  89742418             mov dword ptr [esp + 0x18], esi
// 0056edb3  8bee                 mov ebp, esi
// 0056edb5  8b742428             mov esi, dword ptr [esp + 0x28]
// 0056edb9  33ee                 xor ebp, esi
// 0056edbb  23ef                 and ebp, edi
// 0056edbd  33ee                 xor ebp, esi
// 0056edbf  8b742410             mov esi, dword ptr [esp + 0x10]
// 0056edc3  8bda                 mov ebx, edx
// 0056edc5  c1c305               rol ebx, 5
// 0056edc8  03dd                 add ebx, ebp
// 0056edca  03580c               add ebx, dword ptr [eax + 0xc]
// 0056edcd  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056edd1  c1cf02               ror edi, 2
// 0056edd4  33ef                 xor ebp, edi
// 0056edd6  8db41e9979825a       lea esi, [esi + ebx + 0x5a827999]
// 0056eddd  23ea                 and ebp, edx
// 0056eddf  336c2418             xor ebp, dword ptr [esp + 0x18]
// 0056ede3  8bde                 mov ebx, esi
// 0056ede5  c1c305               rol ebx, 5
// 0056ede8  03dd                 add ebx, ebp
// 0056edea  035810               add ebx, dword ptr [eax + 0x10]
// 0056eded  897c2424             mov dword ptr [esp + 0x24], edi
// 0056edf1  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0056edf5  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0056edf9  c1ca02               ror edx, 2
// 0056edfc  33ea                 xor ebp, edx
// 0056edfe  8dbc1f9979825a       lea edi, [edi + ebx + 0x5a827999]
// 0056ee05  23ee                 and ebp, esi
// 0056ee07  336c2424             xor ebp, dword ptr [esp + 0x24]
// 0056ee0b  8bdf                 mov ebx, edi
// 0056ee0d  c1c305               rol ebx, 5
// 0056ee10  89542414             mov dword ptr [esp + 0x14], edx
// 0056ee14  03dd                 add ebx, ebp
// 0056ee16  035814               add ebx, dword ptr [eax + 0x14]
// 0056ee19  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0056ee1d  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056ee21  8d941a9979825a       lea edx, [edx + ebx + 0x5a827999]
// 0056ee28  c1ce02               ror esi, 2
// 0056ee2b  33ee                 xor ebp, esi
// 0056ee2d  23ef                 and ebp, edi
// 0056ee2f  336c2414             xor ebp, dword ptr [esp + 0x14]
// 0056ee33  8bda                 mov ebx, edx
// 0056ee35  c1c305               rol ebx, 5
// 0056ee38  03dd                 add ebx, ebp
// 0056ee3a  035818               add ebx, dword ptr [eax + 0x18]
// 0056ee3d  c1cf02               ror edi, 2
// 0056ee40  89742410             mov dword ptr [esp + 0x10], esi
// 0056ee44  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0056ee48  8b742424             mov esi, dword ptr [esp + 0x24]
// 0056ee4c  33ef                 xor ebp, edi
// 0056ee4e  23ea                 and ebp, edx
// 0056ee50  336c2410             xor ebp, dword ptr [esp + 0x10]
// 0056ee54  8db41e9979825a       lea esi, [esi + ebx + 0x5a827999]
// 0056ee5b  8bde                 mov ebx, esi
// 0056ee5d  c1c305               rol ebx, 5
// 0056ee60  03dd                 add ebx, ebp
// 0056ee62  03581c               add ebx, dword ptr [eax + 0x1c]
// 0056ee65  c1ca02               ror edx, 2
// 0056ee68  897c2428             mov dword ptr [esp + 0x28], edi
// 0056ee6c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0056ee70  8dbc1f9979825a       lea edi, [edi + ebx + 0x5a827999]
// 0056ee77  89542418             mov dword ptr [esp + 0x18], edx
// 0056ee7b  8bea                 mov ebp, edx
// 0056ee7d  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056ee81  33ea                 xor ebp, edx
// 0056ee83  23ee                 and ebp, esi
// 0056ee85  33ea                 xor ebp, edx
// 0056ee87  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056ee8b  8bdf                 mov ebx, edi
// 0056ee8d  c1c305               rol ebx, 5
// 0056ee90  035820               add ebx, dword ptr [eax + 0x20]
// 0056ee93  03eb                 add ebp, ebx
// 0056ee95  8d942a9979825a       lea edx, [edx + ebp + 0x5a827999]
// 0056ee9c  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056eea0  c1ce02               ror esi, 2
// 0056eea3  33ee                 xor ebp, esi
// 0056eea5  23ef                 and ebp, edi
// 0056eea7  336c2418             xor ebp, dword ptr [esp + 0x18]
// 0056eeab  8bda                 mov ebx, edx
// 0056eead  c1c305               rol ebx, 5
// 0056eeb0  03dd                 add ebx, ebp
// 0056eeb2  035824               add ebx, dword ptr [eax + 0x24]
// 0056eeb5  c1cf02               ror edi, 2
// 0056eeb8  89742424             mov dword ptr [esp + 0x24], esi
// 0056eebc  8b742428             mov esi, dword ptr [esp + 0x28]
// 0056eec0  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0056eec4  33ef                 xor ebp, edi
// 0056eec6  8db41e9979825a       lea esi, [esi + ebx + 0x5a827999]
// 0056eecd  23ea                 and ebp, edx
// 0056eecf  336c2424             xor ebp, dword ptr [esp + 0x24]
// 0056eed3  8bde                 mov ebx, esi
// 0056eed5  c1c305               rol ebx, 5
// 0056eed8  03dd                 add ebx, ebp
// 0056eeda  035828               add ebx, dword ptr [eax + 0x28]
// 0056eedd  c1ca02               ror edx, 2
// 0056eee0  897c2414             mov dword ptr [esp + 0x14], edi
// 0056eee4  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0056eee8  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056eeec  33ea                 xor ebp, edx
// 0056eeee  8dbc1f9979825a       lea edi, [edi + ebx + 0x5a827999]
// 0056eef5  23ee                 and ebp, esi
// 0056eef7  336c2414             xor ebp, dword ptr [esp + 0x14]
// 0056eefb  8bdf                 mov ebx, edi
// 0056eefd  c1c305               rol ebx, 5
// 0056ef00  03dd                 add ebx, ebp
// 0056ef02  03582c               add ebx, dword ptr [eax + 0x2c]
// 0056ef05  89542410             mov dword ptr [esp + 0x10], edx
// 0056ef09  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056ef0d  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0056ef11  8d9c1a9979825a       lea ebx, [edx + ebx + 0x5a827999]
// 0056ef18  c1ce02               ror esi, 2
// 0056ef1b  8bd3                 mov edx, ebx
// 0056ef1d  89742428             mov dword ptr [esp + 0x28], esi
// 0056ef21  c1c205               rol edx, 5
// 0056ef24  33ee                 xor ebp, esi
// 0056ef26  23ef                 and ebp, edi
// 0056ef28  336c2410             xor ebp, dword ptr [esp + 0x10]
// 0056ef2c  8b742414             mov esi, dword ptr [esp + 0x14]
// 0056ef30  03d5                 add edx, ebp
// 0056ef32  035030               add edx, dword ptr [eax + 0x30]
// 0056ef35  c1cf02               ror edi, 2
// 0056ef38  8db4169979825a       lea esi, [esi + edx + 0x5a827999]
// 0056ef3f  8b5034               mov edx, dword ptr [eax + 0x34]
// 0056ef42  89742414             mov dword ptr [esp + 0x14], esi
// 0056ef46  897c2418             mov dword ptr [esp + 0x18], edi
// 0056ef4a  8bee                 mov ebp, esi
// 0056ef4c  8b742428             mov esi, dword ptr [esp + 0x28]
// 0056ef50  33fe                 xor edi, esi
// 0056ef52  23fb                 and edi, ebx
// 0056ef54  c1c505               rol ebp, 5
// 0056ef57  03ea                 add ebp, edx
// 0056ef59  33fe                 xor edi, esi
// 0056ef5b  8b742410             mov esi, dword ptr [esp + 0x10]
// 0056ef5f  03fd                 add edi, ebp
// 0056ef61  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056ef65  335020               xor edx, dword ptr [eax + 0x20]
// 0056ef68  c1cb02               ror ebx, 2
// 0056ef6b  33eb                 xor ebp, ebx
// 0056ef6d  236c2414             and ebp, dword ptr [esp + 0x14]
// 0056ef71  335008               xor edx, dword ptr [eax + 8]
// 0056ef74  336c2418             xor ebp, dword ptr [esp + 0x18]
// 0056ef78  3310                 xor edx, dword ptr [eax]
// 0056ef7a  8db43e9979825a       lea esi, [esi + edi + 0x5a827999]
// 0056ef81  8bfe                 mov edi, esi
// 0056ef83  c1c705               rol edi, 5
// 0056ef86  03fd                 add edi, ebp
// 0056ef88  037838               add edi, dword ptr [eax + 0x38]
// 0056ef8b  895c2424             mov dword ptr [esp + 0x24], ebx
// 0056ef8f  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0056ef93  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0056ef97  8d9c3b9979825a       lea ebx, [ebx + edi + 0x5a827999]
// 0056ef9e  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0056efa2  c1cf02               ror edi, 2
// 0056efa5  33ef                 xor ebp, edi
// 0056efa7  23ee                 and ebp, esi
// 0056efa9  336c2424             xor ebp, dword ptr [esp + 0x24]
// 0056efad  895c2428             mov dword ptr [esp + 0x28], ebx
// 0056efb1  c1c305               rol ebx, 5
// 0056efb4  03dd                 add ebx, ebp
// 0056efb6  03583c               add ebx, dword ptr [eax + 0x3c]
// 0056efb9  c1ce02               ror esi, 2
// 0056efbc  d1c2                 rol edx, 1
// 0056efbe  8954241c             mov dword ptr [esp + 0x1c], edx
// 0056efc2  8910                 mov dword ptr [eax], edx
// 0056efc4  897c2414             mov dword ptr [esp + 0x14], edi
// 0056efc8  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056efcc  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056efd0  8dbc1f9979825a       lea edi, [edi + ebx + 0x5a827999]
// 0056efd7  8bda                 mov ebx, edx
// 0056efd9  33de                 xor ebx, esi
// 0056efdb  89742410             mov dword ptr [esp + 0x10], esi
// 0056efdf  8bf3                 mov esi, ebx
// 0056efe1  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0056efe5  23f3                 and esi, ebx
// 0056efe7  33f2                 xor esi, edx
// 0056efe9  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056efed  8bef                 mov ebp, edi
// 0056efef  c1c505               rol ebp, 5
// 0056eff2  036c241c             add ebp, dword ptr [esp + 0x1c]
// 0056eff6  03f5                 add esi, ebp
// 0056eff8  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0056effc  8db4329979825a       lea esi, [edx + esi + 0x5a827999]
// 0056f003  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056f006  33500c               xor edx, dword ptr [eax + 0xc]
// 0056f009  c1cb02               ror ebx, 2
// 0056f00c  335004               xor edx, dword ptr [eax + 4]
// 0056f00f  89742424             mov dword ptr [esp + 0x24], esi
// 0056f013  335024               xor edx, dword ptr [eax + 0x24]
// 0056f016  33eb                 xor ebp, ebx
// 0056f018  d1c2                 rol edx, 1
// 0056f01a  c1c605               rol esi, 5
// 0056f01d  895c2428             mov dword ptr [esp + 0x28], ebx
// 0056f021  895004               mov dword ptr [eax + 4], edx
// 0056f024  23ef                 and ebp, edi
// 0056f026  336c2410             xor ebp, dword ptr [esp + 0x10]
// 0056f02a  03f2                 add esi, edx
// 0056f02c  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056f030  03ee                 add ebp, esi
// 0056f032  8db42a9979825a       lea esi, [edx + ebp + 0x5a827999]
// 0056f039  8b5028               mov edx, dword ptr [eax + 0x28]
// 0056f03c  335010               xor edx, dword ptr [eax + 0x10]
// 0056f03f  c1cf02               ror edi, 2
// 0056f042  335008               xor edx, dword ptr [eax + 8]
// 0056f045  897c2418             mov dword ptr [esp + 0x18], edi
// 0056f049  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056f04c  337c2428             xor edi, dword ptr [esp + 0x28]
// 0056f050  d1c2                 rol edx, 1
// 0056f052  237c2424             and edi, dword ptr [esp + 0x24]
// 0056f056  895008               mov dword ptr [eax + 8], edx
// 0056f059  337c2428             xor edi, dword ptr [esp + 0x28]
// 0056f05d  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056f061  8bde                 mov ebx, esi
// 0056f063  c1c305               rol ebx, 5
// 0056f066  03da                 add ebx, edx
// 0056f068  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056f06c  03fb                 add edi, ebx
// 0056f06e  8dbc3a9979825a       lea edi, [edx + edi + 0x5a827999]
// 0056f075  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056f079  c1ca02               ror edx, 2
// 0056f07c  8bda                 mov ebx, edx
// 0056f07e  8b500c               mov edx, dword ptr [eax + 0xc]
// 0056f081  3310                 xor edx, dword ptr [eax]
// 0056f083  33eb                 xor ebp, ebx
// 0056f085  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056f088  23ee                 and ebp, esi
// 0056f08a  335014               xor edx, dword ptr [eax + 0x14]
// 0056f08d  336c2418             xor ebp, dword ptr [esp + 0x18]
// 0056f091  d1c2                 rol edx, 1
// 0056f093  89500c               mov dword ptr [eax + 0xc], edx
// 0056f096  897c2410             mov dword ptr [esp + 0x10], edi
// 0056f09a  c1c705               rol edi, 5
// 0056f09d  03fa                 add edi, edx
// 0056f09f  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056f0a3  03ef                 add ebp, edi
// 0056f0a5  8dbc2a9979825a       lea edi, [edx + ebp + 0x5a827999]
// 0056f0ac  8b5030               mov edx, dword ptr [eax + 0x30]
// 0056f0af  335018               xor edx, dword ptr [eax + 0x18]
// 0056f0b2  c1ce02               ror esi, 2
// 0056f0b5  335010               xor edx, dword ptr [eax + 0x10]
// 0056f0b8  895c2424             mov dword ptr [esp + 0x24], ebx
// 0056f0bc  335004               xor edx, dword ptr [eax + 4]
// 0056f0bf  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0056f0c3  d1c2                 rol edx, 1
// 0056f0c5  33ee                 xor ebp, esi
// 0056f0c7  89742414             mov dword ptr [esp + 0x14], esi
// 0056f0cb  8b742410             mov esi, dword ptr [esp + 0x10]
// 0056f0cf  33ee                 xor ebp, esi
// 0056f0d1  895010               mov dword ptr [eax + 0x10], edx
// 0056f0d4  8bdf                 mov ebx, edi
// 0056f0d6  c1c305               rol ebx, 5
// 0056f0d9  03da                 add ebx, edx
// 0056f0db  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056f0df  03eb                 add ebp, ebx
// 0056f0e1  8dac2aa1ebd96e       lea ebp, [edx + ebp + 0x6ed9eba1]
// 0056f0e8  8b5008               mov edx, dword ptr [eax + 8]
// 0056f0eb  335034               xor edx, dword ptr [eax + 0x34]
// 0056f0ee  c1ce02               ror esi, 2
// 0056f0f1  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056f0f4  8bde                 mov ebx, esi
// 0056f0f6  335014               xor edx, dword ptr [eax + 0x14]
// 0056f0f9  8b742414             mov esi, dword ptr [esp + 0x14]
// 0056f0fd  d1c2                 rol edx, 1
// 0056f0ff  33f3                 xor esi, ebx
// 0056f101  896c2418             mov dword ptr [esp + 0x18], ebp
// 0056f105  c1c505               rol ebp, 5
// 0056f108  03ea                 add ebp, edx
// 0056f10a  33f7                 xor esi, edi
// 0056f10c  895014               mov dword ptr [eax + 0x14], edx
// 0056f10f  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056f113  03f5                 add esi, ebp
// 0056f115  c1cf02               ror edi, 2
// 0056f118  8db432a1ebd96e       lea esi, [edx + esi + 0x6ed9eba1]
// 0056f11f  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056f122  895c2410             mov dword ptr [esp + 0x10], ebx
// 0056f126  897c2428             mov dword ptr [esp + 0x28], edi
// 0056f12a  335020               xor edx, dword ptr [eax + 0x20]
// 0056f12d  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056f131  335018               xor edx, dword ptr [eax + 0x18]
// 0056f134  33fb                 xor edi, ebx
// 0056f136  33500c               xor edx, dword ptr [eax + 0xc]
// 0056f139  8bee                 mov ebp, esi
// 0056f13b  d1c2                 rol edx, 1
// 0056f13d  c1c505               rol ebp, 5
// 0056f140  03ea                 add ebp, edx
// 0056f142  895018               mov dword ptr [eax + 0x18], edx
// 0056f145  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056f149  8bdf                 mov ebx, edi
// 0056f14b  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0056f14f  33df                 xor ebx, edi
// 0056f151  03dd                 add ebx, ebp
// 0056f153  8d9c1aa1ebd96e       lea ebx, [edx + ebx + 0x6ed9eba1]
// 0056f15a  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056f15e  c1ca02               ror edx, 2
// 0056f161  8bea                 mov ebp, edx
// 0056f163  8b5010               mov edx, dword ptr [eax + 0x10]
// 0056f166  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056f169  896c2418             mov dword ptr [esp + 0x18], ebp
// 0056f16d  335024               xor edx, dword ptr [eax + 0x24]
// 0056f170  33ee                 xor ebp, esi
// 0056f172  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056f175  33ef                 xor ebp, edi
// 0056f177  d1c2                 rol edx, 1
// 0056f179  89501c               mov dword ptr [eax + 0x1c], edx
// 0056f17c  895c2414             mov dword ptr [esp + 0x14], ebx
// 0056f180  c1c305               rol ebx, 5
// 0056f183  03da                 add ebx, edx
// 0056f185  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056f189  03eb                 add ebp, ebx
// 0056f18b  8dbc2aa1ebd96e       lea edi, [edx + ebp + 0x6ed9eba1]
// 0056f192  8b5028               mov edx, dword ptr [eax + 0x28]
// 0056f195  335020               xor edx, dword ptr [eax + 0x20]
// 0056f198  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056f19c  3310                 xor edx, dword ptr [eax]
// 0056f19e  c1ce02               ror esi, 2
// 0056f1a1  335014               xor edx, dword ptr [eax + 0x14]
// 0056f1a4  33ee                 xor ebp, esi
// 0056f1a6  d1c2                 rol edx, 1
// 0056f1a8  895020               mov dword ptr [eax + 0x20], edx
// 0056f1ab  89742424             mov dword ptr [esp + 0x24], esi
// 0056f1af  8b742414             mov esi, dword ptr [esp + 0x14]
// 0056f1b3  33ee                 xor ebp, esi
// 0056f1b5  8bdf                 mov ebx, edi
// 0056f1b7  c1c305               rol ebx, 5
// 0056f1ba  03da                 add ebx, edx
// 0056f1bc  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056f1c0  03eb                 add ebp, ebx
// 0056f1c2  8dac2aa1ebd96e       lea ebp, [edx + ebp + 0x6ed9eba1]
// 0056f1c9  8b5018               mov edx, dword ptr [eax + 0x18]
// 0056f1cc  335004               xor edx, dword ptr [eax + 4]
// 0056f1cf  c1ce02               ror esi, 2
// 0056f1d2  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056f1d5  8bde                 mov ebx, esi
// 0056f1d7  335024               xor edx, dword ptr [eax + 0x24]
// 0056f1da  8b742424             mov esi, dword ptr [esp + 0x24]
// 0056f1de  d1c2                 rol edx, 1
// 0056f1e0  33f3                 xor esi, ebx
// 0056f1e2  896c2428             mov dword ptr [esp + 0x28], ebp
// 0056f1e6  c1c505               rol ebp, 5
// 0056f1e9  03ea                 add ebp, edx
// 0056f1eb  895024               mov dword ptr [eax + 0x24], edx
// 0056f1ee  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056f1f2  33f7                 xor esi, edi
// 0056f1f4  03f5                 add esi, ebp
// 0056f1f6  8db432a1ebd96e       lea esi, [edx + esi + 0x6ed9eba1]
// 0056f1fd  8b5030               mov edx, dword ptr [eax + 0x30]
// 0056f200  335028               xor edx, dword ptr [eax + 0x28]
// 0056f203  c1cf02               ror edi, 2
// 0056f206  335008               xor edx, dword ptr [eax + 8]
// 0056f209  8bee                 mov ebp, esi
// 0056f20b  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056f20e  895c2414             mov dword ptr [esp + 0x14], ebx
// 0056f212  d1c2                 rol edx, 1
// 0056f214  897c2410             mov dword ptr [esp + 0x10], edi
// 0056f218  895028               mov dword ptr [eax + 0x28], edx
// 0056f21b  c1c505               rol ebp, 5
// 0056f21e  03ea                 add ebp, edx
// 0056f220  33df                 xor ebx, edi
// 0056f222  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0056f226  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056f22a  33df                 xor ebx, edi
// 0056f22c  03dd                 add ebx, ebp
// 0056f22e  8d9c1aa1ebd96e       lea ebx, [edx + ebx + 0x6ed9eba1]
// 0056f235  8b5020               mov edx, dword ptr [eax + 0x20]
// 0056f238  33500c               xor edx, dword ptr [eax + 0xc]
// 0056f23b  c1cf02               ror edi, 2
// 0056f23e  335034               xor edx, dword ptr [eax + 0x34]
// 0056f241  897c2428             mov dword ptr [esp + 0x28], edi
// 0056f245  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056f248  895c2424             mov dword ptr [esp + 0x24], ebx
// 0056f24c  d1c2                 rol edx, 1
// 0056f24e  89502c               mov dword ptr [eax + 0x2c], edx
// 0056f251  c1c305               rol ebx, 5
// 0056f254  03da                 add ebx, edx
// 0056f256  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056f25a  8bfe                 mov edi, esi
// 0056f25c  337c2410             xor edi, dword ptr [esp + 0x10]
// 0056f260  337c2428             xor edi, dword ptr [esp + 0x28]
// 0056f264  03fb                 add edi, ebx
// 0056f266  8dbc3aa1ebd96e       lea edi, [edx + edi + 0x6ed9eba1]
// 0056f26d  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056f270  335030               xor edx, dword ptr [eax + 0x30]
// 0056f273  c1ce02               ror esi, 2
// 0056f276  335010               xor edx, dword ptr [eax + 0x10]
// 0056f279  89742418             mov dword ptr [esp + 0x18], esi
// 0056f27d  335024               xor edx, dword ptr [eax + 0x24]
// 0056f280  33742424             xor esi, dword ptr [esp + 0x24]
// 0056f284  d1c2                 rol edx, 1
// 0056f286  33742428             xor esi, dword ptr [esp + 0x28]
// 0056f28a  895030               mov dword ptr [eax + 0x30], edx
// 0056f28d  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056f291  8bdf                 mov ebx, edi
// 0056f293  c1c305               rol ebx, 5
// 0056f296  03da                 add ebx, edx
// 0056f298  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056f29c  03f3                 add esi, ebx
// 0056f29e  8db432a1ebd96e       lea esi, [edx + esi + 0x6ed9eba1]
// 0056f2a5  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056f2a9  c1ca02               ror edx, 2
// 0056f2ac  8bda                 mov ebx, edx
// 0056f2ae  8b5028               mov edx, dword ptr [eax + 0x28]
// 0056f2b1  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056f2b4  33eb                 xor ebp, ebx
// 0056f2b6  335034               xor edx, dword ptr [eax + 0x34]
// 0056f2b9  33ef                 xor ebp, edi
// 0056f2bb  335014               xor edx, dword ptr [eax + 0x14]
// 0056f2be  89742410             mov dword ptr [esp + 0x10], esi
// 0056f2c2  d1c2                 rol edx, 1
// 0056f2c4  c1c605               rol esi, 5
// 0056f2c7  03f2                 add esi, edx
// 0056f2c9  895034               mov dword ptr [eax + 0x34], edx
// 0056f2cc  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056f2d0  03ee                 add ebp, esi
// 0056f2d2  8db42aa1ebd96e       lea esi, [edx + ebp + 0x6ed9eba1]
// 0056f2d9  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056f2dc  335018               xor edx, dword ptr [eax + 0x18]
// 0056f2df  c1cf02               ror edi, 2
// 0056f2e2  3310                 xor edx, dword ptr [eax]
// 0056f2e4  895c2424             mov dword ptr [esp + 0x24], ebx
// 0056f2e8  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056f2eb  33df                 xor ebx, edi
// 0056f2ed  d1c2                 rol edx, 1
// 0056f2ef  897c2414             mov dword ptr [esp + 0x14], edi
// 0056f2f3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0056f2f7  8bee                 mov ebp, esi
// 0056f2f9  c1c505               rol ebp, 5
// 0056f2fc  03ea                 add ebp, edx
// 0056f2fe  33df                 xor ebx, edi
// 0056f300  895038               mov dword ptr [eax + 0x38], edx
// 0056f303  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056f307  03dd                 add ebx, ebp
// 0056f309  8dac1aa1ebd96e       lea ebp, [edx + ebx + 0x6ed9eba1]
// 0056f310  8b5030               mov edx, dword ptr [eax + 0x30]
// 0056f313  c1cf02               ror edi, 2
// 0056f316  8bdf                 mov ebx, edi
// 0056f318  896c2418             mov dword ptr [esp + 0x18], ebp
// 0056f31c  895c2410             mov dword ptr [esp + 0x10], ebx
// 0056f320  335004               xor edx, dword ptr [eax + 4]
// 0056f323  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0056f327  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056f32a  33fb                 xor edi, ebx
// 0056f32c  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056f32f  33fe                 xor edi, esi
// 0056f331  d1c2                 rol edx, 1
// 0056f333  c1c505               rol ebp, 5
// 0056f336  03ea                 add ebp, edx
// 0056f338  89503c               mov dword ptr [eax + 0x3c], edx
// 0056f33b  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056f33f  03fd                 add edi, ebp
// 0056f341  8dbc3aa1ebd96e       lea edi, [edx + edi + 0x6ed9eba1]
// 0056f348  8b5020               mov edx, dword ptr [eax + 0x20]
// 0056f34b  335008               xor edx, dword ptr [eax + 8]
// 0056f34e  c1ce02               ror esi, 2
// 0056f351  3310                 xor edx, dword ptr [eax]
// 0056f353  89742428             mov dword ptr [esp + 0x28], esi
// 0056f357  335034               xor edx, dword ptr [eax + 0x34]
// 0056f35a  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056f35e  d1c2                 rol edx, 1
// 0056f360  33f3                 xor esi, ebx
// 0056f362  8910                 mov dword ptr [eax], edx
// 0056f364  8bef                 mov ebp, edi
// 0056f366  c1c505               rol ebp, 5
// 0056f369  03ea                 add ebp, edx
// 0056f36b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056f36f  8bde                 mov ebx, esi
// 0056f371  8b742428             mov esi, dword ptr [esp + 0x28]
// 0056f375  33de                 xor ebx, esi
// 0056f377  03dd                 add ebx, ebp
// 0056f379  8d9c1aa1ebd96e       lea ebx, [edx + ebx + 0x6ed9eba1]
// 0056f380  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056f384  c1ca02               ror edx, 2
// 0056f387  8bea                 mov ebp, edx
// 0056f389  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056f38c  33500c               xor edx, dword ptr [eax + 0xc]
// 0056f38f  896c2418             mov dword ptr [esp + 0x18], ebp
// 0056f393  335004               xor edx, dword ptr [eax + 4]
// 0056f396  33ef                 xor ebp, edi
// 0056f398  335024               xor edx, dword ptr [eax + 0x24]
// 0056f39b  33ee                 xor ebp, esi
// 0056f39d  d1c2                 rol edx, 1
// 0056f39f  895c2414             mov dword ptr [esp + 0x14], ebx
// 0056f3a3  c1c305               rol ebx, 5
// 0056f3a6  03da                 add ebx, edx
// 0056f3a8  03eb                 add ebp, ebx
// 0056f3aa  895004               mov dword ptr [eax + 4], edx
// 0056f3ad  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056f3b1  8db42aa1ebd96e       lea esi, [edx + ebp + 0x6ed9eba1]
// 0056f3b8  8b5028               mov edx, dword ptr [eax + 0x28]
// 0056f3bb  335010               xor edx, dword ptr [eax + 0x10]
// 0056f3be  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056f3c2  335008               xor edx, dword ptr [eax + 8]
// 0056f3c5  c1cf02               ror edi, 2
// 0056f3c8  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056f3cb  33ef                 xor ebp, edi
// 0056f3cd  d1c2                 rol edx, 1
// 0056f3cf  897c2424             mov dword ptr [esp + 0x24], edi
// 0056f3d3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0056f3d7  33ef                 xor ebp, edi
// 0056f3d9  895008               mov dword ptr [eax + 8], edx
// 0056f3dc  8bde                 mov ebx, esi
// 0056f3de  c1c305               rol ebx, 5
// 0056f3e1  03da                 add ebx, edx
// 0056f3e3  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056f3e7  03eb                 add ebp, ebx
// 0056f3e9  8dac2aa1ebd96e       lea ebp, [edx + ebp + 0x6ed9eba1]
// 0056f3f0  8b500c               mov edx, dword ptr [eax + 0xc]
// 0056f3f3  3310                 xor edx, dword ptr [eax]
// 0056f3f5  c1cf02               ror edi, 2
// 0056f3f8  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056f3fb  8bdf                 mov ebx, edi
// 0056f3fd  335014               xor edx, dword ptr [eax + 0x14]
// 0056f400  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0056f404  d1c2                 rol edx, 1
// 0056f406  896c2428             mov dword ptr [esp + 0x28], ebp
// 0056f40a  895c2414             mov dword ptr [esp + 0x14], ebx
// 0056f40e  89500c               mov dword ptr [eax + 0xc], edx
// 0056f411  c1c505               rol ebp, 5
// 0056f414  03ea                 add ebp, edx
// 0056f416  33fb                 xor edi, ebx
// 0056f418  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056f41c  33fe                 xor edi, esi
// 0056f41e  03fd                 add edi, ebp
// 0056f420  8dbc3aa1ebd96e       lea edi, [edx + edi + 0x6ed9eba1]
// 0056f427  8b5030               mov edx, dword ptr [eax + 0x30]
// 0056f42a  335018               xor edx, dword ptr [eax + 0x18]
// 0056f42d  c1ce02               ror esi, 2
// 0056f430  335010               xor edx, dword ptr [eax + 0x10]
// 0056f433  33de                 xor ebx, esi
// 0056f435  335004               xor edx, dword ptr [eax + 4]
// 0056f438  89742410             mov dword ptr [esp + 0x10], esi
// 0056f43c  8b742428             mov esi, dword ptr [esp + 0x28]
// 0056f440  d1c2                 rol edx, 1
// 0056f442  33de                 xor ebx, esi
// 0056f444  895010               mov dword ptr [eax + 0x10], edx
// 0056f447  8bef                 mov ebp, edi
// 0056f449  c1c505               rol ebp, 5
// 0056f44c  03ea                 add ebp, edx
// 0056f44e  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056f452  03dd                 add ebx, ebp
// 0056f454  8d9c1aa1ebd96e       lea ebx, [edx + ebx + 0x6ed9eba1]
// 0056f45b  8b5008               mov edx, dword ptr [eax + 8]
// 0056f45e  335034               xor edx, dword ptr [eax + 0x34]
// 0056f461  c1ce02               ror esi, 2
// 0056f464  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056f467  89742428             mov dword ptr [esp + 0x28], esi
// 0056f46b  335014               xor edx, dword ptr [eax + 0x14]
// 0056f46e  895c2424             mov dword ptr [esp + 0x24], ebx
// 0056f472  d1c2                 rol edx, 1
// 0056f474  895014               mov dword ptr [eax + 0x14], edx
// 0056f477  c1c305               rol ebx, 5
// 0056f47a  03da                 add ebx, edx
// 0056f47c  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056f480  8bf7                 mov esi, edi
// 0056f482  33742410             xor esi, dword ptr [esp + 0x10]
// 0056f486  33742428             xor esi, dword ptr [esp + 0x28]
// 0056f48a  03f3                 add esi, ebx
// 0056f48c  8db432a1ebd96e       lea esi, [edx + esi + 0x6ed9eba1]
// 0056f493  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056f496  335020               xor edx, dword ptr [eax + 0x20]
// 0056f499  c1cf02               ror edi, 2
// 0056f49c  335018               xor edx, dword ptr [eax + 0x18]
// 0056f49f  897c2418             mov dword ptr [esp + 0x18], edi
// 0056f4a3  33500c               xor edx, dword ptr [eax + 0xc]
// 0056f4a6  337c2424             xor edi, dword ptr [esp + 0x24]
// 0056f4aa  d1c2                 rol edx, 1
// 0056f4ac  337c2428             xor edi, dword ptr [esp + 0x28]
// 0056f4b0  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056f4b4  895018               mov dword ptr [eax + 0x18], edx
// 0056f4b7  8bde                 mov ebx, esi
// 0056f4b9  c1c305               rol ebx, 5
// 0056f4bc  03da                 add ebx, edx
// 0056f4be  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056f4c2  03fb                 add edi, ebx
// 0056f4c4  8d9c3aa1ebd96e       lea ebx, [edx + edi + 0x6ed9eba1]
// 0056f4cb  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056f4cf  c1ca02               ror edx, 2
// 0056f4d2  8bfa                 mov edi, edx
// 0056f4d4  8b5010               mov edx, dword ptr [eax + 0x10]
// 0056f4d7  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056f4da  895c2410             mov dword ptr [esp + 0x10], ebx
// 0056f4de  335024               xor edx, dword ptr [eax + 0x24]
// 0056f4e1  33ef                 xor ebp, edi
// 0056f4e3  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056f4e6  33ee                 xor ebp, esi
// 0056f4e8  d1c2                 rol edx, 1
// 0056f4ea  c1c305               rol ebx, 5
// 0056f4ed  03da                 add ebx, edx
// 0056f4ef  89501c               mov dword ptr [eax + 0x1c], edx
// 0056f4f2  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056f4f6  03eb                 add ebp, ebx
// 0056f4f8  8d9c2aa1ebd96e       lea ebx, [edx + ebp + 0x6ed9eba1]
// 0056f4ff  8b5028               mov edx, dword ptr [eax + 0x28]
// 0056f502  335020               xor edx, dword ptr [eax + 0x20]
// 0056f505  c1ce02               ror esi, 2
// 0056f508  3310                 xor edx, dword ptr [eax]
// 0056f50a  897c2424             mov dword ptr [esp + 0x24], edi
// 0056f50e  895c2428             mov dword ptr [esp + 0x28], ebx
// 0056f512  89742414             mov dword ptr [esp + 0x14], esi
// 0056f516  335014               xor edx, dword ptr [eax + 0x14]
// 0056f519  8bee                 mov ebp, esi
// 0056f51b  0b6c2410             or ebp, dword ptr [esp + 0x10]
// 0056f51f  23742410             and esi, dword ptr [esp + 0x10]
// 0056f523  23ef                 and ebp, edi
// 0056f525  d1c2                 rol edx, 1
// 0056f527  895020               mov dword ptr [eax + 0x20], edx
// 0056f52a  0bee                 or ebp, esi
// 0056f52c  03ea                 add ebp, edx
// 0056f52e  036c2418             add ebp, dword ptr [esp + 0x18]
// 0056f532  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056f536  c1c305               rol ebx, 5
// 0056f539  c1ca02               ror edx, 2
// 0056f53c  8bfa                 mov edi, edx
// 0056f53e  8b5018               mov edx, dword ptr [eax + 0x18]
// 0056f541  335004               xor edx, dword ptr [eax + 4]
// 0056f544  8db42bdcbc1b8f       lea esi, [ebx + ebp - 0x70e44324]
// 0056f54b  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056f54e  897c2410             mov dword ptr [esp + 0x10], edi
// 0056f552  335024               xor edx, dword ptr [eax + 0x24]
// 0056f555  0b7c2428             or edi, dword ptr [esp + 0x28]
// 0056f559  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0056f55d  236c2428             and ebp, dword ptr [esp + 0x28]
// 0056f561  237c2414             and edi, dword ptr [esp + 0x14]
// 0056f565  d1c2                 rol edx, 1
// 0056f567  0bfd                 or edi, ebp
// 0056f569  03fa                 add edi, edx
// 0056f56b  037c2424             add edi, dword ptr [esp + 0x24]
// 0056f56f  895024               mov dword ptr [eax + 0x24], edx
// 0056f572  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056f576  8bde                 mov ebx, esi
// 0056f578  c1c305               rol ebx, 5
// 0056f57b  c1ca02               ror edx, 2
// 0056f57e  8dbc1fdcbc1b8f       lea edi, [edi + ebx - 0x70e44324]
// 0056f585  8bda                 mov ebx, edx
// 0056f587  8b5030               mov edx, dword ptr [eax + 0x30]
// 0056f58a  335028               xor edx, dword ptr [eax + 0x28]
// 0056f58d  895c2428             mov dword ptr [esp + 0x28], ebx
// 0056f591  335008               xor edx, dword ptr [eax + 8]
// 0056f594  8bee                 mov ebp, esi
// 0056f596  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056f599  0beb                 or ebp, ebx
// 0056f59b  236c2410             and ebp, dword ptr [esp + 0x10]
// 0056f59f  d1c2                 rol edx, 1
// 0056f5a1  895028               mov dword ptr [eax + 0x28], edx
// 0056f5a4  8bde                 mov ebx, esi
// 0056f5a6  235c2428             and ebx, dword ptr [esp + 0x28]
// 0056f5aa  897c2424             mov dword ptr [esp + 0x24], edi
// 0056f5ae  0beb                 or ebp, ebx
// 0056f5b0  03ea                 add ebp, edx
// 0056f5b2  036c2414             add ebp, dword ptr [esp + 0x14]
// 0056f5b6  8b5020               mov edx, dword ptr [eax + 0x20]
// 0056f5b9  33500c               xor edx, dword ptr [eax + 0xc]
// 0056f5bc  c1c705               rol edi, 5
// 0056f5bf  335034               xor edx, dword ptr [eax + 0x34]
// 0056f5c2  c1ce02               ror esi, 2
// 0056f5c5  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056f5c8  8dbc2fdcbc1b8f       lea edi, [edi + ebp - 0x70e44324]
// 0056f5cf  d1c2                 rol edx, 1
// 0056f5d1  8bde                 mov ebx, esi
// 0056f5d3  0b5c2424             or ebx, dword ptr [esp + 0x24]
// 0056f5d7  8bee                 mov ebp, esi
// 0056f5d9  235c2428             and ebx, dword ptr [esp + 0x28]
// 0056f5dd  236c2424             and ebp, dword ptr [esp + 0x24]
// 0056f5e1  89502c               mov dword ptr [eax + 0x2c], edx
// 0056f5e4  0bdd                 or ebx, ebp
// 0056f5e6  03da                 add ebx, edx
// 0056f5e8  035c2410             add ebx, dword ptr [esp + 0x10]
// 0056f5ec  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056f5f0  897c2414             mov dword ptr [esp + 0x14], edi
// 0056f5f4  c1c705               rol edi, 5
// 0056f5f7  c1ca02               ror edx, 2
// 0056f5fa  8dbc3bdcbc1b8f       lea edi, [ebx + edi - 0x70e44324]
// 0056f601  8bda                 mov ebx, edx
// 0056f603  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056f606  335030               xor edx, dword ptr [eax + 0x30]
// 0056f609  897c2410             mov dword ptr [esp + 0x10], edi
// 0056f60d  335010               xor edx, dword ptr [eax + 0x10]
// 0056f610  895c2424             mov dword ptr [esp + 0x24], ebx
// 0056f614  335024               xor edx, dword ptr [eax + 0x24]
// 0056f617  d1c2                 rol edx, 1
// 0056f619  0b5c2414             or ebx, dword ptr [esp + 0x14]
// 0056f61d  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0056f621  236c2414             and ebp, dword ptr [esp + 0x14]
// 0056f625  23de                 and ebx, esi
// 0056f627  0bdd                 or ebx, ebp
// 0056f629  03da                 add ebx, edx
// 0056f62b  035c2428             add ebx, dword ptr [esp + 0x28]
// 0056f62f  895030               mov dword ptr [eax + 0x30], edx
// 0056f632  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056f636  c1c705               rol edi, 5
// 0056f639  c1ca02               ror edx, 2
// 0056f63c  8dbc3bdcbc1b8f       lea edi, [ebx + edi - 0x70e44324]
// 0056f643  8bda                 mov ebx, edx
// 0056f645  8b5028               mov edx, dword ptr [eax + 0x28]
// 0056f648  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056f64b  895c2414             mov dword ptr [esp + 0x14], ebx
// 0056f64f  335034               xor edx, dword ptr [eax + 0x34]
// 0056f652  0b5c2410             or ebx, dword ptr [esp + 0x10]
// 0056f656  335014               xor edx, dword ptr [eax + 0x14]
// 0056f659  235c2424             and ebx, dword ptr [esp + 0x24]
// 0056f65d  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0056f661  236c2410             and ebp, dword ptr [esp + 0x10]
// 0056f665  d1c2                 rol edx, 1
// 0056f667  0bdd                 or ebx, ebp
// 0056f669  03da                 add ebx, edx
// 0056f66b  895034               mov dword ptr [eax + 0x34], edx
// 0056f66e  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056f672  897c2428             mov dword ptr [esp + 0x28], edi
// 0056f676  c1c705               rol edi, 5
// 0056f679  03de                 add ebx, esi
// 0056f67b  c1ca02               ror edx, 2
// 0056f67e  8db43bdcbc1b8f       lea esi, [ebx + edi - 0x70e44324]
// 0056f685  8bfa                 mov edi, edx
// 0056f687  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056f68a  335018               xor edx, dword ptr [eax + 0x18]
// 0056f68d  897c2410             mov dword ptr [esp + 0x10], edi
// 0056f691  3310                 xor edx, dword ptr [eax]
// 0056f693  0b7c2428             or edi, dword ptr [esp + 0x28]
// 0056f697  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056f69a  237c2414             and edi, dword ptr [esp + 0x14]
// 0056f69e  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0056f6a2  236c2428             and ebp, dword ptr [esp + 0x28]
// 0056f6a6  d1c2                 rol edx, 1
// 0056f6a8  0bfd                 or edi, ebp
// 0056f6aa  03fa                 add edi, edx
// 0056f6ac  037c2424             add edi, dword ptr [esp + 0x24]
// 0056f6b0  895038               mov dword ptr [eax + 0x38], edx
// 0056f6b3  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056f6b7  8bde                 mov ebx, esi
// 0056f6b9  c1c305               rol ebx, 5
// 0056f6bc  c1ca02               ror edx, 2
// 0056f6bf  8dbc1fdcbc1b8f       lea edi, [edi + ebx - 0x70e44324]
// 0056f6c6  8bda                 mov ebx, edx
// 0056f6c8  8b5030               mov edx, dword ptr [eax + 0x30]
// 0056f6cb  335004               xor edx, dword ptr [eax + 4]
// 0056f6ce  8bee                 mov ebp, esi
// 0056f6d0  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056f6d3  0beb                 or ebp, ebx
// 0056f6d5  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056f6d8  236c2410             and ebp, dword ptr [esp + 0x10]
// 0056f6dc  d1c2                 rol edx, 1
// 0056f6de  895c2428             mov dword ptr [esp + 0x28], ebx
// 0056f6e2  8bde                 mov ebx, esi
// 0056f6e4  235c2428             and ebx, dword ptr [esp + 0x28]
// 0056f6e8  89503c               mov dword ptr [eax + 0x3c], edx
// 0056f6eb  0beb                 or ebp, ebx
// 0056f6ed  03ea                 add ebp, edx
// 0056f6ef  8b5020               mov edx, dword ptr [eax + 0x20]
// 0056f6f2  335008               xor edx, dword ptr [eax + 8]
// 0056f6f5  036c2414             add ebp, dword ptr [esp + 0x14]
// 0056f6f9  3310                 xor edx, dword ptr [eax]
// 0056f6fb  897c2424             mov dword ptr [esp + 0x24], edi
// 0056f6ff  335034               xor edx, dword ptr [eax + 0x34]
// 0056f702  c1c705               rol edi, 5
// 0056f705  c1ce02               ror esi, 2
// 0056f708  8dbc2fdcbc1b8f       lea edi, [edi + ebp - 0x70e44324]
// 0056f70f  d1c2                 rol edx, 1
// 0056f711  897c2414             mov dword ptr [esp + 0x14], edi
// 0056f715  8910                 mov dword ptr [eax], edx
// 0056f717  c1c705               rol edi, 5
// 0056f71a  8bde                 mov ebx, esi
// 0056f71c  0b5c2424             or ebx, dword ptr [esp + 0x24]
// 0056f720  8bee                 mov ebp, esi
// 0056f722  235c2428             and ebx, dword ptr [esp + 0x28]
// 0056f726  236c2424             and ebp, dword ptr [esp + 0x24]
// 0056f72a  0bdd                 or ebx, ebp
// 0056f72c  03da                 add ebx, edx
// 0056f72e  035c2410             add ebx, dword ptr [esp + 0x10]
// 0056f732  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056f736  c1ca02               ror edx, 2
// 0056f739  8dbc3bdcbc1b8f       lea edi, [ebx + edi - 0x70e44324]
// 0056f740  8bda                 mov ebx, edx
// 0056f742  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056f745  33500c               xor edx, dword ptr [eax + 0xc]
// 0056f748  895c2424             mov dword ptr [esp + 0x24], ebx
// 0056f74c  335004               xor edx, dword ptr [eax + 4]
// 0056f74f  0b5c2414             or ebx, dword ptr [esp + 0x14]
// 0056f753  335024               xor edx, dword ptr [eax + 0x24]
// 0056f756  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0056f75a  236c2414             and ebp, dword ptr [esp + 0x14]
// 0056f75e  d1c2                 rol edx, 1
// 0056f760  23de                 and ebx, esi
// 0056f762  0bdd                 or ebx, ebp
// 0056f764  03da                 add ebx, edx
// 0056f766  035c2428             add ebx, dword ptr [esp + 0x28]
// 0056f76a  895004               mov dword ptr [eax + 4], edx
// 0056f76d  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056f771  897c2410             mov dword ptr [esp + 0x10], edi
// 0056f775  c1c705               rol edi, 5
// 0056f778  c1ca02               ror edx, 2
// 0056f77b  8dbc3bdcbc1b8f       lea edi, [ebx + edi - 0x70e44324]
// 0056f782  8bda                 mov ebx, edx
// 0056f784  8b5028               mov edx, dword ptr [eax + 0x28]
// 0056f787  335010               xor edx, dword ptr [eax + 0x10]
// 0056f78a  895c2414             mov dword ptr [esp + 0x14], ebx
// 0056f78e  335008               xor edx, dword ptr [eax + 8]
// 0056f791  0b5c2410             or ebx, dword ptr [esp + 0x10]
// 0056f795  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056f798  235c2424             and ebx, dword ptr [esp + 0x24]
// 0056f79c  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0056f7a0  236c2410             and ebp, dword ptr [esp + 0x10]
// 0056f7a4  d1c2                 rol edx, 1
// 0056f7a6  0bdd                 or ebx, ebp
// 0056f7a8  03da                 add ebx, edx
// 0056f7aa  895008               mov dword ptr [eax + 8], edx
// 0056f7ad  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056f7b1  897c2428             mov dword ptr [esp + 0x28], edi
// 0056f7b5  c1c705               rol edi, 5
// 0056f7b8  03de                 add ebx, esi
// 0056f7ba  c1ca02               ror edx, 2
// 0056f7bd  8db43bdcbc1b8f       lea esi, [ebx + edi - 0x70e44324]
// 0056f7c4  8bfa                 mov edi, edx
// 0056f7c6  8b500c               mov edx, dword ptr [eax + 0xc]
// 0056f7c9  3310                 xor edx, dword ptr [eax]
// 0056f7cb  897c2410             mov dword ptr [esp + 0x10], edi
// 0056f7cf  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056f7d2  0b7c2428             or edi, dword ptr [esp + 0x28]
// 0056f7d6  335014               xor edx, dword ptr [eax + 0x14]
// 0056f7d9  237c2414             and edi, dword ptr [esp + 0x14]
// 0056f7dd  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0056f7e1  236c2428             and ebp, dword ptr [esp + 0x28]
// 0056f7e5  d1c2                 rol edx, 1
// 0056f7e7  0bfd                 or edi, ebp
// 0056f7e9  03fa                 add edi, edx
// 0056f7eb  037c2424             add edi, dword ptr [esp + 0x24]
// 0056f7ef  89500c               mov dword ptr [eax + 0xc], edx
// 0056f7f2  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056f7f6  8bde                 mov ebx, esi
// 0056f7f8  c1c305               rol ebx, 5
// 0056f7fb  c1ca02               ror edx, 2
// 0056f7fe  8dbc1fdcbc1b8f       lea edi, [edi + ebx - 0x70e44324]
// 0056f805  8bda                 mov ebx, edx
// 0056f807  8b5030               mov edx, dword ptr [eax + 0x30]
// 0056f80a  335018               xor edx, dword ptr [eax + 0x18]
// 0056f80d  897c2424             mov dword ptr [esp + 0x24], edi
// 0056f811  335010               xor edx, dword ptr [eax + 0x10]
// 0056f814  895c2428             mov dword ptr [esp + 0x28], ebx
// 0056f818  335004               xor edx, dword ptr [eax + 4]
// 0056f81b  8bee                 mov ebp, esi
// 0056f81d  d1c2                 rol edx, 1
// 0056f81f  895010               mov dword ptr [eax + 0x10], edx
// 0056f822  c1c705               rol edi, 5
// 0056f825  0beb                 or ebp, ebx
// 0056f827  236c2410             and ebp, dword ptr [esp + 0x10]
// 0056f82b  8bde                 mov ebx, esi
// 0056f82d  235c2428             and ebx, dword ptr [esp + 0x28]
// 0056f831  0beb                 or ebp, ebx
// 0056f833  03ea                 add ebp, edx
// 0056f835  036c2414             add ebp, dword ptr [esp + 0x14]
// 0056f839  8b5008               mov edx, dword ptr [eax + 8]
// 0056f83c  335034               xor edx, dword ptr [eax + 0x34]
// 0056f83f  c1ce02               ror esi, 2
// 0056f842  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056f845  8dbc2fdcbc1b8f       lea edi, [edi + ebp - 0x70e44324]
// 0056f84c  335014               xor edx, dword ptr [eax + 0x14]
// 0056f84f  8bde                 mov ebx, esi
// 0056f851  0b5c2424             or ebx, dword ptr [esp + 0x24]
// 0056f855  d1c2                 rol edx, 1
// 0056f857  235c2428             and ebx, dword ptr [esp + 0x28]
// 0056f85b  895014               mov dword ptr [eax + 0x14], edx
// 0056f85e  897c2414             mov dword ptr [esp + 0x14], edi
// 0056f862  c1c705               rol edi, 5
// 0056f865  8bee                 mov ebp, esi
// 0056f867  236c2424             and ebp, dword ptr [esp + 0x24]
// 0056f86b  0bdd                 or ebx, ebp
// 0056f86d  03da                 add ebx, edx
// 0056f86f  035c2410             add ebx, dword ptr [esp + 0x10]
// 0056f873  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056f877  c1ca02               ror edx, 2
// 0056f87a  8dbc3bdcbc1b8f       lea edi, [ebx + edi - 0x70e44324]
// 0056f881  8bda                 mov ebx, edx
// 0056f883  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056f886  335020               xor edx, dword ptr [eax + 0x20]
// 0056f889  895c2424             mov dword ptr [esp + 0x24], ebx
// 0056f88d  335018               xor edx, dword ptr [eax + 0x18]
// 0056f890  0b5c2414             or ebx, dword ptr [esp + 0x14]
// 0056f894  33500c               xor edx, dword ptr [eax + 0xc]
// 0056f897  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0056f89b  236c2414             and ebp, dword ptr [esp + 0x14]
// 0056f89f  d1c2                 rol edx, 1
// 0056f8a1  23de                 and ebx, esi
// 0056f8a3  0bdd                 or ebx, ebp
// 0056f8a5  03da                 add ebx, edx
// 0056f8a7  035c2428             add ebx, dword ptr [esp + 0x28]
// 0056f8ab  895018               mov dword ptr [eax + 0x18], edx
// 0056f8ae  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056f8b2  897c2410             mov dword ptr [esp + 0x10], edi
// 0056f8b6  c1c705               rol edi, 5
// 0056f8b9  c1ca02               ror edx, 2
// 0056f8bc  8dbc3bdcbc1b8f       lea edi, [ebx + edi - 0x70e44324]
// 0056f8c3  8bda                 mov ebx, edx
// 0056f8c5  8b5010               mov edx, dword ptr [eax + 0x10]
// 0056f8c8  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056f8cb  895c2414             mov dword ptr [esp + 0x14], ebx
// 0056f8cf  335024               xor edx, dword ptr [eax + 0x24]
// 0056f8d2  0b5c2410             or ebx, dword ptr [esp + 0x10]
// 0056f8d6  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056f8d9  235c2424             and ebx, dword ptr [esp + 0x24]
// 0056f8dd  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0056f8e1  236c2410             and ebp, dword ptr [esp + 0x10]
// 0056f8e5  d1c2                 rol edx, 1
// 0056f8e7  0bdd                 or ebx, ebp
// 0056f8e9  03da                 add ebx, edx
// 0056f8eb  89501c               mov dword ptr [eax + 0x1c], edx
// 0056f8ee  8b542410             mov edx, dword ptr [esp + 0x10]
// 0056f8f2  03de                 add ebx, esi
// 0056f8f4  897c2428             mov dword ptr [esp + 0x28], edi
// 0056f8f8  c1c705               rol edi, 5
// 0056f8fb  c1ca02               ror edx, 2
// 0056f8fe  8db43bdcbc1b8f       lea esi, [ebx + edi - 0x70e44324]
// 0056f905  8bfa                 mov edi, edx
// 0056f907  8b5028               mov edx, dword ptr [eax + 0x28]
// 0056f90a  335020               xor edx, dword ptr [eax + 0x20]
// 0056f90d  897c2410             mov dword ptr [esp + 0x10], edi
// 0056f911  3310                 xor edx, dword ptr [eax]
// 0056f913  0b7c2428             or edi, dword ptr [esp + 0x28]
// 0056f917  335014               xor edx, dword ptr [eax + 0x14]
// 0056f91a  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0056f91e  d1c2                 rol edx, 1
// 0056f920  8bde                 mov ebx, esi
// 0056f922  c1c305               rol ebx, 5
// 0056f925  237c2414             and edi, dword ptr [esp + 0x14]
// 0056f929  895020               mov dword ptr [eax + 0x20], edx
// 0056f92c  236c2428             and ebp, dword ptr [esp + 0x28]
// 0056f930  0bfd                 or edi, ebp
// 0056f932  03fa                 add edi, edx
// 0056f934  037c2424             add edi, dword ptr [esp + 0x24]
// 0056f938  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056f93c  c1ca02               ror edx, 2
// 0056f93f  8dbc1fdcbc1b8f       lea edi, [edi + ebx - 0x70e44324]
// 0056f946  8bda                 mov ebx, edx
// 0056f948  8b5018               mov edx, dword ptr [eax + 0x18]
// 0056f94b  335004               xor edx, dword ptr [eax + 4]
// 0056f94e  8bee                 mov ebp, esi
// 0056f950  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056f953  0beb                 or ebp, ebx
// 0056f955  335024               xor edx, dword ptr [eax + 0x24]
// 0056f958  236c2410             and ebp, dword ptr [esp + 0x10]
// 0056f95c  d1c2                 rol edx, 1
// 0056f95e  895c2428             mov dword ptr [esp + 0x28], ebx
// 0056f962  8bde                 mov ebx, esi
// 0056f964  235c2428             and ebx, dword ptr [esp + 0x28]
// 0056f968  895024               mov dword ptr [eax + 0x24], edx
// 0056f96b  0beb                 or ebp, ebx
// 0056f96d  03ea                 add ebp, edx
// 0056f96f  036c2414             add ebp, dword ptr [esp + 0x14]
// 0056f973  8b5030               mov edx, dword ptr [eax + 0x30]
// 0056f976  335028               xor edx, dword ptr [eax + 0x28]
// 0056f979  897c2424             mov dword ptr [esp + 0x24], edi
// 0056f97d  335008               xor edx, dword ptr [eax + 8]
// 0056f980  c1c705               rol edi, 5
// 0056f983  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056f986  c1ce02               ror esi, 2
// 0056f989  8d9c2fdcbc1b8f       lea ebx, [edi + ebp - 0x70e44324]
// 0056f990  d1c2                 rol edx, 1
// 0056f992  8bee                 mov ebp, esi
// 0056f994  0b6c2424             or ebp, dword ptr [esp + 0x24]
// 0056f998  89742418             mov dword ptr [esp + 0x18], esi
// 0056f99c  236c2428             and ebp, dword ptr [esp + 0x28]
// 0056f9a0  23742424             and esi, dword ptr [esp + 0x24]
// 0056f9a4  895028               mov dword ptr [eax + 0x28], edx
// 0056f9a7  0bee                 or ebp, esi
// 0056f9a9  03ea                 add ebp, edx
// 0056f9ab  036c2410             add ebp, dword ptr [esp + 0x10]
// 0056f9af  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056f9b3  8bfb                 mov edi, ebx
// 0056f9b5  c1c705               rol edi, 5
// 0056f9b8  c1ca02               ror edx, 2
// 0056f9bb  8bf2                 mov esi, edx
// 0056f9bd  8b5020               mov edx, dword ptr [eax + 0x20]
// 0056f9c0  33500c               xor edx, dword ptr [eax + 0xc]
// 0056f9c3  89742424             mov dword ptr [esp + 0x24], esi
// 0056f9c7  335034               xor edx, dword ptr [eax + 0x34]
// 0056f9ca  0bf3                 or esi, ebx
// 0056f9cc  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056f9cf  23742418             and esi, dword ptr [esp + 0x18]
// 0056f9d3  895c2414             mov dword ptr [esp + 0x14], ebx
// 0056f9d7  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0056f9db  235c2414             and ebx, dword ptr [esp + 0x14]
// 0056f9df  d1c2                 rol edx, 1
// 0056f9e1  0bf3                 or esi, ebx
// 0056f9e3  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0056f9e7  03f2                 add esi, edx
// 0056f9e9  03742428             add esi, dword ptr [esp + 0x28]
// 0056f9ed  8dbc2fdcbc1b8f       lea edi, [edi + ebp - 0x70e44324]
// 0056f9f4  89502c               mov dword ptr [eax + 0x2c], edx
// 0056f9f7  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056f9fa  335030               xor edx, dword ptr [eax + 0x30]
// 0056f9fd  8bef                 mov ebp, edi
// 0056f9ff  335010               xor edx, dword ptr [eax + 0x10]
// 0056fa02  c1c505               rol ebp, 5
// 0056fa05  335024               xor edx, dword ptr [eax + 0x24]
// 0056fa08  8db42edcbc1b8f       lea esi, [esi + ebp - 0x70e44324]
// 0056fa0f  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0056fa13  c1cb02               ror ebx, 2
// 0056fa16  33eb                 xor ebp, ebx
// 0056fa18  d1c2                 rol edx, 1
// 0056fa1a  33ef                 xor ebp, edi
// 0056fa1c  89742428             mov dword ptr [esp + 0x28], esi
// 0056fa20  03ea                 add ebp, edx
// 0056fa22  c1c605               rol esi, 5
// 0056fa25  036c2418             add ebp, dword ptr [esp + 0x18]
// 0056fa29  895c2414             mov dword ptr [esp + 0x14], ebx
// 0056fa2d  895030               mov dword ptr [eax + 0x30], edx
// 0056fa30  8b5028               mov edx, dword ptr [eax + 0x28]
// 0056fa33  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056fa36  c1cf02               ror edi, 2
// 0056fa39  335034               xor edx, dword ptr [eax + 0x34]
// 0056fa3c  33df                 xor ebx, edi
// 0056fa3e  335014               xor edx, dword ptr [eax + 0x14]
// 0056fa41  8db42ed6c162ca       lea esi, [esi + ebp - 0x359d3e2a]
// 0056fa48  d1c2                 rol edx, 1
// 0056fa4a  895034               mov dword ptr [eax + 0x34], edx
// 0056fa4d  897c2410             mov dword ptr [esp + 0x10], edi
// 0056fa51  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0056fa55  33df                 xor ebx, edi
// 0056fa57  03da                 add ebx, edx
// 0056fa59  035c2424             add ebx, dword ptr [esp + 0x24]
// 0056fa5d  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056fa60  335018               xor edx, dword ptr [eax + 0x18]
// 0056fa63  8bee                 mov ebp, esi
// 0056fa65  3310                 xor edx, dword ptr [eax]
// 0056fa67  c1c505               rol ebp, 5
// 0056fa6a  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056fa6d  c1cf02               ror edi, 2
// 0056fa70  d1c2                 rol edx, 1
// 0056fa72  897c2428             mov dword ptr [esp + 0x28], edi
// 0056fa76  895038               mov dword ptr [eax + 0x38], edx
// 0056fa79  8bfe                 mov edi, esi
// 0056fa7b  337c2410             xor edi, dword ptr [esp + 0x10]
// 0056fa7f  8d9c2bd6c162ca       lea ebx, [ebx + ebp - 0x359d3e2a]
// 0056fa86  337c2428             xor edi, dword ptr [esp + 0x28]
// 0056fa8a  895c2424             mov dword ptr [esp + 0x24], ebx
// 0056fa8e  03fa                 add edi, edx
// 0056fa90  037c2414             add edi, dword ptr [esp + 0x14]
// 0056fa94  8b5030               mov edx, dword ptr [eax + 0x30]
// 0056fa97  335004               xor edx, dword ptr [eax + 4]
// 0056fa9a  c1c305               rol ebx, 5
// 0056fa9d  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056faa0  c1ce02               ror esi, 2
// 0056faa3  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056faa6  89742418             mov dword ptr [esp + 0x18], esi
// 0056faaa  33742424             xor esi, dword ptr [esp + 0x24]
// 0056faae  d1c2                 rol edx, 1
// 0056fab0  33742428             xor esi, dword ptr [esp + 0x28]
// 0056fab4  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056fab8  03f2                 add esi, edx
// 0056faba  03742410             add esi, dword ptr [esp + 0x10]
// 0056fabe  8dbc1fd6c162ca       lea edi, [edi + ebx - 0x359d3e2a]
// 0056fac5  89503c               mov dword ptr [eax + 0x3c], edx
// 0056fac8  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056facc  8bdf                 mov ebx, edi
// 0056face  c1c305               rol ebx, 5
// 0056fad1  c1ca02               ror edx, 2
// 0056fad4  8db41ed6c162ca       lea esi, [esi + ebx - 0x359d3e2a]
// 0056fadb  8bda                 mov ebx, edx
// 0056fadd  8b5020               mov edx, dword ptr [eax + 0x20]
// 0056fae0  335008               xor edx, dword ptr [eax + 8]
// 0056fae3  33eb                 xor ebp, ebx
// 0056fae5  3310                 xor edx, dword ptr [eax]
// 0056fae7  33ef                 xor ebp, edi
// 0056fae9  335034               xor edx, dword ptr [eax + 0x34]
// 0056faec  89742410             mov dword ptr [esp + 0x10], esi
// 0056faf0  d1c2                 rol edx, 1
// 0056faf2  03ea                 add ebp, edx
// 0056faf4  036c2428             add ebp, dword ptr [esp + 0x28]
// 0056faf8  8910                 mov dword ptr [eax], edx
// 0056fafa  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056fafd  33500c               xor edx, dword ptr [eax + 0xc]
// 0056fb00  c1c605               rol esi, 5
// 0056fb03  335004               xor edx, dword ptr [eax + 4]
// 0056fb06  c1cf02               ror edi, 2
// 0056fb09  335024               xor edx, dword ptr [eax + 0x24]
// 0056fb0c  895c2424             mov dword ptr [esp + 0x24], ebx
// 0056fb10  33df                 xor ebx, edi
// 0056fb12  897c2414             mov dword ptr [esp + 0x14], edi
// 0056fb16  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0056fb1a  d1c2                 rol edx, 1
// 0056fb1c  8db42ed6c162ca       lea esi, [esi + ebp - 0x359d3e2a]
// 0056fb23  33df                 xor ebx, edi
// 0056fb25  8bee                 mov ebp, esi
// 0056fb27  03da                 add ebx, edx
// 0056fb29  c1c505               rol ebp, 5
// 0056fb2c  035c2418             add ebx, dword ptr [esp + 0x18]
// 0056fb30  895004               mov dword ptr [eax + 4], edx
// 0056fb33  8b5028               mov edx, dword ptr [eax + 0x28]
// 0056fb36  335010               xor edx, dword ptr [eax + 0x10]
// 0056fb39  8dac2bd6c162ca       lea ebp, [ebx + ebp - 0x359d3e2a]
// 0056fb40  335008               xor edx, dword ptr [eax + 8]
// 0056fb43  c1cf02               ror edi, 2
// 0056fb46  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056fb49  8bdf                 mov ebx, edi
// 0056fb4b  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0056fb4f  d1c2                 rol edx, 1
// 0056fb51  33fb                 xor edi, ebx
// 0056fb53  33fe                 xor edi, esi
// 0056fb55  03fa                 add edi, edx
// 0056fb57  037c2424             add edi, dword ptr [esp + 0x24]
// 0056fb5b  895008               mov dword ptr [eax + 8], edx
// 0056fb5e  8b500c               mov edx, dword ptr [eax + 0xc]
// 0056fb61  3310                 xor edx, dword ptr [eax]
// 0056fb63  896c2418             mov dword ptr [esp + 0x18], ebp
// 0056fb67  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056fb6a  c1c505               rol ebp, 5
// 0056fb6d  335014               xor edx, dword ptr [eax + 0x14]
// 0056fb70  c1ce02               ror esi, 2
// 0056fb73  d1c2                 rol edx, 1
// 0056fb75  8dbc2fd6c162ca       lea edi, [edi + ebp - 0x359d3e2a]
// 0056fb7c  89742428             mov dword ptr [esp + 0x28], esi
// 0056fb80  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056fb84  33f3                 xor esi, ebx
// 0056fb86  89500c               mov dword ptr [eax + 0xc], edx
// 0056fb89  895c2410             mov dword ptr [esp + 0x10], ebx
// 0056fb8d  8bde                 mov ebx, esi
// 0056fb8f  8b742428             mov esi, dword ptr [esp + 0x28]
// 0056fb93  33de                 xor ebx, esi
// 0056fb95  03da                 add ebx, edx
// 0056fb97  035c2414             add ebx, dword ptr [esp + 0x14]
// 0056fb9b  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056fb9f  8bef                 mov ebp, edi
// 0056fba1  c1c505               rol ebp, 5
// 0056fba4  c1ca02               ror edx, 2
// 0056fba7  8d9c2bd6c162ca       lea ebx, [ebx + ebp - 0x359d3e2a]
// 0056fbae  8bea                 mov ebp, edx
// 0056fbb0  8b5030               mov edx, dword ptr [eax + 0x30]
// 0056fbb3  335018               xor edx, dword ptr [eax + 0x18]
// 0056fbb6  896c2418             mov dword ptr [esp + 0x18], ebp
// 0056fbba  335010               xor edx, dword ptr [eax + 0x10]
// 0056fbbd  33ef                 xor ebp, edi
// 0056fbbf  335004               xor edx, dword ptr [eax + 4]
// 0056fbc2  33ee                 xor ebp, esi
// 0056fbc4  d1c2                 rol edx, 1
// 0056fbc6  03ea                 add ebp, edx
// 0056fbc8  036c2410             add ebp, dword ptr [esp + 0x10]
// 0056fbcc  895010               mov dword ptr [eax + 0x10], edx
// 0056fbcf  8b5008               mov edx, dword ptr [eax + 8]
// 0056fbd2  335034               xor edx, dword ptr [eax + 0x34]
// 0056fbd5  895c2414             mov dword ptr [esp + 0x14], ebx
// 0056fbd9  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056fbdc  c1c305               rol ebx, 5
// 0056fbdf  335014               xor edx, dword ptr [eax + 0x14]
// 0056fbe2  8db42bd6c162ca       lea esi, [ebx + ebp - 0x359d3e2a]
// 0056fbe9  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056fbed  c1cf02               ror edi, 2
// 0056fbf0  33ef                 xor ebp, edi
// 0056fbf2  d1c2                 rol edx, 1
// 0056fbf4  897c2424             mov dword ptr [esp + 0x24], edi
// 0056fbf8  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0056fbfc  33ef                 xor ebp, edi
// 0056fbfe  03ea                 add ebp, edx
// 0056fc00  036c2428             add ebp, dword ptr [esp + 0x28]
// 0056fc04  895014               mov dword ptr [eax + 0x14], edx
// 0056fc07  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056fc0a  335020               xor edx, dword ptr [eax + 0x20]
// 0056fc0d  8bde                 mov ebx, esi
// 0056fc0f  335018               xor edx, dword ptr [eax + 0x18]
// 0056fc12  c1c305               rol ebx, 5
// 0056fc15  33500c               xor edx, dword ptr [eax + 0xc]
// 0056fc18  c1cf02               ror edi, 2
// 0056fc1b  8dac2bd6c162ca       lea ebp, [ebx + ebp - 0x359d3e2a]
// 0056fc22  8bdf                 mov ebx, edi
// 0056fc24  d1c2                 rol edx, 1
// 0056fc26  896c2428             mov dword ptr [esp + 0x28], ebp
// 0056fc2a  895c2414             mov dword ptr [esp + 0x14], ebx
// 0056fc2e  895018               mov dword ptr [eax + 0x18], edx
// 0056fc31  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0056fc35  33fb                 xor edi, ebx
// 0056fc37  33fe                 xor edi, esi
// 0056fc39  03fa                 add edi, edx
// 0056fc3b  037c2418             add edi, dword ptr [esp + 0x18]
// 0056fc3f  8b5010               mov edx, dword ptr [eax + 0x10]
// 0056fc42  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056fc45  c1c505               rol ebp, 5
// 0056fc48  335024               xor edx, dword ptr [eax + 0x24]
// 0056fc4b  c1ce02               ror esi, 2
// 0056fc4e  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056fc51  33de                 xor ebx, esi
// 0056fc53  d1c2                 rol edx, 1
// 0056fc55  89501c               mov dword ptr [eax + 0x1c], edx
// 0056fc58  8dbc2fd6c162ca       lea edi, [edi + ebp - 0x359d3e2a]
// 0056fc5f  89742410             mov dword ptr [esp + 0x10], esi
// 0056fc63  8b742428             mov esi, dword ptr [esp + 0x28]
// 0056fc67  33de                 xor ebx, esi
// 0056fc69  03da                 add ebx, edx
// 0056fc6b  035c2424             add ebx, dword ptr [esp + 0x24]
// 0056fc6f  8b5028               mov edx, dword ptr [eax + 0x28]
// 0056fc72  335020               xor edx, dword ptr [eax + 0x20]
// 0056fc75  8bef                 mov ebp, edi
// 0056fc77  3310                 xor edx, dword ptr [eax]
// 0056fc79  c1c505               rol ebp, 5
// 0056fc7c  335014               xor edx, dword ptr [eax + 0x14]
// 0056fc7f  c1ce02               ror esi, 2
// 0056fc82  d1c2                 rol edx, 1
// 0056fc84  89742428             mov dword ptr [esp + 0x28], esi
// 0056fc88  895020               mov dword ptr [eax + 0x20], edx
// 0056fc8b  8bf7                 mov esi, edi
// 0056fc8d  33742410             xor esi, dword ptr [esp + 0x10]
// 0056fc91  8d9c2bd6c162ca       lea ebx, [ebx + ebp - 0x359d3e2a]
// 0056fc98  33742428             xor esi, dword ptr [esp + 0x28]
// 0056fc9c  895c2424             mov dword ptr [esp + 0x24], ebx
// 0056fca0  03f2                 add esi, edx
// 0056fca2  03742414             add esi, dword ptr [esp + 0x14]
// 0056fca6  8b5018               mov edx, dword ptr [eax + 0x18]
// 0056fca9  335004               xor edx, dword ptr [eax + 4]
// 0056fcac  c1c305               rol ebx, 5
// 0056fcaf  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056fcb2  c1cf02               ror edi, 2
// 0056fcb5  335024               xor edx, dword ptr [eax + 0x24]
// 0056fcb8  897c2418             mov dword ptr [esp + 0x18], edi
// 0056fcbc  337c2424             xor edi, dword ptr [esp + 0x24]
// 0056fcc0  d1c2                 rol edx, 1
// 0056fcc2  337c2428             xor edi, dword ptr [esp + 0x28]
// 0056fcc6  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056fcca  03fa                 add edi, edx
// 0056fccc  037c2410             add edi, dword ptr [esp + 0x10]
// 0056fcd0  895024               mov dword ptr [eax + 0x24], edx
// 0056fcd3  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056fcd7  8db41ed6c162ca       lea esi, [esi + ebx - 0x359d3e2a]
// 0056fcde  8bde                 mov ebx, esi
// 0056fce0  c1c305               rol ebx, 5
// 0056fce3  c1ca02               ror edx, 2
// 0056fce6  8dbc1fd6c162ca       lea edi, [edi + ebx - 0x359d3e2a]
// 0056fced  8bda                 mov ebx, edx
// 0056fcef  8b5030               mov edx, dword ptr [eax + 0x30]
// 0056fcf2  335028               xor edx, dword ptr [eax + 0x28]
// 0056fcf5  33eb                 xor ebp, ebx
// 0056fcf7  335008               xor edx, dword ptr [eax + 8]
// 0056fcfa  33ee                 xor ebp, esi
// 0056fcfc  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056fcff  897c2410             mov dword ptr [esp + 0x10], edi
// 0056fd03  d1c2                 rol edx, 1
// 0056fd05  03ea                 add ebp, edx
// 0056fd07  036c2428             add ebp, dword ptr [esp + 0x28]
// 0056fd0b  895028               mov dword ptr [eax + 0x28], edx
// 0056fd0e  8b5020               mov edx, dword ptr [eax + 0x20]
// 0056fd11  33500c               xor edx, dword ptr [eax + 0xc]
// 0056fd14  c1c705               rol edi, 5
// 0056fd17  335034               xor edx, dword ptr [eax + 0x34]
// 0056fd1a  c1ce02               ror esi, 2
// 0056fd1d  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056fd20  8dbc2fd6c162ca       lea edi, [edi + ebp - 0x359d3e2a]
// 0056fd27  d1c2                 rol edx, 1
// 0056fd29  895c2424             mov dword ptr [esp + 0x24], ebx
// 0056fd2d  89742414             mov dword ptr [esp + 0x14], esi
// 0056fd31  89502c               mov dword ptr [eax + 0x2c], edx
// 0056fd34  8bef                 mov ebp, edi
// 0056fd36  33de                 xor ebx, esi
// 0056fd38  8b742410             mov esi, dword ptr [esp + 0x10]
// 0056fd3c  33de                 xor ebx, esi
// 0056fd3e  03da                 add ebx, edx
// 0056fd40  035c2418             add ebx, dword ptr [esp + 0x18]
// 0056fd44  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056fd47  335030               xor edx, dword ptr [eax + 0x30]
// 0056fd4a  c1c505               rol ebp, 5
// 0056fd4d  335010               xor edx, dword ptr [eax + 0x10]
// 0056fd50  c1ce02               ror esi, 2
// 0056fd53  335024               xor edx, dword ptr [eax + 0x24]
// 0056fd56  8dac2bd6c162ca       lea ebp, [ebx + ebp - 0x359d3e2a]
// 0056fd5d  d1c2                 rol edx, 1
// 0056fd5f  8bde                 mov ebx, esi
// 0056fd61  8b742414             mov esi, dword ptr [esp + 0x14]
// 0056fd65  33f3                 xor esi, ebx
// 0056fd67  33f7                 xor esi, edi
// 0056fd69  03f2                 add esi, edx
// 0056fd6b  03742424             add esi, dword ptr [esp + 0x24]
// 0056fd6f  895030               mov dword ptr [eax + 0x30], edx
// 0056fd72  8b5028               mov edx, dword ptr [eax + 0x28]
// 0056fd75  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056fd78  896c2418             mov dword ptr [esp + 0x18], ebp
// 0056fd7c  335034               xor edx, dword ptr [eax + 0x34]
// 0056fd7f  c1c505               rol ebp, 5
// 0056fd82  335014               xor edx, dword ptr [eax + 0x14]
// 0056fd85  c1cf02               ror edi, 2
// 0056fd88  d1c2                 rol edx, 1
// 0056fd8a  895034               mov dword ptr [eax + 0x34], edx
// 0056fd8d  8db42ed6c162ca       lea esi, [esi + ebp - 0x359d3e2a]
// 0056fd94  897c2428             mov dword ptr [esp + 0x28], edi
// 0056fd98  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056fd9c  33fb                 xor edi, ebx
// 0056fd9e  895c2410             mov dword ptr [esp + 0x10], ebx
// 0056fda2  8bdf                 mov ebx, edi
// 0056fda4  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0056fda8  33df                 xor ebx, edi
// 0056fdaa  03da                 add ebx, edx
// 0056fdac  035c2414             add ebx, dword ptr [esp + 0x14]
// 0056fdb0  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056fdb4  8bee                 mov ebp, esi
// 0056fdb6  c1c505               rol ebp, 5
// 0056fdb9  c1ca02               ror edx, 2
// 0056fdbc  8d9c2bd6c162ca       lea ebx, [ebx + ebp - 0x359d3e2a]
// 0056fdc3  8bea                 mov ebp, edx
// 0056fdc5  8b5038               mov edx, dword ptr [eax + 0x38]
// 0056fdc8  335018               xor edx, dword ptr [eax + 0x18]
// 0056fdcb  896c2418             mov dword ptr [esp + 0x18], ebp
// 0056fdcf  3310                 xor edx, dword ptr [eax]
// 0056fdd1  33ee                 xor ebp, esi
// 0056fdd3  33502c               xor edx, dword ptr [eax + 0x2c]
// 0056fdd6  33ef                 xor ebp, edi
// 0056fdd8  d1c2                 rol edx, 1
// 0056fdda  895038               mov dword ptr [eax + 0x38], edx
// 0056fddd  03ea                 add ebp, edx
// 0056fddf  8b5030               mov edx, dword ptr [eax + 0x30]
// 0056fde2  335004               xor edx, dword ptr [eax + 4]
// 0056fde5  036c2410             add ebp, dword ptr [esp + 0x10]
// 0056fde9  33503c               xor edx, dword ptr [eax + 0x3c]
// 0056fdec  895c2414             mov dword ptr [esp + 0x14], ebx
// 0056fdf0  33501c               xor edx, dword ptr [eax + 0x1c]
// 0056fdf3  c1c305               rol ebx, 5
// 0056fdf6  c1ce02               ror esi, 2
// 0056fdf9  d1c2                 rol edx, 1
// 0056fdfb  89503c               mov dword ptr [eax + 0x3c], edx
// 0056fdfe  8b442418             mov eax, dword ptr [esp + 0x18]
// 0056fe02  33c6                 xor eax, esi
// 0056fe04  89742424             mov dword ptr [esp + 0x24], esi
// 0056fe08  8bf0                 mov esi, eax
// 0056fe0a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0056fe0e  8d9c2bd6c162ca       lea ebx, [ebx + ebp - 0x359d3e2a]
// 0056fe15  33f0                 xor esi, eax
// 0056fe17  03f2                 add esi, edx
// 0056fe19  8beb                 mov ebp, ebx
// 0056fe1b  c1c505               rol ebp, 5
// 0056fe1e  03f7                 add esi, edi
// 0056fe20  8d942ed6c162ca       lea edx, [esi + ebp - 0x359d3e2a]
// 0056fe27  0111                 add dword ptr [ecx], edx
// 0056fe29  015904               add dword ptr [ecx + 4], ebx
// 0056fe2c  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056fe30  c1c802               ror eax, 2
// 0056fe33  014108               add dword ptr [ecx + 8], eax
// 0056fe36  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056fe3a  01410c               add dword ptr [ecx + 0xc], eax
// 0056fe3d  015110               add dword ptr [ecx + 0x10], edx
// 0056fe40  5f                   pop edi
// 0056fe41  5e                   pop esi
// 0056fe42  5d                   pop ebp
// 0056fe43  5b                   pop ebx
// 0056fe44  83c410               add esp, 0x10
// 0056fe47  c20800               ret 8
// library rbx2016-raknet/SHA1.cpp (function ?Transform@CSHA1@@AAEXQAIQAE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet SHA1.cpp

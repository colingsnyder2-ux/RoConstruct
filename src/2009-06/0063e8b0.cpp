// from server: 100% by EspClaude
// from server: 92% by EspClaude
// roc 2009-06 0063e8b0  unit: RBX::VHat::?$FactoryProduct  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063e8b0
//
// 0063e8b0  56                   push esi
// 0063e8b1  57                   push edi
// 0063e8b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0063e8b6  8bf1                 mov esi, ecx
// 0063e8b8  eb06                 jmp 0x63e8c0
// 0063e8ba  8d9b00000000         lea ebx, [ebx]
// 0063e8c0  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0063e8c6  3bf8                 cmp edi, eax
// 0063e8c8  7e42                 jle 0x63e90c
// 0063e8ca  83f803               cmp eax, 3
// 0063e8cd  7732                 ja 0x63e901
// 0063e8cf  ff248568e96300       jmp dword ptr [eax*4 + 0x63e968]
// 0063e8d6  8bce                 mov ecx, esi
// 0063e8d8  e8a3ebffff           call 0x63d480
// 0063e8dd  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0063e8e3  8d4801               lea ecx, [eax + 1]
// 0063e8e6  eb59                 jmp 0x63e941
// 0063e8e8  8bce                 mov ecx, esi
// 0063e8ea  e821fdffff           call 0x63e610
// 0063e8ef  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0063e8f5  8d4801               lea ecx, [eax + 1]
// 0063e8f8  eb47                 jmp 0x63e941
// 0063e8fa  8bce                 mov ecx, esi
// 0063e8fc  e82ffcffff           call 0x63e530
// 0063e901  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0063e907  8d4801               lea ecx, [eax + 1]
// 0063e90a  eb35                 jmp 0x63e941
// 0063e90c  7d49                 jge 0x63e957
// 0063e90e  48                   dec eax
// 0063e90f  83f803               cmp eax, 3
// 0063e912  7724                 ja 0x63e938
// 0063e914  ff248578e96300       jmp dword ptr [eax*4 + 0x63e978]
// 0063e91b  8bce                 mov ecx, esi
// 0063e91d  e81efeffff           call 0x63e740
// 0063e922  eb14                 jmp 0x63e938
// 0063e924  8bce                 mov ecx, esi
// 0063e926  e8b5dcffff           call 0x63c5e0
// 0063e92b  eb0b                 jmp 0x63e938
// 0063e92d  8d8ef4000000         lea ecx, [esi + 0xf4]
// 0063e933  e848b2fbff           call 0x5f9b80
// 0063e938  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0063e93e  8d48ff               lea ecx, [eax - 1]
// 0063e941  3bc8                 cmp ecx, eax
// 0063e943  7412                 je 0x63e957
// 0063e945  898ec0000000         mov dword ptr [esi + 0xc0], ecx
// 0063e94b  6848bba400           push 0xa4bb48
// 0063e950  8bce                 mov ecx, esi
// 0063e952  e879d9dcff           call 0x40c2d0
// 0063e957  3bbec0000000         cmp edi, dword ptr [esi + 0xc0]
// 0063e95d  0f855dffffff         jne 0x63e8c0
// 0063e963  5f                   pop edi
// 0063e964  5e                   pop esi
// 0063e965  c20800               ret 8
// 0063e968  fa                   cli 
// 0063e969  e8630001e9           call 0xe964e9d1
// 0063e96e  6300                 arpl word ptr [eax], ax
// 0063e970  e8e86300d6           call 0xd6644d5d
// 0063e975  e863002de9           call 0xe990e9dd
// 0063e97a  6300                 arpl word ptr [eax], ax
// 0063e97c  38e9                 cmp cl, ch
// 0063e97e  6300                 arpl word ptr [eax], ax
// 0063e980  24e9                 and al, 0xe9
// 0063e982  6300                 arpl word ptr [eax], ax
// 0063e984  1be9                 sbb ebp, ecx
// 0063e986  6300                 arpl word ptr [eax], ax
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Descriptor;extern Descriptor stateProperty;
struct Connection{void disconnect();};
struct Accoutrement{char prefix[0xc0];int state;char gap[0x30];Connection connection;void enterWorkspace();void leaveWorkspace();void equip();void enterCharacter();void connectTouch();void unequip();void leaveCharacter();void changed(const Descriptor&);void setState(int v){if(v!=state){state=v;changed(stateProperty);}}void setDesired(int,const void*);};
void Accoutrement::setDesired(int desired,const void*){do{if(state<desired){switch(state){case 3:equip();break;case 2:enterCharacter();break;case 1:enterWorkspace();break;case 0:connectTouch();break;}setState(state+1);}else if(desired<state){switch(state){case 4:unequip();break;case 3:leaveCharacter();break;case 2:leaveWorkspace();break;case 1:connection.disconnect();break;}setState(state-1);}}while(desired!=state);}

void Accoutrement::enterWorkspace(){}
void Accoutrement::leaveWorkspace(){}


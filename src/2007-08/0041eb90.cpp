// from server: 98% by Intel
﻿// from server: 97% by EspClaude
// roc 2007-08 0041eb90  unit: CSettingsExplorer  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041eb90
//
// 0041eb90  6aff                 push -1
// 0041eb92  6898b97300           push 0x73b998
// 0041eb97  64a100000000         mov eax, dword ptr fs:[0]
// 0041eb9d  50                   push eax
// 0041eb9e  83ec24               sub esp, 0x24
// 0041eba1  53                   push ebx
// 0041eba2  55                   push ebp
// 0041eba3  56                   push esi
// 0041eba4  57                   push edi
// 0041eba5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041ebaa  33c4                 xor eax, esp
// 0041ebac  50                   push eax
// 0041ebad  8d442438             lea eax, [esp + 0x38]
// 0041ebb1  64a300000000         mov dword ptr fs:[0], eax
// 0041ebb7  8bf1                 mov esi, ecx
// 0041ebb9  8b8604030000         mov eax, dword ptr [esi + 0x304]
// 0041ebbf  50                   push eax
// 0041ebc0  e87bffffff           call 0x41eb40
// 0041ebc5  33ed                 xor ebp, ebp
// 0041ebc7  83c404               add esp, 4
// 0041ebca  8944241c             mov dword ptr [esp + 0x1c], eax
// 0041ebce  896c242c             mov dword ptr [esp + 0x2c], ebp
// 0041ebd2  896c2430             mov dword ptr [esp + 0x30], ebp
// 0041ebd6  896c2434             mov dword ptr [esp + 0x34], ebp
// 0041ebda  8b06                 mov eax, dword ptr [esi]
// 0041ebdc  8b908c010000         mov edx, dword ptr [eax + 0x18c]
// 0041ebe2  8bce                 mov ecx, esi
// 0041ebe4  896c2440             mov dword ptr [esp + 0x40], ebp
// 0041ebe8  ffd2                 call edx
// 0041ebea  8b98d0000000         mov ebx, dword ptr [eax + 0xd0]
// 0041ebf0  8bcb                 mov ecx, ebx
// 0041ebf2  e8195c2400           call 0x664810
// 0041ebf7  3bc5                 cmp eax, ebp
// 0041ebf9  89442414             mov dword ptr [esp + 0x14], eax
// 0041ebfd  7471                 je 0x41ec70
// 0041ebff  90                   nop 
// 0041ec00  8d442414             lea eax, [esp + 0x14]
// 0041ec04  50                   push eax
// 0041ec05  8bcb                 mov ecx, ebx
// 0041ec07  e8345c2400           call 0x664840
// 0041ec0c  8b10                 mov edx, dword ptr [eax]
// 0041ec0e  8bc8                 mov ecx, eax
// 0041ec10  8b4260               mov eax, dword ptr [edx + 0x60]
// 0041ec13  ffd0                 call eax
// 0041ec15  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0041ec19  3bd5                 cmp edx, ebp
// 0041ec1b  8b7854               mov edi, dword ptr [eax + 0x54]
// 0041ec1e  8b742430             mov esi, dword ptr [esp + 0x30]
// 0041ec22  897c2418             mov dword ptr [esp + 0x18], edi
// 0041ec26  7421                 je 0x41ec49
// 0041ec28  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0041ec2c  8bc6                 mov eax, esi
// 0041ec2e  2bc2                 sub eax, edx
// 0041ec30  2bca                 sub ecx, edx
// 0041ec32  c1f802               sar eax, 2
// 0041ec35  c1f902               sar ecx, 2
// 0041ec38  3bc1                 cmp eax, ecx
// 0041ec3a  730d                 jae 0x41ec49
// 0041ec3c  8bc6                 mov eax, esi
// 0041ec3e  83c004               add eax, 4
// 0041ec41  893e                 mov dword ptr [esi], edi
// 0041ec43  89442430             mov dword ptr [esp + 0x30], eax
// 0041ec47  eb21                 jmp 0x41ec6a
// 0041ec49  3bd6                 cmp edx, esi
// 0041ec4b  7606                 jbe 0x41ec53
// 0041ec4d  ff15d8e67700         call dword ptr [0x77e6d8]
// 0041ec53  8d4c2418             lea ecx, [esp + 0x18]
// 0041ec57  51                   push ecx
// 0041ec58  8d44242c             lea eax, [esp + 0x2c]
// 0041ec5c  56                   push esi
// 0041ec5d  50                   push eax
// 0041ec5e  8d54242c             lea edx, [esp + 0x2c]
// 0041ec62  52                   push edx
// 0041ec63  8bc8                 mov ecx, eax
// 0041ec65  e8b6f90c00           call 0x4ee620
// 0041ec6a  396c2414             cmp dword ptr [esp + 0x14], ebp
// 0041ec6e  7590                 jne 0x41ec00
// 0041ec70  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0041ec74  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0041ec78  3bc3                 cmp eax, ebx
// 0041ec7a  760a                 jbe 0x41ec86
// 0041ec7c  ff15d8e67700         call dword ptr [0x77e6d8]
// 0041ec82  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0041ec86  3b442430             cmp eax, dword ptr [esp + 0x30]
// 0041ec8a  8d742428             lea esi, [esp + 0x28]
// 0041ec8e  8bf8                 mov edi, eax
// 0041ec90  7606                 jbe 0x41ec98
// 0041ec92  ff15d8e67700         call dword ptr [0x77e6d8]
// 0041ec98  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0041ec9c  53                   push ebx
// 0041ec9d  56                   push esi
// 0041ec9e  8d442430             lea eax, [esp + 0x30]
// 0041eca2  57                   push edi
// 0041eca3  50                   push eax
// 0041eca4  e847f0ffff           call 0x41dcf0
// 0041eca9  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0041ecad  3bc5                 cmp eax, ebp
// 0041ecaf  7409                 je 0x41ecba
// 0041ecb1  50                   push eax
// 0041ecb2  e8ab0f2100           call 0x62fc62
// 0041ecb7  83c404               add esp, 4
// 0041ecba  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0041ecbe  64890d00000000       mov dword ptr fs:[0], ecx
// 0041ecc5  59                   pop ecx
// 0041ecc6  5f                   pop edi
// 0041ecc7  5e                   pop esi
// 0041ecc8  5d                   pop ebp
// 0041ecc9  5b                   pop ebx
// 0041ecca  83c430               add esp, 0x30
// 0041eccd  c20800               ret 8

// from server: 100% by king_originala
// roc-cl: 50727
#include <vector>
namespace RBX {class Instance {};struct Selection {
 void clearSelection();void addToSelection(Instance*);
 template<class Iterator>void setSelection(Iterator first,Iterator last){clearSelection();for(;first!=last;first++)addToSelection(*first);}
};}
RBX::Selection* selectionFrom(RBX::Instance*);
struct __POSITION;typedef __POSITION* POSITION;
struct CXTPReportRecord {char prefix[0x54];RBX::Instance* instance;};
struct CXTPReportRow {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
 virtual CXTPReportRecord* GetRecord()const;
};
struct CXTPReportSelectedRows {POSITION GetFirstSelectedRowPosition();CXTPReportRow* GetNextSelectedRow(POSITION&);};
struct CXTPReportControl {char pad[0xd0];CXTPReportSelectedRows* rows;CXTPReportSelectedRows* GetSelectedRows()const{return rows;}};
struct CSettingsExplorer {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual void slot55();
virtual void slot56();
virtual void slot57();
virtual void slot58();
virtual void slot59();
virtual void slot60();
virtual void slot61();
virtual void slot62();
virtual void slot63();
virtual void slot64();
virtual void slot65();
virtual void slot66();
virtual void slot67();
virtual void slot68();
virtual void slot69();
virtual void slot70();
virtual void slot71();
virtual void slot72();
virtual void slot73();
virtual void slot74();
virtual void slot75();
virtual void slot76();
virtual void slot77();
virtual void slot78();
virtual void slot79();
virtual void slot80();
virtual void slot81();
virtual void slot82();
virtual void slot83();
virtual void slot84();
virtual void slot85();
virtual void slot86();
virtual void slot87();
virtual void slot88();
virtual void slot89();
virtual void slot90();
virtual void slot91();
virtual void slot92();
virtual void slot93();
virtual void slot94();
virtual void slot95();
virtual void slot96();
virtual void slot97();
virtual void slot98();
 virtual CXTPReportControl* GetReportControl();
 char prefix[0x300];RBX::Instance* context;
 void OnSelectionChanged(void*,long*);
};
void CSettingsExplorer::OnSelectionChanged(void*,long*){
 RBX::Selection* selection=selectionFrom(context);
 std::vector<RBX::Instance*> instances;
 CXTPReportSelectedRows* rows=GetReportControl()->GetSelectedRows();
 POSITION position=rows->GetFirstSelectedRowPosition();
 while(position){
  CXTPReportRow* row=rows->GetNextSelectedRow(position);
  CXTPReportRecord* record=row->GetRecord();
  RBX::Instance* instance=record->instance;
  instances.push_back(instance);
 }
 const std::vector<RBX::Instance*>& collected=instances;
 selection->setSelection(collected.begin(),collected.end());
}

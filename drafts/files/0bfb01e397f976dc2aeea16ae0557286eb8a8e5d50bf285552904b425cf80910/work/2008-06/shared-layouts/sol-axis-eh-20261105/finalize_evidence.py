from pathlib import Path
import json,hashlib,sys
ROOT=Path.cwd();sys.path.insert(0,str(ROOT))
from roc import match
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
out=ROOT/'work/2008-06/shared-layouts/sol-axis-eh-20261105';p=out/'continuation.json';j=json.loads(p.read_text());b,image=match._image('2008-06');cs=Cs(CS_ARCH_X86,CS_MODE_32)
j['original_disassembly']={hex(a):['%08x %s %s'%(x.address,x.mnemonic,x.op_str) for x in cs.disasm(bytes(image[a-b:a-b+n]),a)] for a,n in [(0x640560,139),(0x7daa10,29),(0x640540,25),(0x640620,115)]}
for imp in j['original_imports_before_coff_binding']:
 imp['descriptor_file_offset']=imp.pop('descriptor_rva')
 import pefile
 pe=pefile.PE(str(ROOT/'clients/2008-06/Roblox.exe'))
 imp['descriptor_rva']=hex(pe.get_rva_from_offset(int(imp['descriptor_file_offset'],16)))
j['abi_evidence']={'string_constructor':'Original 6405a1 pushes ArrowCursor address833850 (NUL terminated), 6405a6 sets ECX=this+24h, 6405ae calls [802458]. MSVCP90 named import QAE@PBD@Z encodes public x86 thiscall constructor(const char*); installed RTM xstring constructor calls _Tidy then assign. Caller consumes no constructor return; no loaded implementation or hidden behavior inferred.','string_destructor':'Original Axis destructor640620 sets ECX=this+24h at64063e then calls [802468] at640650, no explicit stack argument, QAE@XZ names x86 thiscall destructor(). Installed xstring destructor calls _Tidy(true). No return value consumed.','cleanup_states':'FuncInfo8fb954 magic19930522 maxState2 unwindMap8fb944; state0 -> -1/7daa10 NamedArrowBase; state1 -> 0/7daa18 auto_ptr member+20h. No string cleanup entry; do not infer string destructor EH coverage.','mouse_continuation':'Original NamedArrowBase617dd0 jmp615780; Mouse stores canonical vptr anchors8439fc and8439e0 then ECX adjustment+4 tailjmp47d410, actual IRenderable body c3. All recorded COFF operands have zero addends. Mouse vtable/RTTI full closure not re-proven here.'}
j['unknown_nodes'].insert(0,'MegaDragger destructor0060e700 actual provider binding beyond auto_ptr cleanup; operator delete and EH helper6a14c0 transitive ABI')
j['weak_selection']='No E->G ALIAS inference. Existing Axis/Mouse weak search characteristic2 is LIBRARY; final fallback selection unknown until selected PE.'
j['graph_status']='7 relocation-normalized EH nodes exact conditional on explicit Mouse binding; unresolved MegaDragger external stops traversal. Not fullsafe.'
j['metrics']={'compiles':0,'links':0,'diagnostic_executions':0,'source_edits':0,'hypotheses_rejected_this_task':0,'prior_budget_reset':False}
j['required_flags']='Parent-provided IRenderable object requires /U_RELEASEASSERT /U_DEBUG; flags recorded, not source-pinned.'
p.write_text(json.dumps(j,indent=2)+'\n')
print('continuation SHA256',hashlib.sha256(p.read_bytes()).hexdigest());print('preserved original failure',j['preserved_generic_failure_sha256'])

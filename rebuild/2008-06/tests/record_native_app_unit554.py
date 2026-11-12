"""Verify the inactive 2008-06 native rows of the application range 00554000..00558000, and record the unit map of the
range (boundary evidence in the receipt's `unit_map`; rows counted by other receipts are listed there as text).

Unit map summary (details in UNIT_MAP below):
  * 00554000..0055432f: the tail of util/Name.cpp (Name::lookup / getNullName, the declare thunk 00554160; Name owner,
    core header util/Name.h). Not built here.
  * 00554330..0055730f: util/RunStateOwner.cpp (RunService). Its members are recovered by
    tests/record_native_app_unit54c_2008.py (app-unit54c-2008 receipt counts 27 of them); this recorder builds only the
    template instantiations the unit emits: the run-thread bind / function0 plumbing, the task-queue and run-thread
    holder destructors, condition::timed_wait, and the Stepped / Heartbeat event and bound-function descriptor
    templates with their boost.signals / boost.any / boost.function instances.
  * 00557310..: v8tree/Instance.cpp (Instance owner, core header v8tree/Instance.h; app-unit558-2008 receipt counts
    five rows here). Not built here.

Build: native-classes/AppUnit554RunServiceTemplates.cpp with the document-swap flags, VS2008 RTM 21022, /fp:fast (the
RunService unit profile of tests/record_native_app_unit54c_2008.py), plus the committed native-headers profile
boost-function-pod-vtable ahead of native-headers: function0(bind_t) 005564a0 and the function2 constructor 00556e20
store constant manager tables (0082d51c / 0082d620) without a guard. It includes util/RunStateOwner.h read-only and
creates no header (nothing is shadowed). No pending build: no body here needs a missing declaration.

Row identity is proven by a call-graph closure from the root rows (each relocation-masked exact at the address its
evidence names): every REL32 call target of an exact row binds to the symbol the compiled instruction references; that
symbol's compiled body must be exact there, and so on. Each symbol binds to one address; an address may carry several
symbols (identical-code folding), each of whose bodies must be exact there. Every REL32/DIR32 target of every proven
row is verified: imports by DLL export name, strings and constants by bytes, vtables by original RTTI names, type
descriptors by their decorated name, constant boost.function manager tables by their contents (each slot must be the
proven manage / invoke row), own (proven) rows, and the remaining externals by the explicit EXTERNAL map (call-site
evidence in comments). Counted rows are the proven rows inside the range that no other receipt counts.
Writes work/2008-06/shared-layouts/app-unit554-working.json. Never writes a quoted bare address of a row it does not
count (some recorders treat any such string in another receipt as counted there).
Set NATIVE_APP_UNIT554_DISCOVER=1 to list unbound targets instead of asserting.
"""
import glob
import json
import os
import re
import struct
import sys
from collections import deque
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(Path(__file__).resolve().parent))
from roc import match, rebuild  # noqa: E402
import native_bind as nb  # noqa: E402

R = ROOT / 'rebuild/2008-06'
HDR = R / 'native-headers'
OUT = nb.OUT / 'app-unit554'
OUT.mkdir(parents=True, exist_ok=True)
SOURCE = R / 'native-classes/AppUnit554RunServiceTemplates.cpp'
HEADERS = [HDR / 'util/RunStateOwner.h', HDR / 'boost-function-pod-vtable/boost/function/function_template.hpp',
           HDR / 'boost-function-pod-vtable/boost/function/function_base.hpp', HDR / 'reflection/signal.h']
DISCOVER = bool(os.environ.get('NATIVE_APP_UNIT554_DISCOVER'))
RECEIPT = ROOT / 'work/2008-06/shared-layouts/app-unit554-working.json'
RANGE = (0x554000, 0x558000)
PROFILE_DIRS = ['boost-function-pod-vtable']


def build(name, src):
    obj = OUT / (name + '.obj')
    flags = nb.flags()
    i = next(k for k, x in enumerate(flags) if x.replace('\\', '/').endswith('rebuild/2008-06/native-headers'))
    flags = flags[:i] + ['/I' + str(HDR / p) for p in PROFILE_DIRS] + flags[i:] + ['/fp:fast', '/Fo' + str(obj),
                                                                                    str(src)]
    code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, OUT)
    assert code == 0, log[-4000:]
    return obj, flags


OBJ, FLAGS = build('NativeAppUnit554RunServiceTemplates', SOURCE)

original = nb.Original()
names = {int(k, 16): v.get('symbol', '') for k, v in json.loads((R / 'offline/evidence.json').read_text())['names'].items()}
FUNCTIONS = {int(json.loads(l)['addr'], 16): json.loads(l)['size'] for l in
             (ROOT / 'work/2008-06/functions.jsonl').read_text().splitlines() if l.strip()}

RS = 'RunService@RBX@@'
SPR = 'V?$shared_ptr@V' + RS + '@boost@@'
SPD = 'V?$shared_ptr@VDataModel@RBX@@@boost@@'
LIST2 = 'V?$list2@V?$value@' + SPR + '@_bi@boost@@V?$value@' + SPD + '@23@@_bi@'
BIND = 'V?$bind_t@XV?$mf1@XV' + RS + SPD + '@_mfi@boost@@' + LIST2 + '3@@_bi@boost@@'
FN2 = 'V?$function@$$A6AXMM@ZV?$allocator@X@std@@@boost@@'
SDI2 = '?$SignalDescImpl@$01$$A6AXMM@Z@Reflection@RBX@@'
ADAPTER = 'VGenericSlotAdapter@' + SDI2
CALLER = 'U?$caller@MMV?$function@$$A6AXMM@ZV?$allocator@X@std@@@boost@@@?$call_bound2@X@detail@signals@boost@@'
SCI = 'V?$slot_call_iterator@' + CALLER + 'Vnamed_slot_map_iterator@345@@detail@signals@boost@@'
SIGNAL2 = '?$signal2@XMMU?$last_value@X@boost@@HU?$less@H@std@@V?$function@$$A6AXMM@ZV?$allocator@X@std@@@2@@boost@@'
FUNCTION0 = '?$function0@XV?$allocator@Vfunction_base@boost@@@std@@@boost@@'
FUNCTION_V = '?$function@$$A6AXXZV?$allocator@X@std@@@boost@@'
DEQUE = '?$deque@V?$function@$$A6AXXZV?$allocator@X@std@@@boost@@V?$allocator@V?$function@$$A6AXXZV?$allocator@X@std@@' \
        '@boost@@@std@@@std@@'
HOLDER = '?$holder@' + FN2 + '@any@boost@@'

# ---- identity roots: (address, symbol pattern, evidence) ----------------------------------------------------------------
# A pattern is a list of substrings; it must select exactly one compiled symbol (resolved below and written to the
# receipt), whose body must be exact at the address.
ROOTS = [
    (0x555470, ['??$bind@XVRunService@RBX@@V?$shared_ptr@VDataModel'],
     'evidence name; start() 005565ed (bind(&RunService::runProc, shared_from(this), dataModel))'),
    (0x5564a0, ['??$?0V?$bind_t@XV?$mf1@XVRunService', '@' + FUNCTION0 + 'QAE@'],
     'start() 005565f9 on the bind result (manager table 0082d51c stored without a guard)'),
    (0x555b70, ['?manage@?$functor_manager@V?$bind_t@XV?$mf1@XVRunService'],
     'slot 0 of the constant manager table 0082d51c that function0(bind_t) 005564a0 stores'),
    (0x555780, ['?invoke@?$void_function_obj_invoker0@V?$bind_t@XV?$mf1@XVRunService'],
     'evidence name; slot 1 of the manager table 0082d51c'),
    (0x555090, ['??1?$bind_t@XV?$mf1@XVRunService'], 'unwind funclet 007cddb3 of bind 00555470 (bind_t temporary)'),
    (0x554b70, ['??1?$scoped_ptr@Vthread@boost@@@boost@@QAE@XZ'],
     'unwind funclets 007cde93 / 007ce003 of RunService() 00556b00 / ~RunService 00555c00 on runThread +0x27c'),
    (0x555bb0, ['??1' + DEQUE + 'QAE@XZ'],
     'unwind funclets 007cdecb / 007ce03b of RunService() / ~RunService on the task queue +0x2b4 (_Tidy 00419b40)'),
    (0x554f90, ['??4' + FUNCTION_V + 'QAEAAV01@ABV01@@Z'],
     'drainTasks 00555a63 (item = front()); also ContentProvider 0055ebd6 / 0055ec06 / 0055f4db'),
    (0x554c30, ['??$timed_wait@V?$scoped_lock@Vmutex@boost@@@thread@detail@boost@@@condition@boost@@'],
     'RunService helpers 00554e9b (+0x264) / 00554f45 (+0x24c), lock and xtime pushed, ret 8'),
    (0x556830, ['??0?$SignalDesc@VRunService@RBX@@$$A6AXMM@Z@Reflection@RBX@@QAE@PBD00@Z'],
     'static initializer 007f2814 (Stepped event; vtable 0082d5f8 RTTI SignalDesc<RunService, void(float, float)>)'),
    (0x556960, ['??0?$SignalDesc@VRunService@RBX@@$$A6AXM@Z@Reflection@RBX@@QAE@PBD0@Z'],
     'static initializer 007f283f (Heartbeat event; vtable 0082d608 RTTI SignalDesc<RunService, void(float)>)'),
    (0x556a30, ['??0?$BoundFuncDesc@VRunService@RBX@@$$A6AXXZ$0A@@Reflection@RBX@@QAE@'],
     'static initializers 007f2865 / 007f2895 / 007f28c5 (vtable 0082d618 RTTI BoundFuncDesc<RunService, void(), 0>)'),
    (0x556aa0, ['?execute@?$BoundFuncDesc@VRunService@RBX@@$$A6AXXZ$0A@@Reflection@RBX@@'],
     'BoundFuncDesc<RunService, void(), 0> vtable 0082d618 (dynamic_cast + pmf call)'),
    (0x556290, ['?newSignalInstance@?$TSignalDesc@$$A6AXMM@Z@Reflection@RBX@@'],
     'TSignalDesc<void(float, float)> vtable slot (new 0x38, TSignalInstance ctor 00556220 with vtable 0082d518)'),
    (0x557230, ['?connectGeneric@' + SDI2],
     'SignalDesc<RunService, void(float, float)> vtable slot (signal2 connect 005560c0)'),
    (0x556500, ['?invoke@?$void_function_obj_invoker2@' + ADAPTER],
     'evidence name; slot 1 of the function2 manager table 0082d620 (00556e20)'),
    (0x5561e0, ['?manage@?$functor_manager@' + ADAPTER], 'slot 0 of the manager table 0082d620'),
    (0x556eb0, ['??R' + SIGNAL2 + 'QAE?AUunusable@'],
     'evidence name; per-frame Stepped raise 00557216 (fire through the TSignalInstance)'),
    (0x555f70, ['?clone@' + HOLDER], 'any::holder<function<void(float, float)>> vtable 0082d508'),
    (0x555f60, ['?type@' + HOLDER], 'any::holder<function<void(float, float)>> vtable 0082d508'),
]
# ---- externals: the address the original instruction uses (call site in parentheses) --------------------------------
EXTERNAL = {
    # 00554810 is the 96-byte storage1 ctor followed by the 5-byte thunk 00554870: BOUNDS evidence, bound by the call
    # site of storage2's ctor and not counted
    '??0?$storage1@V?$value@' + SPR + '@_bi@boost@@@_bi@boost@@QAE@V?$value@' + SPR + '@12@@Z': 0x554810,  # 00554cee
    # classDescriptor<RunService> 00556430 compiles exact, but its symbol carries the header's 3PADA class-name argument
    # (original RTTI: 3QBDB): bound by the call sites of the descriptor ctors only, not proven or counted here
    '?classDescriptor@?$Described@V' + RS + '$1?sRunService@2@3PADAV?$FactoryProduct@V' + RS + 'VInstance@2@$1?sRunService'
    '@2@3PADA@2@@Reflection@RBX@@SAAAVClassDescriptor@23@XZ': 0x556430,  # 00556852 / 00556982 / 00556a57
    # Callees outside this unit (Reflection / boost.signals / boost.thread / Name library rows, and template COMDATs the
    # linker folded into copies elsewhere; 00417f00 / 0041a620 / 0041ae30 / 0041af90 are try / catch(...) bodies that the
    # analysis splits at their catch funclets, so they are bound by the call site only), the throw-info records and the
    # manager-table
    # slots of the group_bridge_compare function2 inside signal2's ctor (support row 00499c00):
    '?_Buynode@?$list@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@std@@IAEPAU_Node@?$_List_nod@UItem@SignatureDescriptor@Reflection@RBX@@V?$allocator@UItem@SignatureDescriptor@Reflection@RBX@@@std@@@2@PAU342@0ABUItem@SignatureDescriptor@Reflection@RBX@@@Z': 0x417f00,  # 005568af / 00556900 / 005569df
    '??$?0VGenericSlotWrapper@Reflection@RBX@@@shared_count@detail@boost@@QAE@PAVGenericSlotWrapper@Reflection@RBX@@@Z': 0x41a620,  # 00557260
    '?manage@?$functor_manager@V?$group_bridge_compare@U?$less@H@std@@H@detail@signals@boost@@V?$allocator@Vfunction_base@boost@@@std@@@function@detail@boost@@SAXABTfunction_buffer@234@AAT5234@W4functor_manager_operation_type@234@@Z': 0x41a6b0,  # table
    '?invoke@?$function_obj_invoker2@V?$group_bridge_compare@U?$less@H@std@@H@detail@signals@boost@@_NVstored_group@234@V5234@@function@detail@boost@@SA_NAATfunction_buffer@234@Vstored_group@3signals@4@1@Z': 0x41a700,  # table
    '??$?0Udata_t@slot_base@detail@signals@boost@@@shared_count@detail@boost@@QAE@PAUdata_t@slot_base@1signals@2@@Z': 0x41ae30,  # 0041b105
    '?_Construct_n@?$vector@Vany@boost@@V?$allocator@Vany@boost@@@std@@@std@@QAEXIABVany@boost@@@Z': 0x41af90,  # 0041b1c1
    '?declare@Name@RBX@@SAABV12@PBDH@Z': 0x553f90,  # 0055687a / 005568ce / 005569aa
    '??0lock_error@boost@@QAE@XZ': 0x5683f0,  # 00554c4b
    '??1call_notification@detail@signals@boost@@QAE@XZ': 0x56a650,  # 00556fc3
    '??0call_notification@detail@signals@boost@@QAE@ABV?$shared_ptr@Vsignal_base_impl@detail@signals@boost@@@3@@Z': 0x56a760,  # 00556ed4
    '?connect_slot@signal_base_impl@detail@signals@boost@@QAE?AVconnection@34@ABVany@4@ABVstored_group@234@V?$shared_ptr@Udata_t@slot_base@detail@signals@boost@@@4@W4connect_position@34@@Z': 0x56a900,  # 00556164
    '??0signal_base@detail@signals@boost@@QAE@ABV?$function2@_NVstored_group@detail@signals@boost@@V1234@V?$allocator@Vfunction_base@boost@@@std@@@3@ABVany@3@@Z': 0x56b3f0,  # 00499c84
    '??0SignalDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBD@Z': 0x56bab0,  # 00556860 / 00556990
    '??$singleton@M@Type@Reflection@RBX@@SAABV012@XZ': 0x56cca0,  # 00556886 / 005568da / 005569b6
    '?begin@named_slot_map@detail@signals@boost@@QAE?AVnamed_slot_map_iterator@234@XZ': 0x571380,  # 00556f90
    '?end@named_slot_map@detail@signals@boost@@QAE?AVnamed_slot_map_iterator@234@XZ': 0x5713b0,  # 00556f2c / 00556f41 / 00556f79
    '??$singleton@X@Type@Reflection@RBX@@SAABV012@XZ': 0x594a50,  # 00556a81
    '??0Value@Reflection@RBX@@QAE@XZ': 0x594ac0,  # 00556893 / 005568e7 / 005569c3
    '?do_lock@mutex@boost@@AAEXAAPAX@Z': 0x594d20,  # 00554c8b
    '?do_unlock@mutex@boost@@AAEXAAPAX@Z': 0x594d40,  # 00554c71
    '??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z': 0x595790,  # 00556a60
    '?create_connection@slot_base@detail@signals@boost@@IAEXXZ': 0x595840,  # 0055712c
    '??1thread@boost@@QAE@XZ': 0x5a6840,  # 00554b7a
    '?enter_wait@condition_impl@detail@boost@@QAEXXZ': 0x5f1dd0,  # 00554c65
    '?do_timed_wait@condition_impl@detail@boost@@QAE_NABUxtime@3@@Z': 0x5f1ea0,  # 00554c7d
    '__TI3?AVlength_error@std@@': 0x8d0cc0,  # 00682d29
    '__TI3?AVlock_error@boost@@': 0x8d0f1c,  # 00554c50
    '__TI3?AVbad_function_call@boost@@': 0x8d161c,  # 0040a512
    '__TI2?AVbad_cast@std@@': 0x8d362c,  # 00556ad5
}
# function0<void>::operator=(const function0&) 00554470: the analysed row ends before its catch funclet 005544f2; the
# compiled body is exact against the joined rows (BOUNDS evidence below). Called by swap 00554be3 / 00554bef.
JOINED = {'??4?$function0@XV?$allocator@X@std@@@boost@@QAEAAV01@ABV01@@Z': (0x554470, 0x5544f2)}
DATA_EXTERNAL = {k for k in EXTERNAL if k.startswith('__TI')}


def load_bodies():
    raw = Path(OBJ).read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    bodies = {}
    for n, b, r in match.coff_functions(raw):
        start, section = definitions[n]
        table = sections[section]
        rel = []
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * i)
            offset -= start
            if 0 <= offset < len(b):
                rel.append((offset, symbols[index][0], kind))
        bodies.setdefault(n, (b, r, rel))
    return bodies


TARGET = {}


def target_of(address):
    if address not in TARGET:
        body, refs, _ = match.target('2008-06', '%08x' % address)
        TARGET[address] = (body, refs)
    return TARGET[address]


def joined_target(rows):
    body, refs = b'', []
    for a in rows:
        t, r = target_of(a)
        refs += [x + len(body) for x in r] if r and isinstance(r[0], int) else list(r)
        body += t
    return body, refs


class Closure:
    def __init__(self, roots):
        self.bodies = load_bodies()
        self.raw = Path(OBJ).read_bytes()
        self.index = match._coff_data_index(self.raw)
        self.used, self.unbound = set(), []
        self.proven, self.aliases, self.why, self.not_exact = {}, {}, {}, {}
        self.data_checked = {}
        queue = deque()
        for address, pattern, evidence in roots:
            hits = [n for n in self.bodies if not nb.LOCAL_EH.match(n) and all(p in n for p in pattern)]
            assert len(hits) == 1, ('root pattern must select one symbol', pattern, hits)
            queue.append((address, hits[0], 'root: ' + evidence))
        while queue:
            address, symbol, reason = queue.popleft()
            if address in self.proven:
                if symbol not in self.aliases[address]:
                    assert self.exact_at(symbol, address), ('folded alias not exact', '%08x' % address, symbol)
                    self.aliases[address].append(symbol)
                continue
            if not self.exact_at(symbol, address):
                self.not_exact.setdefault(address, (symbol, reason))
                continue
            self.proven[address], self.aliases[address], self.why[address] = symbol, [symbol], reason
            _, _, rel = self.bodies[symbol]
            target, _ = target_of(address)
            for offset, sym, kind in rel:
                if kind == 20:
                    value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
                    if value in FUNCTIONS and sym in self.bodies and not nb.LOCAL_EH.match(sym) \
                            and sym not in EXTERNAL and sym not in JOINED:
                        queue.append((value, sym, 'called by %08x' % address))
        self.own = {}
        for address, syms in self.aliases.items():
            for s in syms:
                prev = self.own.setdefault(s, address)
                assert prev == address, ('one address per symbol', s, hex(prev), hex(address))
        self.joined = {}
        for sym, rows in JOINED.items():
            body, refs, _ = self.bodies[sym]
            target, target_refs = joined_target(rows)
            assert len(target) == len(body) and match.exact_match(target, target_refs, body, refs), ('joined', sym)
            self.joined[sym] = rows[0]
        self.checked = {a: self.verify(a, s) for a, s in sorted(self.proven.items())}

    def exact_at(self, symbol, address):
        if symbol not in self.bodies or address not in FUNCTIONS:
            return False
        body, refs, _ = self.bodies[symbol]
        target, target_refs = target_of(address)
        return match.exact_match(target, target_refs, body, refs)

    def resolve(self, owner, sym, value):
        """Verify one relocation target; returns a description or None (unbound)."""
        sections, symbols, definitions, _ = self.index
        hit = original.imported(value)
        if hit is not None:
            assert hit[1] == nb.plain(sym), (owner, sym, hex(value), hit)
            return '%s!%s' % hit
        if sym.startswith('__real@'):
            assert original.data(value, len(sym[7:]) // 2) == bytes.fromhex(sym[7:])[::-1], (owner, sym)
            return 'constant %s' % sym[7:]
        if sym.startswith('??_C@'):
            pos, at = definitions[sym]
            literal = self.raw[sections[at][4] + pos:sections[at][4] + sections[at][3]].split(b'\0')[0] + b'\0'
            assert original.data(value, len(literal)) == literal, (owner, sym, hex(value))
            return 'string %r' % literal[:-1].decode('latin-1')
        if sym.startswith('??_7'):
            rtti, at = original.vtable_class(value)
            cls = sym[4:sym.index('@@6B') + 2]
            assert rtti == '.?AV' + cls, (owner, sym, hex(value), rtti)
            return 'vtable RTTI %s offset %#x' % (rtti, at)
        if sym.startswith('??_R0'):
            name = '.' + sym[5:-2]
            assert original.string(value + 8) == name, (owner, sym, hex(value), original.string(value + 8))
            return 'type descriptor %s' % name
        if 'stored_vtable' in sym:
            return self.verify_table(owner, sym, value)
        if sym in self.own:
            assert self.own[sym] == value, (owner, sym, hex(value), hex(self.own[sym]))
            return 'own row'
        if sym in self.joined:
            assert self.joined[sym] == value, (owner, sym, hex(value))
            return 'joined rows (bounds evidence)'
        if sym in EXTERNAL:
            assert EXTERNAL[sym] == value, (owner, sym, hex(value), hex(EXTERNAL[sym]))
            self.used.add(sym)
            return 'external' + (' (evidence name)' if names.get(value, '') == sym else '')
        return None

    def verify_table(self, owner, sym, value):
        """A constant boost.function manager table: bytes equal and every slot one of the proven rows."""
        if sym in self.data_checked:
            assert self.data_checked[sym][0] == value, (owner, sym, hex(value))
            return self.data_checked[sym][1]
        sections, symbols, definitions, _ = self.index
        pos, at = definitions[sym]
        table = sections[at]
        size = table[3] - pos
        mine = self.raw[table[4] + pos:table[4] + table[3]]
        theirs = original.data(value, size)
        slots = []
        masked = set()
        for i in range(table[7]):
            offset, index, kind = struct.unpack_from('<IIH', self.raw, table[5] + 10 * i)
            offset -= pos
            if not 0 <= offset < size:
                continue
            assert kind == 6, (sym, kind)
            target = struct.unpack_from('<I', theirs, offset)[0]
            slot = symbols[index][0]
            how = self.resolve(sym, slot, target)
            if how is None:
                self.unbound.append("    %r: %#x,   # %s in table %s" % (slot, target, names.get(target, '')[:50],
                                                                      sym[:50]))
                how = 'UNBOUND'
            slots.append('%s -> %#x (%s)' % (slot[:60], target, how))
            masked.update(range(offset, offset + 4))
        assert all(mine[k] == theirs[k] for k in range(size) if k not in masked), (owner, sym)
        how = 'manager table (%s)' % '; '.join(slots)
        self.data_checked[sym] = (value, how)
        return how

    def verify(self, address, symbol):
        body, refs, rel = self.bodies[symbol]
        target, _ = target_of(address)
        sections, symbols, definitions, _ = self.index
        verified, local = {}, set()
        for offset, sym, kind in rel:
            if kind == 20:
                value = (address + offset + 4 + struct.unpack_from('<i', target, offset)[0]) & 0xffffffff
            else:
                start, section = definitions[symbol]
                code = self.raw[sections[section][4] + start:]
                value = (struct.unpack_from('<I', target, offset)[0] - struct.unpack_from('<i', code, offset)[0]) \
                    & 0xffffffff
            if nb.LOCAL_EH.match(sym):
                local.add(sym)
                continue
            how = self.resolve(symbol, sym, value)
            if how is None:
                self.unbound.append("    %r: %#x,   # %s in %s at %08x" % (sym, value, names.get(value, '')[:50],
                                                                          symbol[:50], address + offset))
                continue
            verified[sym] = '%s (%s)' % (hex(value), how)
        return {'size': len(body), 'target_size': len(target), 'verified_targets': verified, 'local_eh': sorted(local)}

    def check(self):
        if DISCOVER:
            print('\n'.join(sorted(set(self.unbound))))
            for a, (s, r) in sorted(self.not_exact.items()):
                print('NOT EXACT %08x %s (%s)' % (a, s[:120], r))
            for a in sorted(self.proven):
                print('PROVEN %08x %s %s' % (a, self.proven[a][:110], self.why[a][:40]))
            print('PROVEN', len(self.proven), 'in range', sum(1 for a in self.proven if RANGE[0] <= a < RANGE[1]))
            print('UNUSED EXTERNAL', sorted(set(EXTERNAL) - self.used))
            return
        assert not self.unbound, '\n'.join(self.unbound)
        assert sorted(self.used) == sorted(EXTERNAL), sorted(set(EXTERNAL) - self.used)
        assert not self.not_exact, {('%08x' % a): v for a, v in self.not_exact.items()}
        for symbol, address in EXTERNAL.items():
            assert address in FUNCTIONS or original.imported(address) is not None or symbol in DATA_EXTERNAL, \
                (symbol, hex(address))


MAIN = Closure(ROOTS)
MAIN.check()
if DISCOVER:
    sys.exit(0)


def counted_elsewhere():
    out = {}
    for path in glob.glob(str(ROOT / 'work/2008-06/shared-layouts/*.json')):
        if Path(path).name == RECEIPT.name:
            continue
        try:
            data = json.loads(Path(path).read_text())
        except Exception:
            continue
        if not isinstance(data, dict):
            continue
        rows = []
        if 'exact_function_rows' in data:
            rows = data['exact_function_rows']
        elif isinstance(data.get('exact_addresses'), list):
            rows = data['exact_addresses']
        elif isinstance(data.get('exact_unique_addresses'), list):
            rows = data['exact_unique_addresses']
        else:
            def walk(o):
                if isinstance(o, list):
                    for e in o:
                        walk(e)
                elif isinstance(o, dict):
                    if 'address' in o and o.get('exact') is True:
                        rows.append(o['address'])
                    else:
                        for v in o.values():
                            walk(v)
            walk(data.get('methods', []))
        if isinstance(rows, dict):
            rows = list(rows)
        for r in rows:
            r = r.get('address', '') if isinstance(r, dict) else str(r)
            m = re.match(r'(?:0x)?([0-9a-fA-F]{6,8})', r)
            if m:
                out.setdefault(int(m.group(1), 16), []).append(Path(path).name)
    return out


elsewhere = counted_elsewhere()
range_functions = sorted(a for a in FUNCTIONS if RANGE[0] <= a < RANGE[1])
range_counted = {a: sorted(set(v)) for a, v in sorted(elsewhere.items()) if RANGE[0] <= a < RANGE[1]}
counted = sorted(a for a in MAIN.proven if RANGE[0] <= a < RANGE[1] and a not in elsewhere)
assert not set(counted) & set(elsewhere)
support = sorted(a for a in MAIN.proven if a not in counted)

# ---- BOUNDS evidence (not counted): compiled bodies exact against joined / truncated rows -------------------------------
BOUNDS = []
for sym, rows in JOINED.items():
    BOUNDS.append({'rows': ' + '.join('%08x' % a for a in rows) + ' (joined; not counted)', 'symbol': sym,
                   'compiled_size': len(MAIN.bodies[sym][0]), 'joined_size': sum(FUNCTIONS[a] for a in rows),
                   'exact_when_joined': True,
                   'reason': 'one function: the assignment body and its catch(...) funclet (clear, rethrow); the '
                             'analysed rows split it (extent fix needed)'})
_storage1 = '??0?$storage1@V?$value@' + SPR + '@_bi@boost@@@_bi@boost@@QAE@V?$value@' + SPR + '@12@@Z'
_body, _refs, _ = MAIN.bodies[_storage1]
_target, _target_refs = target_of(0x554810)
assert len(_target) == len(_body) + 5 and _target[len(_body):len(_body) + 1] == b'\xe9'
assert match.exact_match(_target[:len(_body)], [x for x in _target_refs if x < len(_body)], _body, _refs)
_thunk = (0x554810 + len(_body) + 5 + struct.unpack_from('<i', _target, len(_body) + 1)[0]) & 0xffffffff
assert _thunk == 0x554350
BOUNDS.append({'rows': '00554810 (first %d bytes; not counted)' % len(_body), 'symbol': _storage1,
               'compiled_size': len(_body), 'row_size': len(_target), 'exact_prefix': True,
               'reason': 'the row also covers the 5-byte thunk 00554870 (jmp 00554350, the FactoryProduct<RunService> '
                         'destructor of the adjacent ??_E thunks): the storage1 ctor ends at 0055486f'})


def row(a, note):
    return dict({'address': '%08x (%s)' % (a, note), 'symbol': MAIN.proven[a], 'folded_symbols': MAIN.aliases[a][1:],
                 'identity': MAIN.why[a]}, **MAIN.checked[a])


rows_out = [dict({'address': '%08x' % a, 'symbol': MAIN.proven[a], 'folded_symbols': MAIN.aliases[a][1:],
                  'identity': MAIN.why[a], 'exact': True}, **MAIN.checked[a]) for a in counted]
support_out = [row(a, ('counted by ' + ', '.join(sorted(set(elsewhere[a])))) if a in elsewhere else
                   'outside the range %08x..%08x' % RANGE) for a in support]

NOT_BUILT = [
    ('00554000..00554320', 'util/Name.cpp tail: the declare thunk 00554160, Name::lookup(string) 00554180, getNullName '
     '00554270, lookup(const char*) 00554290 (evidence names) and the 5-byte jump 00554320 (ICF-shared one-jump '
     'body, 9 callers in unwind funclets): Name owner (util/Name.h core header), not built'),
    ('00554330 / 00554460', 'RunService header inlines called from DataModel (stopRequested = true + notify_all on '
     '+0x264; runThread->join() on +0x27c): the native header declares only endRunThread(bool), not emitted out of '
     'line (RunService owner proposal in the app-unit54c-2008 receipt)'),
    ('00554350 / 005543b0 / 00554410..00554430 / 005567c0..00556810 / 00556720 / 00556430 / 00555020',
     'FactoryProduct<RunService> dtor / ctor / ??_G / ??_E thunks, DescribedCreatable ctor, classDescriptor and '
     'getClassName: their symbols or the vtables they store carry the class-name argument $1?sRunService@2@3QBDB, the '
     'committed header declares `extern char sRunService[]` (3PADA). classDescriptor 00556430 compiles exact here but '
     'under the 3PADA symbol, so it is not bound or counted (app-unit54c-2008 proposal: `extern const char '
     'sRunService[];`)'),
    ('00554470 + 005544f2', 'function0<void>::operator=(const function0&): exact only joined with its catch funclet '
     '(BOUNDS evidence)'),
    ('00554510..005547a1', 'the four Notifier<RunService, E>::raise(E, Listener*) bodies with their catch funclets '
     '(app-unit54c-2008 BOUNDS evidence)'),
    ('00554810', 'storage1<value<shared_ptr<RunService>>> ctor: exact for its 96 bytes, the row includes the next '
     'thunk (BOUNDS evidence)'),
    ('00554880 / 00554e10 / 00554ed0 / 005550a0 / 00555190',
     'RunService private helpers of runProc (per-frame step with DataModel::Lock and the 1/frame float, wait for state '
     'change with condition::timed_wait on +0x264, wait for run views on +0x24c, AdjustThrottle over the views map) '
     'and runProc itself: not declared in util/RunStateOwner.h (proposal)'),
    ('005559a0 + 00555afb', 'drainTasks with its catch funclet (app-unit54c-2008 BOUNDS evidence)'),
    ('00556520', 'RunService::start(): needs the run-thread wrapper 00597110 (function0<void> from the bind and the '
     'thread name "rbx_runProc", priority -1; donor name background_function), not declared in any native header'),
    ('00557150 / 005571b0', 'per-frame Heartbeat / Stepped raises with one float (ret 4): the header declares '
     'raiseHeartbeat / raiseStepped(float, float) (app-unit54c-2008 proposal)'),
    ('00557310 / 00557330 + 00557455', 'std::hex-style ios_base manipulator and boost::call_once (boost.thread '
     'once.cpp shape, CreateMutexA "__boost_once_" name): library code, not recovered'),
    ('00557470..00557fe0', 'v8tree/Instance.cpp (Instance owner): getFullName 005574d0, BoundFuncDesc<Instance, '
     'shared_ptr<Instance>(string, bool), 2>::declareSignature 005575d0, isAncestorOf2 00557640, isDescendentOf2 '
     '00557890, readProperties 00557920 (app-unit558-2008 pending), the Object / AbstractFactoryProduct deleting dtors '
     '00557470 / 005579e0 (vtable 0082d6b0), the Notifier<Instance, E>::raise(E, Listener*) bodies with catch funclets, '
     'the 0x10 / 0x18 sp_counted allocators 00557f50..00557fe0: Instance.h does not declare getFullName / '
     'isAncestorOf2 / isDescendentOf2 (proposal); not built here'),
]
proven_in_range = {a for a in MAIN.proven if RANGE[0] <= a < RANGE[1]}
unbuilt = ['%08x' % a + ' not built' for a in range_functions if a not in proven_in_range and a not in range_counted]

UNIT_MAP = {
    'name 00554000..0055432f': (
        'util/Name.cpp (starts at 00553910 in the app-unit54c-2008 map): declare thunk 00554160, lookup(string) '
        '00554180, getNullName 00554270, lookup(const char*) 00554290, one-jump body 00554320. Name owner.'),
    'run-service 00554330..0055730f': (
        'util/RunStateOwner.cpp. Boundary evidence: RTTI .?AVRunService@RBX@@ vtables 0082d404..0082d4c4 stored by '
        'RunService() 00556b00 / ~RunService 00555c00 (create<RunService> 00405fbf: new 0x2d8), the RunService ??_E '
        'thunks 00555e40..00555ef0, the "rbx_runProc" thread name (0082d524, start 00556520), "Run Service" '
        '(ctor), and the event / function descriptors of the unit: SignalDesc<RunService, void(float, float)> vtable '
        '0082d5f8 (ctor 00556830, static initializer 007f2814), SignalDesc<RunService, void(float)> vtable 0082d608 '
        '(00556960, 007f283f), BoundFuncDesc<RunService, void(), 0> vtable 0082d618 (00556a30, 007f2865 / 007f2895 / '
        '007f28c5). Members counted by app-unit54c-2008; the COMDAT template instances of the unit are built here.'),
    'instance 00557310..': (
        'v8tree/Instance.cpp (continues past 00558000 in the app-unit558-2008 map): std manipulator 00557310 and '
        'boost::call_once 00557330 (library), Object ??_G 00557470 (vtable 0082d6b0), onChildChanged / contains '
        '(app-unit558-2008), getFullName 005574d0 ("." separator 0081ca8c, name +0x110), the Instance descriptors and '
        'Notifier<Instance, E> raises, findFirstChildByName, addAttribute<const Name*>.'),
    'excluded / library code': (
        'no CRobloxApp / CMainFrame / CRobloxDoc / CRobloxView row. boost::call_once 00557330 (+ catch funclet '
        '00557455) and the ios manipulator 00557310 are library code. The boost.bind / boost.function / boost.signals '
        '/ boost.any / std::deque bodies built here are Roblox-instantiated templates (element or functor types '
        'RunService / DataModel / SignalDescImpl<2, void(float, float)>), not separately linked library objects; '
        'scoped_ptr<thread>, function<void()> and condition::timed_wait<scoped_lock> are generic instances whose '
        'COMDAT the linker took from this unit (their rows lie in it).'),
    'counted here': 'the template instances listed in exact_function_rows (rows below).',
}
REJECTED = {
    'without the boost-function-pod-vtable profile (donor boost 1.34.1 function_template.hpp)':
        'function0(bind_t) compiles to 172 B with a separate assign_to / guarded static vtable init vs the 85 B '
        'original 005564a0, which stores the constant table 0082d51c',
    'explicit `template class SignalDesc<RunService, void(float)>`':
        'does not compile (the three-name ctor needs arg2_type): only the used two-name ctor is instantiated',
}
PROPOSALS = {
    'util/RunStateOwner.h (RunService owner)': (
        'Declare the runProc helpers so the remaining RunService rows can be built: a per-frame step taking '
        'shared_ptr<DataModel> by value (00554880, thiscall ret 8: DataModel::Lock 00411b40 / ~Lock 005773c0, fires a '
        'one-float signal 00578e50 with framePeriod +0x1c0, stores the elapsed time in +0x1c8), a timed wait for a '
        'state change taking a double (00554e10, ret 8: timed_wait on stateChangedCondition +0x264 under runMutex '
        '+0x240), a wait for the run views returning bool (00554ed0: timed_wait on runViewsDoneCondition +0x24c while '
        'invalidRunViewCount +0x2a8 != 0, stores the wait time in +0x1d0), and an AdjustThrottle(double) loop over the '
        'views map (005550a0, ret 8, under viewMutex +0x280). Names are descriptive; ABIs from the call sites in '
        'runProc 00555190. Also a declaration of the run-thread wrapper 00597110 (function0<void>, const char* name, '
        'int priority; callers 00556623 / 0057bd22 / 0057bf7f / 005972ce / 005ae9eb) for start() 00556520. The '
        'earlier app-unit54c-2008 proposals (const sRunService, one-float raises) still apply.'),
    'v8tree/Instance.h (core owner)': (
        'Declare `std::string getFullName() const;` (005574d0: recursive, parent +0x104, "." 0081ca8c, name '
        '+0x110, hidden return) and the shared_ptr overloads `bool isAncestorOf2(boost::shared_ptr<Instance>);` '
        '00557640 / `bool isDescendentOf2(boost::shared_ptr<Instance>);` 00557890 (evidence manglings QAE_NV?$shared_'
        'ptr...). Not built here; the Instance.cpp rows belong to the app-unit558-2008 map.'),
    'BOUNDS (server host; no bounds.json change)': (
        '00554470 + 005544f2 are one function (function0<void>::operator= with its catch funclet), and 00554810 ends at '
        '0055486f (the next 5 bytes 00554870 are a separate jmp 00554350 thunk). See bounds_evidence.'),
}

receipt = {
    'class': 'RunService unit template instances of the application range 00554000..00558000 (2008-06), inactive',
    'compiler': 'MSVC 15.00.21022 (VS2008 RTM), document-swap flags, /fp:fast, boost-function-pod-vtable profile',
    'flags': FLAGS,
    'sources': {str(p.relative_to(ROOT)).replace('\\', '/'): nb.sha(p) for p in
                [Path(__file__).resolve(), SOURCE] + HEADERS},
    'objects': {'main': nb.sha(OBJ)},
    'unit_map': UNIT_MAP,
    'range_functions': len(range_functions),
    # Written as 'ADDR counted by RECEIPT' text, never as a quoted bare address: some recorders (local_backpack,
    # viewnew_brick_build, viewnew_part_mesh) treat any '"ADDR"' in another receipt as counted there and drop it.
    'range_rows_counted_by_other_receipts': ['%08x counted by %s' % (a, ', '.join(v)) for a, v in range_counted.items()],
    'range_rows_not_built': unbuilt,
    'not_built_reasons': ['%s: %s' % x for x in NOT_BUILT],
    'rows': rows_out,
    'support_rows_not_counted': support_out,
    'bounds_evidence': BOUNDS,
    'pending_build_only': [],
    'exact_function_rows': ['%08x' % a for a in counted],
    'rejected': REJECTED,
    'proposals': PROPOSALS,
    'scope': 'Inactive. Exact bodies with verified call/data targets; no active build, swap or credit. No new header.',
}
text = json.dumps(receipt, indent=2) + '\n'
quoted = set(re.findall(r'"([0-9a-f]{8})"', text))
assert quoted <= {'%08x' % a for a in counted}, sorted(quoted - {'%08x' % a for a in counted})[:10]
RECEIPT.write_text(text)
print('PASS app-unit554: %d counted exact rows; %d support rows; %d range rows, %d counted elsewhere, %d not built'
      % (len(counted), len(support_out), len(range_functions), len(range_counted), len(unbuilt)))
print(' '.join('%08x' % a for a in counted))

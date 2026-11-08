"""Compile original-style history startup against isolated 2008 signal declarations."""
import hashlib
import json
import struct
import sys
from pathlib import Path
import pefile

root = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(root))
from roc import match, rebuild

out = root / 'rebuild/2008-06/out/history-start-trial'
for name in ('reflection', 'v8tree', 'v8datamodel', 'util'):
    (out / name).mkdir(parents=True, exist_ok=True)
signal_path = root / 'tools/rbxgs/Client/App/include/reflection/signal.h'
signal = signal_path.read_text()
needle = 'boost::signals::connection connect(SignalSource* source, const boost::slot<boost::function<CallbackSignature>>& slot)'
assert signal.count(needle) == 1
signal = signal.replace(needle, '''boost::signals::connection connect(SignalSource* source, const boost::slot<boost::function<CallbackSignature> >& slot, int group) {
                if (source) return sig(*source).connect(group, slot);
                return boost::signals::connection();
            }
            ''' + needle)
(out / 'reflection/signal.h').write_text(signal)
instance_path = root / 'rebuild/2008-06/native-headers/v8tree/Instance.h'
instance = instance_path.read_text()
needle = '    static const Reflection::RefPropDescriptor<Instance, Instance> propParent;'
assert instance.count(needle) == 1
instance = instance.replace(needle, needle + '''
    static Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>, const Reflection::PropertyDescriptor*)> event_itemChanged;
    template<class Function> void visitDescendents(Function func) const {
        if (children) {
            boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > snapshot = children.read();
            std::vector<boost::shared_ptr<Instance> >::const_iterator end = snapshot->end();
            std::vector<boost::shared_ptr<Instance> >::const_iterator it = snapshot->begin();
            for (; it != end; ++it) {
                func(*it);
                (*it)->visitDescendents(func);
            }
        }
    }''')
(out / 'v8tree/Instance.h').write_text(instance)
utilities_path = root / 'tools/rbxgs/Client/App/include/util/Utilities.h'
utilities = utilities_path.read_text()
needle = 'boost::shared_ptr<const T> read() const'
assert utilities.count(needle) == 1
(out / 'util/Utilities.h').write_text(utilities.replace(needle, '__declspec(noinline) ' + needle))
history_path = root / 'rebuild/2008-06/native-headers/v8datamodel/ChangeHistoryService.h'
history = history_path.read_text()
needle = '    void start();'
assert history.count(needle) == 1
history = history.replace(needle, needle + '\n    void commit(const char*);\n    void mergeFirst();\n    void prepare();')
(out / 'v8datamodel/ChangeHistoryService.h').write_text(history)
record_path = root / 'rebuild/2008-06/native-headers/v8datamodel/HistoryRecord.h'
record = record_path.read_text()
needle = '    HistoryItem* get(boost::shared_ptr<Instance>);'
assert record.count(needle) == 1
record = record.replace(needle, needle + '\n    bool empty();\n    void merge(HistoryRecord*);')
needle = '    void capture(const Reflection::Property&);'
assert record.count(needle) == 1
record = record.replace(needle, needle + '\n    void mergeProperty(const std::pair<const Reflection::PropertyDescriptor* const, Reflection::Value>&);')
needle = '    HistoryItem(ChangeHistoryService*, boost::shared_ptr<Instance>);'
assert record.count(needle) == 1
record = record.replace(needle, needle + '\n    HistoryItem();')
(out / 'v8datamodel/HistoryRecord.h').write_text(record)
source = root / 'rebuild/2008-06/experiments/trials/NativeChangeHistoryStartTrial.cpp'
obj = out / 'NativeChangeHistoryStartTrial.obj'
base = json.loads((root / 'work/2008-06/shared-layouts/change-history-layout-working.json').read_text())
flags = [x for x in base['flags']['enable'] if not x.startswith('/Fo') and not x.endswith('ChangeHistoryEnable.cpp')]
flags.insert(0, '/I' + str(out))
flags += ['/Fo' + str(obj), str(source)]
code, log = rebuild.run(rebuild.toolchain(21022), 'cl', flags, out)
assert code == 0, log
raw = obj.read_bytes()
name, body, refs = next(x for x in match.coff_functions(raw) if x[0].startswith('?start@ChangeHistoryService@'))
target, targetrefs, _ = match.target('2008-06', '0058c620')
sections, symbols, definitions, _ = match._coff_data_index(raw)
start, index = definitions[name]
section = sections[index]
edges = {}
data = {}
thunks = []
strings = []
for i in range(section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + 10*i)
    offset -= start
    if 0 <= offset < len(body)-4:
        label = symbols[symbol][0]
        if kind == 20:
            edges[label] = hex(0x58c620 + offset + 4 + struct.unpack_from('<i', target, offset)[0])
        elif kind == 6 and label.startswith('?event_'):
            data[label] = hex(struct.unpack_from('<I', target, offset)[0])
        elif kind == 6 and label.startswith('??_9ChangeHistoryService@'):
            thunks.append(hex(struct.unpack_from('<I', target, offset)[0]))
        elif kind == 6 and label.startswith('??_C@'):
            strings.append(hex(struct.unpack_from('<I', target, offset)[0]))
exact = match.exact_match(target, targetrefs, body, refs)
assert exact, (len(body), len(target))
for prefix, destination in [('??0HistoryRecord@', '0x58bf20'), ('??$visitDescendents@', '0x4a27e0'),
                            ('?commit@ChangeHistoryService@', '0x58c2c0'), ('?mergeFirst@ChangeHistoryService@', '0x58bf80'),
                            ('?connect@?$TSignalDesc@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@Z', '0x4a3340'),
                            ('?connect@?$TSignalDesc@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@PBVPropertyDescriptor', '0x588fb0')]:
    assert any(k.startswith(prefix) and v == destination for k, v in edges.items()), (prefix, edges)
assert set(data.values()) == {'0x973e40', '0x973ca0', '0x9751b0'}
assert thunks == ['0x587240', '0x587240', '0x587280', '0x587290']
assert strings == ['0x831948']
visit_name, visit_body, visit_refs = next(x for x in match.coff_functions(raw) if x[0].startswith('??$visitDescendents@'))
visit_target, visit_targetrefs, _ = match.target('2008-06', '004a27e0')
assert match.exact_match(visit_target, visit_targetrefs, visit_body, visit_refs), (len(visit_body), len(visit_target))
visit_start, visit_index = definitions[visit_name]
visit_section = sections[visit_index]
visit_edges = {}
for i in range(visit_section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, visit_section[5] + 10*i)
    offset -= visit_start
    if 0 <= offset < len(visit_body)-4 and kind == 20:
        visit_edges[symbols[symbol][0]] = hex(0x4a27e0 + offset + 4 + struct.unpack_from('<i', visit_target, offset)[0])
for prefix, destination in [('?read@?$CopyOnWrite@', '0x4915b0'), ('??R?$mf1@', '0x587420'), ('??$visitDescendents@', '0x4a27e0')]:
    assert any(k.startswith(prefix) and v == destination for k, v in visit_edges.items()), (prefix, visit_edges)
helpers = []
for address, prefix in [('004915b0', '?read@?$CopyOnWrite@'), ('00587420', '??R?$mf1@XVChangeHistoryService@')]:
    helper_name, helper_body, helper_refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    helper_target, helper_targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(helper_target, helper_targetrefs, helper_body, helper_refs), (address, len(helper_body), len(helper_target))
    helpers.append({'address': address, 'symbol': helper_name, 'size': len(helper_body)})
for address, prefix, required in [
    ('00587a20', '?empty@HistoryRecord@RBX@@', [('?_Inc@const_iterator@', '0x6510f0')]),
    ('0058c2c0', '?commit@ChangeHistoryService@RBX@@', [('?prepare@ChangeHistoryService@', '0x58c0f0'), ('?empty@HistoryRecord@', '0x587a20'), ('?push_back@?$list@', '0x587ca0'), ('??0HistoryRecord@', '0x58bf20')]),
    ('0058bf80', '?mergeFirst@ChangeHistoryService@RBX@@', [('?merge@HistoryRecord@', '0x58bcb0'), ('??1HistoryRecord@', '0x58bed0'), ('?erase@?$list@', '0x5888f0')]),
    ('0058c0f0', '?prepare@ChangeHistoryService@RBX@@', [('?erase@?$list@', '0x588970'), ('?mergeFirst@ChangeHistoryService@', '0x58bf80')]),
    ('0058bcb0', '?merge@HistoryRecord@RBX@@', [('?find@?$_Tree@', '0x587ce0'), ('?erase@?$_Tree@', '0x58a3f0'), ('??$for_each@', '0x588240'), ('??A?$map@', '0x58bba0'), ('??4HistoryItem@', '0x5899b0')]),
    ('00589950', '??0HistoryItem@RBX@@QAE@XZ', [('??0?$_Tree@', '0x589190')]),
    ('005899b0', '??4HistoryItem@RBX@@', [('??4shared_count@', '0x4025b0'), ('?erase@?$_Tree@', '0x588c10'), ('?_Copy@?$_Tree@', '0x588cf0')]),
    ('005894e0', '?mergeProperty@HistoryItem@RBX@@', [('??A?$map@', '0x589000')]),
    ('0058bba0', '??A?$map@PAVInstance@RBX@@UHistoryItem', [('??0HistoryItem@RBX@@QAE@XZ', '0x589950'), ('??0HistoryItem@RBX@@QAE@ABU', '0x589cd0'), ('?insert@?$_Tree@', '0x58b370'), ('??1HistoryItem@RBX@@', '0x589720')]),
]:
    method_name, method_body, method_refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    method_target, method_targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(method_target, method_targetrefs, method_body, method_refs), (address, len(method_body), len(method_target))
    method_start, method_index = definitions[method_name]
    method_section = sections[method_index]
    method_edges = {}
    member_targets = []
    for i in range(method_section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, method_section[5] + 10*i)
        offset -= method_start
        if 0 <= offset < len(method_body)-4 and kind == 20:
            method_edges[symbols[symbol][0]] = hex(int(address, 16) + offset + 4 + struct.unpack_from('<i', method_target, offset)[0])
        if address == '0058bcb0' and 0 <= offset < len(method_body)-4 and kind == 6 and symbols[symbol][0].startswith('?mergeProperty@HistoryItem@'):
            member_targets.append(hex(struct.unpack_from('<I', method_target, offset)[0]))
    if address == '0058bcb0':
        assert member_targets == ['0x5894e0']
    for expected, destination in required:
        assert any(k.startswith(expected) and v == destination for k, v in method_edges.items()), (address, expected, method_edges)
    helpers.append({'address': address, 'symbol': method_name, 'size': len(method_body), 'direct_calls': method_edges})
for address, prefix, required, expected_data in [
    ('00578790', '??0?$SignalDesc@VInstance@RBX@@', [('?classDescriptor@', '0x40ad80'), ('??0SignalDescriptor@', '0x56bab0'), ('?declare@Name@', '0x553f90')], []),
    ('007f3440', '??__E?event_itemChanged@Instance@RBX@@', [('??0?$SignalDesc@VInstance@RBX@@', '0x578790'), ('_atexit', '0x6a17af')], ['0x9751b0']),
    ('007fd660', '??__F?event_itemChanged@Instance@RBX@@', [('??1?$list@', '0x4199e0')], ['0x9751c8', '0x9751b0']),
]:
    method_name, method_body, method_refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix))
    method_target, method_targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(method_target, method_targetrefs, method_body, method_refs), (address, len(method_body), len(method_target))
    method_start, method_index = definitions[method_name]
    method_section = sections[method_index]
    method_edges = {}
    global_refs = []
    for i in range(method_section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, method_section[5] + 10*i)
        offset -= method_start
        if 0 <= offset < len(method_body)-4 and kind == 20:
            method_edges[symbols[symbol][0]] = hex(int(address, 16) + offset + 4 + struct.unpack_from('<i', method_target, offset)[0])
        if 0 <= offset < len(method_body)-4 and kind == 6 and symbols[symbol][0].startswith('?event_itemChanged@Instance@'):
            global_refs.append(hex(struct.unpack_from('<I', method_target, offset)[0]))
    for expected, destination in required:
        assert any(k.startswith(expected) and v == destination for k, v in method_edges.items()), (address, expected, method_edges)
    assert global_refs == expected_data, (address, global_refs)
    helpers.append({'address': address, 'symbol': method_name, 'size': len(method_body), 'direct_calls': method_edges, 'global_refs': global_refs})
event_vtable = next(n for n in definitions if n.startswith('??_7?$SignalDesc@VInstance@RBX@@') and 'PBVPropertyDescriptor' in n)
event_start, event_index = definitions[event_vtable]
event_section = sections[event_index]
event_slots = {}
for i in range(event_section[7]):
    offset, symbol, kind = struct.unpack_from('<IIH', raw, event_section[5] + 10*i)
    if offset >= event_start and kind == 6:
        event_slots[(offset-event_start)//4] = symbols[symbol][0]
assert event_slots[1].startswith('?connectGeneric@?$SignalDescImpl@$01')
assert event_slots[2].startswith('?newSignalInstance@?$TSignalDesc@')
pe = pefile.PE(str(root / 'work/2008-06/original-p4-reference/Roblox.exe'))
image_base = pe.OPTIONAL_HEADER.ImageBase
assert struct.unpack('<III', pe.get_data(0x83004c-image_base, 12)) == (0x41bdf0, 0x57b680, 0x577f30)
for address, prefix, required in [
    ('0057b680', '?connectGeneric@?$SignalDescImpl@$01', [('??$?0VGenericSlotWrapper@', '0x41a620'), ('?connect@?$signal2@', '0x577d60')]),
    ('00577d60', '?connect@?$signal2@', [('?get_data@slot_base@', '0x4915b0'), ('?connect_slot@signal_base_impl@', '0x56a900')]),
    ('0057acb0', '??$?0VGenericSlotAdapter@?$SignalDescImpl@$01', [('??0data_t@slot_base@', '0x41ad40'), ('?create_connection@slot_base@', '0x595840')]),
]:
    method_target, method_targetrefs, _ = match.target('2008-06', address)
    method_name, method_body, method_refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix) and match.exact_match(method_target, method_targetrefs, x[1], x[2]))
    method_start, method_index = definitions[method_name]
    method_section = sections[method_index]
    method_edges = {}
    for i in range(method_section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, method_section[5] + 10*i)
        offset -= method_start
        if 0 <= offset < len(method_body)-4 and kind == 20:
            method_edges[symbols[symbol][0]] = hex(int(address, 16) + offset + 4 + struct.unpack_from('<i', method_target, offset)[0])
    for expected, destination in required:
        assert any(k.startswith(expected) and v == destination for k, v in method_edges.items()), (address, expected, method_edges)
    helpers.append({'address': address, 'symbol': method_name, 'size': len(method_body), 'direct_calls': method_edges})
signal_methods = []
for address, prefix, two_args, required in [
    ('004a3340', '?connect@?$TSignalDesc@', False, [('?sig@?$TSignalDesc@', '0x5875e0'), ('?connect@?$signal1@', '0x4a3020')]),
    ('00588fb0', '?connect@?$TSignalDesc@', True, [('?sig@?$TSignalDesc@', '0x5875e0'), ('?connect@?$signal2@', '0x588db0')]),
    ('005875e0', '?sig@?$TSignalDesc@', False, [('?getSignalInstance@SignalDescriptor@', '0x56bb20')]),
    ('005875e0', '?sig@?$TSignalDesc@', True, [('?getSignalInstance@SignalDescriptor@', '0x56bb20')]),
    ('004a3020', '?connect@?$signal1@', False, [('?connect_slot@signal_base_impl@', '0x56a900')]),
    ('00588db0', '?connect@?$signal2@', True, [('?connect_slot@signal_base_impl@', '0x56a900')]),
]:
    method_name, method_body, method_refs = next(x for x in match.coff_functions(raw) if x[0].startswith(prefix) and ('PBVPropertyDescriptor' in x[0]) == two_args)
    method_target, method_targetrefs, _ = match.target('2008-06', address)
    assert match.exact_match(method_target, method_targetrefs, method_body, method_refs), (address, len(method_body), len(method_target))
    method_start, method_index = definitions[method_name]
    method_section = sections[method_index]
    method_edges = {}
    for i in range(method_section[7]):
        offset, symbol, kind = struct.unpack_from('<IIH', raw, method_section[5] + 10*i)
        offset -= method_start
        if 0 <= offset < len(method_body)-4 and kind == 20:
            method_edges[symbols[symbol][0]] = hex(int(address, 16) + offset + 4 + struct.unpack_from('<i', method_target, offset)[0])
    for expected, destination in required:
        assert any(k.startswith(expected) and v == destination for k, v in method_edges.items()), (address, expected, method_edges)
    signal_methods.append({'address': address, 'symbol': method_name, 'size': len(method_body), 'direct_calls': method_edges})
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
receipt = {'source_sha256': sha(source), 'object_sha256': sha(obj), 'observer_sha256': sha(Path(__file__)),
           'input_sha256': {str(p.relative_to(root)): sha(p) for p in (signal_path, instance_path, history_path, record_path, utilities_path)},
           'flags': flags, 'size': len(body), 'target_size': len(target), 'exact': exact, 'direct_calls': edges, 'event_relocations': data, 'callback_thunks': thunks,
           'visit': {'address': '004a27e0', 'size': len(visit_body), 'direct_calls': visit_edges}, 'helpers': helpers, 'signal_methods': signal_methods, 'event_vtable_slots': event_slots,
           'scope': 'Isolated diagnostic declarations, event ownership and 2008 signal implementation unproven. Never link or run this object in the player.'}
(root / 'work/2008-06/shared-layouts/history-start-trial.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('startup candidate:', len(body), '/', len(target), 'exact:', exact)

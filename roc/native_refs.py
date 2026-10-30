"""Native-only reference checks. Unknown symbols remain unresolved, never guessed."""
import struct
import json
from pathlib import Path

from roc import match


def import_checks(obj, symbol, addr, client='2008-06', target=None):
    from roc import standins
    target = match.target(client,addr)[0] if target is None else target
    sections, symbols, functions, _ = match._coff_data_index(obj)
    if symbol not in functions:
        return []
    start, section = functions[symbol]
    relptr, count = sections[section][5], sections[section][7]
    imports = standins._imports(client)
    base, image = match._image(client)
    checks = []
    for n in range(count):
        offset,index,kind = struct.unpack_from('<IIH',obj,relptr+10*n)
        offset -= start
        if not 0 <= offset <= len(target)-4 or kind not in (6,20):
            continue
        actual = symbols[index][0]
        word = int.from_bytes(target[offset:offset+4],'little',signed=kind==20)
        destination = (int(addr,16)+offset+4+word)&0xffffffff if kind==20 else word
        expected = imports.get(destination)
        if expected is None and kind==20 and base <= destination <= base+len(image)-6:
            at = destination-base
            if image[at:at+2]==b'\xff\x25':
                expected = imports.get(int.from_bytes(image[at+2:at+6],'little'))
        row = dict(offset=offset,symbol=actual,target='%08x'%destination,relocation=kind,status='unresolved')
        if expected and not expected.split('!',1)[-1].startswith('#'):
            name = actual[len('__imp_'):] if actual.startswith('__imp_') else actual
            aliases = {name}
            if name.startswith('_'):
                aliases.add(name[1:])
            aliases.update(a.rsplit('@',1)[0] for a in list(aliases) if '@' in a and a.rsplit('@',1)[-1].isdigit())
            compatible = expected.split('!',1)[-1] in aliases
            # Direct native wrappers may legitimately forward to an import. Their
            # symbol spelling alone cannot prove or disprove the linked callee.
            row.update(expected=expected,status='compatible_import_name' if compatible else
                       'incorrect_symbol_reference' if actual.startswith('__imp_') else 'unresolved')
        checks.append(row)
    return checks


def validate(root, report, addresses, client='2008-06'):
    """A newly owned address needs at least one matching code/data/reference witness."""
    wanted = set(addresses)
    if not wanted:
        return dict(checked=0,unknown_references=0)
    directory = Path(root)/'rebuild'/client/'out'/report['module']
    bindings = report.get('owned_symbols')
    if bindings is None and report.get('owned_symbols_file'):
        metadata = (directory/report['owned_symbols_file']).resolve()
        if not metadata.is_relative_to(directory.resolve()):
            raise ValueError('Native reference map escaped module directory')
        bindings = json.loads(metadata.read_text())
    if bindings is None:
        raise ValueError('Native reference map missing; rebuild with the current verifier')
    root = directory/'linked'
    checked, unknown, failures = set(), 0, {}
    objects = {}
    for addr in sorted(wanted):
        notes = []
        for binding in bindings.get(addr, []):
            path = (root/binding['object']).resolve()
            if not path.is_relative_to(root.resolve()):
                raise ValueError('Reference witness escaped linked object directory')
            if path not in objects:
                objects[path] = path.read_bytes()
            obj, symbol = objects[path], binding['symbol']
            target, relocs, _ = match.target(client,addr)
            bodies = [(body,r) for s,body,r in match.coff_functions(obj) if s==symbol]
            if not any(match.exact_match(target,relocs,body,r) for body,r in bodies):
                notes.append('linked object code changed')
                continue
            _, bad = match.data_check(client,addr,target,match.coff_data_refs(obj,symbol))
            refs = import_checks(obj,symbol,addr,client,target)
            contradictions = [r for r in refs if r['status']=='incorrect_symbol_reference']
            if not bad and not contradictions:
                checked.add(addr)
                unknown += sum(r['status']=='unresolved' for r in refs)
                break
            notes += bad + [str(r) for r in contradictions]
        if addr not in checked:
            failures[addr] = notes or ['no linked symbol witness']
    if failures:
        first = next(iter(failures))
        raise ValueError('Native data/reference mismatch at '+first+': '+str(failures[first][:2]))
    return dict(checked=len(checked),unknown_references=unknown,scope='code, referenced data, known import names; unresolved native symbols require ABI context')

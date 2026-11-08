"""Map archive provider references to owning functions; never compile or run a client."""
import argparse
import bisect
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT))
from roc import libs, match


def consumers(raw, wanted):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    references = []
    for section_index, section in enumerate(sections):
        for index in range(section[7]):
            offset, symbol_index, kind = struct.unpack_from('<IIH', raw, section[5] + index * 10)
            symbol, _, number, _ = symbols[symbol_index]
            if number == 0 and symbol in wanted:
                references.append((section_index, offset, symbol, kind))
    if not references:
        return []
    intervals = {}
    for name, body, _ in match.coff_functions(raw):
        start, section_index = definitions[name]
        intervals.setdefault(section_index, {}).setdefault(start, []).append((name, len(body)))
    starts = {section: sorted(rows) for section, rows in intervals.items()}
    rows = []
    for section, offset, symbol, kind in references:
        candidates = starts.get(section, [])
        index = bisect.bisect_right(candidates, offset) - 1
        owners = []
        if index >= 0:
            start = candidates[index]
            owners = [name for name, size in intervals[section][start] if offset < start + size]
        rows.append({'owners': owners, 'kind': 'function' if owners else 'data_or_unmapped',
                     'symbol': symbol, 'section': section + 1, 'offset': offset, 'relocation_kind': kind})
    return rows


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('member')
    parser.add_argument('--archive', type=Path, default=ROOT / 'rebuild/2008-06/out/RbxgsApp/linked/linked.lib')
    parser.add_argument('--family', help='Substring filter on provider symbols; defaults to member stem')
    parser.add_argument('--run', type=Path, help='Terminal diagnostic run; include explicit object inputs')
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    digest = hashlib.sha256(args.archive.read_bytes()).hexdigest()
    members = list(libs.archive_members(args.archive))
    target = next(raw for name, raw in members if Path(name).name.lower() == args.member.lower())
    family = args.family or Path(args.member).stem
    wanted = {name for name in match._coff_data_index(target)[2] if family in name}
    inputs = [('archive:' + name, raw) for name, raw in members if Path(name).name.lower() != args.member.lower()]
    if args.run:
        assert (args.run / 'result.json').is_file(), 'terminal diagnostic receipt required'
        command = json.loads((args.run / 'output/native-doc-link-command.json').read_text())
        for argument in command['arguments']:
            if argument.lower().endswith('.obj') and not argument.startswith('/'):
                path = Path(argument)
                if not path.is_absolute():
                    path = Path(command['cwd']) / path
                inputs.append(('object:' + str(path), path.read_bytes()))
    grouped = {}
    input_hashes = {}
    for label, raw in inputs:
        try:
            rows = consumers(raw, wanted)
        except (ValueError, struct.error):
            continue
        if rows:
            input_hashes[label] = hashlib.sha256(raw).hexdigest()
        for row in rows:
            for owner in row['owners'] or ['<data-or-unmapped>']:
                entry = grouped.setdefault(owner, {'function': owner, 'inputs': set(), 'symbols': set()})
                entry['inputs'].add(label)
                entry['symbols'].add(row['symbol'])
    rows = [dict(function=owner, inputs=sorted(row['inputs']), symbols=sorted(row['symbols']))
            for owner, row in sorted(grouped.items())]
    assert digest == hashlib.sha256(args.archive.read_bytes()).hexdigest(), 'archive changed during audit'
    receipt = {'scope': __doc__ + ' References are possible edges, not actual extraction or ABI/runtime proof.',
               'archive': str(args.archive), 'archive_sha256': digest, 'member': args.member,
               'family': family, 'provider_symbols': sorted(wanted), 'input_sha256': input_hashes, 'consumers': rows}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps({'member': args.member, 'family': family, 'provider_symbols': len(wanted),
                      'consumer_functions': len(rows), 'consumer_inputs': len(input_hashes), 'output': str(args.output)}))


if __name__ == '__main__':
    main()

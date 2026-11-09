"""Check explicit EH data providers against saved real objects; never compile/link/run native code."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import match


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('baseline', type=Path, help='Saved EH audit receipt with primary object and explicit function providers')
    parser.add_argument('name_object', type=Path, help='Object defining the real Instance Name descriptor storage')
    parser.add_argument('--audit', type=Path, default=Path(__file__).with_name('audit_native_eh_graph.py'))
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--property-object', type=Path)
    parser.add_argument('--standardout-object', type=Path)
    parser.add_argument('--mutex-object', type=Path)
    args = parser.parse_args()
    assert all((args.property_object, args.standardout_object, args.mutex_object)) or not any((args.property_object, args.standardout_object, args.mutex_object))
    args.output.mkdir(parents=True)
    baseline = json.loads(args.baseline.read_text())
    primary = (ROOT / baseline['object']).resolve()
    assert hashlib.sha256(primary.read_bytes()).hexdigest() == baseline['object_sha256']
    raw = args.name_object.read_bytes()
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    name = next(name for name in definitions if name.startswith('?desc_Name@Instance@RBX@@'))
    value, section = definitions[name]
    assert sections[section][9] & 0x80
    primary_name = next(name for name, _, _ in match.coff_functions(primary.read_bytes()) if name.startswith('??0RunService@RBX@@'))
    command = [sys.executable, str(args.audit), str(primary), baseline['address'], primary_name]
    unchanged = {primary: baseline['object_sha256'], args.name_object: hashlib.sha256(raw).hexdigest()}
    for row in baseline['provider_inputs']:
        path = (ROOT / row['object']).resolve()
        assert hashlib.sha256(path.read_bytes()).hexdigest() == row['sha256']
        unchanged[path] = row['sha256']
        command += ['--provider', row['symbol'], str(path)]
    cases = []

    def run_case(label, providers):
        receipt = args.output / (label + '.json')
        done = subprocess.run(command + ['--output', str(receipt)] + providers, cwd=ROOT, capture_output=True, text=True)
        (args.output / (label + '.log')).write_text(done.stdout + done.stderr)
        data = json.loads(receipt.read_text()) if receipt.exists() else None
        cases.append({'case': label, 'exit': done.returncode})
        return done, data

    done, data = run_case('valid-data-provider', ['--provider', name, str(args.name_object)])
    assert data is not None
    assert any(row.get('symbol') == name and row.get('kind') == 'EH data' and row.get('exact') and row.get('zero_initialized') for row in data['events'])
    assert (done.returncode == 0) == (not data['errors']), 'Remaining graph obligations must fail closed'
    done, data = run_case('missing-data-provider', [])
    assert done.returncode and data and any(name in error for error in data['errors'])

    # Negative fixture only: a private clone with genuinely initialized nonzero
    # storage. It is never linked, executed, or used as a native candidate.
    changed = bytearray(raw)
    optional_size = struct.unpack_from('<H', raw, 16)[0]
    section_header = 20 + optional_size + section * 40
    data_pointer = (len(changed) + 3) & ~3
    changed.extend(bytes(data_pointer - len(changed) + sections[section][3]))
    struct.pack_into('<I', changed, section_header + 20, data_pointer)
    struct.pack_into('<I', changed, section_header + 36, (sections[section][9] & ~0x80) | 0x40)
    changed[data_pointer + value] = 1
    corrupt = args.output / 'nonzero-storage.obj'
    corrupt.write_bytes(changed)
    done, data = run_case('nonzero-storage-rejected', ['--provider', name, str(corrupt)])
    assert done.returncode and data
    assert any(row.get('symbol') == name and row.get('kind') == 'EH data' and not row.get('exact') for row in data['events'])

    changed = bytearray(raw)
    symbol_index = next(index for index, row in symbols.items() if row[0] == name)
    symbol_pointer = struct.unpack_from('<I', raw, 8)[0]
    struct.pack_into('<I', changed, symbol_pointer + symbol_index * 18 + 8, sections[section][3])
    invalid = args.output / 'out-of-range-storage.obj'
    invalid.write_bytes(changed)
    done, data = run_case('out-of-range-storage-rejected', ['--provider', name, str(invalid)])
    assert done.returncode and data and any('invalid data range' in error for error in data['errors'])
    done, _ = run_case('missing-exact-symbol-rejected', ['--provider', name + '_missing', str(args.name_object)])
    assert done.returncode and 'exact provider symbol missing' in done.stderr
    done, _ = run_case('duplicate-provider-rejected', ['--provider', name, str(args.name_object), '--provider', name, str(args.name_object)])
    assert done.returncode and 'duplicate provider symbol' in done.stderr
    if args.mutex_object:
        providers = ['--provider', name, str(args.name_object)]
        for prefix, path in (('?raisePropertyChanged@Instance@RBX@@', args.property_object),
                             ('?singleton@StandardOut@RBX@@', args.standardout_object),
                             ('??0mutex@boost@@', args.mutex_object), ('??1mutex@boost@@', args.mutex_object)):
            contents = path.read_bytes()
            symbol = next(n for n, _, _ in match.coff_functions(contents) if n.startswith(prefix))
            unchanged[path] = hashlib.sha256(contents).hexdigest()
            providers += ['--provider', symbol, str(path)]
        done, data = run_case('kernel-import-abi-resolves', providers)
        assert data and any(row.get('symbol') == '__imp__DeleteCriticalSection@4' and row.get('exact') for row in data['events'])
        assert (done.returncode == 0) == (not data['errors'])
        # Negative fixture only: wrong stdcall arity must not match the real import.
        contents = args.mutex_object.read_bytes()
        assert contents.count(b'__imp__DeleteCriticalSection@4') == 1
        invalid = args.output / 'wrong-import-arity.obj'
        invalid.write_bytes(contents.replace(b'__imp__DeleteCriticalSection@4', b'__imp__DeleteCriticalSection@8'))
        providers = [str(invalid) if item == str(args.mutex_object) else item for item in providers]
        done, data = run_case('kernel-import-wrong-arity-rejected', providers)
        assert done.returncode and data and any('__imp__DeleteCriticalSection@8' in error for error in data['errors'])
    for path, digest in unchanged.items():
        assert hashlib.sha256(path.read_bytes()).hexdigest() == digest
    (args.output / 'summary.json').write_text(json.dumps({'cases': cases, 'passed': len(cases),
        'scope': 'Valid zero storage resolves; incomplete remaining graph still fails. Negative private clones rejected. Dynamic initialization, ABI and runtime remain separate.'}, indent=2) + '\n')
    print(len(cases), 'EH data-provider checks passed')


if __name__ == '__main__':
    main()

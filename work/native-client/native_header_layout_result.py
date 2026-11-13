"""Read strict constant-offset results from a compiler-produced layout probe."""
import argparse
import json
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--object', type=Path, required=True)
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    rows = []
    for name, code, relocs in match.coff_functions(args.object.read_bytes()):
        if not name.startswith('_roc_offset_'):
            continue
        # VS2008 /O2 emits mov eax, imm32; ret for this exact probe shape.
        if len(code) != 6 or code[0] != 0xb8 or code[5] != 0xc3 or relocs:
            raise SystemExit('unsupported offset probe shape: ' + name)
        rows.append({'field': name[len('_roc_offset_'):],
                     'offset': int.from_bytes(code[1:5], 'little'),
                     'code_hex': code.hex()})
    if not rows:
        raise SystemExit('no offset probes found')
    result = {'object': str(args.object.resolve()), 'rows': rows,
              'scope': 'compiler-derived existing-header layout evidence only; no target or runtime proof'}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=1) + '\n', encoding='utf-8')
    print('layout-rows', len(rows), 'output', args.output)


if __name__ == '__main__':
    main()

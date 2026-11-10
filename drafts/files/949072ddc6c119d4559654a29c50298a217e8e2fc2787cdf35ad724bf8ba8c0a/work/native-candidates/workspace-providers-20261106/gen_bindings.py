import json
import struct
import sys
from pathlib import Path

ROOT = next((p for p in Path(__file__).resolve().parents if (p / 'roconstruct-package.json').is_file()),
            Path(r'C:\Users\colin\Desktop\RoConstruct-main\RoConstruct-Native-4f7d46a43031423c966cd798b30be257'))
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / 'rebuild/2008-06/tests'))
from roc import match
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_OP_IMM

RUN = ROOT / 'work/2008-06/native-check-runs/20261106-140554-cab011e3'
MANIFEST = ROOT / 'rebuild/2008-06/tests/workspace-providers-unit-20261106.json'
ANALYSIS = max(RUN.glob('analysis-*.json'), key=lambda p: p.stat().st_mtime)


def relocs_for(raw, symbol):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    matches = [s for s in definitions if s == symbol] or [s for s in definitions if s.startswith(symbol)]
    if len(matches) != 1:
        raise ValueError('symbol missing/ambiguous: ' + symbol)
    start, section = definitions[matches[0]]
    table = sections[section]
    out = {}
    for index in range(table[7]):
        offset, name, kind = struct.unpack_from('<IIH', raw, table[5] + 10 * index)
        out[offset - start] = {'external': symbols[name][0], 'type': kind}
    return matches[0], out


def main():
    results = {Path(r['source']).name: r for r in json.loads((RUN / 'results.json').read_text(encoding='utf-8'))}
    analysis = json.loads(ANALALYSIS := ANALYSIS.read_text(encoding='utf-8'))
    data = json.loads(MANIFEST.read_text(encoding='utf-8'))
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    total = 0
    for job in data['jobs']:
        source = Path(job['source']).name
        result = results.get(source)
        if not result:
            continue
        raw = Path(result['object']).read_bytes()
        for check in job['checks']:
            symbol = check['symbol']
            name, relocs = relocs_for(raw, symbol)
            target, _, _ = match.target('2008-06', check['addr'])
            calls = []
            for ins in decoder.disasm(target, int(check['addr'], 16)):
                if ins.mnemonic != 'call':
                    continue
                op = ins.operands[0]
                if op.type != X86_OP_IMM:
                    continue
                off = ins.address - int(check['addr'], 16)
                r = relocs.get(off + 1)
                calls.append({'offset': off, 'target': '%08x' % op.imm,
                              'symbol': r['external'] if r else None})
            check['calls'] = calls
            total += len(calls)
    MANIFEST.write_text(json.dumps(data, separators=(',', ':')), encoding='utf-8')
    print('checks with bindings', sum(len(j['checks']) for j in data['jobs']), 'bindings total', total)


if __name__ == '__main__':
    main()

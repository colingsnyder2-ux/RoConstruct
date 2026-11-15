"""Bounded, isolated Ogre source search; results still require native proof."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys
import time

import native_repair_tools as aid


def positional_score(obj, config):
    data = json.loads(Path(config).read_text())
    target, original_refs, _ = aid.match.target('2008-06', data['address'])
    body, refs = aid.function(Path(obj), data['symbol'])
    if set(original_refs) <= set(refs) and aid.match.exact_match(target, original_refs, body, refs):
        return 0
    mask = {i for offset in set(original_refs) | set(refs) for i in range(offset, offset + 4)}
    differences = sum(a != b for i, (a, b) in enumerate(zip(target, body)) if i not in mask)
    return max(1, differences + abs(len(target) - len(body)) + 4 * len(set(original_refs) - set(refs)))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source', type=Path)
    parser.add_argument('address')
    parser.add_argument('symbol')
    parser.add_argument('method')
    parser.add_argument('--seconds', type=int, default=180)
    parser.add_argument('--candidates', type=int, default=200)
    parser.add_argument('--mode', choices=['random', 'exhaustive'], default='exhaustive')
    parser.add_argument('--seed', type=int, default=1701)
    parser.add_argument('--score-mode', choices=['fuzzy', 'positional'], default='fuzzy')
    parser.add_argument('--passes', default='noop_node,scope_block,reorder_saves,hoist_decl,sink_decl,merge_decl,temp_for_expr,ref_local,inline_local,reuse_local,split_local,flip_compare,invert_if,branch_dup')
    args = parser.parse_args()
    if not 1 <= args.seconds <= 600 or not 1 <= args.candidates <= 1000:
        parser.error('budget must be 1..600 seconds and 1..1000 candidates')
    source, address = aid.validate(args.source, args.address, args.symbol)
    directory = aid.run_dir('permuter', address)
    print(directory, flush=True)
    digest = hashlib.sha256(source.read_bytes()).hexdigest()
    scratch = directory / 'input'
    scratch.mkdir()
    copy = scratch / source.name
    shutil.copyfile(source, copy)
    config = directory / 'score.json'
    config.write_text(json.dumps({'address': address, 'symbol': args.symbol,
                                  'source_dir': str(source.parent)}, indent=2))
    started = time.monotonic()
    deadline = started + args.seconds
    for item, name in ((source, 'original.obj'), (copy, 'copied.obj')):
        aid.guarded_compile(item, directory / name, config, max(1, deadline - time.monotonic()))
    if aid.function(directory / 'original.obj', args.symbol) != aid.function(directory / 'copied.obj', args.symbol):
        raise RuntimeError('scratch context changed emitted body')
    quote = aid.shell_quote
    command = quote(sys.executable) + ' ' + quote(Path(aid.__file__).resolve())
    compile_cmd = command + ' internal-compile {src} {obj} ' + quote(config)
    score_cmd = command + ' internal-score {obj} ' + quote(config)
    if args.score_mode == 'positional':
        score_cmd = quote(sys.executable) + ' ' + quote(Path(__file__).resolve()) + ' score {obj} ' + quote(config)
    output = directory / 'candidates'
    argv = [aid.tool('permuter'), '-s', copy, '-f', args.method,
            '-c', compile_cmd, '--score-cmd', score_cmd, '-m', args.mode,
            '-p', args.passes, '--depth', '2', '--max-candidates', str(args.candidates),
            '--iterations', str(args.candidates), '--seed', str(args.seed),
            '-j', '2', '--timeout', '40', '-I', aid.ROOT / 'rebuild/2008-06/native-headers',
            '-o', output]
    status = 'finished'
    try:
        result = aid.bounded(argv, max(1, deadline - time.monotonic()))
        (directory / 'search.log').write_text(result.stdout + result.stderr)
        exit_code = result.returncode
    except subprocess.TimeoutExpired as error:
        status, exit_code = 'timeout', None
        partial = error.stdout or b''
        (directory / 'search.log').write_text(partial.decode(errors='replace') if isinstance(partial, bytes) else partial)
    improvements = []
    for score in sorted(output.glob('output-*/score.txt')):
        improvements.append({'score': int(score.read_text().strip()), 'directory': str(score.parent)})
    receipt = {'status': status, 'exit_code': exit_code, 'address': address,
               'source': str(source), 'source_sha256': digest,
               'source_unchanged': hashlib.sha256(source.read_bytes()).hexdigest() == digest,
               'passes': args.passes, 'mode': args.mode, 'seed': args.seed,
               'score_mode': args.score_mode,
               'depth': 2, 'candidate_limit': args.candidates,
               'seconds': round(time.monotonic() - started, 2), 'improvements': improvements,
               'scope': 'Candidate search only; semantic, byte, data and call checks required before adoption.'}
    (directory / 'receipt.json').write_text(json.dumps(receipt, indent=2))
    print(json.dumps(receipt), flush=True)


if __name__ == '__main__':
    if len(sys.argv) == 4 and sys.argv[1] == 'score':
        print(positional_score(sys.argv[2], sys.argv[3]))
    else:
        main()

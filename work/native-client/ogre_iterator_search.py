"""Permute an iterator block, but score its code inside the authentic renderer."""
import json
import hashlib
from pathlib import Path
import subprocess
import sys

import native_repair_tools as aid
from ogre_bounded_broad_search import positional_score


def body(text):
    return text[text.index('{') + 1:text.rindex('}')].strip()


def compile_block(source, obj, config):
    config = json.loads(Path(config).read_text())
    original = Path(config['source']).read_text(encoding='utf-8')
    if original.count(config['block']) != 1:
        raise RuntimeError('canonical block changed during search')
    candidate = original.replace(config['block'], body(Path(source).read_text()))
    digest = hashlib.sha256(candidate.encode()).hexdigest()
    merged = Path(obj).parent / ('native-' + digest[:16] + '.cpp')
    merged.write_text(candidate, encoding='utf-8')
    aid.compile_candidate(merged, Path(obj), Path(config['source']).parent)
    archive = Path(config['source_archive']) / digest
    archive.mkdir(parents=True, exist_ok=True)
    score = positional_score(obj, Path(config['config_path']))
    raw = Path(obj).read_bytes()
    data, refs = aid.function(Path(obj), config['symbol'])
    (archive / 'metrics.json').write_text(json.dumps({'score': score, 'body_hex': data.hex(),
        'relocations': refs, 'object_sha256': hashlib.sha256(raw).hexdigest()}, indent=1))
    if score <= 37:
        (archive / 'native.cpp').write_text(candidate, encoding='utf-8')
        (archive / 'candidate.obj').write_bytes(raw)


def main():
    if len(sys.argv) == 5 and sys.argv[1] == 'compile':
        compile_block(*sys.argv[2:])
        return
    source = aid.ROOT / 'rebuild/2008-06/native-classes/OgreRbxSceneManager.cpp'
    text = source.read_text(encoding='utf-8')
    start = text.index('localLightList.clear();', text.index('void RbxSceneManager::renderSingleObject'))
    end = text.index('pLightListToUse = &localLightList;', start) + len('pLightListToUse = &localLightList;')
    block = text[start:end]
    directory = aid.run_dir('permuter', '0069bc50')
    print(directory, flush=True)
    scratch = directory / 'input'
    scratch.mkdir()
    snippet = scratch / 'iterator.cpp'
    snippet.write_text('void iterator_search(const LightList& rendLightList, LightList& localLightList, const Pass* pass, const LightList*& pLightListToUse) {\n' + block + '\n}\n')
    config = directory / 'config.json'
    symbol = '?renderSingleObject@RbxSceneManager@Ogre@@MAEXPBVRenderable@2@PBVPass@2@_NPBV?$vector@PAVLight@Ogre@@V?$allocator@PAVLight@Ogre@@@std@@@std@@@Z'
    config.write_text(json.dumps({'source': str(source), 'block': block, 'address': '0069bc50',
        'symbol': symbol, 'source_archive': str(directory / 'compiled'), 'config_path': str(config)}, indent=1))
    original = aid.compile_candidate(source, directory / 'original.obj')
    compile_block(snippet, directory / 'base.obj', config)
    if aid.function(original, symbol) != aid.function(directory / 'base.obj', symbol):
        raise RuntimeError('block reinsertion changed the base body')
    quote = aid.shell_quote
    compile_cmd = quote(sys.executable) + ' ' + quote(Path(__file__).resolve()) + ' compile {src} {obj} ' + quote(config)
    score_cmd = quote(sys.executable) + ' ' + quote(aid.HERE / 'ogre_bounded_broad_search.py') + ' score {obj} ' + quote(config)
    args = [aid.tool('permuter'), '-s', snippet, '-f', 'iterator_search', '-c', compile_cmd,
            '--score-cmd', score_cmd, '-m', 'exhaustive', '--depth', '3',
            '-p', 'ref_local,reorder_saves,hoist_decl,sink_decl,merge_decl,scope_block,inline_local,temp_for_expr,split_local,reuse_local',
            '--max-candidates', '120', '-j', '2', '--timeout', '45', '-o', directory / 'candidates']
    try:
        result = aid.bounded(args, 300)
        log = result.stdout + result.stderr
        status = 'finished' if result.returncode in (0, 3) else 'failed'
    except subprocess.TimeoutExpired as error:
        log, status = error.stdout or b'', 'timeout'
    (directory / 'search.log').write_text(log.decode(errors='replace') if isinstance(log, bytes) else log)
    improvements = [{'score': int(p.read_text()), 'directory': str(p.parent)}
                    for p in (directory / 'candidates').glob('output-*/score.txt')]
    result = {'status': status, 'improvements': improvements,
              'scope': 'Snippet is search scaffolding only; every score compiles its body inside the original renderer. No helper is added to native code.'}
    (directory / 'receipt.json').write_text(json.dumps(result, indent=1))
    print(json.dumps(result), flush=True)


if __name__ == '__main__':
    main()

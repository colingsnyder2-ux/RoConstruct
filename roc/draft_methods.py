"""Hash-bound repo-wide AST method inventory; compiler resolution remains a separate gate."""
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from importlib.metadata import version
import os
import re
from pathlib import Path
import sqlite3
import sys

runtime=Path(__file__).resolve().parents[1]/'local/draft-parser'
if runtime.is_dir():sys.path.insert(0,str(runtime))
if version('tree-sitter') != '0.25.2' or version('tree-sitter-cpp') != '0.23.4':
    raise RuntimeError('Install the pinned draft parser: python -m pip install --target local/draft-parser -r requirements-draft-merger.txt')
from tree_sitter import Language, Parser
import tree_sitter_cpp
CPP_LANGUAGE=Language(tree_sitter_cpp.language())
CPP_PARSER=Parser(CPP_LANGUAGE)

def source_paths(root):
    root=Path(root).resolve()
    paths=[]
    for directory,dirs,files in os.walk(root/'rebuild/2008-06'):
        dirs[:]=sorted(d for d in dirs if d.lower() not in ('out','__pycache__','.git')
            and not (Path(directory)/d).is_symlink()
            and not (hasattr(Path(directory)/d,'is_junction') and (Path(directory)/d).is_junction()))
        for name in sorted(files):
            path=Path(directory)/name
            if path.suffix.lower() in ('.cpp','.c','.cc','.cxx','.h','.hpp','.inl','.inc','.ipp') and not path.is_symlink() and path.resolve().is_relative_to(root):
                paths.append(path)
    return paths


def shadow_path(name):
    parts=Path(name).parts
    return any(part.lower() in ('_unsplit','_archive','tests','patches','source') or
               part.lower().startswith('native-donor-') for part in parts)

def tokens(text):
    return re.sub(r'\s+', '', text)


def extract(source):
    tree=CPP_PARSER.parse(source)
    result=[]
    stack=[(tree.root_node,(),False)]
    while stack:
        node,scopes,uncertain=stack.pop()
        uncertain=uncertain or node.type in ('template_declaration','preproc_if','preproc_ifdef','preproc_elif','preproc_else')
        if node.type in ('namespace_definition','class_specifier','struct_specifier'):
            name=node.child_by_field_name('name')
            if name: scopes=scopes+(name.text.decode(),)
            else: uncertain=True
        if node.type=='function_definition':
            decl=node.child_by_field_name('declarator')
            while decl and decl.type!='function_declarator':
                decl=decl.child_by_field_name('declarator') or (decl.named_children[0] if decl.named_children else None)
            if decl:
                name=decl.child_by_field_name('declarator')
                params=decl.child_by_field_name('parameters')
                if name and params:
                    qname=name.text.decode()
                    prefix='::'.join(scopes)
                    if qname.startswith('::'):qname=qname[2:]
                    elif prefix and not qname.startswith(prefix+'::'):qname=prefix+'::'+qname
                    types=[]
                    for param in params.named_children:
                        raw=param.text
                        default=param.child_by_field_name('default_value')
                        if default: raw=source[param.start_byte:default.start_byte].rstrip().rstrip(b'=').rstrip()
                        pd=param.child_by_field_name('declarator')
                        while pd and pd.type!='identifier':pd=pd.child_by_field_name('declarator')
                        if pd:
                            start=pd.start_byte-param.start_byte;end=pd.end_byte-param.start_byte
                            raw=raw[:start]+raw[end:]
                        types.append(tokens(raw.decode()))
                    tail=source[params.end_byte:decl.end_byte].decode()
                    tail=re.sub(r'\b(override|final)\b','',tail)
                    body=node.child_by_field_name('body')
                    leaves=[]
                    literals=[]
                    pending=[body] if body else []
                    while pending:
                        part=pending.pop()
                        if part.type=='comment':continue
                        if part.type in ('string_literal','raw_string_literal'):literals.append(part.text.decode(errors='replace'))
                        children=part.children
                        if children:pending.extend(reversed(children))
                        else:leaves.append(part.text)
                    result.append(dict(signature=tokens(qname)+'('+','.join(types)+')'+tokens(tail),
                        body_sha256=hashlib.sha256(b'\0'.join(leaves)).hexdigest(),
                        line=node.start_point.row+1,needs_semantic_resolution=uncertain or '<' in qname,
                        strings=sorted(set(literals))))
        for child in node.named_children:stack.append((child,scopes,uncertain))
    return result,tree.root_node.has_error


def build(root):
    from roc.draft_merger import content_hash, proof_key
    from roc.native_drafts import atomic
    root=Path(root).resolve()
    index=defaultdict(list)
    inventory={}
    for path in source_paths(root):
        rel=path.relative_to(root).as_posix()
        raw=path.read_bytes(); sha=content_hash(raw)
        inventory[rel]=sha
        rows,errors=extract(raw)
        shadow=shadow_path(rel)
        for row in rows:
            index[row['signature']].append(dict(row,path=rel,sha256=sha,shadow=shadow,parse_errors=errors))
        if len(inventory)%500==0:print('Indexed',len(inventory),'files',flush=True)
    identity=proof_key(dict(files=inventory,verifier=content_hash(Path(__file__).read_bytes())))
    report=dict(identity=identity,inventory=inventory,index=dict(index),compiler_resolved=False,
                warning='AST-only candidate lookup. Aliases/macros/templates/conditional compilation require original compiler symbol and batch collision checks.')
    atomic(root/'work/draft-merger/method-index.json',report)
    return dict(identity=identity,files=len(inventory),signatures=len(index))


def inspect(root):
    from roc.draft_merger import content_hash
    from roc.native_drafts import atomic
    root=Path(root).resolve();folder=root/'work/draft-merger'
    index=json.loads((folder/'method-index.json').read_text())
    actual={path.relative_to(root).as_posix() for path in source_paths(root)}
    stale=sorted(actual.symmetric_difference(index['inventory']))
    for name,sha in index['inventory'].items():
        path=root/name
        if not path.is_file() or content_hash(path.read_bytes())!=sha:stale.append(name)
    latest=json.loads((folder/'latest.json').read_text())
    db=sqlite3.connect(folder/'state.sqlite3')
    results=[];cache={}
    for bundle in latest['bundles']:
        for entry in bundle['files']:
            sha=entry['candidate_sha256']; name=entry['path']
            if sha is None or Path(name).suffix.lower() not in ('.cpp','.c','.cc','.cxx','.h','.hpp','.inl','.inc','.ipp'):continue
            key=(name,sha)
            if key in cache:
                cache[key]['bundles'].append(bundle['id']);continue
            raw=db.execute('SELECT bytes FROM contents WHERE sha256=?',(sha,)).fetchone()[0]
            definitions,errors=extract(raw)
            methods=[]
            for method in definitions:
                hits=index['index'].get(method['signature'],[])
                canonical=[h for h in hits if not h['shadow']]
                method.update(locations=hits,status='exists-same-body' if any(h['body_sha256']==method['body_sha256'] for h in canonical) else 'exists-different-body' if canonical else 'shadow-only' if hits else 'not-found',
                    uncertain=errors or method['needs_semantic_resolution'] or any(h['parse_errors'] or h['needs_semantic_resolution'] for h in canonical),
                    compiler_resolved=False)
                methods.append(method)
            row=dict(path=name,sha256=sha,bundles=[bundle['id']],methods=methods,parse_errors=errors)
            cache[key]=row;results.append(row)
    db.close()
    summary=dict(run=latest['summary']['run'],index_identity=index['identity'],stale_paths=stale,
                 variants=len(results),method_states=dict(Counter(m['status'] for r in results for m in r['methods'])))
    atomic(folder/'method-decisions.json',dict(summary=summary,variants=results))
    return summary


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action',choices=('build','inspect'))
    parser.add_argument('--root',type=Path,default=Path(__file__).resolve().parents[1])
    args=parser.parse_args()
    print(json.dumps(build(args.root) if args.action=='build' else inspect(args.root),indent=2))

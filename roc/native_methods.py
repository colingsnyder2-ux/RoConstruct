"""Conservative spans for existing inline header bodies; layouts/signatures stay immutable."""
from functools import lru_cache
import re
from collections import defaultdict

from roc import native_sweep as sweep


@lru_cache(maxsize=32)
def methods(text):
    result=dict(sweep.methods(text));found=defaultdict(list)
    clean=sweep.masked_cpp(text)
    for owner in re.finditer(r'\b(class|struct)\s+(?:__declspec\([^)]*\)\s+)?(\w+)\s*(?:\bfinal\s*)?(?::[^;{]+)?\{',clean):
        begin=owner.end();finish=sweep.closing(clean,begin-1,'{','}')
        cursor=begin;access='public' if owner[1]=='struct' else 'private'
        while cursor<finish:
            if clean[cursor].isspace():cursor+=1;continue
            label=re.match(r'(public|private|protected)\s*:',clean[cursor:])
            if label:access=label[1];cursor+=label.end();continue
            boundary=re.search('[;{}]',clean[cursor:finish])
            if not boundary:break
            at=cursor+boundary.start()
            if clean[at]==';':cursor=at+1;continue
            if clean[at]=='}':break
            prefix=clean[cursor:at]
            signature=re.search(r'(~?\w+)\s*\(',prefix)
            if signature and signature[1] not in (owner[2],'~'+owner[2],'if','for','while','switch','catch'):
                start=cursor+signature.start();opening=clean.index('(',start)
                end=sweep.closing(clean,opening,'(',')')+1
                if access=='public' and end<=at and re.fullmatch(r'\s*(?:(?:const|volatile|override|final)\s*)*',clean[end:at]):
                    stop=sweep.closing(clean,at,'{','}')+1
                    if not re.search(r'(?m)^\s*#',clean[start:stop]):found[owner[2]+'::'+signature[1]].append((start,stop))
            cursor=sweep.closing(clean,at,'{','}')+1
    for method,spans in found.items():
        if method not in result and len(spans)==1:result[method]=spans[0]
    return result


def body_edits(before,after,method):
    old=methods(before);new=methods(after)
    if method not in old or method not in new:raise ValueError('Assigned method missing or ambiguous')
    a,b=old[method];c,d=new[method]
    original=sweep.masked_cpp(before);candidate=sweep.masked_cpp(after)
    brace=original.index('{',a);new_brace=candidate.index('{',c)
    if re.sub(r'\s+','',original[a:brace])!=re.sub(r'\s+','',candidate[c:new_brace]):raise ValueError('Method signature must stay unchanged')
    edits=[[before[a:b],before[a:brace]+after[new_brace:d]]]
    if sweep.apply_edits(before,edits)!=after:raise ValueError('Changes outside the assigned method body')
    return edits

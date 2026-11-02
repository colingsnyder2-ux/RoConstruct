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


def validation_edits(edits):
    """Keep owner-established casts unchanged; never exempt a new or altered cast."""
    result=[]
    for old,new in edits:
        clean=sweep.masked_cpp(old)
        fragments=set()
        for found in re.finditer(r'\breinterpret_cast\s*<',clean):
            close=sweep.closing(clean,clean.index('<',found.start()),'<','>')+1
            opening=close
            while opening<len(clean) and clean[opening].isspace():opening+=1
            if clean[opening:opening+1]!='(':continue
            end=sweep.closing(clean,opening,'(',')')+1
            fragments.add(old[found.start():end])
        for fragment in fragments:
            count=min(old.count(fragment),new.count(fragment))
            old=old.replace(fragment,'native_existing_cast',count)
            new=new.replace(fragment,'native_existing_cast',count)
        result.append([old,new])
    return result


def canonical_edits(native,body,method):
    """Transfer a body across identically typed, named parameters; keep canonical declarations."""
    original=methods(native);returned=methods(body)
    if method not in original or method not in returned:raise ValueError('Missing canonical method')
    a,b=original[method];c,d=returned[method]
    old=sweep.masked_cpp(native);new=sweep.masked_cpp(body)
    brace=old.index('{',a);new_brace=new.index('{',c)
    if re.sub(r'\s+','',old[a:brace])==re.sub(r'\s+','',new[c:new_brace]):return [[native[a:b],native[a:brace]+body[new_brace:d]]]
    def parameters(clean,start):
        opening=clean.index('(',start);end=sweep.closing(clean,opening,'(',')')
        text=clean[opening+1:end].strip()
        if not text or text=='void':return [],end
        if re.search(r'[<>()=\[\]]',text):raise ValueError('Complex parameter adaptation needs owner review')
        result=[]
        for part in text.split(','):
            match=re.fullmatch(r'(.+?)([A-Za-z_]\w*)\s*',part.strip())
            if not match or not match[1].strip():raise ValueError('Named canonical parameters required')
            result.append((re.sub(r'\s+','',match[1]),match[2]))
        return result,end
    left,left_end=parameters(old,a);right,right_end=parameters(new,c)
    if [t for t,_ in left]!=[t for t,_ in right] or re.sub(r'\s+','',old[left_end+1:brace])!=re.sub(r'\s+','',new[right_end+1:new_brace]):raise ValueError('Canonical parameter types/qualifiers differ')
    rename={source:destination for (_,destination),(_,source) in zip(left,right) if source!=destination}
    clean=new[new_brace:d]
    if any(re.search(r'\b'+re.escape(name)+r'\b',clean) for name in set(rename.values())-set(rename)):raise ValueError('Canonical parameter name collides with candidate body')
    expression=body[new_brace:d];edits=[]
    for token in re.finditer(r'\b[A-Za-z_]\w*\b',clean):
        name=token[0];prefix=clean[:token.start()].rstrip()
        if name in rename and not prefix.endswith(('.', '->', '::')):edits.append((token.start(),token.end(),rename[name]))
    for start,end,name in reversed(edits):expression=expression[:start]+name+expression[end:]
    return [[native[a:b],native[a:brace]+expression]]

# Headless BSim query adapted from Ghidra's QueryFunction.py example.
# @category BSim.Python
# @runtime Jython
import json
import os
from ghidra.features.bsim.query import BSimClientFactory, GenSignatures
from ghidra.features.bsim.query.protocol import QueryNearest

args = getScriptArgs()
if len(args) != 3 or currentProgram is None:
    raise ValueError('Expected database URL, function-name substring, new output JSON')
database_url, needle, output = args
if not needle:
    raise ValueError('Function-name substring must not be empty')
if os.path.exists(output):
    raise ValueError('Output already exists: ' + output)
database = BSimClientFactory.buildClient(BSimClientFactory.deriveBSimURL(database_url), False)
if not database.initialize():
    raise ValueError(database.getLastError().message)
results = []
matched_functions = 0
try:
    functions = currentProgram.getFunctionManager().getFunctions(True)
    while functions.hasNext():
        function = functions.next()
        if needle not in function.getName(True):
            continue
        matched_functions += 1
        if matched_functions > 50:
            raise ValueError('More than 50 functions matched; narrow the substring')
        signatures = GenSignatures(False)
        try:
            signatures.setVectorFactory(database.getLSHVectorFactory())
            signatures.openProgram(currentProgram, None, None, None, None, None)
            signatures.scanFunction(function)
            query = QueryNearest()
            query.manage = signatures.getDescriptionManager()
            query.max = 30
            query.thresh = 0.7
            query.signifthresh = 0.0
            response = database.query(query)
            if response is None:
                raise ValueError(database.getLastError().message)
            for group in response.result:
                for note in group:
                    match = note.getFunctionDescription()
                    results.append({'query': str(function.getName(True)),
                                    'executable': str(match.getExecutableRecord().getNameExec()),
                                    'function': str(match.getFunctionName()),
                                    'address': '0x%x' % match.getAddress(),
                                    'similarity': note.getSimilarity(),
                                    'significance': note.getSignificance()})
        finally:
            signatures.dispose()
finally:
    database.close()
if not results:
    raise ValueError('No matching function or database results for: ' + needle)
with open(output, 'w') as stream:
    json.dump({'scope': 'similarity leads only; original analysis may be incomplete',
               'results': results}, stream, indent=2)
print('BSim matches:', len(results))

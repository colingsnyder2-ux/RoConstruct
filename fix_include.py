p = 'rebuild/2008-06/native-headers/v8datamodel/LocalBackpack.h'
s = open(p, encoding='utf-8').read()
s = s.replace('#include "Network/Player.h"', '#include "Network/Player.h"\n#include "Network/Players.h"')
open(p, 'w', encoding='utf-8', newline='\n').write(s)
print('done')
for l in s.splitlines():
    if 'Network' in l and 'include' in l:
        print(l)

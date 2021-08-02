import numpy as np
import scipy.constants as spc
import matplotlib.pyplot as plt
import pandas as pd
from math import log10, floor

def round_sig(x, sig=2):
    return round(x, sig-int(floor(log10(abs(x))))-1)

sig_ch = ['BP21', 'BP23', 'HP17','HP20', 'HP3']
outfile = 'preselection_table.txt'

# read file with preselection results
res = pd.read_table('preselection.txt', delim_whitespace=True, names=('channel', 'N_bef', 'N_aft', 'eff', 'entries_aft'))
res.iloc[:,0] = [str.replace('idm_bg_','') for str in res.iloc[:,0]]
res.iloc[:,0] = [str.replace('idm_hphm_slep_','') for str in res.iloc[:,0]]
res.iloc[:,0] = [str.replace('_1500','') for str in res.iloc[:,0]]


# add a row with the sum of backgrounds
#res.loc['Total bckg.',1:3] = res.iloc[0:9,1:3].sum(axis=0)
tot_bg_row = {'channel':'tot_backg',
              'N_bef':res.iloc[0:9,1].sum(axis=0), 'N_aft':res.iloc[0:9,2].sum(axis=0),
              'eff':round_sig(res.iloc[0:9,2].sum(axis=0)/res.iloc[0:9,1].sum(axis=0)), 'entries_aft':res.iloc[0:9,-1].sum(axis=0) }
res = res.append(tot_bg_row,ignore_index=True)

# add a row with the sig/bg ratios
for i in range(len(res.iloc[9:-1,0])):
    ratio_row = {'channel':'signal/backg. ('+res.iloc[i+9,0]+')',
                 'N_bef':round_sig(res.iloc[i+9,1] / res.iloc[28,1]), 'N_aft':round_sig(res.iloc[i+9,2] / res.iloc[28,2]),
                 'eff':np.NAN, 'entries_aft':np.NAN }
    res = res.append(ratio_row,ignore_index=True)
    #res.loc['signal/backg. ('+sig_ch[i]+')',1:3] = res.iloc[i,1:3] / res.iloc[14,1:3]

print('Preselection results:')
print(res)

### create latex table ###
table = res.drop(columns='entries_aft')
table = table.drop(labels=[45,46],axis=0)
table = table.drop(labels=table.index[35:44],axis=0)
table = table.drop(labels=[29,32,33],axis=0)

table.iloc[:-6,-1] = [round_sig(i) for i in table.iloc[:-6,-1]]   # round efficiencies to 2 significant digits
table.iloc[0:29,1] = [round_sig(i,3) for i in table.iloc[0:29,1]] # round ev. numbers to 3 significant digits
table.iloc[0:29,2] = [round_sig(i,3) for i in table.iloc[0:29,2]] # round ev. numbers to 3 significant digits
# write eff. in %
table.iloc[:-5,-1] = ["{:.2%}".format(i) for i in table.iloc[:-5,-1]]
# add math characters
table.iloc[9:28,0] = '$H^{+}H^{-}$ (' + table.iloc[9:28,0] + ')'
table.iloc[0:9,0] = '$' + table.iloc[0:9,0] + '$'
table.iloc[0:9,0] = [str.replace('l',r'\ell') for str in table.iloc[0:9,0]]
table.iloc[0:9,0] = [str.replace('v',r'\nu') for str in table.iloc[0:9,0]]

#fmt = '%s','%f','%f','%0.2f'
#np.savetxt(outfile, table, fmt=fmt, delimiter=' & ')
np.savetxt('temp.txt', table, fmt='%s', delimiter=' & ')

with open('temp.txt', 'r') as istr:
    with open(outfile, 'w') as ostr:
        for line in istr:
            line = line.replace('nan',' ')
            line = line.replace('.0 ',' ')
            line = line.rstrip('\n') + r' \\ '
            print(line, file=ostr)

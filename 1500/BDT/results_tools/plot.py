import numpy as np
import scipy.constants as spc
import matplotlib.pyplot as plt
import pandas as pd

masses = pd.read_table('masses.txt', delim_whitespace=True, names=('channel', '2m_H+/-','m_Hpm-m_H'))
results = pd.read_table('1.5tev_results_reweighted_simpleMissingP4.txt', delim_whitespace=True, names=('channel', 'Nsig', 'Nbg', 'cut', 'signif', 'sig_eff', 'bg_eff'))
#weighted_results = pd.read_table('1.5tev_results_weighted.txt', delim_whitespace=True, names=('channel', 'Nsig', 'Nbg', 'cut', 'signif', 'sig_eff', 'bg_eff'))

resultsVsMasses = pd.concat( [masses, results['signif']], axis = 1 )
#resultsVsMasses_weighted = pd.concat( [masses, weighted_results['signif']], axis = 1 )

#print(resultsVsMasses_weighted)

np.savetxt(r'./signif-massDiff_1500_reweighted_simpleMissingP4.txt', resultsVsMasses.loc[:,['channel','m_Hpm-m_H','signif']].values, fmt='%s')

#plt.rc('text', usetex=True)
#plt.rc('font', family='serif')

#plt.plot(resultsVsMasses.iloc[:-4,1], resultsVsMasses.iloc[:-4,2], 'o', label = 'off-shell W, 3 TeV')
#plt.plot(resultsVsMasses.iloc[-4:,1], resultsVsMasses.iloc[-4:,2], 'o', label = 'on-shell W, 3 TeV')
plt.plot(resultsVsMasses.iloc[:,1], resultsVsMasses.iloc[:,2], 'o', label = 'reweighted, full-sim missing P4, 3 TeV')
plt.plot(resultsVsMasses_weighted.iloc[:,1], resultsVsMasses_weighted.iloc[:,2], 'o', label = 'different weights, 3 TeV')
#print(data)

plt.xlabel(r'$2m_{H^{\pm}}$ [GeV]', fontsize = 16)
plt.ylabel(r'$S/\sqrt{S+B}$', fontsize = 16)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)

plt.axhline(y=5.0, color = 'r', linewidth = 1)
plt.legend(loc=1, fontsize = 14)


#plt.savefig('./significance_1500.pdf')
plt.show()

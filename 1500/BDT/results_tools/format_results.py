import numpy as np
import scipy.constants as spc
import matplotlib.pyplot as plt
import pandas as pd

masses = pd.read_table('masses.txt', delim_whitespace=True, names=('channel', '2m_H+/-', 'm_Hpm-m_H'))

### all results from delphes with overlay ###
res = pd.read_table('1.5tev_results_reweighted_simpleMissingP4.txt', delim_whitespace=True, names=('channel', 'Nsig', 'Nbg', 'cut', 'signif', 'sig_eff', 'bg_eff'))
resVsMass = masses.merge( res.loc[:,['channel', 'signif']], how='inner', on='channel' )

print('All results with overlay:')
print(resVsMass)
np.savetxt(r'./signif-mass_1500_reweighted_simpleMissingP4.txt', resVsMass.loc[:,['channel','2m_H+/-','signif']].values, fmt='%s')
np.savetxt(r'./signif-massDiff_1500_reweighted_simpleMissingP4.txt', resVsMass.loc[:,['channel','m_Hpm-m_H','signif']].values, fmt='%s')

### single sample results - full sim. vs. delphes with overlay ###
ss_results = pd.read_table('1.5tev_results_singleSample_simpleMissingP4.txt', delim_whitespace=True, names=('channel', 'evt_sig', 'evt_bg', 'cut', 'fast_signif', 'Nsig', 'Nbg', 'sig_eff', 'bg_eff'))
fsres = pd.read_table('1.5tev_fullSimResults_singleSample.txt', delim_whitespace=True, names=('channel', 'evt_sig', 'evt_bg', 'cut', 'full_signif', 'Nsig', 'Nbg', 'sig_eff', 'bg_eff'))
res_ss = masses.merge( ss_results.loc[:,['channel','fast_signif']],
                       how='inner', on='channel' )
res_ss = res_ss.merge( fsres.loc[:,['channel','full_signif']],
                       how='inner', on='channel' )

res_ss['diff'] = res_ss.apply(lambda row: row.fast_signif - row.full_signif, axis=1)
res_ss['ratio'] = res_ss.apply(lambda row: row.full_signif / row.fast_signif, axis=1)

print('Overlay vs. Full Sim.:')
print(res_ss)
np.savetxt(r'./signifDiff-massDiff_fullsim-overlay_singleSampleTrain_simpleMissingP4_1500.txt', res_ss.loc[:,['channel', 'm_Hpm-m_H', 'diff', 'ratio']].values, fmt='%s')
np.savetxt(r'./signif-mass_1500_Overlay_SingleSampleTrain_simpleMissingP4.txt', res_ss.loc[:,['channel', '2m_H+/-', 'fast_signif']].values, fmt='%s')

### single sample results - full sim. vs. pure delphes ###
dres = pd.read_table('1.5tev_pureDelphesResults_singleSample.txt', delim_whitespace=True, names=('channel', 'evt_sig', 'evt_bg', 'cut', 'fast_signif', 'Nsig', 'Nbg', 'sig_eff', 'bg_eff'))
dres_ss = masses.merge( dres.loc[:,['channel','fast_signif']],
                        how='inner', on='channel' )
dres_ss = dres_ss.merge( fsres.loc[:,['channel','full_signif']],
                         how='inner', on='channel' )

dres_ss['diff'] = dres_ss.apply(lambda row: row.fast_signif - row.full_signif, axis=1)
dres_ss['ratio'] = dres_ss.apply(lambda row: row.full_signif / row.fast_signif, axis=1)
print('Pure Delphes vs. Full Sim.:')
print(dres_ss)
np.savetxt(r'./signifDiff-massDiff_fullsim-fastsim_singleSampleTrain_1500.txt', dres_ss.loc[:,['channel', 'm_Hpm-m_H', 'diff', 'ratio']].values, fmt='%s')

### full simulation results ###
fsresVsMass = masses.merge( fsres.loc[:,['channel', 'full_signif']], how='inner', on='channel' )
print('Full Sim. results:')
print(fsresVsMass)
np.savetxt(r'./signif-mass_fullSim1500_SingleSampleTrain.txt', fsresVsMass.loc[:,['channel','2m_H+/-','full_signif']].values, fmt='%s')

### pure delphes results ###
pdresVsMass = masses.merge( dres.loc[:,['channel', 'fast_signif']], how='inner', on='channel' )
print('Pure Delphes results:')
print(pdresVsMass)
np.savetxt(r'./signif-mass_Delphes1500_SingleSampleTrain.txt', pdresVsMass.loc[:,['channel','2m_H+/-','fast_signif']].values, fmt='%s')

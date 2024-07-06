import ROOT

ROOT.gStyle.SetOptStat(0)

input_num = ROOT.TFile('CheckHits_1_0_0_0.root')
input_den = ROOT.TFile('CheckHits_1_1_1_1.root')

canv = ROOT.TCanvas('c', 'c', 800, 800)
canv.Divide(2, 4)

for lay in range(7):
    h_num = input_num.Get(f'zPhi_L{lay}')
    h_den = input_den.Get(f'zPhi_L{lay}')
    h_num.GetZaxis().SetRangeUser(0, 1.5)
    h_num.Divide(h_den)
    pad = canv.cd(lay + 1)
    pad.SetRightMargin(0.18)
    h_num.Draw('colz')

ofile = ROOT.TFile('CheckHitsRatio_1000_1111.root', 'recreate')
ofile.cd()
canv.Write()
#canv.Print('ratio.png')
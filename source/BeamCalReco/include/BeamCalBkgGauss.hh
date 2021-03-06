/**
* @file BeamCalBkgGauss.hh
* @brief File contains manager for BeamCal gaussian background
* @author Andrey Sapronov
* @version 0.0.1
* @date 2015-02-18
*/

#pragma once

#include <string>
#include <vector>

#include "BeamCalBkg.hh"
#include "BCPadEnergies.hh"

class TFile;
class TRandom3;
class TTree;

class BeamCalGeo;

using std::vector;
using std::string;

class BeamCalBkgGauss : public BeamCalBkg {
 public:
  BeamCalBkgGauss(const string &bg_method_name, const BeamCalGeo* BCG);
  ~BeamCalBkgGauss();

 private:
  vector<PadEdepRndPar_t> *m_padParLeft;
  vector<PadEdepRndPar_t> *m_padParRight;

 public:
  void init(vector<string> &bg_files, const int n_bx);

  void getEventBG(BCPadEnergies &peLeft, BCPadEnergies &peRight);

 private:
  void readBackgroundPars(TTree *bg_par_tree, const BCPadEnergies::BeamCalSide_t bc_side);

 public:
  BeamCalBkgGauss(const BeamCalBkgGauss&);
  BeamCalBkgGauss& operator=(const BeamCalBkgGauss&);

};


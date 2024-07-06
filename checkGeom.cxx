void checkGeom(){
  TFile* _file0 = TFile::Open("o2sim_geometry-aligned.root");
  _file0->Get("ccdb_object");
  gGeoManager->CheckOverlaps(0.0001, "f");
  auto list = gGeoManager->GetListOfOverlaps();
  gGeoManager->Export("geometry_overlap.root");

  TFile* _file1 = TFile::Open("geometry_overlap.root");
  _file1->Get("ccdb_object");
  auto listOv = gGeoManager->GetListOfOverlaps();
  std::vector<TGeoVolume*> v_chips;
  for (auto key_ob : *listOv) {
    TGeoOverlap *ov = static_cast<TGeoOverlap*>(key_ob);
    auto first_vol = std::string(ov->GetFirstVolume()->GetName());
    auto second_vol = std::string(ov->GetSecondVolume()->GetName());
    // std::cout << first_vol.data() << "\t" << second_vol.data() << std::endl;
    bool firstVolChip = first_vol.find("ITSUChip") < first_vol.size();
    v_chips.push_back(firstVolChip ? ov->GetFirstVolume() : ov->GetSecondVolume());
  }
  auto it = std::unique(v_chips.begin(), v_chips.end());
  v_chips.resize(std::distance(v_chips.begin(), it));
  std::cout << "Found overlaps = " << v_chips.size() << std::endl;
}
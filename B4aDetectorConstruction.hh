#ifndef B4aDetectorConstruction_h
#define B4aDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4GlobalMagFieldMessenger;

class B4aDetectorMessenger;
class B4aDetectorConstruction;
class G4UserLimits;
class G4Region;
class G4RegionStore;
class G4ProductionCuts;


//extern B4aDetectorConstruction *Kratta_detector;
/// In addition a transverse uniform magnetic field is defined 
/// via G4GlobalMagFieldMessenger class.

class B4aDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    B4aDetectorConstruction();
    virtual ~B4aDetectorConstruction();

  public:
    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();
 B4aDetectorConstruction *myDetector;

  //void SetNpdChoice(G4int wybor)       {npd_choice=wybor;};
  void SetNeumann(G4int Neumann)       {neumann=Neumann;};
  void SetBfwhmX(G4double BfwhmX)      {bfwhmx=BfwhmX;};
  void SetBfwhmY(G4double BfwhmY)      {bfwhmy=BfwhmY;};
  //void SetBtEnergy(G4double BtEnergy)  {bt=BtEnergy;};
  void SetBtEnergy(G4double BtEnergy);
  void SetPz(G4double Pz)              {pz=Pz;};
  void SetPzz(G4double Pzz)            {pzz=Pzz;};
  void SetThetaMin(G4double ThetaMin)  {themin=ThetaMin;};
  void SetThetaMax(G4double ThetaMax)  {themax=ThetaMax;};
  void SetTheta2Min(G4double The2Min)  {themin2=The2Min;};
  void SetTheta2Max(G4double Theta2Max){themax2=Theta2Max;};
  void SetPhiMin(G4double PhiMin)      {fimin=PhiMin;};
  void SetPhiMax(G4double PhiMax)      {fimax=PhiMax;};
  //void SetKinematicsMin(G4double kinMin) {genMin=kinMin*0.001;};
  //void SetKinematicsMax(G4double kinMax) {genMax=kinMax*0.001;};
  void SetParamUpdate() ;  

  //  int    GetNpdChoice()   {return npd_choice;};  
  int    GetNeumann()     {return neumann;};
  double GetBfwhmX()      {return bfwhmx;};
  double GetBfwhmY()      {return bfwhmy;};
  double GetBtEnergy()    {return bt;};
  double GetPz()          {return pz;};
  double GetPzz()         {return pzz;};
  double GetThetaMin()    {return themin;};
  double GetThetaMax()    {return themax;};
  double GetTheta2Min()   {return themin2;};
  double GetTheta2Max()   {return themax2;};
  double GetPhiMin()      {return fimin;};
  double GetPhiMax()      {return fimax;};
  //double GetKinematicsMin() {return genMin;};
  //double GetKinematicsMax() {return genMax;};
  double GetTargetHigh()  {return thigh;};
  double GetTargetXplace(){return tXplace;};
  double GetTargetYplace(){return tYplace;};
  double GetTargetZplace(){return tZplace;};

  //void SetTargetIs(G4int TargetIs)                 { targetis = TargetIs;};
  void SetTargetOutRadius(G4double HoleOut)        { toutrad = HoleOut; };
  void SetTargetHigh(G4double TargetHigh)          { thigh = TargetHigh; };

  // Target placement
  void SetTargetXplace(G4double TargetXplace)      { tXplace = TargetXplace; };
  void SetTargetYplace(G4double TargetYplace)      { tYplace = TargetYplace; };
  void SetTargetZplace(G4double TargetZplace)      { tZplace = TargetZplace; };

    // get methods
    //
    //const G4VPhysicalVolume* GetAbsorberPV() const;
    //const G4VPhysicalVolume* GetGapPV() const;
     
  private:

  //G4int targetis;
  G4double toutrad,  tfroutrad, thigh, tXplace, tYplace, tZplace;
  G4int aj1bx, aj1by, ajbz, aj1theta, aj2theta, aj1phi, aj2phi, aj1ekin, aja10,
    aja20, aju, ajcs1, ajcs02, aj1r1, aj1r2, npd_choice, neumann, n_elastic;
  G4double bfwhmx, bfwhmy, bt, pz, pzz, themin, themax, themin2,
    themax2, fimin, fimax, genMin, genMax;

  G4UserLimits *fStepLimit ;

  G4Region *fTargetRegion;
  G4Region *fGraRegion;
  G4Region *fPDdeadRRegion;
  G4Region *fPDdeadFRegion;
  G4Region *fPDactiveRegion;
  G4Region *fPDRegion;
  G4Region *fKrWrRegion;
  G4Region *fKrWinRegion;

    // methods
    //
    void DefineMaterials();
    G4VPhysicalVolume* DefineVolumes();
  
    // data members
    //
    static G4ThreadLocal G4GlobalMagFieldMessenger*  fMagFieldMessenger; 
                                      // magnetic field messenger
     
  //G4VPhysicalVolume*   fAbsorberPV; // the absorber physical volume
  //G4VPhysicalVolume*   fGapPV;      // the gap physical volume
    B4aDetectorMessenger *detectorMessenger;
    
    G4bool  fCheckOverlaps; // option to activate checking of volumes overlaps
};

// inline functions

//inline const G4VPhysicalVolume* B4aDetectorConstruction::GetAbsorberPV() const { 
//return fAbsorberPV; 
//}

//inline const G4VPhysicalVolume* B4aDetectorConstruction::GetGapPV() const  { 
//return fGapPV; 
//}
     



#endif


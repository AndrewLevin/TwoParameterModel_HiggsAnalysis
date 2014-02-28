/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Your description goes here... 

#include "Riostream.h" 

#include "HiggsAnalysis/CombinedLimit/interface/RooTwoParameterModelScaling.h" 

#include <math.h> 
#include "TMath.h" 
#include "RooFormulaVar.h"
#include "RooRealVar.h"
#include "RooFit.h"

#include "TFile.h"

ClassImpUnique(RooTwoParameterModelScaling,MAGICWORDOFSOMESORT) 


  RooTwoParameterModelScaling::RooTwoParameterModelScaling() :
    P(0)
{
  initialize_histograms();
}

RooTwoParameterModelScaling::RooTwoParameterModelScaling(const char *name, 
					     const char *title,
					     RooAbsReal& _param1,
					     RooAbsReal& _param2,
					     const char * FILENAME, 
					     const char * NAME) :
   RooAbsReal(name,title),
   param1("param1","param1",this,_param1),
   param2("param2","param2",this,_param2),
   th2d_filename(FILENAME),
   th2d_name(NAME),
   P(0)
{ 
  initialize_histograms();

} 

void RooTwoParameterModelScaling::read_histograms() const
{

  TFile * f = new TFile(th2d_filename);

  assert(f);
  assert(P);

  P[0] = (TH2D*)f->Get(th2d_name);

  assert(P[0]);

}

void RooTwoParameterModelScaling::initialize_histograms() {

  P = new TH2D*[1]();

}


RooTwoParameterModelScaling::
RooTwoParameterModelScaling(const RooTwoParameterModelScaling& other, 
		      const char* name) :  
  RooAbsReal(other,name),
  param1("param1",this,other.param1),
  param2("param2",this,other.param2),
  th2d_filename(other.th2d_filename),
  th2d_name(other.th2d_name),
  P(0)
{ 
  initialize_histograms();
} 


RooTwoParameterModelScaling::~RooTwoParameterModelScaling() {
  
  if (P[0])
    delete P[0];

  delete [] P;
}

Double_t RooTwoParameterModelScaling::evaluate() const 
{ 

  double v1(param1), v2(param2);

  if (!P || !P[0]) {
    std::cout << "P not initialized ---> initializing it" << std::endl;
    read_histograms();
  }

  if (v1 < P[0]->GetXaxis()->GetXmin())
    v1 = P[0]->GetXaxis()->GetXmin();
  if (v1 > P[0]->GetXaxis()->GetXmax())
    v1 = P[0]->GetXaxis()->GetXmax();
  if (v2 < P[0]->GetYaxis()->GetXmin())
    v2 = P[0]->GetYaxis()->GetXmin();
  if (v2 > P[0]->GetYaxis()->GetXmax())
    v2 = P[0]->GetYaxis()->GetXmax();

  return P[0]->Interpolate(v1,v2);
}

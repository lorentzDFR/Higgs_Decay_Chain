//app.cc

//to compile and link the executable:
//g++ -o app app.cc Particle.cc CompositeParticle.cc Vector3D.cc `$ROOTSYS/bin/root-config --libs --cflags`


#include "Vector3D.h"
#include "Particle.h"
#include "CompositeParticle.h"


#include "TRandom3.h"
#include "TH1F.h"
#include "TCanvas.h"

int main(){

  TRandom3 R(0);
  int ndecay = 10000;
  

  CompositeParticle h1("higgs1", 35,125.,0);

  Particle g1("photon1", 22,0.,0);
  Particle g2("photon2", 22,0.,0);

  h1.add(&g1);
  h1.add(&g2);

  CompositeParticle h2("higgs2", 35, 125.,0);

  CompositeParticle z1("z1", 2, 91.,0);
  CompositeParticle z2("z2", 3, 31.,0);

  Particle ele("electron", 11, 0.000511,-1);
  Particle pos("positron", -11, 0.000511,1);
  Particle mup("muon+", -13, 0.1056,1);
  Particle mum("mu-", 13, 0.1056, -1);

  h2.add(&z1);
  h2.add(&z2);
  z1.add(&ele);
  z1.add(&pos);
  z2.add(&mup);
  z2.add(&mum);
  

  TH1F hist1("hist1","Distribution of opening angle between photons", 150, 0.,M_PI);
  double alfa;
  
  for(int i = 0; i<ndecay; i++){

    h1.setMomentum( Vector3D(0,0,R.Gaus(50,10) ) );
    
    //scalar product between momenta
    
    alfa = acos(( g1.getMomentum() * g2.getMomentum() ) / ( g1.getMomentum().mod() * g2.getMomentum().mod() )  );

    hist1.Fill(alfa);
  }


  TCanvas canv("canv","canvas", 1280,1024);

  hist1.GetXaxis()->SetTitle("Distribution of opening angle [Rad]");
  hist1.GetYaxis()->SetTitle("#events");
  hist1.Draw();
  canv.SaveAs("Alfa distribution Higgs decay");

  
  TH1F hist2("hist2","Distribution of Momenta [GeV] for electrons", 100, 0.,150.);
  TH1F hist3("hist3","Distribution of Momenta [GeV] for positrons", 100, 0.,150.);
  TH1F hist4("hist4","Distribution of Momenta [GeV] for mu+", 100, 0.,150.);
  TH1F hist5("hist5","Distribution of Momenta [GeV] for mu-", 100, 0.,150.);

  canv.Clear();
  canv.Divide(2,2);

  for(int i=0; i<ndecay; i++){

  h2.setMomentum( Vector3D(0,0, R.Gaus(100,20)  ) );

    hist2.Fill(ele.getMomentum().mod());
    hist3.Fill(pos.getMomentum().mod());
    hist4.Fill(mup.getMomentum().mod());
    hist5.Fill(mum.getMomentum().mod());

  
  }
  canv.cd(1);
  hist2.Draw();
  canv.cd(2);
  hist3.Draw();
  canv.cd(3);
  hist4.Draw();
  canv.cd(4);
  hist5.Draw();

  canv.SaveAs("Distributions of momenta for decay products");

}

#include "CompositeParticle.h"
#include<iostream>
#include<list>
#include<math.h>

//Root header files
#include "TRandom3.h"
#include "TLorentzVector.h"

CompositeParticle::CompositeParticle(const string& name, const int& id, const double& mass, const int& charge) : Particle(name,id,mass,charge){}


void CompositeParticle::add(Particle* p){

  particles_.push_back(p);

}


std::ostream& operator<<(ostream& os, const CompositeParticle& p){

  os<< "Composite: "<<p.getName()<<"\t id: "<<p.getId()<<"\t #particles: "<<p.particles_.size()<< "\t c.m. momentum: "<<p.getMomentum();

  return os;
}

void CompositeParticle::setMomentum(const Vector3D& threeMomentum){


  
  if(particles_.size() == 2){

    Particle::setMomentum(threeMomentum);
    Particle p1 = *(particles_.at(0) );
    Particle p2 = *(particles_.at(1) );
    double m1 = p1.getMass();
    double m2 = p2.getMass();
    double p,p1x,p1y,p1z,p2x,p2y,p2z,theta,phi;

    
    
    p = sqrt( pow(getMass(),4) + pow(m1*m1 - m2*m2, 2) - 2*getMass()*getMass() * (m1*m1 + m2*m2 ) ) / (2*getMass());

    
    TRandom3* gen = new TRandom3();
    gen->SetSeed(0);


    
    theta = gen->Uniform(0,2*M_PI);
    phi = gen->Uniform(0,M_PI);
    
    p1x = p*sin(phi)*cos(theta);
    p1y = p*sin(phi)*sin(theta);
    p1z = p*cos(phi);
 
    p2x=-p1x;
    p2y=-p1y;
    p2z=-p1z;
    
    //cout<<p<<"  "<<p1x<<"   "<<p1y<<"    "<<p1z<<endl;
    //cout<<p<<"  "<<p2x<<"   "<<p2y<<"    "<<p2z<<endl;
    


    //Boosting

    double E,E1,E2, bx,by,bz;
    double Px,Py,Pz;
    Px = threeMomentum.getX();
    Py = threeMomentum.getY();
    Pz = threeMomentum.getZ();
  
    E = sqrt( getMass()*getMass() + getMomentum()*getMomentum() );

    bx = Px/E;
    by = Py/E;
    bz = Pz/E;

    E1 = sqrt(m1*m1+p*p);
    E2 = sqrt(m2*m2+p*p);

    //cout<<"Energie singole: "<<E1<<"   "<<E2;
    
    TLorentzVector F(Px,Py,Pz,E);
    TLorentzVector S1(p1x,p1y,p1z,E1);
    TLorentzVector S2(p2x,p2y,p2z,E2);
    S1.Boost(bx,by,bz);
    S2.Boost(bx,by,bz);
    
    (particles_.at(0))->setMomentum( Vector3D(S1.Px(),S1.Py(),S1.Pz()) );
    (particles_.at(1))->setMomentum( Vector3D(S2.Px(),S2.Py(),S2.Pz()) );

    //cout<<" beta cdm: "<<bx<<"    "<<by<<"   "<<bz<<endl;;
    //cout<<" quadrimomento 1 lab "<<S1.Px()<<"    "<<S1.Py()<<"   "<<S1.Pz()<<"    "<<S1.E()<<endl;
    //cout<<" quadrimomento 2 lab "<<S2.Px()<<"    "<<S2.Py()<<"   "<<S2.Pz()<<"    "<<S2.E()<<endl;
    

    //checking invariant mass

    //cout<<sqrt(pow(S1.E()+S2.E(),2) -pow(  ((particles_.at(0))->getMomentum() +(particles_.at(1))->getMomentum()).mod(), 2  )  ) <<endl;
    

    
      
  }else{
    
    std::cout<<"2 body decay not possible, #particles different from 2"<<std::endl;
    std::exit(EXIT_FAILURE);

    
  }
  

}

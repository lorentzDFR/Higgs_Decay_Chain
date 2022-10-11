#include "Particle.h"

Particle::Particle(const string& name, const int& id, const double& mass, const int& charge, const Vector3D& threeMomentum){

  name_ = name;
  id_ = id;
  mass_ = mass;
  charge_ = charge;
  threeMomentum_ = threeMomentum;
}


void Particle::setName(const string& name){

  name_ = name;
}

void Particle::setId(const int& id){

  id_ = id;
}

void Particle::setMass(const double& mass){

  mass_ = mass;
}

void Particle::setCharge(const double& charge){

  charge_ = charge;
}

void Particle::setMomentum(const Vector3D& threeMomentum){

  threeMomentum_ = threeMomentum;
}

ostream& operator<<(ostream& os, const Particle& p){

  os << "Particle: "<<p.getName()<<"\t id: "<<p.getId()<<"\t   mass: "<<p.getMass()<<" GeV"<<"\t  charge: "<<p.getCharge()<<"\tMomentum "<<p.getMomentum();

  return os;
}

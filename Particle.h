#ifndef Particle_h
#define Particle_h

#include "Vector3D.h"
#include<iostream>
#include<string>

class Particle{
  
 public:
  
  Particle(const string& name, const int& id=0, const double& mass=0, const int& charge=0, const Vector3D& threeMomentum = 0);
  
  void setName(const string& name);
  void setId(const int& id);
  void setMass(const double& mass);
  void setCharge(const double& charge);

  virtual void setMomentum(const Vector3D& threeMomentum);
  
  string getName() const {return name_;}
  int getId() const {return id_;}
  double getMass() const {return mass_;}
  double getCharge() const {return charge_;}
  Vector3D getMomentum() const {return threeMomentum_;}

  friend ostream& operator<<(ostream& os, const Particle& p);
  
 private:

  string name_;
  int id_;
  double mass_;
  double charge_;
  Vector3D threeMomentum_;
  
  
};



#endif


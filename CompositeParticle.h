#ifndef CompositeParticle_h
#define CompositeParticle_h

#include "Particle.h"
#include<vector>

class CompositeParticle : public Particle{

 public:

  CompositeParticle(const string& name, const int& id, const double& mass, const int& charge);

  void add(Particle* p);

  virtual void setMomentum(const Vector3D& threeMomentum);

  friend ostream& operator<<(ostream& os, const CompositeParticle& p);

 private:

  vector<Particle*> particles_;
  
  
};


#endif

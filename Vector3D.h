#ifndef Vector3D_h
#define Vector3D_h
#include<iostream>

using namespace std;

class Vector3D{
  
 public:
  Vector3D(const double& x = 0,const  double& y = 0,const  double& z = 0);
  Vector3D(const Vector3D& vec);

  double mod() const;
  double getX() const;
  double getY() const;
  double getZ() const;

  //void setX(double x);
  //void setY(double y);
  //void setZ(double z);
  //double distance(const Vector3D& vec) const;
  
  const Vector3D& operator=(const Vector3D& rhs);
  const Vector3D& operator+=(const Vector3D& rhs);
  Vector3D operator+(const Vector3D& rhs) const;
  Vector3D operator-(const Vector3D& rhs) const;
  Vector3D operator*(const double& rhs) const;// vec*double
  double operator*(const Vector3D& rhs) const;// dot product
  Vector3D operatorX(const Vector3D& rhs) const;// cross product
  Vector3D operator/(const double& rhs) const;// vec / scalar
  
  
  friend Vector3D operator*(double lhs, const Vector3D& rhs);//  double*vec
  friend ostream& operator<<(ostream& os, const Vector3D& rhs);
  
 private:

  double v_[3];

};

#endif

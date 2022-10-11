#include "Vector3D.h"
#include<iostream>
#include<math.h>
Vector3D::Vector3D(const double& x,const  double& y,const double& z){

  v_[0] = x;
  v_[1] = y;
  v_[2] = z;
}

Vector3D::Vector3D(const Vector3D& vec){


  v_[0] = vec.v_[0];
  v_[1] = vec.v_[1];
  v_[2] = vec.v_[2];
}

double Vector3D::mod() const{

  double module;
  module = sqrt(v_[0]*v_[0] +  v_[1]*v_[1]  + v_[2]*v_[2]);

  return module;
}

double Vector3D::getX() const{

  return v_[0];
}

double Vector3D::getY() const{

  return v_[1];
}

double Vector3D::getZ() const{

  return v_[2];
}

const Vector3D& Vector3D::operator=(const Vector3D& rhs){

  v_[0] = rhs.v_[0];
  v_[1] = rhs.v_[1];
  v_[2] = rhs.v_[2];

  return *this;
}

const Vector3D& Vector3D::operator+=(const Vector3D& rhs){

  v_[0] = v_[0] + rhs.v_[0];
  v_[1] = v_[1] + rhs.v_[1];
  v_[2] = v_[2] + rhs.v_[2];

  return *this;
}

Vector3D Vector3D::operator+(const Vector3D& rhs) const{
  
  Vector3D vec;
  
  vec.v_[0] = v_[0] + rhs.v_[0];
  vec.v_[1] = v_[1] + rhs.v_[1];
  vec.v_[2] = v_[2] + rhs.v_[2];
  return vec;
}

Vector3D Vector3D::operator-(const Vector3D& rhs) const{
  
  Vector3D vec;
  
  vec.v_[0] = v_[0] - rhs.v_[0];
  vec.v_[1] = v_[1] - rhs.v_[1];
  vec.v_[2] = v_[2] - rhs.v_[2];
  return vec;
}

Vector3D Vector3D::operator*(const double& rhs) const{

  Vector3D prod;

  prod.v_[0] = v_[0]*rhs;
  prod.v_[1] = v_[1]*rhs;
  prod.v_[2] = v_[2]*rhs;
  return prod;
}

double Vector3D::operator*(const Vector3D& rhs) const{

  double dot;

  dot = v_[0]*rhs.v_[0] + v_[1]*rhs.v_[1] + v_[2]*rhs.v_[2];
  return dot;
}
  
Vector3D Vector3D::operatorX(const Vector3D& rhs) const{

  Vector3D cross;
  
  cross.v_[0] = v_[1]*rhs.v_[2] - v_[2]*rhs.v_[1];
  cross.v_[1] = v_[2]*rhs.v_[0] - v_[0]*rhs.v_[2];
  cross.v_[2] = v_[0]*rhs.v_[1] - v_[1]*rhs.v_[0];
  return cross;
}

Vector3D Vector3D::operator/(const double& rhs) const{
  
   Vector3D div;

  div.v_[0] = v_[0]/rhs;
  div.v_[1] = v_[1]/rhs;
  div.v_[2] = v_[2]/rhs;
  return div;
}

Vector3D operator*(double lhs, const Vector3D& rhs){
  
  Vector3D prod;

  prod.v_[0] = lhs*rhs.v_[0];
  prod.v_[1] = lhs*rhs.v_[1];
  prod.v_[2] = lhs*rhs.v_[2];
  return prod;
}

std::ostream& operator<<(std::ostream& os, const Vector3D& rhs){

  using namespace std;
  os << "("<< rhs.v_[0] <<","<<rhs.v_[1]<<","<<rhs.v_[2]<<")"<<endl;

  return os;
}

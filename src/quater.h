// -*- mode:C++ ; compile-command: "g++ -I.. -I../include -g -c quater.cc" -*-
/*
 *  Copyright (C) 2001 B. Parisse, Institut Fourier, 38402 St Martin d'Heres
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef _GIAC_QUATER_H
#define _GIAC_QUATER_H
#include "first.h"
#include "gen.h"
#include <string>

#ifndef NO_NAMESPACE_GIAC
namespace giac {
#endif // ndef NO_NAMESPACE_GIAC
  
  extern const std::string _quaternion_s;
  extern unary_function_ptr at_quaternion; // user-level quaternion constructor
  class quaternion : public gen_user {
  public:
    gen r,i,j,k;
    virtual gen_user * memory_alloc() const { 
      quaternion * ptr= new quaternion(*this);
      return dynamic_cast<gen_user *>(ptr); 
    }
    virtual void copy_to (gen_user * g) const { 
      quaternion * q=dynamic_cast<quaternion *> (g);
      q->r=r;
      q->i=i;
      q->j=j;
      q->k=k;
    }
    virtual void memory_free(gen_user * ptr){
      delete(dynamic_cast<quaternion *>(ptr));
    }
    quaternion(const quaternion & q):r(q.r),i(q.i),j(q.j),k(q.k){};
    quaternion(const gen & myr,const gen & myi,const gen & myj,const gen & myk):r(myr),i(myi),j(myj),k(myk) {};
    quaternion():r(zero),i(zero),j(zero),k(zero) {};
    quaternion(const gen & g);
    virtual gen operator + (const gen & g) const { 
      quaternion q(g);
      return quaternion(r+q.r,i+q.i,j+q.j,k+q.k);
    }
    virtual gen operator - (const gen & g) const { 
      quaternion q(g);
      return quaternion(r-q.r,i-q.i,j-q.j,k-q.k);
    }
    virtual std::string print (GIAC_CONTEXT) const ;
  };

  class galois_field : public gen_user {
  public:
    gen p; // F_p^m, characteristic of the field
    gen P; // minimal irreducible polynomial of degree m, as vector
    gen x; // the name of the variable for construction
    gen a; // value as a vector polynomial or undef (whole field)
    virtual gen_user * memory_alloc() const { 
      galois_field * ptr= new galois_field(*this);
      return ptr; 
    }
    virtual void copy_to (gen_user * g) const { 
      galois_field * q=dynamic_cast<galois_field *> (g);
      q->p=p;
      q->P=P;
      q->x=x;
      q->a=a;
    }
    virtual void memory_free(gen_user * ptr){
      delete(dynamic_cast<galois_field *>(ptr));
    }
    galois_field(const galois_field & q);
    galois_field(const gen p_,const gen & P_,const gen & x_,const gen & a_);
    galois_field(const gen & g);
    void reduce(); // reduce a
    virtual gen operator + (const gen & g) const;
    virtual gen operator - (const gen & g) const;
    virtual gen operator - () const;
    virtual gen operator * (const gen & g) const;
    virtual gen inv () const ;
    virtual std::string print (GIAC_CONTEXT) const ;
    virtual bool operator == (const gen &) const ;
    virtual bool is_zero() const;
    virtual bool is_one() const;
    virtual bool is_minus_one() const;
    virtual gen operator () (const gen &,GIAC_CONTEXT) const;
    virtual gen operator [] (const gen &) ;
    virtual gen operator > (const gen & g) const;
    virtual gen operator < (const gen & g) const;
    virtual gen operator >= (const gen & g) const;
    virtual gen operator <= (const gen & g) const;
    virtual gen gcd (const gen &) const { return plus_one;}    
    virtual gen gcd (const gen_user & a) const { return plus_one; }
    virtual void polygcd (const polynome &,const polynome &,polynome &) const ;
    virtual gen makegen(int i) const ;
    virtual void polyfactor (const polynome & p,factorization & f) const ;
    virtual gen conj(GIAC_CONTEXT) { return *this;}
    virtual gen re(GIAC_CONTEXT) { return *this;}
    virtual gen im(GIAC_CONTEXT) {  return 0;}
  };

#ifndef NO_NAMESPACE_GIAC
} // namespace giac
#endif // ndef NO_NAMESPACE_GIAC

#endif // _GIAC_QUATER_H

// -*- mode:C++ ; compile-command: "g++ -I.. -g -c sym2poly.cc" -*-
/*
 *  Copyright (C) 2000 B. Parisse, Institut Fourier, 38402 St Martin d'Heres
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
#ifndef _GIAC_SYM2POLY_H_
#define _GIAC_SYM2POLY_H_
#include "first.h"
#include <vector>

#include "poly.h"
#include "gen.h"
#include "identificateur.h"
#include "symbolic.h"
#include "gausspol.h"
#include "series.h"

#ifndef NO_NAMESPACE_GIAC
namespace giac {
#endif // ndef NO_NAMESPACE_GIAC

  class unary_function_ptr;
  // high-level fonctions on gen
  gen ratnormal(const gen & e);
  // gen normal(const gen & e); // rational simplifications
  gen normal(const gen & e,GIAC_CONTEXT); // rational simplifications
  gen normal(const gen & e,bool distribute_div,GIAC_CONTEXT);
  gen normalize_sqrt(const gen & e,GIAC_CONTEXT);

  extern unary_function_ptr at_normal ;
  symbolic symb_normal(const gen & args);

  gen simplify3(gen & n,gen & d);
  gen recursive_normal(const gen & e,GIAC_CONTEXT);  
  gen recursive_normal(const gen & e,bool distribute_div,GIAC_CONTEXT);
  gen _non_recursive_normal(const gen & args);
  extern unary_function_ptr at_non_recursive_normal ;
  symbolic symb_non_recursive_normal(const gen & args);

  gen rationalgcd(const gen & a, const gen & b);

  gen factor(const gen & e,bool withsqrt,GIAC_CONTEXT); // full factorization (alg ext)
  gen ratfactor(const gen & e,bool withsqrt,GIAC_CONTEXT); // full factorization (rat)
  gen factor(const gen & e,const identificateur & x,bool withsqrt,GIAC_CONTEXT); // factorization w.r.t. x
  gen factor(const gen & e,const gen & f,bool withsqrt,GIAC_CONTEXT);
  gen _factor(const gen & args,GIAC_CONTEXT);
  extern unary_function_ptr at_factor ;
  gen _collect(const gen & args,GIAC_CONTEXT);
  extern unary_function_ptr at_collect ;
  symbolic symb_factor(const gen & args);

  // partial fraction de_VECT.
  gen partfrac(const gen & e,const vecteur & l,bool withsqrt,GIAC_CONTEXT);
  gen partfrac(const gen & e,bool withsqrt,GIAC_CONTEXT); 
  gen partfrac(const gen & e,const identificateur & x,bool withsqrt,GIAC_CONTEXT); 
  gen partfrac(const gen & e,const gen & f,bool withsqrt,GIAC_CONTEXT);
  gen _partfrac(const gen & args,GIAC_CONTEXT);
  extern unary_function_ptr at_partfrac ;
  symbolic symb_partfrac(const gen & args);

  gen _resultant(const gen & args,GIAC_CONTEXT);
  extern unary_function_ptr at_resultant ;
  symbolic symb_resultant(const gen & args);
  
  // reading arguments from the command line
  void readargs(int ARGC, char *ARGV[],const vecteur & l,vecteur & args,GIAC_CONTEXT); 
  void readargs_from_stream(std::istream & inf,vecteur & args,vecteur & l,GIAC_CONTEXT);
  gen read1arg_from_stream(std::istream & inf,vecteur & l,GIAC_CONTEXT);

  // return position of expression in vecteur l, 0 if not found
  int equalposcomp(const vecteur & l,const gen & e);
  // add expression to list of variables
  void addtolvar(const gen & e, vecteur & l);
  // find list of variables of an expression and set tensor_dim to lvar size
  vecteur lvar(const gen & e); 
  gen symb_lvar(const gen & e);
  extern unary_function_ptr at_lvar;
  void lvar(const vecteur & v,vecteur & l);
  void lvar(const sparse_poly1 & p,vecteur & l);
  void lvar(const gen & e,vecteur & l);
  // Vars for algebraic extension
  // Format is a matrice, each line is a vecteur of names/expressions
  // Each line corresponds to an alg extension over at least one new variable
  // The first line corresponds to other names/expressions not embedded
  // in an algebraic extension, it might be empty
  void alg_lvar(const gen & e,matrice & m);
  matrice alg_lvar(const gen & e);
  void alg_lvar(const sparse_poly1 & p,vecteur & l);
  gen symb_algvar(const gen & e);
  extern unary_function_ptr at_algvar;

  vecteur cdr_VECT(const vecteur & l);

  vecteur divisor(const gen & n);
  // fractions, see fration.h for other functions
      // fraction pow(const _FRAC & p,const gen & n);

  void evident(polynome & p,factorization & f);

  // symbolic to tensor
  fraction sym2r(const gen & e, const vecteur & l,GIAC_CONTEXT);
  // return true if num and den are totally converted to internal format
  bool sym2r (const gen &e,const vecteur &l,const vecteur & lv, const vecteur & lvnum,const vecteur & lvden, int l_size, gen & num,gen & den,GIAC_CONTEXT);
  bool sym2r (const gen &e,const vecteur &l, int l_size, gen & num,gen & den,GIAC_CONTEXT);
      // conversion to internal form
  gen e2r(const gen & e,const vecteur & l,GIAC_CONTEXT); 
  extern unary_function_ptr at_e2r ;
  symbolic symb_e2r(const gen & arg1, const gen & arg2);
  void fxnd(const gen & e,gen & num, gen & den);
  // fraction / x -> fraction of vecteur
  gen e2r(const gen & e,const gen & x,GIAC_CONTEXT);
  gen _e2r(const gen & args,GIAC_CONTEXT);

  // monomial and tensor to symbolic
  gen r2sym(const gen & e,const index_m & i,const vecteur & l,GIAC_CONTEXT);
  gen r2sym(const polynome & p, const vecteur & l,GIAC_CONTEXT);
      // back conversion
  gen r2sym(const gen & p, const vecteur & l,GIAC_CONTEXT);
  gen r2e(const gen & p,const vecteur & l,GIAC_CONTEXT);
  // fraction of vecteur -> fraction / x
  gen r2e(const gen & r,const gen & x,GIAC_CONTEXT);
  gen _r2e(const gen & args,GIAC_CONTEXT);
  extern unary_function_ptr at_r2e ;
  symbolic symb_r2e(const gen & arg1,const gen &arg2);
  
  gen r2sym(const fraction & f, const vecteur & l,GIAC_CONTEXT);
  gen r2sym(const std::vector< pf<gen> > & pfde_VECT,const vecteur & l,GIAC_CONTEXT);

  void dbgprint(const polynome &p);
  void dbgprint(const gen & e);

#ifndef NO_NAMESPACE_GIAC
} // namespace giac
#endif // ndef NO_NAMESPACE_GIAC

#endif // _GIAC_SYM2POLY_H_

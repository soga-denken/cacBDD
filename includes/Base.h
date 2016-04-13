/*****************************************************************************
Copyright (c) 2012 - 2013, The Board of Trustees of the University of Beijing Technology and
the University of Griffith.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the
  above copyright notice, this list of conditions
  and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the University of Beijing Technology and
  the University of Griffith nor the names of its contributors 
  may be used to endorse or promote products derived from this
  software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

/*****************************************************************************
written by
   Guanfeng Lv, last updated 10/26/2012
*****************************************************************************/

#pragma once

// replace this macro with std::min, std::max
#include<algorithm>
//#define Max(a,b) ((a > b)?a:b)
//#define Min(a,b) ((a < b)?a:b)
//-------------------------------------

namespace cacBDD
{
	const int ONE_MILLION = 1048576;
	//-------------------------------------
	typedef int DD;

	//#define ADDR(k)      (k & 0x7FFFFFFF)
	// if not template, then compiler error
	template<class T>
	T ADDR(T k)
	{
		return k & 0x7FFFFFFF;
	}


	//#define ISCOMP(A)    (A & 0x80000000) 
	// if not template, then compiler error
	template<class T>
	T ISCOMP(T A)
	{
		return A & 0x80000000;
	}
	//-------------------------------------
	//#define EXIST         0x80000001
	//#define RESTRICT      0x80000002
	//#define AND           0x80000003
	//#define XOR           0x80000004
	//#define OP_MAX_VALUE  0x00000010
	const int EXIST = 0x80000001;
	const int RESTRICT = 0x80000002;
	const int AND = 0x80000003;
	const int XOR = 0x80000004;
	const int OP_MAX_VALUE = 0x00000010;
	//-------------------------------------
	//#define BDD_ITE                 0x02  
	//#define BDD_AND_ABSTRACT        0x06  
	//#define BDD_XOR_EXIST_ABSTRACT	0x0a  
	//#define BDD_COMPOSE_RECUR       0x0e  
	//#define BDD_ITE_CONSTANT        0x22

	const int BDD_ITE                = 0x02;
	const int BDD_AND_ABSTRACT       = 0x06;
	const int BDD_XOR_EXIST_ABSTRACT = 0x0a;
	const int BDD_COMPOSE_RECUR      = 0x0e;
	const int BDD_ITE_CONSTANT       = 0x22;

	//-------------------------------------
	// conflict with CUDD, so modify this
	//#define DD_P1 12582917
	//#define DD_P2 4256249
	//#define DD_P3 741457
	const int _DD_P1 = 12582917;
	const int _DD_P2 = 4256249;
	const int _DD_P3 = 741457;
	//-------------------------------------
	//#define CACHE_DYN 0
	//#define CACHE_FIX 1
	//#define CACHE_OLD 2

	const int CACHE_DYN = 0;
	const int CACHE_FIX = 1;
	const int CACHE_OLD = 2;
	//=====================================

	//#define Hash3(o,f,g,s) (((((unsigned)(unsigned long)(f) + (unsigned)(unsigned long)(o)) * DD_P1 + (unsigned)(unsigned long)(g)) * DD_P2) >> (s))
	// if not template, then compiler error
	template<class op, class T>
	unsigned int Hash3(op o, T f, T g, int s)
	{
		return (((((unsigned)(unsigned long)(f)+(unsigned)(unsigned long)(o)) * _DD_P1 + (unsigned)(unsigned long)(g)) * _DD_P2) >> (s));
	}

	//#define Hash2(f,g,s) ((((unsigned)(unsigned long)(f) * DD_P1 + (unsigned)(unsigned long)(g)) * DD_P2) >> (s))
	// if not template, then compiler error
	template<class T>
	unsigned int Hash2(T f, T g, int s)
	{
		return ((((unsigned)(unsigned long)(f)* _DD_P1 + (unsigned)(unsigned long)(g)) * _DD_P2) >> (s));
	}
}

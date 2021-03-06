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

#include<DdNode.h>

namespace cacBDD
{
	class XManager;

	class CTableNode {
	public:
		DD A;
		DD B;
		DD C;
		DD R;
		CTableNode() :A(0), B(0), C(0), R(0) {};
		void SetValue(int a, int b, int c, int r) { A = a; B = b; C = c; R = r; };
	};

	class XCTable {
	private:
		friend class XManager;
		XManager *mgr;
		int count;
		int shiftSize;

		CTableNode *items;
		int toAddCount;

		long long findCount;
		long long foundedCount;
		long long missCount; //for cudd reward cache resize
		void Refresh();

	public:
		XCTable(XManager *manager, int vBitCount);
		~XCTable();
		void Clear();

		void  Insert(DD A, DD B, DD C, DD tmp);
		bool  Find(DD A, DD B, DD C, DD &r);

		void  size_inc(int addCount);
		void  Expand(bool isInc = true);
		int   Count() { return count; }
		double HitRate() { return 1.0 * foundedCount / (findCount + 1); }
	};
}

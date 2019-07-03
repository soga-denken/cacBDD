
#pragma once

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>

namespace cacBDD
{

	class XFunction {
	public:
		static float  format_float(float v, int dotCnt)
		{
			if (dotCnt > 6) dotCnt = 6;

			float k = pow(10.0f, dotCnt);
			float i = floor(v * k) / k;
			return i;
		}

		static double  format_double(double v, int dotCnt)
		{
			if (dotCnt > 6) dotCnt = 6;

			double k = pow(10.0f, dotCnt);
			double i = floor(v * k) / k;
			return i;
		}

		static std::string Format(int v, int outlen)
		{
			char buf[50];
			memset(buf, 0, 50);
			// suppress C4996 warning
#ifdef _MSC_VER
			sprintf_s(buf, "%d", v);
#else
			sprintf(buf, "%d", v);
#endif
			std::string r = buf;
			size_t k = r.length();
			for (unsigned int i = 0; i < outlen - k; i++) {
				r = r + ' ';
			}
			return r;
		}

		static std::string Format(long long v, int outlen)
		{
			char buf[50];
			memset(buf, 0, 50);
			// suppress C4996 warning
#ifdef _MSC_VER
			sprintf_s(buf, "%lld", v);
#else
			sprintf(buf, "%lld", v);
#endif
			std::string r = buf;
			size_t k = r.length();
			for (unsigned int i = 0; i < outlen - k; i++) {
				r = r + ' ';
			}
			return r;
		}

		static std::string Format(double v, int outlen, int dotlen = 2)
		{
			v = format_double(v, dotlen);
			char buf[50];
			memset(buf, 0, 50);
			// suppress C4996 warning
#ifdef _MSC_VER
			sprintf_s(buf, "%f", v);
#else
			sprintf(buf, "%f", v);
#endif
			std::string r = buf;
			int k = (int)r.length();
			for (int i = 0; i < outlen - k; i++) {
				r = r + ' ';
			}
			return r;
		}

		static std::string Format(const char *v, int slen, int outlen)
		{
			if (outlen < slen) { outlen = slen; }

			std::string r = v;
			for (int i = 0; i < outlen - slen; i++) {
				r = r + ' ';
			}
			return r;
		}
	};

}
